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
};
int binary_search(int val,int *x,int s,int e)
{
	if(s>e)
	return 0;
	//cout<<s<<" "<<e<<"--";
	int mid =(s+e)/2;
	if(x[mid]==val)
	{
	//cout<<val<<endl;
	return mid;
	}
	else
	{
		if(x[mid]>val)
		{
			binary_search(val,x,s,mid-1);
		}
		else
			binary_search(val,x,mid+1,e);
	}
}
void create_tree(struct node**p,int*x,int *y,int s,int e,int m)
{
	if(s>e)
	return;
	else
	{
		int root= y[m];
		struct node*temp =(struct node*)malloc(sizeof(struct node));
		temp->data = root;
		temp->left = NULL;
		temp->right =NULL;
		m++;
		cout<<root<<" "<<s<<" "<<e<<endl;
		int k = binary_search(root,x,s,e);
		cout<<k<<endl;
		create_tree(&(temp->left),x,y,s,k-1,m);
		create_tree(&(temp->right),x,y,k+1,e,m);
		*p= temp;
	}
}
void inOrder(struct node*p)
{
	if(p!=NULL)
	{
		inOrder(p->left);
		cout<<p->data<<" ";
		inOrder(p->right);
	}
}
int main()
{
	struct node*p=NULL;
	int inorder[]={5,10,12,15,20,25,30,35};
	int preorder[] ={20,10,5,15,12,30,25,35};
	create_tree(&p,inorder,preorder,0,7,0);
	inOrder(p);
	return 0;
}