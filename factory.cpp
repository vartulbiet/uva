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
class A
{
	public:
	virtual void fun(){cout<<"In A"<<endl;};
};
class B : public A
{
	void fun()
	{
		cout<<"In B"<<endl;
	}
};
class C: public A
{
	void fun()
	{
		cout<<"In C"<<endl;
	}
};

int main()
{
	A *x = new A();
	x->fun();
	x= new B();
	x->fun();
	x=new C();
	x->fun();
	return 0;
}