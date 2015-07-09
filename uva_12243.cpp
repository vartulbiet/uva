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
int main()
{
	string jj;
	getline(cin,jj);
	
	
	while(jj!="*")
	{
	//fflush(stdin);
	char s[2000];
		for(int i =0;i<jj.size();i++)
		s[i]= jj[i];
		//printf("%s\n",s);
		char* h = strtok(s," ");
		char f = h[0];
		bool bt = true;
		while(h!=NULL && bt)
		{
		//printf("%s\n",h);
			if(f == h[0] || f == h[0]+'A'-'a' || f == h[0]-'A'+'a')
				bt =true;
			else
				bt= false;
				h = strtok(NULL," ");
		}
		if(bt)
		cout<<"Y"<<endl;
		else
		cout<<"N"<<endl;
		jj.erase(jj.begin(),jj.end());
	getline(cin,jj);
	//cout<<jj<<endl;
	memset(s,'\0',sizeof(s));
	
	}
	return 0;
}