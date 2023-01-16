#include<iostream>
#include<string>
using namespace std;
class Solution{
public:
    string convert(string s, int numRows) {
		if (numRows == 1) return s;

		int step = numRows * 2 - 2; // 间距
		int index = 0;// 记录s的下标
		int len = s.length();
		int add = 0; // 真实的间距
		string ret;
		for(int i = 0; i < numRows; i++) {
			index = i;
			add = i * 2;
			while (index < len)//超出字符串长度计算下一层
			{
				ret += s[index]; // 当前行的第一个字母
				add = step - add;// 第一次间距是step -2*i，第二次是2*i, 
				index += (i == 0 || i == numRows-1) ? step : add; // 0行和最后一行使用step间距，其余使用add间距
			}
		}
		return ret;

    }

};

/*
class Solution {
public:
    string convert(string s, int numRows) {
        //1.step = 2*numRows - 2
        //2.step - (hangshu-1)*2  2*i
        //3.2*i    step - (hangshu-1)*2
        //numRows.step
        if(numRows == 1)
            return s;
        int length = s.size();
        int step = 2 * numRows - 2;
        string end;
        int index;
        for(int i = 0; i < numRows; i++)
        {
            index = i;
            int temp = 2*i;
            int ret = step - temp;
            while(index < length) {
            end = end + s[index];
            if(i == 0 || i == numRows - 1)
            {
                index += step;
            }
            else
            {
                index += ret;
                ret = step - ret;
            }
            }
        }
        return end;
        //"PINALIGYAIHRNPI"

    }
};
*/
int main()
{
    Solution s;
    string str;
    int numRows;
    getline(cin, str);
    cin >> numRows;
    cout << s.convert(str , numRows);
    system("pause");
    return 0;


}