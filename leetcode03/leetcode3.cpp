#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int count=0,right=0;
        for(int left=0;left<s.size();left++)
        {   
            if (left == 0)  map[s[left]]++;  //使用滑动窗口
            else  map.erase(s[left - 1]);
            while (right < s.size()-1 && map.find(s[right+1]) == map.end()) { //find函数判断是否在hash中，不在返回end()。
                map[s[right + 1]]++;
                right++;
            }
            count=max(count,right-left+1);
        }
    return count;
    }
};
int main()
{
    string m;
    cin >> m;
    Solution solution;
    cout << solution.lengthOfLongestSubstring(m) << endl;
    system("pause");
    return 0;
}