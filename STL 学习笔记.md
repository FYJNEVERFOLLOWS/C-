# STL 学习笔记

## vector
[【小彭老师C++公开课】全面理解STL标准库 vector容器 精讲](https://www.bilibili.com/video/BV1qF411T7sd)


vector 初始化后有三个指针存储在栈上：第一个指向堆上的起始地址，第二个标记结束位
vector 把数据存在堆上，所以才能动态扩容

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3kga3uy35j21l80u0q8j.jpg)

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3kgo7dh7gj21m70u0n3w.jpg)

resize(n) 的逻辑是扩容至 max(n, capacity*2)

push_back 遇到容量不足时，扩容两倍。

每增加 / 删除一个元素就扩容 / 回收的复杂度是 $O(n^2)$ (new 一块新的内存空间 & copy 原来的元素到新的空间)

内存池：开一块内存空间，通过 newnode() 来申请新节点以避免频繁地开辟空间
```cpp
Node pool[MAXN]; int top;
Node* newnode() {
    return &pool[top++];
}
```

vector 开空间是成倍增长的，假如我现在有一百万的空间，我现在要再加入一个数，那又需要开一百万的空间，你有没有办法去优化？

：为了均衡开空间的空间代价和每次插入重开空间的时间代价，我会采取分块的方法，具体就是每插入一个数，我只额外去开sqrt（n）个空间，等到这些空间被占用之后再新开sqrt(n+sqrt（n）)个，我认为这样能做到两者比较均衡。


## 迭代器入门
![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3klencvaaj21m20u0n3l.jpg)  

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3llaaxs2kj21pz0u0104.jpg)

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3llav9jdcj21sv0u0gs7.jpg)

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3lldx357kj21mw0u0dms.jpg)

