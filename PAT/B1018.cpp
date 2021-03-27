/* 锤子剪刀布 */
// 用 C 语言写的时候注意吸收掉换行符
#include<cstdio>

char max(int b, int c, int j){  // 选出获胜次数最多的手势
    int t;
    char m;
    if(b<c){ t = c; m = 'C'; }
    else { t = b; m = 'B'; }
    if(t<j) m='J';
    
    return m;
}

int main(){
    int n, m, awin[3]={}, bwin[3]={}; // 设 布-0，锤子-1，剪刀-2
    char a, b;
    scanf("%d", &n);
    m = n;
    while(n--) {
        getchar();
        scanf("%c %c", &a, &b);
        if(a=='C'&&b=='J')
            awin[1]++;
        else if(a=='J'&&b=='B')
            awin[2]++;
        else if(a=='B'&&b=='C')
            awin[0]++;
        else if(b=='C'&&a=='J')
            bwin[1]++;
        else if(b=='J'&&a=='B')
            bwin[2]++;
        else if(b=='B'&&a=='C')
            bwin[0]++;
    }
    int aw = awin[0] + awin[1] + awin[2], bw = bwin[0] + bwin[1] + bwin[2];
    printf("%d %d %d\n", aw, m-aw-bw, bw);
    printf("%d %d %d\n", bw, m-aw-bw, aw);
    printf("%c %c\n", max(awin[0], awin[1], awin[2]), max(bwin[0], bwin[1], bwin[2]));
    return 0;
}


// 解法二
#include<iostream>

int change(char ch) {
	if (ch == 'B') return 0;
	else if (ch == 'C') return 1;
	else if (ch == 'J') return 2;
}

int main() {
	std::ios::sync_with_stdio(false);

	int m;						// 控制次数
	int av = 0, bv = 0, n = 0;	// 记录胜负
	int a[3] = {}, b[3] = {};	// 纪录手势胜利次数
	char ah, bh;				// 记录单次手势
	char rechge[3] = { 'B', 'C', 'J' };		// 使数字变回字符
	std::cin >> m;
	while (m--) {
		std::cin >> ah >> bh;
		if ((change(ah) + 1) % 3 == change(bh)) {	// 甲获胜条件
			av++;
			a[change(ah)]++;
		}
		else if (change(ah) == change(bh)) {
			n++;
		}
		else {
			bv++;
			b[change(bh)]++;
		}
	}
	std::cout << av << " " << n << " " << bv << '\n';
	std::cout << bv << " " << n << " " << av << '\n';

	int at = 0, bt = 0;
	for (int i = 0; i < 3; i++) {
		if (a[i] > a[at]) at = i;
		if (b[i] > b[at]) bt = i;
	}
	std::cout << rechge[at] << " " << rechge[bt];

	return 0;
}