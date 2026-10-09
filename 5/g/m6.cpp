#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int N, ans;
bitset<225> bs;

void put(int x, int y, bitset<225> &bs)
{
	for (int i = 0; i < N; i++)
		bs[i+N*y] = bs[x+N*i] = 1;
	for (int i = 0; x+i < N && y+i < N; i++)
		bs[(x+i)+N*(y+i)] = 1;
	for (int i = 0; x-i >= 0 && y+i < N; i++)
		bs[(x-i)+N*(y+i)] = 1;
	for (int i = 0; x+i < N && y-i >= 0; i++)
		bs[(x+i)+N*(y-i)] = 1;
	for (int i = 0; x-i >= 0 && y-i >= 0; i++)
		bs[(x-i)+N*(y-i)] = 1;
}

void solve(int n, int x, bitset<225> &bs)
{
	if (!n)
	{
		ans++;
		return;
	}
	for (int i = x; i < x+N; i++)
	{
		if (!bs[i]) 
		{
			bitset<225> tmp = bs;
			put(i%N, i/N, tmp);
			solve(n-1, x+N, tmp);
		}
	}
}

int main()
{
	scanf("%d", &N);
	solve(N, 0, bs);
	printf("%d\n", ans);
	return 0;
}
