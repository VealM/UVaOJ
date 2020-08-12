#include<iostream>
using namespace std;
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("thirdmax.in","r",stdin);
    freopen("thirdmax.out","w",stdout);
#endif
    int maxn = 0x80000000;
    int fir, sec, thd;
    fir = sec = thd = maxn;
    int num;
    while (cin >> num)
    {   
        if(num == fir || num == sec || num == thd) continue;
        if (num > fir)
            {
                thd = sec; sec = fir; fir = num;
            }
        else if (num > sec)
            {
                thd = sec; sec = num;
            }
        else if (num > thd)
            {
                thd = num;
            }
    }

    if (thd == maxn)
        cout << fir << endl;
    else 
        cout << thd << endl;
    
    return 0;
}