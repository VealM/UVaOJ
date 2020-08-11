#include<iostream>
#include<string>
#include<cstdio>
#define LOCAL
using namespace std;
int main(){
#ifdef LOCAL
    freopen("5-1-3.in","r",stdin);
    freopen("5-1-3.out","w",stdout);
#endif
    string s;
    cin >> s;
    int len_s = s.size(), T = 0;
    for ( T = 1; T <= len_s; T++)
    {
        if (!(len_s % T))
        {
            int ok = 1;
            for (int k = T; k < len_s; k++)
            {
                    if (s[k]!=s[k%T])
                    {
                        ok = 0;break;
                    }
                        
            }
           if (ok)
                {
                    cout << T << endl;
                    break;
                } 

        }
        
    }
    return 0;
}