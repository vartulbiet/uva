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
#define graphAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<10
using namespace std;
struct node
{
	int data;
	struct node*left;
	struct node*right;
	struct node*par;
};
map<int,struct node*>mymap;
struct node* insert(int num)
{
	struct node*temp =(struct node*)malloc(sizeof(struct node));
	temp->data = num;
	temp->par =NULL;
	temp->left = NULL;
	temp->right =NULL;
	return temp;
}
void join(struct node*x,struct node*y)
{
	if((x)->left==NULL)
	(x)->left =y;
	else
	(x)->right = y;
	(y)->par =x;
}
struct node*get_root(struct node*z)
{
	if(z->par==NULL)
	return z;
	else
	{
		return get_root(z->par);
	}
}
void inorder(struct node*t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	}
	else
	return;
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(mymap.find(a)==mymap.end())
		mymap[a] = insert(a);
		if(mymap.find(b)==mymap.end())
		mymap[b] = insert(b);
		join(mymap[a],mymap[b]);
	}
	struct node*t =get_root(mymap[b]);
	inorder(t);
	return 0;
}