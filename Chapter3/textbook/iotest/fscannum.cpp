#include<cstdio>
#include<time.h>
using namespace std;
int main(){
    FILE *fin, *fout;
    fin = fopen("plus.txt", "rb");
    fout = fopen("fscannum.out","wb");
    int a, b;
    while (fscanf(fin, "%d%d",&a,&b) == 2)
    {
        fprintf(fout, "%d\n",a+b);
    }
    fprintf(fout, "Time used = %.3f\n",(double)clock() / CLOCKS_PER_SEC);
    //cout << "Time used = " << fixed << setprecision(3) << (double)clock() / CLOCKS_PER_SEC << endl;
    fclose(fin);
    fclose(fout);
    return 0;
}