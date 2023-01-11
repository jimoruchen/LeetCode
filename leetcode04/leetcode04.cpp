#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<double> a;
    int length1 = nums1.size();
    int length2 = nums2.size();
    int m = length1 + length2;
    for(int i = 0; i < length1; i++)
    {           
        a.push_back(nums1[i]); 
    }
    for(int i = 0; i < length2; i++)
    {
        a.push_back(nums2[i]);
    }
    sort(a.begin(),a.end());
    if(m % 2 == 0)
        return (a[m/2] + a[m/2-1]) / 2;
    else
        return a[m / 2];
    }
};

int main()
{
    Solution s;
    vector<int> nums1;
    int num1 = 0;
    do {
        cin >> num1;
        nums1.push_back(num1);
    } while (getchar() != '\n');
    vector<int>nums2;
    int num2 = 0;
    do {
        cin >> num2;
        nums2.push_back(num2);
    } while (getchar() != '\n');
    cout << s.findMedianSortedArrays(nums1,nums2);
    system("pause");
    return 0;


}