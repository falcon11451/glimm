#include <stdio.h>

int N, Mask;
long long ans;

void dfs(int n, int col, int diag, int diag1)
{
	if (!n)
	{
		ans++;
		return;
	}
	int msk = ~(col|diag|diag1) & Mask;
	for (int i = msk&-msk; msk; msk-=i, i = msk&-msk)
		dfs(n-1, col|i, (diag<<1)|(i<<1), (diag1>>1)|(i>>1));
}

int main()
{
	scanf("%d", &N);
	Mask = (1<<N)-1;
	dfs(N, 0, 0, 0);
	printf("%lld\n", ans);
	return 0;
}
