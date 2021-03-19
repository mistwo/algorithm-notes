# Details & Tips

## C/C++ Syntax

- `cin`，`cout` 消耗的时间比 `scanf`，`printf` 多得多；

- 代码保存成 `.cpp` 文件，使用 C语言库的时候使用等价写法，如 `#include <cstdio>`；

- 变量名应该有具体含义

- 变量类型
  - `int` 的取值范围大概在 $10^9$ 以内
  - `long long` 赋值超过 $2^{31}-1$，后面要加 `LL`，如 `long long num = 123456789012345LL`
  - `unsigned` 表示无符号数，所占位数不变
  - 浮点型使用双精度 `double` 即可
  - 字符常量使用 **ASCII 码**统一编码，`char` 用单引号，`char[]` 表示字符串用双引号
  - 小写字母 - 大写字母 = **32**
  - C 语言中使用 `bool` 需要添加头文件 `stdbool.h`，**0** 为 false，**非 0** 为 true
- 常量
  - 宏定义 `#define yes no`，直接替换对应部分，注意**添加括号**
  - `const int pi = 3.14;`
- 运算符
  - 除数不能为 0
  - 自增运算符，`i++` 是先使用 i 再将 i+1，`++i` 则是先让 i+1 再使用 i
  - 条件运算符 `A ? B : C` ，如果 A 为真则执行并返回 B，否则执行并返回 C
  - 位运算符 `cosnt int INF = ( 1<<30 ) - 1;`，或 `const int INF = 0x3fffffff;`
- 赋值运算简化操作：`a=a*2` 等价于 `a*=2` 
- 

