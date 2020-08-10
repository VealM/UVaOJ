#include<cstdio>
#include<time.h>
using namespace std;
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("putstr.txt","r",stdin);
    freopen("charstr.out","w",stdout);
#endif
    int ch;
    while ((ch = getchar()) != EOF)
    {
        putchar(ch);
    }
    printf("Time used = %.3f\n",(double)clock() / CLOCKS_PER_SEC);
    return 0;
}
