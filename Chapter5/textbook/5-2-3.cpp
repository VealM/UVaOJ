#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
#include<algorithm>
using namespace std;
const int maxn = 1000;
struct bign
{
    int len, s[maxn]; //长度 逆序数组存储
    string sign = ""; //符号位
    // 构造函数
    bign(){memset(s, 0, sizeof(s)); len = 1;}
    bign(const string& num){*this = num;}
    bign(const int& num){*this = num;}
    //成员函数
        // 赋值运算符 
    bign operator = (const string& num);
    bign operator = (const int& num);
        // bign转换为字符串 const代表此this指针不可改变指向对象
    string str() const;
        //自加运算符
    //bign operator += (const bign& b);
        //自减运算符
    //bign operator -= (const bign &b);
    // 比较运算符    
    bool operator < (const bign &b) const;
    bool operator > (const bign &b) const;
    bool operator >= (const bign &b) const;
    bool operator <= (const bign &b) const;
    bool operator == (const bign &b) const;
    bool operator != (const bign &b) const; 
};
//成员函数接口实现
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

/*
bign bign::operator += (const bign& b){
    int g = 0, olen = len;
    len = 0;
    for (int i = 0; i < max(olen, b.len) || g; i++)
    {
        int x = g + s[i] + b.s[i];
        s[len++] = x % 10;
        g = x / 10; 
    }
    return *this;
}
*/

bool bign::operator< (const bign &b) const{
    if (len != b.len) return len < b.len;
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] != b.s[i]) return s[i] < b.s[i];
    }
    return false;
}
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
//非成员函数实现
 // 输入流
istream& operator >> (istream &in, bign& x)
{
        string s;
        in >> s;
        x = s;
        return in;
}
//输出流
ostream& operator << (ostream &out, const bign& x)
{
        out << x.str();
        return out;
}
//加法
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
bign operator += (bign& a, const bign& b)
{
    a = a + b;
    return a;
}
bign operator - (const bign& a ,const bign& b)
{
    bign c = 0;
    if (a == b) return c;
    c.len = 0;
    if (a > b){
        for (int i = 0,g = 0; i < max(a.len, b.len); i++)
        {
            int x = a.s[i] - b.s[i] - g;
            if (x < 0){
                x += 10; g = 1;
            }
            else g = 0;
            c.s[c.len++] = x; 
        }
    }
    else {
        c.sign = "-";
        for (int i = 0, g = 0; i < max(a.len, b.len); i++)
        {
            int x = b.s[i] - a.s[i] - g;
            if (x < 0){
                x += 10; g = 1;
            } 
            else g = 0;
            c.s[c.len++] = x;
        }
    }
    //清除前导0
    int j;
    for (j = c.len -1; c.s[j]==0; j--){}
    c.len = j + 1;
    return c;
    
}

bign operator -= (bign& a, const bign& b){
    a = a - b;
    return a;
}

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
bign operator *= (bign& a, const bign& b){
    a = a * b;
    return a;
}

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

bign operator /= (bign& a, const bign& b){
    a = a / b;
    return a;
} 
/*
bign operator / (const bign& a, const bign& b){
    if (a < b) return bign(0);
    if (a == b) return bign(1);
    bign res(0), c(0); 
    int i, j, k;
    for (i = a.len - 1; i >= 0; i--)
    {
        c += a.s[i];
        if (c < b) {
            for (j = i-1;j >= 0;j--){
                c *= 10;
                c += a.s[j];
                res *= 10;
                if (c >= b) { i = j; break;}        
            }
            if (j == -1) {res *= 10;break;}
        }
       
        for(k = 9; k >= 0; k--){
            if ( k*b <= c) { c -= k*b; break;}
        }
        res *= 10;
        res += k; 
        c *= 10;
    }
    return res;
}
*/
int main(){
    bign num1, num2;
    cin >> num1 >> num2;
    cout << num1 + num2 << endl;
    cout << num1 - num2 << endl;
    cout << num1 * num2 << endl;
    cout << num1 / num2 << endl;
    return 0;

}