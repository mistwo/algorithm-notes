// schId 从 1 开始编号，因此数组大小应大于 99999，循环遍历时也应做出相应的改变
#include<cstdio>
const int MAXSIZE = 100010;
int gradeAll[MAXSIZE] = {0};

int main(){
    int N, schId, grade, max = 1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d %d", &schId, &grade);
        gradeAll[schId] += grade;
    }
    for (int i = 2; i <= N; i++)
        if (gradeAll[max] < gradeAll[i])
            max = i;
    printf("%d %d", max, gradeAll[max]);
    return 0;
}