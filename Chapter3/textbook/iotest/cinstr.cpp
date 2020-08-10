#include<iostream>
#include<string>
#include<time.h>
#include<iomanip>
using namespace std;
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("putstr.txt","r", stdin);
    freopen("cinstr.out","w", stdout);
#endif
    string s;
    while (cin >> s)
    {
        cout << s << "\n";
    }
    cout << "Time used = " << fixed << setprecision(3) << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;    
}