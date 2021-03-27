/* 程序运行时间 */

#include <cstdio>
#include <cmath>
const int CLK_TCK = 100;

int main(){
    double c1, c2;
    int sec;
    scanf("%lf%lf", &c1, &c2);
    sec = round((c2 - c1) / CLK_TCK);
    printf("%02d:%02d:%02d\n", sec/3600, sec%3600/60, sec%60);
    return 0;
}

// 另解：用 ans 替代 round 函数，直接使用差值后两位判断是否四舍五入，避免了浮点数运算，实际上运行速度更快
#include <cstdio>
int main(){
    int c1, c2;
    scanf("%d%d", &c1, &c2);
    int ans = c2 - c1;
    if (ans % 100 >= 50)
        ans = ans / 100 + 1;
    else
        ans = ans / 100;
    printf("%02d:%02d:%02d\n", ans / 3600, ans % 3600 / 60, ans % 60);
    return 0;
}