#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#define REP(i, a, b) for ( int i = int(a); i <= int(b); i++ )
#define PB push_back
#define MP make_pair
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define MAXN 1000
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define INF 1<<30
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
struct node
{
	int data;
	struct node*arr[30];
};

void init(struct node**x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = 1;
	//temp->arr =NULL;
	for(int i =0;i<30;i++)
	{
		temp->arr[i] = NULL;
	}
	*x = temp;
}

void insert(struct node**root,string str)
{
	if(*root == NULL)
	{
		init(root);
	}
		struct node*par =*root;
		int i =0;
		while(i<str.size())
		{
			if((par)->arr[str[i]-'a'] == NULL)
			{
				 init(&((par)->arr[str[i]-'a']));
			}			
			(par) = (par)->arr[str[i]-'a'];

			i++;
		}
}
int main()
{
	struct node* p = NULL;
	int n =0;
	init(&p);
	cin>>n;
	for(int i =0;i<n;i++)
	{
		string s;
		cin>>s;
		insert(&p,s);
	}
	return 0;
}