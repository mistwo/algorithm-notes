/* 数字分类 */
// 这里有一个坑，即交错求和答案可能为 0，和输出 N 的判断条件一样，需要特殊处理，否则样例 8 无法通过
// 我设置了一个 flag，不为 0 时说明进行过运算而非没有输入
// 另外要注意输出浮点数的强制转换

#include <cstdio>

int main(){
    int n, a[6] = {1}, num, step = 0, flag = 0;
    scanf("%d", &n);
    while ((n--) && scanf("%d", &num)){
        int t = num % 5;
        switch(t){
            case 0:
                if(num%2==0) a[1] += num;
                break;
            case 1:
                flag = 1; a[2] += a[0] * num; a[0] *= (-1);
                break;
            case 2:
                a[3]++;
                break;
            case 3:
                a[4] += num; step++;
                break;
            case 4:
                if(num>a[5]) a[5] = num;
                break;
            default:
                break;
        }
    }
    for (int i = 1; i < 6; i++){
        if (i == 2 && flag != 0)
            printf("%d", a[2]);
        else if (a[i] == 0)
            printf("%c", 'N');
        else if (i == 4)
            printf("%.1lf", (double)a[i] / step);
        else
            printf("%d", a[i]);
        if (i != 5)
            printf(" ");
    }
    return 0;
}


// 以前写的答案，分别处理并输出
#include<cstdio>
#include<cmath>

int main() {
	int n, sum = 0, j = 0, t = 0;
	while (scanf("%d", &n) != EOF) {
		int num[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);

		for (int i = 0; i < n; i++) {       // 1
			if (num[i] % 10 == 0) {
				sum += num[i];
				j++;
			}
		}
		if (j)
			printf("%d", sum);
		else
			printf("N");

		sum = 0;
		j = 0;
		for (int i = 0; i < n; i++) {       // 2
			if (num[i] % 5 == 1) {
				sum += pow(-1, (double)t) * num[i];
				j++;
				t++;
			}
		}
		if (j)
			printf(" %d", sum);
		else
			printf(" N");

		sum = 0;
		j = 0;
		for (int i = 0; i < n; i++) {       // 3
			if (num[i] % 5 == 2) {
				sum++;
				j++;
			}
		}
		if (j)
			printf(" %d", sum);
		else
			printf(" N");

		sum = 0;
		j = 0;
		t = 0;
		for (int i = 0; i < n; i++) {       // 4
			if (num[i] % 5 == 3) {
				sum += num[i];
				t++;
				j++;
			}
		}
		if (j)
			printf(" %.1f", (double)sum / t);
		else
			printf(" N");

		sum = 0;
		j = 0;
		for (int i = 0; i < n; i++) {       // 5
			if (num[i] % 5 == 4 && sum < num[i]) {
				sum = num[i];
				j++;
			}
		}
		if (j)
			printf(" %d\n", sum);
		else
			printf(" N\n");
	}
	
	return 0;
}