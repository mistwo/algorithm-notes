/* 部分 A+B */
// 一开始把 A/=10 写进 if 里面了，导致死循环，PAT 编译器却提示 scanf 却少返回值，这个坑点值得注意
#include <cstdio>

int main(){
    long long A, Da, B, Db;
    int Pa = 0, Pb = 0;
    scanf("%lld%lld%lld%lld", &A, &Da, &B, &Db);
    while (A || B){
        if (A % 10 == Da)
            Pa = Pa * 10 + Da;
        A /= 10;
        if (B % 10 == Db)
            Pb = Pb * 10 + Db;   
        B /= 10;
    }
    printf("%d\n", Pa + Pb);
    return 0;
}