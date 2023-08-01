#include<iostream>
#include<unordered_set>
#include<vector>
#include<stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head ->next)   return NULL;
        unordered_set<ListNode *> mp;
        while(head)
        {
            if(mp.count(head))
                return head;
            mp.insert(head);
            head = head ->next;
        }
        return NULL;
        
    }
};
ListNode * CreateListNode(vector<int> a, int n)
{
    /*ListNode *p = head;
    for(int i = 0; i < n; i++)
    {
        ListNode *q = new ListNode;
        q ->val = a[i];
        q ->next = p ->next;
        p ->next = q;
        p = q;
    }*/
    ListNode * head = new ListNode(a[0]);
    ListNode * cur = head;
    for(int i = 1; i < n; i++)
    {
        cur ->next = new ListNode(a[i]);
        cur = cur ->next;
    }
    return head;
}

void PrintLinkList(ListNode *head)
{
    ListNode * p = head;
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
    vector<int> nums1;
    int i;
    do
    {
        cin >> i;
        nums1.push_back(i);
    } while(getchar() != '\n');
    int n1 = nums1.size();
    ListNode *head = CreateListNode(nums1, n1);
    PrintLinkList(head);
    ListNode * p = s.detectCycle(head);
    if (p)
        cout << "链表中存在环，环的入口节点值为：" << p->val << endl;
    else
        cout << "链表中不存在环。" << endl;
    system("pause");
    return 0;  
}