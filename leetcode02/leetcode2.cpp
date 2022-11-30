#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* creat(int n)
{
    auto *head = new ListNode();
    auto *rear = head;
    for(int i = 0; i < n; i++)
    {
        auto temp = new ListNode();
        cin >> temp->val;
        rear->next = temp;
        rear = rear->next;
    }
    return head->next;

} 

void print(ListNode * result)
{
    while(result)
    {
        cout << result->val;
        result = result->next;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto * head = new ListNode();  //定义一个合并后的头结点head
        auto * temp = head;            //中间量temp=head，temp一直保持在链表尾部
        int carry = 0;
        while(l1 || l2 || carry)       //当l1,l2为空carry不为空，将carry加到链表尾部
        {
            if(l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            temp->next = new ListNode(carry % 10);      //将carry的个位加到链表尾部
            temp = temp->next;
            carry /= 10;
        }
        return head->next;    
    }
        //  2        4         3                  5         6         4
        //carry = 7
        //carry /= 10
        //cur->next = new ListNode(carry % 10);
        //cur = cur->next;
        //7        0         8
};
int main()
{
    int num1;
    cout << "输入链表1的长度" << endl;
    cin >> num1;
    cout << "依次输入链表1元素的值" << endl;
    auto head1 = creat(num1);

    int num2;
    cout << "输入链表2的长度" << endl;
    cin >> num2;
    cout << "依次输入链表2元素的值" << endl;
    auto head2 = creat(num2);

    Solution s;
    auto result = s.addTwoNumbers(head1,head2);
    print(result);
    system("pause");
    return 0;

}