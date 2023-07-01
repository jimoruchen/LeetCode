#include<iostream>
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

class Solution
{
public:                                      //合并两个有序链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)  
    {
        if(list1 == nullptr)
            return list2;
        else if(list2 == nullptr)
            return list1;
        else if(list1->val < list2->val)
        {
            list1 ->next = mergeTwoLists(list1 ->next, list2);
            return list1;
        }
        else
        {
            list2 ->next = mergeTwoLists(list2 ->next, list1);
            return list2;
        }
    }  
};

void CreateListNode(ListNode *head, vector<int> a, int n)
{
    ListNode *p = head;
    for(int i = 0; i < n; i++)
    {
        ListNode *q = new ListNode;
        q ->val = a[i];
        q ->next = p ->next;
        p ->next = q;
        p = q;
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
    vector<int> nums1, nums2;
    int i;
    ListNode *head1 = new ListNode;
    do
    {
        cin >> i;
        nums1.push_back(i);
    } while(getchar() != '\n');
    int n1 = nums1.size();
    CreateListNode(head1, nums1, n1);
    int j;
    ListNode *head2 = new ListNode;
    do
    {
        cin >> j;
        nums2.push_back(j);
    } while(getchar() != '\n');
    int n2 = nums2.size();
    CreateListNode(head2, nums2, n2);
    PrintLinkList(head1);
    PrintLinkList(head2);
    ListNode *head3 = s.mergeTwoLists(head1, head2) ->next;
    PrintLinkList(head3);
    system("pause");
    return 0;  
}