#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#define fin cin
#define fout cout
int main(){
    //ifstream fin("subseq.in");
    //ofstream fout("subseq.out");
    int n, m;
    while (fin >> n >> m)
    {
        if (n == 0 || m == 0)
            break;

        double res = 0;
        for (int i = m; i >= n; i--)
        {
            long long prt = i*i;
            double s = 1.0 / prt;
            res += s;
        }
        fout << fixed << setprecision(5) << res << endl;
    }
    return 0;
}