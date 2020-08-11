#include<iostream>
#include<fstream>
using namespace std;
#define fin cin
#define fout cout
int main(){
    //ifstream fin("hanxin.in");
    //ofstream fout("hanxin.out");
    int a = 0, b = 0, c = 0;
    int mods = 3, modm = 5, modl = 7;
    while (fin >> a >> b >> c)
    {   
        int p;
        for ( p = 10; p <= 100; p++)
        {
            if (p % mods == a && p % modm ==b && p%modl ==c)
            {
                fout << p <<endl;
                break; 
            }
        }
        if (p == 101)
            fout << "No answer" << endl;
    }
    return 0;
}