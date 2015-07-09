#include<iostream>
#include<vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
#include<string.h>
#include <iomanip>
#include <cstdio>
#include<math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<20
using namespace std;
struct node
{
	int data;
	struct node*link;
};
void insert(struct node**z,int d)
{
	if(*z==NULL)
	{
		struct node*temp = (struct node*)malloc(sizeof(struct node));
		temp->data = d;
		temp->link = NULL;
		*z = temp;
	}
	else
	{
		struct node*temp =*z;
		while(temp->link !=NULL)
		temp = temp->link;
		struct node*r =(struct node*)malloc(sizeof(struct node));
		r->data = d;
		r->link = NULL;
		temp->link = r;
	}
}

void print_LL(struct node*z)
{
	while(z!=NULL)
	{
		cout<<z->data<<" ";
		z =z->link;
	}
}
bool isPalindrome(struct node*root)
{
	
}
int main()
{
	struct node*p =NULL;
	insert(&p,5);
	insert(&p,6);
	insert(&p,7);
	insert(&p,8);
	insert(&p,9);
	insert(&p,10);
	insert(&p,11);
	print_LL(p);
	return 0;
}