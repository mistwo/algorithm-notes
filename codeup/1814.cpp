// 剩下的树
// 思路一：有树标记为 0，否则非 0，最后数 0 的个数即可
#include <cstdio>

int main(){
    int L, M, mLess, mMore, count=0;
    while (scanf("%d %d", &L, &M) != EOF){
        if(L==0&&M==0) break;
        int tree[L + 1] = {0};
        for (int i = 0; i < M; i++){
            scanf("%d %d", &mLess, &mMore);
            for (int j = mLess; j <= mMore; j++)
                tree[j]++;
        }
        for (int i = 0; i <= L; i++)
            if(tree[i]==0)
                count++;
        printf("%d\n", count);
        count = 0;
    }
    return 0;
}

// 思路二：将有树的位置标为 0，没树的地方标为 1
#include<cstdio>

int main() {
	int l, m, left, right, t = 0;
	while (scanf("%d %d", &l, &m) != EOF) {
		if (l == 0 || m == 0) break;
		int tree[l + 1] = {};
		while (m--) {
			scanf("%d %d", &left, &right);
			for (; left <= right; left++) {
				tree[left] = 1;
			}
		}
		for (int i = 0; i < l + 1; i++)
			t += tree[i];
		printf("%d\n", l + 1 - t);
		t = 0;
	}
	return 0;
}