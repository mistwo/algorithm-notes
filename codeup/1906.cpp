// 特殊乘法
#include <cstdio>
#include <cstring>

int main(){
    char A[10], B[10];
    while (scanf("%s %s", A, B) != EOF) {
        int count = 0, lenA = strlen(A), lenB = strlen(B);
        for (int i = 0; i < lenA; i++)
            for (int j = 0; j < lenB; j++)
                count += ((A[i]-'0') * (B[j]-'0'));
        printf("%d\n", count);
    }
    return 0;
}