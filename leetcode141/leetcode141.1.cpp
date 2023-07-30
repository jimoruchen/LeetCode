#include<iostream>
#include<unordered_set>
#include<vector>
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
    bool hasCycle(ListNode *head) {
        if(!head || !head ->next)    return false;
        unordered_set<ListNode *> mp;
        while(head)
        {
            if(mp.find(head) != mp.end())
                return true;
            mp.insert(head);
            head = head ->next;
        }
        return false;
    }
};

void CreateListNode(ListNode *head, vector<int> a, int n)
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
    ListNode *head = new ListNode;
    do
    {
        cin >> i;
        nums1.push_back(i);
    } while(getchar() != '\n');
    int n1 = nums1.size();
    CreateListNode(head, nums1, n1);
    PrintLinkList(head);
    cout << s.hasCycle(head) << endl;
    system("pause");
    return 0;  
}