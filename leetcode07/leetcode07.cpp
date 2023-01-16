#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int y = 0;     // -2147483648    2147483647
        int ret = 0;
        while(x != 0)
        {
            y = x % 10;
            if(ret>214748364 || (ret==214748364 && y>7))  //到最后一位判断是否大于2147483647
                return 0;
            if(ret<-214748364 || (ret==-214748364 && y<-8))  //到最后一位判断是否小于-2147483648
                return 0;
            ret = ret*10 + y;
            x = x / 10;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    int x;
    cin >> x;
    cout << s.reverse(x) << endl;
    system("pause");
    return 0;

}