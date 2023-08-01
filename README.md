# LeetCode完整代码
## leetcode142 环形链表 II
1.用unordered_set存储每一个节点，如果节点不在set中则insert，在就返回该节点
2.用快慢指针定义从head到交叉节点为距离a，从交叉节点到相遇为b,环中另一部分为c，则2*(a+b)=a+b+n(b+c),a=c+(n-1)(b+c)，所以定义一个从head开始的节点与slow同时出发，两者一定在交叉节点相遇，因为a等于c加上n-1个环，由此该节点即为交叉节点。
