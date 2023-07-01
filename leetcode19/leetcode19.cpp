#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void  CreatLinkList1(ListNode *head, vector<int> a, int n) 
{
    /*ListNode * p = head;    //尾插法
    for(int i = 0; i < n; i++)
    {
        ListNode * q = new ListNode;
        q ->val = a[i];
        q ->next = p ->next;
        p ->next = q;
        p = q;
    }*/
    ListNode * cur = head;
    for(int i = 0; i < n; i++)
    {
        cur ->next = new ListNode(a[i]);
        cur = cur ->next;
    }
}

void PrintLinkList(ListNode *head)
{
    ListNode * p = head ->next;
    cout << "输出链表：";
    while(p) 
    {
        cout << p ->val << " ";
        p = p ->next;
    }
    cout << endl;
}
class Solution {                   //删除链表的倒数第 N 个结点
public:
    //int getlength(ListNode * head)
    //{
    //    int length = 0;
    //    while(head)
    //    {
    //        ++length;
    //        head = head ->next;
    //    }
    //    return length;
    //
    //}                       //删除倒数第n个节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode * q = head;
        while(q)
        {
           length++;
           q = q ->next;
        }
        //ListNode * dummy = new ListNode;
        //dummy ->next = head;
        //int length = getlength(head);
        ListNode * dummy = new ListNode(0,head);
        ListNode * cur = dummy;
        for(int i = 1; i < length - n + 1; ++i)
            cur = cur ->next;
        cur ->next = cur ->next ->next;
       // delete p;
        return dummy ->next;
      
    }
};
int main() 
{
    Solution s;
    ListNode * head = new ListNode;
    vector<int> nums;
    int i;
    do
    {
        cin >> i;
        nums.push_back(i);
    }while(getchar() != '\n');
    int m = nums.size();
    CreatLinkList1(head, nums, m);
    PrintLinkList(head);
    int n;
    cin >> n;
    PrintLinkList(s.removeNthFromEnd(head,n));
    system("pause");
    return 0;
}