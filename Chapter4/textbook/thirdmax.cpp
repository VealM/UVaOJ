#include<iostream>
using namespace std;
int main(){
    int fir, sec, thd, num;
    cin >> num;
    fir = sec = thd = num;
    while (cin >> num)
    {
        if (num > fir)
        {
            thd = sec;
            sec = fir;
            fir = num;
        }
        else if (num > sec)
        {
            thd = sec;
            sec = num;
        }
        else if (num > thd)
        {
            thd = num;
        }
        
    }
    cout << fir << " " << sec << " " << thd << endl;
    return 0;
}