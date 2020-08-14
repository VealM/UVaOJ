# 大整数类设计文档
*大整数类断断续续写了两天，最后写除法的时候才发现最大的问题是没有明确的输入输出限制意识，导致隐藏bug*
输入：必须为正整数，四则运算、比较运算符仅限于正整数之间
输出：减法输出可为负数，其余均应为非负整数。

## 存储

``` cpp
struct bign{
    int len, s[maxn];
    string sign;
}
```

使用整数数组对大整数进行**逆序逐位**存储(从下标0开始)，len记录长度，sign记录符号位(正数为空，负数为"-")

## 构造函数

默认构造函数
``` cpp
bign(){memset(s, 0, sizeof(s)); len = 1;}
```
使用赋值运算定义有参构造函数

### 重载赋值运算符

声明

``` cpp
bign operator = (const string& num);
bign operator = (const int& num);
```

注：const string& 代表字符串的常量引用，也即无法通过该引用修改字符串的值（但不代表该字符串是常量字符串）。
另有一种说法，常量引用相比于常量效率要高，因此传参尽量使用常量引用（然而，我觉得真正理由如上条+引用不用拷贝因而效率高）。

思路：
- 1 字符串赋值
逐字符读取string num，存储至数组；
- 2 整数初赋值
将int num通过ostringstream最终读到string num，调用字符串赋值

实现
``` cpp
bign bign::operator = (const string& num){
        len = num.size();
        for (int i = 0; i < len; i++)
        {
            s[i] = num[len - 1 -i] - '0';
        }
        return *this; // 返回对象
}

bign bign::operator = (const int& num){
        ostringstream numstr;
        numstr << num;
        string bnum = numstr.str();
        *this = bnum;
        return *this;
}
```

### 有参构造函数

``` cpp
bign(const string& num){*this = num;}
bign(const int& num){*this = num;}
```

使用示例
``` cpp
string s = "123456789";
bign num1(s);
int n2 = 1234567;
bign num2(n2);
```

**疑问**：是否应考虑如下初始化方式

``` cpp
bign num("123456");
```

这里，"123456"的类型是const char[6]，我考虑过以下构造函数，但显然强制转换也不能这么搞 const char* s = "123456";所以这个问题暂时不知道怎么解决。后面输入流间接解决了这个问题。

``` cpp
bign(const char* s);
```

## 输入输出流

输入输出流为非成员函数接口。

### 输入流

读入bign对象

思路
从流对象in中读取string，并用string对bign x赋值，返回流对象in
*此处为 bign& x是因为输入流改变了x，因此不能为const bign& x*
实现

``` cpp
istream& operator >> (istream &in, bign& x)
{
        string s;
        in >> s;
        x = s;
        return in;
}
```

### 输出流

#### str方法
我们通过先定义bign的str()方法（成员函数），再据此给出输出流的实现

``` cpp
string bign::str() const{
        string numstr;
        for (int i = 0; i < len; i++)
        {
            numstr = char(s[i] + '0') + numstr;
        }
        numstr = sign + numstr; //符号位输出
        if (numstr.empty()) numstr = "0";
        return numstr;
}
```

#### 输出

``` cpp
ostream& operator << (ostream &out, const bign& x)
{
        out << x.str();
        return out;
}
```

## 运算符

先定义比较运算符，因为减法、除法都能用得到
### 比较关系符

#### <

``` cpp
bool bign::operator< (const bign &b) const{
    if (len != b.len) return len < b.len;
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] != b.s[i]) return s[i] < b.s[i];
    }
    return false;
}
```

然后向大家展示如何用<定义完所有比较符（这大约就是数学的魔力吧）

``` cpp
bool bign:: operator > (const bign &b) const{
    return b < *this;
}
bool bign:: operator<= (const bign &b) const{
    return !(b < *this);
}
bool bign:: operator>= (const bign &b) const{
    return !(*this < b);
}
bool bign:: operator!= (const bign &b) const{
    return (*this < b) || (b < *this);
}
bool bign:: operator== (const bign &b) const{
    return !(*this < b) && !(b < *this);
}
```

### 算术关系符

#### +

模拟手算，需要注意如果相加至最高位仍有进位，需要记录

``` cpp
bign operator + (const bign& a , const bign& b)
{
    bign c = 0;
    c.len = 0;
    for (int i = 0, g = 0; i < max(a.len, b.len) || g; i++)
    {
        int x = g;
        if (i < a.len) x += a.s[i];
        if (i < b.len) x += b.s[i];
        
        c.s[c.len++] = x % 10;
        g = x / 10;        
    }
    return c;
}
```

