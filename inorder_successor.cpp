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
int ans =0;
struct node
{
	int data;
	struct node*left;
	struct node*right;
};
void insert(struct node**root,int num)
{
	if(*root==NULL)
	{
		struct node*temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->left=NULL;
		temp->right =NULL;
		*root =temp;
	}
	else
	{
		if((*root)->data>num)
		{
			insert(&((*root)->left),num);
		}
		else
			insert(&((*root)->right),num);
	}
}
void inorder(struct node*p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}
}
struct node* left_most_child(struct node*x)
{
	if(x->left==NULL)
	return x;
	else
	return left_most_child(x->left);
}
void get_next_largest(struct node*x,int val)
{
	if(val == x->data)
	{
		if(x->right == NULL)
		return;
		else
		{
			struct node* t= left_most_child(x->right);
			ans = t->data;
		}
	}
	else if(val<x->data)
	{
		ans = x->data;
		get_next_largest(x->left,val);
	}
	else
		get_next_largest(x->right,val);
}
int main()
{
	struct node*p = NULL;
	insert(&p,50);
	insert(&p,25);
	insert(&p,35);
	insert(&p,100);
	insert(&p,15);
	insert(&p,5);
	insert(&p,2);
	insert(&p,3);
	insert(&p,1);
	inorder(p);
	int val;
	ans =0;
	cin>>val;
	get_next_largest(p,val);
	cout<<ans<<endl;
	return 0;
}