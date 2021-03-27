/* A+B 和 C */
// 取值超过了 int 范围，使用 long long
#include <cstdio>
typedef long long ll; 

int main(){
    int T, tcase = 1;
    scanf("%d", &T);
    while (T--){
        ll A, B, C;
        scanf("%lld %lld %lld", &A, &B, &C);
        if (A + B > C)
            printf("Case #%d: true\n", tcase);
        else
            printf("Case #%d: false\n", tcase);
        tcase++;
    }
    return 0;
}