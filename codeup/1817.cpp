// A+B
// 思路一：把字符串的逗号去掉，然后用 atoi() 把字符串转换成数字
#include <cstdio>
#include <cstring>
#include <cstdlib>
const int max_size = 20;

int main(){
    char A[max_size], B[max_size];
    while (scanf("%s %s", A, B) != EOF) {
        int lenA = strlen(A), lenB = strlen(B);
        for (int i = lenA; i >= 0; i--)
            if(A[i]==',')
                for (int j = i; j < lenA; j++) 
                    A[j] = A[j + 1];
        for (int i = lenB; i >= 0; i--)
            if(B[i]==',')
                for (int j = i; j < lenB; j++) 
                    B[j] = B[j + 1];
        int numA = atoi(A), numB = atoi(B);
        printf("%d\n", numA + numB);
    }
    return 0;
}

// 思路二：把每一位数字取出，用 10 乘后加上下一位，直到算出整个数字，然后添加符号
#include<cstdio>
#include<cstring>

int main() {
	char num1[20], num2[20];

	while (scanf("%s %s", num1, num2) != EOF) {
		int n1 = 0, n2 = 0;
		for (int i = 0; i < strlen(num1); i++) {
			if (num1[i] <= '9' && num1[i] >= '0')
				n1 = n1 * 10 + (num1[i] - '0');
		}
		for (int i = 0; i < strlen(num2); i++) {
			if (num2[i] <= '9' && num2[i] >= '0')
				n2 = n2 * 10 + (num2[i] - '0');
		}
		if (num1[0] == '-') n1 = -n1;
		if (num2[0] == '-') n2 = -n2;
		printf("%d\n", n1 + n2);
	}
	return 0;
}