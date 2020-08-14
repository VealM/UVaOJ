#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 3000;
int f[maxn];
int main(){
    int n;
    cin >> n;
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for ( int i = 2; i <= n; i++)
    {
        int g = 0; //初始进位
        for(int k=0; k < maxn; k++)
            {
                int s = g + f[k] * i;
                f[k] = s % 10;
                g = s / 10;
            }
    }
    int j;
    for ( j = maxn - 1; j>=0; j--) 
    {
        if(f[j]) break;
    }
    for(;j>=0;j--){cout << f[j];}
    cout << endl;
    return 0;
}