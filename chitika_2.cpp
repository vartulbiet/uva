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
	char data;
	struct node*link;
};
void insert_char(struct node**head,char element)
{
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	temp->data = element;
	temp->link =NULL;
	if(*head ==NULL)
	{
		*head =temp;
	}
	else
	{
		struct node*r = *head;
		while(r->link!=NULL)
		{
			r = r->link;
		}
		r->link = temp;
	}
}

void insert_number(struct node**head,string val)
{
	for(int i =0;i<val.size();i++)
	{
		insert_char(head,val[i]);
	}
}
string get_binary(int n)
{
	vector<int>arr;
	while(n!=0)
	{
		arr.PB(n%2);
		n/=2;	
	}
	string bnry;
	for(int i =0;i<arr.size();i++)
	{
		bnry.PB('0'+arr[i]);
	}
	return bnry;
}
int get_num(struct node* s,int i)
{
	if(s ==NULL)
	return 0;
	else
	return (s->data - '0')*pow(2,i)+get_num(s->link,i+1);
}
void print_val(struct node*p)
{
	struct node*temp = p;
	while(p != NULL)
	{
		cout<<"->";
		cout<<p->data;
		p=p->link;
	}
	cout<<"  	Value is: "<<get_num(temp,0);
	cout<<endl;
}
struct node* increment(struct node*head,char val)
{
	if(head == NULL)
	{
		if(val == '0')
		return NULL;
		else
		{
			struct node*temp = (struct node*)malloc(sizeof(struct node));
			temp->data = val;
			temp->link =NULL;
			return temp;
		}
	}
	else
	{
		struct node*temp = (struct node*)malloc(sizeof(struct node));
		if(head->data == '0')
		{
			temp->data = val;
			temp->link = increment(head->link,'0');
		}
		else
		{
			if(val == '0')
			{
			temp->data = '1';
			temp->link = increment(head->link,'0');
			}
			else
			{
				temp->data = '0';
				temp->link = increment(head->link,'1');
			}
		}
		return temp;
	}
}
struct node*increment_wrapper(struct node*head)
{
	return increment(head,'1');
}
int main()
{
	int n =0;
	cout<<"Enter a positive number::"<<endl;
	cin>>n;
	n = abs(n);
	string s = get_binary(n);
	struct node*z =NULL;
	insert_number(&z,s);
	print_val(z);
//for(int i =0;i<100;i++)
	//{
		struct node*y = increment_wrapper(z);
		print_val(y);
	//	z=y;
	//}
	return 0;
}