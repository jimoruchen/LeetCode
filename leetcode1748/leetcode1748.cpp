#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
/*class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int ,int> map;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            ++map[nums[i]];
        }
        int count = 0;
        for(auto it = map.begin(); it != map.end(); it++)
        {
            if(it ->second == 1) 
                count += it ->first;
        }
        return count;
    }
};*/

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int ,int> map;
        int len = nums.size();
        for(auto num : nums)
            ++map[num];
        int count = 0;
        for(auto &[key, value] : map)
        {
            if(value == 1) 
                count += key;
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int n;
    do
    {
        cin >> n;
        nums.push_back(n);
    } while (getchar() != '\n');
    cout << s.sumOfUnique(nums);
    system("pause");
    return 0;
}