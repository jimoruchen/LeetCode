#include<iostream>
#include<string>
#include<vector>
using namespace std;  
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int begin = 0;
        int count = 1;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        //dp[i][j] = (s[i] = s[j]) and dp[i + 1][j - 1]
        //(j - 1) - (i + 1) < 1              对于s[i..j] j - i < 3 即宽度为2或3时不用检查
        for (int j = 1; j < n; j++) {

            for (int i = 0; i < n; i++) {
                
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {    //当s[i]=s[j]但长度为2或3时不用检查
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && j - i + 1 > count) {
                    count = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, count); //substr复制子字符串
    }
};

int main() {
    Solution s;
    string str;
    getline(cin, str);
    cout << s.longestPalindrome(str);
    system("pause");
    return 0;
}