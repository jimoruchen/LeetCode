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
    ListNode* reverseList(ListNode* head)
    {
        if(!head || !head ->next)
            return head;
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while(cur)
        {
            ListNode *p = cur ->next;
            cur ->next = prev;
            prev = cur;
            cur = p;
        }
        return prev;
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
    int n;
    do{
        cin >> n;
        nums.push_back(n);
    }while(getchar() != '\n');
    ListNode *head = CreateLinkList(nums);
    PrintLinkList(head);
    PrintLinkList(s.reverseList(head));
    system("pause");
    return 0;
}
