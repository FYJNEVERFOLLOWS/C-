# STL 学习笔记

## vector
[【小彭老师C++公开课】全面理解STL标准库 vector容器 精讲](https://www.bilibili.com/video/BV1qF411T7sd)


vector 初始化后有三个指针存储在栈上：第一个指向堆上的起始地址，第二个标记结束位
vector 把数据存在堆上，所以才能动态扩容

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3kga3uy35j21l80u0q8j.jpg)

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3kgo7dh7gj21m70u0n3w.jpg)

resize(n) 的逻辑是扩容至 max(n, capacity*2)

push_back 遇到容量不足时，扩容两倍。

## 迭代器入门
![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3klencvaaj21m20u0n3l.jpg)  

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3llaaxs2kj21pz0u0104.jpg)

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3llav9jdcj21sv0u0gs7.jpg)

![](https://tva1.sinaimg.cn/large/e6c9d24ely1h3lldx357kj21mw0u0dms.jpg)

