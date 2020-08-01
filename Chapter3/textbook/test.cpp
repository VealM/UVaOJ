#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string s1("hello");
    int n = -1;
    // size与empty操作
    if (s1.size() < n)
        cout << "wrong answer!" << endl;
    cout << "s1 is empty? " << s1.empty() << endl; 
    cout << "length of s1 is" << s1.size() << endl;
    
    // 字符串比较
    /*
    string s2 = "abby";
    string s3 = "abby finder";
    string s4 = "abbY";
    string s5 = "Zbby";

    cout << s2 << " < " << s3 << '\t' << (s2<s3) <<endl;
    cout << s2 << " < " << s4 << '\t' << (s2<s4) <<endl;
    cout << s2 << " < " << s5 << '\t' << (s2<s5) <<endl;
    */

   // 子串
    // 查找子串
   string s = "we learn english from abc.";
   cout << s.substr(3,5) << endl;
   string s6 = "abc";
   cout << s.find(s6) << endl;
   cout << s.rfind(s6) << endl; // s.find(s2) == s.rfind(s2)
   cout << s.find_first_of(s6) << endl;
   cout << s.find_last_of(s6) << endl;
   cout << s.find_first_not_of(s6) << endl;
   cout << s.find_last_not_of(s6) << endl;
   
   // 替换、插入、删除子串
   string s7 = "hello";
   cout << string(6,'*') << "string replace" << string(6,'*') << endl;
   cout << s.replace(22,3,s7) << endl;
   cout << s.replace(22,5,s6,0,2) << endl;
   cout << string(6,'*') << "string erase" << string(6,'*') << endl;
   cout << s.erase(22,2) << endl;
   cout << string(6,'*') << "string insert" << string(6,'*') << endl;
   cout << s.insert(22,s7) << endl;

   // 将string对象作为流处理
   string s8("Beijing 2008.8 year 3 days");
   istringstream input(s8);
   string ss1, ss2, ss3;
   double y;
   int d;
   input >> ss1 >> y >> ss2 >> d >> ss3; //将input流写入各个变量
   ostringstream output; 
   output << ss1 << '\t' << ss2 << '\t' << ss3 << '\t' << d << '\t' << y << endl; //将各个变量写入output变量
   cout << output.str();
   // getline用法
   //cout << string(6,'*') << "test for getline" << string(6,'*') << endl;
   //string ss4;
   //getline(cin,ss4);
   //cout << ss4 << endl;

   // string对象的遍历访问
    // 全序列遍历
   cout << string(6,'*') << "test for range for" << string(6,'*') << endl;
   for (auto c : s7)
        cout << c << endl;
   // 引用遍历
   for (auto &c : s7)
        c = toupper(c);
    cout << s7 << endl;
   // 下标遍历
   if (!s7.empty())
        cout << s7[0] << endl; 
   return 0;
}