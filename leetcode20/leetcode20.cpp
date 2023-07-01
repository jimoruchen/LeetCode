#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len % 2 == 1)
            return false;
        unordered_map<char, char> map = {
        {')', '('},
        {']', '['},
        {'}', '{'}
        };
        stack<char> stk;
        for(char ch : s)
        {
            if(map.count(ch))
            {
                if(stk.empty() || stk.top() != map[ch])
                    return false;
                stk.pop();
            }
            else
                stk.push(ch);
        }
        return stk.empty();
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    string str;
    cin >> str;
    cout << s.isValid(str) << endl;
    system("pause");
    return 0;
}