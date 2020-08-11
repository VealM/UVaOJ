#include<iostream>
using namespace std;
int main(){
    int a , b;
    while (cin >> a >> b)
    {
        try
        {   // 列举可能异常情形并抛出异常         
            if (b == 0) throw runtime_error("divided by zero!"); //
            // 正常执行部分
            cout << a / b << endl;    
        }
        // 处理try中抛出的异常
        catch(runtime_error err)
        {
            cout << err.what() << "\n Try again? enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
        
    }
    return 0;
}