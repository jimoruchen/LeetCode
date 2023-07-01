# C++:

## 1.substr:
substr(num); //返回从num脚标开始的所有字符，包括num角标对应的字符。
substr(a,b); //返回从a角标开始的b个字符，包括a,a+b脚标对应的字符。
for (char ch: s); //遍历字符串s
## 2.find():
str1.find(str2)：查找第一次出现的目标字符串的位置。
str1.find(str2,2)：从第二个位置开始查找str。
![img](file:///C:/Users/jimo/AppData/Local/Temp/msohtmlclip1/01/clip_image001.png)
## 3.unordered_map:
初始化：unordered_map<char, int> map;;
插入：map['a'] = 1; map.insert( { {'b',2} , {'c',3} } );
删除key为'a'的元素：map.erase('a'); 
删除第一个元素：map.erase(map.begin());
如果元素存在：if(map.find('a')!=map.end()) if(map.count('a')!=0)
if(it != map.end())     return {it->second, i};  返回值（索引）和对应的数字的索引
判断是否为空：if( map.empty() )；

count函数：直接放回的是一个数值，如果存在，那么返回1，反之0
hashmap[1] = 9;  cout << hashmap.count(1) << endl; 返回1

求元素个数：map.size();
查找：auto it = map.find(nums[i] - target)  查找键为nums[i] - target，找到返回该键值对的迭代器，否则返回end迭代器
遍历：//方法一
unordered_map<int, int> map;
for( auto& a : map)
{
  char key= a.first;
  int value= a.second;
}
//方法二
unordered_map<string,int>::iterator it;
for (auto it = map.begin(); it != map.end(); it++) 
{
​    char key = it->first;
​    int value = it->second;
}

## 4.vector
### 4.1vector新建：
    vector<int> a;
    vector<int> b = {1,2,3};
    int num;
    cout << "新建链表：" ;
    do
    {
        cin >> num;
        a.push_back(num);
    }while(getchar()!='\n');    
### 4.2遍历：
for(auto i: a)
​    cout << i;
==for(int i = 0; i < n; i++)
   cout << a[i]; 