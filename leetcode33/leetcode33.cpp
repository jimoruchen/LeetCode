#include<iostream>
#include<vector>
using namespace std;
class Solution {                    //搜索旋转排序数组
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int l = 0, r = n; 
        while(l <= r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[0] <= nums[mid]) {
            if(nums[0] <= target && target <= nums[mid])
                r = mid - 1;
            else
                l = mid + 1;    
        }
        else {
            if(nums[mid] <= target && target <= nums[n])
                l = mid + 1;
            else
                r = mid - 1;    
        }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums;
    int i = 0, target;
    do
    {
        cin >> i;
        nums.push_back(i);
    } while(getchar() != '\n');
    cin >> target;
    cout << s.search(nums,target); 
    system("pause");
    return 0;
}