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
            int seg = len_s / T;
            for (int k = 0; k < T; k++)
            {
                for (int i = 1; i < seg; i++)
                {
                    if (s[k]!=s[k+i*T])
                    {
                        ok = 0;break;
                    }
                    
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