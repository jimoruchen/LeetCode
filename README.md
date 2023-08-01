# LeetCode完整代码
## leetcode142 环形链表 II
1.用unordered_set存储每一个节点，如果节点不在set中则insert，在就返回该节点。

2.用快慢指针定义从head到交叉节点为距离a，从交叉节点到相遇为b,环中另一部分为c，则2*(a+b)=a+b+n(b+c),a=c+(n-1)(b+c)，所以定义一个从head开始的节点与slow同时出发，两者一定在交叉节点相遇，因为a等于c加上n-1个环，由此该节点即为交叉节点。

## 剑指 Offer 09 用两个栈实现队列
首先定义两个栈stk1,stk2,用stk1实现appendTail队尾插入操作，在deleteHead函数中实现判断stk1是否为空，不为空则将stk1的所有元素push到stk2中，然后将stk2的第一个元素出栈实现队列删除首元素的功能，然后将stk2的所有元素在push到stk1中。
