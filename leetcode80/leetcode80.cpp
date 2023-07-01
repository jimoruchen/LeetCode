#include<iostream>
#include<vector>
using namespace std;
class Solution {                      //删除有序数组中的重复项 II
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int l = 2, r = 2;
        while (r < n) {
            if (nums[l - 2] != nums[r]) {
                nums[l] = nums[r];
                ++l;
            }
            ++r;
        }
        return l;
    }
};
int main() 
{
    Solution s;
    vector<int> nums;
    int i;
    do
    {
        cin >> i;
        nums.push_back(i);
    }while(getchar() != '\n');
    int temp = s.removeDuplicates(nums);
    cout << temp << endl;
    for(i = 0; i < temp; i++)
        cout << nums[i] << " ";
    system("pause");
    return 0;
}