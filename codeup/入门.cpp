// 2.4 问题 G: 例题5-7 求圆周率pi的近似值
#include <cstdio>
int main() {
    double pi = 0, i;
    int j;
    for (i = 1, j = 0; (1 / i) > 1e-6; i += 2, j++)
    {
        if (j % 2 != 0)
            pi -= (1/i);
        else
            pi += (1/i);
    }
    printf("PI=%.8f\n", pi * 4);
    return 0;
}

// 解法二
#include <cstdio>

int main(){
    double PI = 1L, N = 1e-6;
    for (int i = 1; 1.0 / (i + i + 1) > N; ++i)
        PI = PI + ((i % 2) == 0 ? (1.0 / (i + i + 1)) : (-1.0 / (i + i + 1)));
    printf("PI=%.8f\n", PI * 4);
    return 0;
}

// 2.4 问题 I: 习题5-10 分数序列求和
#include <cstdio>

int main(){
    double f1 = 1, f2 = 1, fn = 0, sum = 0;

    for (int i = 0; i < 20; i++){
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
        sum += (f2 / f1);
    }
    printf("%.6f\n", sum);
    return 0;
}

// 2.5 习题6-6 杨辉三角
#include <cstdio>

int main(){
    int n, triangle[11][10] = {{0}};
    triangle[0][1] = 1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        for (int j = 1; j <= i+2; j++)
            triangle[i+1][j] = triangle[i][j] + triangle[i][j - 1];
    }
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= i+1; j++)
            printf("%d ", triangle[i][j]);
        printf("\n");
    }
    return 0;
}

// 2.7 C语言10.16
#include <cstdio>
#include <cstring>

void exchange(int *p){
    int *q = p, t;
    for (int i = 0; i < 10; i++)
        if (p[i] < *q)
            q = &p[i];
    t = p[0];
    p[0] = *q;
    *q = t;
    for (int i = 0; i < 10; i++)
        if (p[i] > *q)
            q = &p[i];
    t = p[9];
    p[9] = *q;
    *q = t;
}

void input(int *p){
    for (int i = 0; i < 10; i++)
        scanf("%d", &p[i]);
}

void output(int *p){
    for (int i = 0; i < 10; i++)
        printf("%d ", p[i]);
    printf("\n");
}
int main(){
    int num[10];
    input(num);
    exchange(num);
    output(num);
    return 0;
}

// 2.8 C语言11.4
#include <cstdio>
#include <cstring>

struct person{
    int num;
    char name[10];
    char sex;
    char job;
    union {
        int Class;
        char position[10];
    }category;
};

int main(){
    person ps[20];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d %s %c %c", &ps[i].num, ps[i].name, &ps[i].sex, &ps[i].job);
        if(ps[i].job=='s')
            scanf("%d", &ps[i].category.Class);
        if(ps[i].job=='t')
            scanf("%s", ps[i].category.position);
    }

    for (int i = 0; i < n; i++) {
        if(ps[i].job=='s')
            printf("%d %s %c %c %d\n", ps[i].num, ps[i].name, ps[i].sex, ps[i].job, ps[i].category.Class);
        if(ps[i].job=='t')
            printf("%d %s %c %c %s\n", ps[i].num, ps[i].name, ps[i].sex, ps[i].job, ps[i].category.position);        
    }

    return 0;
}