// 找 x
#include <cstdio>
#include <cstring>

int main(){
    int n = 0;
    while (scanf("%d", &n) != EOF) {
        int num[n], x;
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        scanf("%d", &x);
        for (int i = 0; i <= n; i++){
            if(i==n){
                printf("-1\n");
                break;
            } 
            if(num[i]==x){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}