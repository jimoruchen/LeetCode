#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> a;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]+nums[j]==target)
            {
                a.push_back(i);
                a.push_back(j);
            }
        }
    }
    return a;
    }
};
int main()
{
    Solution s;
    vector<int> a;
    int target =9;
    vector<int> nums = {2,7,11,15};
    a = s.twoSum(nums,target);
    for (auto i : a)
        cout << i << " ";
    system("pause");

}