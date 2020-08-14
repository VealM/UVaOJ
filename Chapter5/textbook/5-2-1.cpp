#include<iostream>
using namespace std;
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("5-2-1.in", "r", stdin);
    freopen("5-2-1.out", "w", stdout);
#endif
    int a, b;
    while (cin >> a >> b)
    {
        int cnt = 0, g = 0;
        if(!a && !b)
            break;
        for (;a || b;)
        {
            g = g + a%10 + b%10;
            g /= 10;
            cnt += g;
            a /= 10;
            b /= 10;
        }
        cout << cnt << endl;
    }
    return 0;
}