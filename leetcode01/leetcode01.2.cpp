#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {                     //两数之和
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++)
    {                                            //在哈希表中查找是否存在一个键等于目标值减去当前数字的差值
        auto it = map.find(target - nums[i]);    //找到则返回指向这个键值对的迭代器，否则返回哈希表的 end 迭代器
        if(it != map.end())                      
            return {it->second, i};  //如果 it 不等于哈希表的 end 迭代器，则说明已经找到了
        map[nums[i]] = i;            //返回它的值 it->second（即补数的索引）和当前数字的索引 i 构成的向量。
    }
    return {};                       //如果没有找到解决方案，则返回一个空向量
    }
};
int main()
{
    Solution s;
    vector<int> a;
    int target =9;
    vector<int> nums;
    int i;
    do
    {
        cin >> i;
        nums.push_back(i);
    }while(getchar() != '\n');
    a = s.twoSum(nums,target);
    for (auto i : a)
        cout << i << " ";
    system("pause");
}