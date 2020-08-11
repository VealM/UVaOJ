#include<iostream>
#include<iomanip> 
using namespace std;

int main(){
    double a = 0.043567;
    cout << fixed << setprecision(5) << a << endl;
    cout << resetiosflags(ios::fixed) << scientific << setprecision(6) << a << endl;
    cout << resetiosflags(ios::scientific) << setprecision(5) << a << endl;
    return 0;
}