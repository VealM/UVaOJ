#include<iostream>
using namespace std;

int getDigit(int q, int& mul){
    //return q/100 + (q/10)%10 + q%10;
    int hi = q/100;
    int mid = (q/10) % 10;
    int lo = q % 10;
    mul = mul * hi * mid * lo;
    return hi + mid + lo;
}

int main(){
    int s ,m, l;
    for ( s = 123; s < 333; s++)
    {
        m = s*2;
        l = s*3;
        int multi = 1;
        int sum = getDigit(s,multi) + getDigit(m,multi) + getDigit(l,multi);
        int check = 2*3*4*5*6*7*8*9;
        if (sum == 45 && multi == check)
            cout << s << " " << m  << " " << l << endl;
    }
    return 0;
}