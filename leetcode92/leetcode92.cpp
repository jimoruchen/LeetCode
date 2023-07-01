#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        while(!head && !head ->next)                //1 2 3 4 5    left = 2, right = 4
            return head;                            //prev始终指向left左侧的节点也就是1，
        ListNode *dummy = new ListNode(-1);         //初始时cur指向left代表的节点，next为cur下一个节点
        dummy->next = head;                         //将next节点插入prev节点后一个节点。
        ListNode *prev = dummy;
        for(int i = 0; i < left - 1; i++)
            prev = prev ->next;
        ListNode *cur = prev ->next;
        for(int i = 0; i < right - left; i++)
        {
            ListNode *next = cur ->next;
            cur ->next = next ->next;
            next ->next = prev ->next;
            prev ->next = next;
        }
        return dummy ->next;
    }
};

ListNode *CreateLinkList(vector<int> s)
{
    ListNode *head = new ListNode(s[0]);
    ListNode *p = head;
    int length = s.size();
    for(int i = 1; i < length; i++)
    {
        p ->next = new ListNode(s[i]);
        p = p ->next;
    }
    return head;
}

void PrintLinkList(ListNode *head)
{
    ListNode *p = head;
    cout << "输出链表: ";
    while(p)
    {
        cout << p ->val << " ";
        p = p ->next;
    }
    cout << endl;
}

int main()
{
    Solution s;
    vector<int> nums;
    int n, left, right;
    do{
        cin >> n;
        nums.push_back(n);
    }while(getchar() != '\n');
    ListNode *head = CreateLinkList(nums);
    PrintLinkList(head);
    cin >> left >> right;
    PrintLinkList(s.reverseBetween(head, left, right));
    system("pause");
    return 0;
}
