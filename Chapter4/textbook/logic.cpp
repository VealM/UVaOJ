#include<iostream>
#include<string>
using namespace std;
int main(){
    int len_s = 280;
    try
    {
        if (len_s > 256) throw out_of_range("len_s is out of range");
    }
    catch(out_of_range error)
    {
        cout << error.what() << endl;
    }
    return 0;
}