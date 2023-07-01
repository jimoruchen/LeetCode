#include<iostream>
#include<unordered_map>
using namespace std;
class Solution  {                // 罗马数字转整数
public:
    int romanToInt(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++)
            map[s[i]] < map[s[i + 1]] ? count -= map[s[i]] : count += map[s[i]];  
        return count;
    }
private:
    unordered_map<char, int> map {
       {'I', 1},
       {'V', 5},
       {'X', 10},
       {'L', 50},
       {'C', 100},
       {'D', 500},
       {'M', 1000}, 
    };
};

int main()
{
    Solution s;
    string str;
    cin >> str;
    cout << s.romanToInt(str) << endl;
    system("pause");
    return 0;
}