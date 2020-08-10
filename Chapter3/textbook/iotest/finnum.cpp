#include<fstream>
#include<iomanip>
#include<time.h>
using namespace std;
ifstream fin("plus.txt");
ofstream fout("finnum.out");
int main(){
    int a, b;
    while (fin >> a >> b)
    {
        fout << a+b << '\n';
    }
    fout << "Time used = " << fixed << setprecision(3) << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}