根据cpp primer中的设计准则而言，将+=定义为bign类的成员函数，在此基础上将+定义为非成员函数更合适...但我感觉+=真的蛮容易写混的...干脆还是从+写起，也方便其他人查看思路
#### +=

``` cpp

bign operator += (bign& a, const bign& b)
{
    a = a + b;
    return a;
}
```

#### *
其实乘法比减法好写
思路还是逐位模拟手算，这里比较妙的一点是逐位乘积相加时，我直接在存储上操作完成了**乘以10的幂次**效果

``` cpp
bign operator * (const bign& a, const bign& b){
    if (a == 0 || b == 0) return bign(0);
    if (a == 1) return b;
    if (b == 1) return a;
    bign res = 0;
    int j, i, g;
    for ( j = 0; j < b.len; j++)
    {
        bign c = 0; c.len = j; // 乘子 b[j]
        for ( i = 0, g = 0; i < a.len || g; i++)
        {
            int multi = g + b.s[j]*a.s[i];
            g = multi / 10;
            c.s[c.len++] = multi % 10;
        }
        res += c;
    }
    return res;
}
```

据说乘法可以用递归算法，效率更高，后期有空补上（

#### *=

``` cpp
bign operator *= (bign& a, const bign& b){
    a = a * b;
    return a;
}
```

#### /

对于除法写的不满意，其中涉及到一个频繁的运算(\*=10)，其实就是一个append(0)操作，但是数组的话是O(N)复杂度，所以我就偷懒用大整数乘法了，感觉**10的幂次乘是不是作为乘法的特殊样例进行快速处理**比较好？
这里也做了个前导零清除的操作，其实可以在第一次遇到商的非零位记录，算出来res.len的。

``` cpp
bign operator / (const bign& a, const bign& b){
    if (b == 0) throw runtime_error("could not divided by zero!");
    if (a < b) return bign(0);
    if (a == b) return bign(1);
    bign res(0); res.len = a.len;
    bign c(0);
    for (int i = a.len - 1; i >= 0; i--)
    {
        c += a.s[i];
        if (c == b)
        {
            c = 0; res.s[i] = 1;
        }
        else if (c < b)
        {
            c *= 10; res.s[i] = 0;
        }
        else
        {
            int k = 0;
            bign tot(0);
            while (tot <= c)
            {
                tot += b;
                k++;
            }
            tot -= b;
            c -= tot;
            c *= 10;
            res.s[i] = k - 1;
        }
        
    }
    // 清除前导0
    int j;
    for (j = res.len - 1; res.s[j]==0; j--);
    res.len = j + 1;
    return res;
}
```

说到这里不得不提某个隐藏bug，它就藏在while循环里...之前我是这么写的

``` cpp
while (c >= 0)
{
        c -= b;
        k++;
}
c += b;
res.s[i] = k - 1;
```

也就是说，当 c>= 0 不满足时跳出while循环，但此时c为负数，负数不能与0进行比较（因为比较运算符仅限非负整数间比较）！

这个bug最终靠gdb调试查出来，据说说好的代码都不靠gdb抓bug...一笔写成...只能吐槽自己还是太菜啦

另一个问题是**非法输入处理**(除数为0)，之前看c++ primer有try和throw，我也用了下...但感觉这个处理不是很优雅...因为我尝试非法输入后，尽管显示了提示信息，但exe程序好像还是崩溃了...回忆了下，似乎cpp中如果输入除数为0，直接返回inf。

``` cpp
 if (b == 0) throw runtime_error("could not divided by zero!");
```

#### /=

``` cpp
bign operator /= (bign& a, const bign& b){
    a = a / b;
    return a;
} 
```

当时还写了个除法操作，也是模拟手算，但异常麻烦，只是不用处理前导0问题了，我注释掉了。

## 测试单元

测试主函数还是非常漂亮的

``` cpp
int main(){
    bign num1, num2;
    cin >> num1 >> num2;
    cout << num1 + num2 << endl;
    cout << num1 - num2 << endl;
    cout << num1 * num2 << endl;
    cout << num1 / num2 << endl;
    return 0;

}
```

后期还可以把类定义放在bign.h里，然后函数实现放在bign.cpp，用到bign类的文件名为main.cpp，不过最终编译的时候要自己写个makefile来编译链接，有空再补上~（毕竟是win下脱离了IDE写代码我也好苦...）