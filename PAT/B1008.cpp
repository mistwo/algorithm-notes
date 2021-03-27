/* 数组元素循环右移问题 */
// 这里有两个坑，如果 m>n 就会无法通过 1、2 样例；最后一个数字后不能输出空格

// 解法一：直接输出数字
#include<cstdio>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    m = m % n;
    int num[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    for (int i = n - m; i < n; i++)
        printf("%d ", num[i]);
    for (int i = 0; i < n - m; i++){
        if (i == n - m - 1) printf("%d", num[i]);
        else printf("%d ", num[i]);
    }
    return 0;
}

// 解法二：在数组里依次调整顺序
#include <cstdio>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int num[n], p = m;
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	for (int i = 0; i < m; i++) {
		int t = num[n - 1];
		for (int j = n - 1; j > 0; j--)
			num[j] = num[j - 1];
		num[0] = t;
	}
	for (int i = 0; i < n; i++) {
		printf("%d", num[i]);
		if (i != n - 1) printf(" ");
	}
	return 0;
}

// 解法三：三次逆序，将前半部分逆序，将后半部分逆序，最后将整体逆序