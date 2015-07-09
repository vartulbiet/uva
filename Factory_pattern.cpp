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
#define INF 1<<30
using namespace std;
class SuperConcrete
{
	public:
	virtual void doPrint() =0;
};
class Concrete1:public SuperConcrete
{
	public:
	void doPrint()
	{
		cout<<"Hi this is concrete1"<<endl;
	}	
};
class Concrete2:public SuperConcrete
{
	public:
	void doPrint()
	{
		cout<<"Hi this is concrete2"<<endl;
	}	
};
class factory
{
	public:
	bool cond;
	void applyFactory()
	{
		SuperConcrete *a;
		if(cond)
		a = new Concrete1();
		else
		a= new Concrete2();
		a->doPrint();
	}
};
int main()
{
	factory x ;
	x.applyFactory();
	x.cond = false;
	x.applyFactory();
	x.cond = true;
	x.applyFactory();
	return 0;
}