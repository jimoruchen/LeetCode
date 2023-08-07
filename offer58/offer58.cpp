#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    /*string reverseLeftWords(string s, int n) {
        string ss;
        int tmp = 0;
        int len = s.size();
        for(int i = n; i < len; i++)
            ss = ss + s[i];
        for(auto ch : s)
        {
            ss = ss + ch;
            tmp ++;
            if(tmp == n)    break;
        }
            
        return ss;
    }*/
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{
    Solution s;
    string str;
    int n;
    getline(cin, str);
    cin >> n;
    cout << s.reverseLeftWords(str, n);
    system("pause");
    return 0;
}