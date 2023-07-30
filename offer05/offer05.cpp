#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        string m;
        for(auto ch : s)
        {
            if(ch == ' ')
                m += "%20";
            else    m += ch;
        }
        return m;
    }

    /*string replaceSpace(string s) {
        string m;
        string :: iterator it = s.begin();
        while(it != s.end())
        {
            if(*it == ' ')
                m += "%20";
            else    m += *it;
            ++it;
        }
        return m;
    }*/
};

int main()
{
    Solution s;
    string str;
    getline(cin, str);
    cout << s.replaceSpace(str) << endl;        //使用getline输入string字符串，cin遇空格停止
    //char str2[20];
    //cin.get(str2, 20);
    //cout << s.replaceSpace(str2) << endl;
    system("pause");
    return 0;
}