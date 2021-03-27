/* 划拳 */
#include <cstdio>

int main(){
    int n, jh, jc, jwin=0, yh, yc, ywin=0;
    scanf("%d", &n);
    while ((n--) && scanf("%d%d%d%d", &jh, &jc, &yh, &yc)){
        if(jc == jh+yh && yc != jh+yh)
            jwin++;
        if(yc == jh+yh && jc != jh+yh)
            ywin++;
    }
    printf("%d %d\n", ywin, jwin);
    return 0;
}