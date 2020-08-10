#include<cstdio>
#include<time.h>
using namespace std;
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("plus.txt","r",stdin);
    freopen("scannum.out","w",stdout);
#endif
    int a, b;
    while (scanf("%d%d",&a,&b) == 2)
    {
        printf("%d\n",a+b);
    }
    printf("Time used = %.3f\n",(double)clock() / CLOCKS_PER_SEC);
    //cout << "Time used = " << fixed << setprecision(3) << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}