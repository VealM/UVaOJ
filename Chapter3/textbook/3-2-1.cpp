// 3-2-1.cpp 竖式问题
// g++ 3-2-1.cpp -o 3-2-1 支持C++11标准
#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cstdio>
using namespace std;
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("3-2-1.in", "r", stdin);
    freopen("3-2-1.out", "w", stdout);
#endif
    string src;
    cin >> src;
    int abc, de, x, y, z, cnt = 0;
    // 题目默认'0'用' '代替，所以我们从111和11开始遍历
    for (abc = 111; abc < 999; abc++)
    {
        for (de = 11; de < 99; de++)
        {
            // 计算竖式
            x = abc * (de % 10);
            y = abc * (de / 10);
            z = abc * de;

            // 重定向输出
            ostringstream s;
            s << abc << de << x << y << z;
            string op = s.str();

            // 合理性检验
            bool ok = 1;
            for(auto c : op)
            {
                if(src.find(c) == string::npos)
                    {
                        ok = 0;
                        break;
                    }
            }
            // 输出竖式
            if (ok)
                {
                    cnt++;
                    cout << "<" << cnt << ">" << endl;
                    string split(5,'-');
                    cout << setw(5) << abc << '\n' << "X" << setw(4) << de << '\n' << split << '\n' << setw(5) << x << '\n' << setw(4) << y << '\n' << split << '\n' << setw(5) << z << endl;
                }
        }
        
    }
    cout << "The number of solutions = " << cnt << endl;
    return 0;
    
}