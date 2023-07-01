#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char,int> mp;
        int right = 0, count = 0;
        for(int left = 0; left < s.size(); left++)   //从最左开始寻找最长的子串，有重复则在哈希表中删除最左的字符
        {
            if(left == 0)  mp[s[left]]++;
            else mp.erase(s[left - 1]);
            while(right < s.size() && mp.find(s[right + 1]) == mp.end())  //判断s[right+1]是否在哈希表中
            {
                mp[s[right + 1]]++;
                right++;
            }
            count = max(count, right - left + 1);
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