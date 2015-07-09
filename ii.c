#include<stdio.h>
#include<malloc.h>
int(*funArr2[10])(float,char,char) = {NULL};
int main()
{
	union A {
	long int y[5];
	union B{
	double g;
	union C{
	int k;
	union D{
	char ch;
	int x[5];
	}s;
	}a;
	}b;
	}*p;
	p = (union A*)malloc(sizeof(union A));
	p->b.a.k = 15;
	printf("%d%d\n",p->b.a.s.x[0],p->y[0]);
	return 0;
	}