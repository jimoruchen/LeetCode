#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {                //最长子串
        unordered_map<char, int> mp;
        int r = 0, count = 0;
        for(int l= 0; l < s.size(); l++)
        {
            if(l != 0)   mp.erase(s[l - 1]);
            while(r < s.size() && mp.find(s[r]) == mp.end())
            {
                mp[s[r]]++;
                r++;
            }
            count = max(count, r - l);
        }
    return count;
    }
};

int main()
{
    Solution s;
    string str;
    cin >> str;
    cout << s.lengthOfLongestSubstring(str);
    system("pause");
    return 0;
}