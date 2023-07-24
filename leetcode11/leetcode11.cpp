#include<iostream>
#include<vector>
using namespace std;
class Solution {    
public:                                         //盛最多水的容器，使用双指针法
    int maxArea(vector<int>& height) {          //如果height[l]<height[r],则无论r向左移多少，height[l] * (r - l)最大
        int r = height.size() - 1;              //此时l++右移
        int l = 0, Max = 0, tmp = 0;
        while(l < r)
        {
            if(height[l] <= height[r])
            {
                tmp = height[l] * (r - l);
                Max = max(Max, tmp);
                l++;
            }
            else
            {
                tmp = height[r] * (r - l);
                Max = max(Max, tmp);
                r--;
            }
        }
        return Max;
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
    cout << s.maxArea(nums) << endl;
    system("pause");
    return 0;
}