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
#define ll long long int
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
struct trie
{
	int value;
	struct trie *children[26];
};
void init(struct trie**par)
{
	if(*par ==NULL)
	{
		struct trie* x = (struct trie*)malloc(sizeof(struct trie));
		x->value =0;
		for(int i =0;i<26;i++)
		x->children[i] = NULL;
		*par =x;
	}
}
void insert(struct trie**par,string inp)
{
	struct trie*t =*par;
	for(int i =0;i<inp.size();i++)
	{
		if((*par)->children[inp[i]-'a'] == NULL)
		{
			struct trie*child = NULL;
			init(&child);
			(*par)->children[inp[i]-'a'] =child; 
		}
		if(i == inp.size()-1)
		(*par)->children[inp[i]-'a']->value =1;
		(*par) = (*par)->children[inp[i]-'a'];
	}
	*par =t;
}

bool search(struct trie*par,string x)
{
	for(int i =0;i<x.size();i++)
	{
			if(par->children[x[i]-'a'] == NULL)
				return false;
			else 
			{
				par = par->children[x[i]-'a'];
			}
	}
	return true;
}
int main()
{
	struct trie*par =NULL;
	init(&par);
	int d =0;
	cin>>d;
	while(d--)
	{
	string f;
	cin>>f;
	insert(&par,f);
	}
	string t;
	cin>>t;
	bool g = search(par,t);
	if(g == 0)
	cout<<"false"<<endl;
	else
	cout<<"true"<<endl;
	return 0;
}