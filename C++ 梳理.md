# C++ Primer
## 2.3 复合类型
### 2.3.1 引用
引用一定要被初始化且初始值必须是一个对象（而非常量值）（必须绑定到某一对象）
```cpp
int &r1 = 10;       // error: initializer must be an object
double dval = 3.14;
int &r2 = dval;     // error: initializer must be an int object
```
When we use a reference as an initializer, we are really using the object to which the reference is bound:
```cpp
int ival = 1024;
int &r1 = ival;
int &r2 = r1;       // ok: r2 is bound to the object to which r1 is bound, i.e., to ival
int i = r1;         // ok: initializes i to the same value as ival
```
### 2.3.2 指针
指针的值有 4 种状态：
1. 指向一个对象
2. 指向紧邻对象所占空间的下一个位置
3. 空指针，即没有指向任何对象
4. 无效指针，上述情况之外的其他值

void* can hold the address value of any data pointer type

引用不是对象，所以指针无法指向引用；

而引用可以绑定到指针（因为指针是一个对象）

## 3.2. String
```cpp
vector<string> v5{"hi"}; // list initialization: v5 has one element
vector<string> v6("hi"); // error: can't construct a vector from a string literal
vector<string> v7{10}; // v7 has ten default-initialized elements
vector<string> v8{10, "hi"}; // v8 has ten elements with value "hi"
```

## 3.3. Vector
vector 对象（以及 string 对象）的下标运算符用于访问已存在的元素，而不能用于添加元素


# 深 / 浅拷贝
当一个类中包含动态分配的资源时，浅拷贝将不会分配第二份资源，使得拷贝后的对象和之前的对象指向相同的一份资源（如数组）。

<ruby>交换机<rt>Switch</rt></ruby>