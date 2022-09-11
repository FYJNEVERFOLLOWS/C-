## 深 / 浅拷贝
当一个类中包含动态分配的资源时，浅拷贝将不会分配第二份资源，使得拷贝后的对象和之前的对象指向相同的一份资源（如数组）。

<ruby>交换机<rt>Switch</rt></ruby>

## Lambda expression
```cpp
[] (int a, int b) {
    return a < b;
}
[] (int a, int b) -> bool {
    return a < b;
}
```

`[]`: capture 捕获器

`[=]`: pass-by-value for all variables 捕获当前作用域中的所有变量

`[c]`: pass-by-value 仅捕获变量 `c`

`[&]`: pass-by-reference
