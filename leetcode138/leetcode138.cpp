#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node *random;
    Node(int val) : val(val), next(NULL), random(NULL) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return nullptr;
        unordered_map<Node *, Node *> map;
        Node * cur = head;
        while(cur){
            map[cur] = new Node(cur ->val);
            cur = cur ->next;
        }
        cur = head;
        while(cur){
            map[cur] ->next = map[cur ->next];
            map[cur] ->random = map[cur ->random];
            cur = cur ->next;
        }
        return map[head];
    }
};

Node *CreatLinkList(vector<int> nums)
{
    int len = nums.size();
    Node *head = new Node(nums[0]);
    Node *p = head;
    for(int i  = 1; i < len; i++) {
        p ->next = new Node(nums[i]);
        p = p ->next; 
    }
    return head;
}

void PrintLinkList(Node *head)
{
    cout << "输出链表" << endl;
    Node *p = head;
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
    int n;
    vector<int> nums;
    do{
        cin >> n;
        nums.push_back(n);
    }while(getchar() != '\n');
    Node * head = CreatLinkList(nums);
    PrintLinkList(s.copyRandomList(head));
    system("pause");
    return 0;
}