#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k || !head || !head->next)
            return head;
        ListNode *cur = head;
        int length = 1;
        while(cur ->next)
        {
            ++length;
            cur = cur ->next;        //将最后一个节点和头结点连接，需让cur指针指向最后一个节点
        }                           //此时cur指向最后一个节点，如果从第一个节点开始则指向的节点不存在，不能进行cur ->next = head
        k %= length;
        cur ->next = head;  
        ListNode *p = head;
        for(int i = 0; i< length - k - 1; i++)
            p = p ->next;

        head = p ->next;
        p ->next = nullptr;
        return head;
    } 
};

ListNode *createlinklist(vector<int> a, int n)
{
    ListNode *head = new ListNode(a[0]);  //head节点即为第一个节点，值为a[0]
    ListNode *cur = head;
    for(int i = 1; i < n; i++)
    {
        cur ->next = new ListNode(a[i]);
        cur = cur ->next;
    }
    return head;
}

/*
ListNode *createlinklist2(vector<int> a, int n)
{
    ListNode *head = new ListNode(a[0]);
    ListNode *cur = head;
    for(int i = 1; i < n; i++)
    {
        ListNode *p = new ListNode(a[i]);
        p ->next = cur ->next;
        cur ->next = p;
        cur = p;
    }
}
*/

void printlinklist(ListNode *head)
{
    ListNode *p = head;
    cout << "输出链表: ";
    while(p)
    {
        cout << p ->data << " ";
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
    int len = nums.size();
    ListNode *head = createlinklist(nums, len);
    printlinklist(head);
    cout << "输入旋转的值：" << endl;
    int k;
    cin >> k;
    printlinklist(s.rotateRight(head, k));
    system("pause");
    return 0;
}