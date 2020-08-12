#include<iostream>
using namespace std;
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("thirdmax.in","r",stdin);
    freopen("secmax.out","w",stdout);
#endif
    int fir, sec, num;
    cin >> fir >> sec;
    if (fir < sec)
        { int t = fir;fir = sec;sec = t;}
    while (cin >> num)
    {
        if (num > fir)
        {
            sec = fir;
            fir = num;
        }
        else if (num > sec)
        {
            sec = num;
        }
        
    }
    cout << fir << " " << sec << endl;
    return 0;
}