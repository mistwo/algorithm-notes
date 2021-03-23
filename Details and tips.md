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

- `typedef` 常用于给复杂数据类型起别名

- 运算符

  - 除数不能为 0
  - 自增运算符，`i++` 是先使用 i 再将 i+1，`++i` 则是先让 i+1 再使用 i
  - 条件运算符 `A ? B : C` ，如果 A 为真则执行并返回 B，否则执行并返回 C
  - 位运算符 `cosnt int INF = ( 1<<30 ) - 1;`，或 `const int INF = 0x3fffffff;`

- 赋值运算简化操作：`a=a*(m+2)` 等价于 `a*=m+2` 

- 输入输出

  - `scanf` 的使用

    | 数据类型  | 格式控制 |         举例         |
    | :-------: | :------: | :------------------: |
    | long long |   %lld   |  scanf("%lld", &n)   |
    |  double   |   %lf    |  scanf("%lf", &db)   |
    |  char[]   |    %s    | scanf("%s", **str**) |

    除了字符型输入，`scanf` 对其他格式的输入以**空白符为结束标志**

  - `printf` 不用添加寻址符 `&`，除了 `double` 以外格式符与 `scanf` 均一致

  - 格式控制：

    - `%md` 第 m 位右对齐
    - `%0md` 第 m 位右对齐，左边不足则补 0
    - `%.mf` 保留 m 位小数点

  - `getchar()` 和 `putchar()` 输入输出字符，其中 `getchar()` 可以接收**换行符**

- `<math.h>`

  - `fabs(double x)` 取绝对值
  - `floor(double x)` 向下取整，`ceil(double x)` 向上取整
  - `pow(double r, double p)` r 的 p 次方
  - `sqrt(double x)` 算术平方根
  - `log(double x)` 自然对数 e 为底的对数，要实现任意底数的对数则要用到换底公式
  - `sin(double x)`、`cos(double x)`、`tan(double x)`，如 45° 的正切值 `tan( pi*45/180 )` 
  - `asin(double x)`、`acos(double x)`、`atan(double x)`，可以认为 `pi==acos(-1.0)` 
  - `round(double x)` 四舍五入
  
- 选择结构

  - `if(n)` 等价于 `if(n!=0)`，`if(!n)` 等价于 `is(n==0)`
  - `switch` 中使用 `break` 结束

- 循环结构

  - `for(A; B; C){ D; }` 的执行顺序是 `A -> B -> D -> C -> B ->...` 
  - C 语言里不允许这种写法：`for(int i=0; B; C)` 

- 数组

  - 数组大小只能为**常量**，`下标 = size -1` 
  - `int a[10]={0}` 表示给数组 a 赋初值为 0，也可以用 `memset` 函数来实现这一功能
  - 如果数组大小超过 $10^{-6}$ 级别，需要将其**定义在主函数外**，否则会导致程序异常退出。因为局部变量空间在系统栈，而全局变量来自静态存储区，空间较大
  - `string.h` 头文件中，有函数 `void *memset(void str[], int c, size_t n)`，用于给数组赋值，如 `memset(a, 0, sizeof(a));`。初学者只建议赋值 **0** 和 **-1**，其他数字使用 `fill()` 函数赋值
  - 数组可以作为参数，但不能作为返回类型
  - 数组做参数时，第一维不用填写

- 字符数组 `c[10]`，字符串数组 `str[5][5]` 

  - 初始化，可以用双引号字符串直接赋值
  - 输入
    - 用 `scanf` 只能读取到空格为止，`gets` 以换行符为结束标志，末尾自带 '\0'
    - `getchar()` 会吸收换行符，输入字符串不带 '\0'，用 `printf` 或 `puts` 输出时会乱码
    - 因此，开**字符数组时，切记使数组空间比需要的空间至少大 1** 
  
- `<string.h>` 

  - `strlen(str)` 返回字符数组 \0 前的字符个数
  - `strcmp(str1, str2)` 返回两个字符串比较结果，str1 < str2 返回负整数，相等返回 0，否则返回正整数
  - `strcpy(str1, str2)` 将 str2 复制到 str1，包括 \0
  - `strcat(str1, str2)` 将 str2 连接到 str1 后面

- 灵活使用 `sscanf(str, 格式, &n)` 和 `sprintf(str, 格式, n)` 能够更好地解决字符串相关问题

- **指针**

  - `*` 在定义时表示指针类型，如 `int *n;` 即 n 是 int 型的指针变量
  - `*` 也用于取指针变量存放的地址指向的值，如 `int *p=&a; printf("%d", *p);`，修改 `*p` 会直接修改该地址的值
  - `&` 是取地址符，如 `int a; int *n = &a` 即取变量 a 的地址赋给指针变量 n
  - 指针变量可以进行加减法，如 `int* p; p++;` 即指向当前整数的下一个整数的地址
  - 数组名称也作为数组首地址使用，有数组 a[10]，表达式 `&a[i]` 与 `a+i` 是等价的
  - 两个 int 指针相减，表示两个指针之间相差了多少个 int，而不是具体的地址值的差
  - 给函数传递变量的地址（地址传递），在函数中修改地址中的变量的值，能够直接改变变量的值，而非副本；**但不能直接修改地址，因为传入的地址是个副本**

- **引用**

  - 在 C++ 语法中，引用不产生副本，相当于给变量起了个别名，使用方法是在变量类型后面加 `&`，**常量不能使用引用**

- 结构体

  - 访问结构体指针里的元素有两种写法：`(*p).name` 或 `p->name` 

  - 可以使用**构造函数**初始化结构体，如：

    ```C++
    #include<cstdio>
    struct Point{
        int x, y;
        Point(){}	// 不初始化
        point(int _x, int_y):x(_x), y(_y) {}	// 定义时初始化
    }pt[10];
    
    int main(){
        int num=0;
        for(int i = 1; i<=3 i++)
           	pt[num++] = Point(i, 2);
        return 0;
    }
    ```

- 浮点数的比较：在大量运算后，浮点数可能会出现”误差“，如 0 变成 -0，如 3.14 变成 3.1999999，也就是说**一个数字经过运算后可能变成一个”范围值“**，这里可使用 eps 避免这种误差带来的麻烦

  ```C
  #include<math.h>
  const double eps=le-8;
  const double Pi=acos(-1.0);
  
  #define Equ(a,b) ((fabs((a)-(b))) < (eps))
  #define More(a,b) (((a)-(b))>(eps))
  #define Less(a,b) (((a)-(b))<(-eps))
  #define MoreEqu(a,b) (((a)-(b))>(-eps))
  #define LessEqu(a,b) (((a)-(b))<(eps))
  ```
  
- 在空间够用的情况下，常常采用**以空间换时间**的策略

- 黑盒测试

  - **单点测试**根据通过样例的数量判分，**多点测试**则需要通过全部样例才能得分。多点测试时，每次循环都要**重置**变量和数组，重置数组一般用 `memset()` 和 `fill()` 函数

  - 在读取文件的时候，若没有给定结束条件，则需要读取到末尾，`scanf()` 读取到末尾返回 -1，即 **EOF**

    ```c
    while (scanf("%d", &n) != EOF) {...}
    
    // 读取字符串时还可以这样写
    while (gets(str) != NULL) {...}
    ```

  - 输出要求加空格、换行，但最后一个输出后无空格、换行，可以利用循环结构来控制输出









