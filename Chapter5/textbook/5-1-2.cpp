#include<iostream>
using namespace std;
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("5-1-2.in", "r", stdin);
    freopen("5-1-2.out", "w", stdout);
#endif
    int c, q = 1; // cin.get()返回值为整数，如为字符，则无法与EOF进行区分
    while ((c = cin.get())!= EOF)
    {
        if (c == '"')
            {
                if (q == 1)
                    cout << "``";
                else
                    cout << "''";
                q = !q;    
            }
        else
            cout.put(c); //使用cout.put进行字符输出
        
    }
    return 0;
}