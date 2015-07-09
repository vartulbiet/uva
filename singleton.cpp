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
class Singleton
{
	private:
		static bool check ;
		static Singleton*t ;
		Singleton()
		{
		}
	public:
	  static  Singleton* get_instance();
	  void method();
		~Singleton()
		{
			check = false;
		}
};
void Singleton::method()
{
    cout << "Method of the singleton class" << endl;
}
bool Singleton::check =false;
Singleton* Singleton::t = NULL;
Singleton* Singleton:: get_instance()
{
	if(!check)
	{
		check =true;
		t= new Singleton();
	}
	return t;
}
int main()
{
	Singleton *ch,*rh;
	ch= Singleton::get_instance();
	rh= Singleton::get_instance();
	ch->method();
	rh->method();
	return 0;
}