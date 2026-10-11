#include <stdio.h>
#include <wchar.h>
#include <locale.h>

typedef struct{
	double x[3], ave, var, sc;
	wchar_t name[5];
}Person;

int p[3];
Person ps[3];

double average(double x[3])
{
	return (x[0]+x[1]+x[2])/3;
}

double variance(double x[3])
{
	double xb = average(x);
	return ((x[0]-xb)*(x[0]-xb)+(x[1]-xb)*(x[1]-xb)+(x[2]-xb)*(x[2]-xb))/3;
}

double score(double x[3])
{
	return average(x)*3-variance(x)/3;
}

void sort(int p[3])
{
	for (int i = 0; i < 2; i++)
		for (int j = i+1; j < 3; j++)
			if (ps[p[i]].sc < ps[p[j]].sc) p[i]^=p[j]^=p[i]^=p[j];
}


int main()
{
	setlocale(LC_ALL, "");
	for (int i = 0; i < 3; i++)
	{
		wscanf(L"%ls%lf%lf%lf", ps[i].name, ps[i].x, ps[i].x+1, ps[i].x+2);
		ps[i].ave = average(ps[i].x);
		ps[i].var = variance(ps[i].x);
		ps[i].sc = score(ps[i].x);
		p[i] = i;
		//printf("%lf ", ps[i].sc);
	}
	sort(p);
	wprintf(L"%ls > %ls > %ls\n", ps[p[0]].name, ps[p[1]].name, ps[p[2]].name);
	return 0;
}
