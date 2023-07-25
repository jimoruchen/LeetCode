#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {                    //判断子序列
        int len1 = s.size();
        int len2 = t.size();
        int i = 0, j = 0;
        while(i < len1 && j < len2)
        {
            if(s[i] == t[j])
                i++;
            j++;
        }
        return i == len1;
    }
};

int main()
{
    Solution s;
    string str1, str2;
    cin >> str1 >> str2;
    cout << s.isSubsequence(str1, str2);
    system("pause");
    return 0;
}