#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("plus.txt","r",stdin);
    freopen("cinnum.out","w",stdout);
#endif
    int a, b;
    while (cin >> a >> b)
    {
        cout << a+b << '\n';
    }
    cout << "Time used = " << fixed << setprecision(3) << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}