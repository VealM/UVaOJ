#include<cstdio>
#include<time.h>
using namespace std;
#define MAXN 10010
#define LOCAL
char s[MAXN];
int main(){
#ifdef LOCAL
    freopen("putstr.txt","r", stdin);
    freopen("fgetstr.out","w", stdout);
#endif
    while (fgets(s, MAXN, stdin) != NULL) puts(s);
   
    printf("Time used = %.3f\n",(double)clock() / CLOCKS_PER_SEC);
    return 0;
}