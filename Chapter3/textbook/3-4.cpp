#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<cstdio>
#define LOCAL
using namespace std;
int main(){
#ifdef LOCAL
    freopen("3-4.in", "r", stdin);
    freopen("3-4.out", "w", stdout);
#endif
    string src;string s;vector<int> p;
    getline(cin,src);
    //预处理
    int len_src = src.size();
    for (int i = 0; i < len_src ; i++)
    {
        if (isalpha(src[i]))
            {
                s.push_back(tolower(src[i])); //追加单字符使用push_back
                p.push_back(i);
            }
    }

    int x = 0, y = 0, m = 0, j = 0; //s中回文串位置
    int len_s = s.size();
    int max = 0;
    for ( m = 0; m < len_s; m++)
    {
        //奇长子串
        for ( j = 0; m-j >=0 && m+j < len_s; j++)
        {
            if (s[m-j] != s[m+j]) break;
            int cur_len = 2*j + 1;
            if (cur_len > max) 
                {
                    max = cur_len;
                    x = m - j;
                    y = m + j;
                }
        }
        //偶长子串
        for ( j = 0; m-j >=0 && m+j-1 < len_s; j++)
        {
            if (s[m-j] != s[m+j-1]) break;
            int cur_len = 2*j;
            if (cur_len > max)
                {
                    max = cur_len;
                    x = m - j;
                    y = m + j - 1;
                }
        }
        
    }
    // 映射回原坐标
    x = p[x];
    y = p[y];
    //原样输出
    cout << src.substr(x, y-x+1) << endl;
    return 0;
}