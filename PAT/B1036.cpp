/* 跟奥巴马一起编程 */
#include <cstdio>

int main(){
    int N, row;
    char C;
    scanf("%d %c", &N, &C);
    
    if (N % 2 == 0) row = N / 2;
    else row = N / 2 + 1;

    for (int i = 1; i <= row; i++){
        if (i == 1 || i == row)
            for (int j = 0; j < N; j++)
                printf("%c", C);
        else {
            printf("%c", C);
            for (int j = 1; j < N - 1; j++) printf("%c", ' ');
            printf("%c", C);
        }
        if (i != row) printf("\n");
    }
    return 0;
}