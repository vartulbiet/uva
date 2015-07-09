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
using namespace std;
struct node
{
	int data;
	struct node*link;
};

void insert(struct node**t,int num)
{
	struct node*s =*t;
	if(s==NULL)
	{
		struct node*temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->link = NULL;
		*t = temp;
	}
	else
	{
		while(s->link!=NULL)
		{
			s=s->link;
		}
		struct node*temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->link = NULL;
		s->link = temp;
	}
}


int add(struct node**x,struct node*y,struct node*z)
{
	int d =0;struct node*tt =NULL;
	if(y==NULL && z!=NULL)
	{
		struct node*temp =(struct node*)malloc(sizeof(struct node));
		temp->data= z->data+add(&(temp->link),y,z->link);
		*x= temp;
		return 0;
	}
	else if(z==NULL && y!=NULL)
	{
		struct node*temp =(struct node*)malloc(sizeof(struct node));
		temp->data= y->data;
		temp->data= z->data+add(&(temp->link),y->link,z);
		*x= temp;
		return 0;
	}
	else if(y!=NULL && z!=NULL)
	{
		struct node*temp = (struct node*)malloc(sizeof(struct node));
		d = y->data+z->data+add(&(temp->link),y->link,z->link);
		temp->data= d%10;
		*x = temp;
		return d/10;
	}
	else
		return 0;
}


void printt(struct node*z)
{
	if(z!=NULL)
	{
		cout<<z->data<<" ";
		printt(z->link);
	}
}
void wrap_add(struct node**x,struct node*y,struct node*z)
{
	int a = add(x,y,z);
	if(a>0)
	{
		struct node*yy= *x;
		struct node*temp = (struct node*)malloc(sizeof(struct node));
		temp->data = a;
		temp->link =yy;
		*x =temp;
	}
}

int main()
{
	struct node*z =NULL;
	insert(&z,7);
	insert(&z,6);
	insert(&z,8);
	insert(&z,9);
	printt(z);
	cout<<endl;
	struct node*y =NULL;
	insert(&y,6);
	insert(&y,8);
	insert(&y,9);
	printt(y);
	cout<<endl;
	struct node*x = NULL;
	wrap_add(&x,y,z);
	printt(x);
	return 0;
}