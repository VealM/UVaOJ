#include<fstream>
#include<string>
#include<iomanip>
#include<time.h>
using namespace std;
int main(){
    string s;
    ifstream fin("putstr.txt");
    ofstream fout("finstr.out");
    while (fin >> s)
    {
        fout << s << "\n";
    }
    fout << "Time used = " << fixed << setprecision(3) << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;    
}