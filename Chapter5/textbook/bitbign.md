# 大整数类（二进制版）

之前的十进制版使用int s[maxn]来存储大整数，大佬说这样浪费了，用short就可以，不过即使是short，还是浪费了两位。刚刚忽然想，可以用位图数组来存储大整数，一位都不浪费（

位图数组示意如下

![bitmap.png](https://i.loli.net/2020/08/15/1GIaxWLoBmVHChv.png)

十进制意义下，int s[maxn]表示的存储上限即10^maxn；二进制意义下，int s[maxn]表示的存储上限即2^(32*maxn)

我们称s[i]的下标i为*element index*，称二进制位的下标为*index*

采用位图数组存储，我们则完全模拟数字电路中的加法器进行运算；作为一个不懂数字电路的渣渣，先不考虑超前并行加法器这么深奥的东西，先考虑三个定义在位图数组上最基本的操作

- 给定index，查看位图数组的index位
- 给定index，设置index位为1
- 给定index, 设置index位为0

对于int，data_size = 32;同理，short的data_size = 8; long long的data_size = 64。

下列方法将用到位运算的奇淫技巧
**GetBit方法实现**

``` cpp
bool GetBit(const bign& a, int index){
    //定位element
    int element_index = index / data_size;
    //定位element中的相对位置
    int position = index % data_size;
    long long flag = 1;
    flag = flag << position;
    if ((a.s[element_index] & flag) != 0)
        return true;
    else
        return false;
}
```

**SetBit方法实现**

``` cpp
void SetBit(bign& a, int index){
    int element_index = index / data_size;
    int position = index % data_size;
    long long flag = 1;
    flag = flag << position;
    a.s[element_index] = a.s[element_index] | flag;
}
```

**ClearBit方法实现**

``` cpp
void ClearBit(bign &a, int index){
    int element_index = index / data_size;
    int position = index % data_size;
    long long flag = 1;
    flag = ~(flag << position); //取反
    a.s[element_index] = a.s[element_index] & flag;
}
```
三个方法的复杂度全是O(1)！

比较麻烦的就是大整数初始化问题...小学学的进制转化是模N取余法...百度了一下大整数进制转换，结果又变成我写的10进制里的大整数除法...吐了...但如果追求运算而非显示十进制的话，我觉得我这个想法挺好的...如果要人类一点的话，那还是大佬说的用short作为基本单位来模拟加进位吧