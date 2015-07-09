#include <iostream>
#include <vector>
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
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull long long int  
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
#define M 1000000009
using namespace std;
int main()
{
	int n = 0; 
	while(cin>>n)
	{
		if(n == 0)
			break;
		queue<int>q;
		for(int i = 1 ;i <= n ; i ++)
			q.push(i);
		vector<int>thrown;
		while(q.size() > 1)
		{
			int temp = q.front ();
                q.pop();
                thrown.push_back (temp);
                temp = q.front ();
                q.pop();
                q.push(temp);
		}
		int y = q.front();
		cout<<"Discarded cards: ";
		for(int i = 0;i < thrown.size(); i++)
		{
			if(i != 0)
				cout<<", ";
			cout<<thrown[i];
		}
		cout<<endl;
		cout<<"Remaining card: ";
		
		cout<<y<<endl;
	}
	return 0;
}