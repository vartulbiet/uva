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
#include <queue>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define INF 1<<30
using namespace std;
int main()
{
	string x,y;
	cin>>x;
	while(x!="#")
	{
		cin>>y;
		int a =x.size();
		int b =y.size();
		int table[a+1][b+1];
		for (int i = 0; i < a + 1; i++) 
		table[i][0] = i;
         for (int i = 0; i < b + 1; i++) 
		table[0][i] = i;
		
		for(int i =1;i<a+1;i++)
		{
			for(int j =1;j<b+1;j++)
			{
				int c =1;
				if(x[i-1]==y[i-1])
				c =0;
				table[i][j] = min(table[i-1][j]+1,min(table[i][j-1]+1,table[i-1][j-1]+c));
			}
		}
				char buf[25];
				int i =a;
				int j =b;
                vector <string > commands;
                while(i>0 && j>0){
                 if(table[i-1][j] + 1 == table[i][j]){
                 sprintf(buf,"D%c%02d",x[i-1],j+1);
                 i--;
                 }
                 else if(table[i][j-1]+1 == table[i][j]){
                 sprintf(buf,"I%c%02d",y[j-1],j);
                 j--;
                 }
                 else {
                 if(x[--i] != y[--j])sprintf(buf,"C%c%02d",y[j],j+1);
                 else continue;
                 }
                 commands.push_back(string(buf));
                 }
                 while(i>0){
                 sprintf(buf,"D%c%02d",x[--i],1);
                 commands.push_back(string(buf));
                 }
                 while(j>0){
                 sprintf(buf,"I%c%02d",y[j-1],j);
                 commands.push_back(string(buf));
                 j--;
                 }
                 string instr = "";
                 for(int k = commands.size()-1;k >= 0;k--)
                 instr += commands[k];
                 instr += 'E';
                
                cout << instr;
                cout << endl;
				cin>>x;
	}
}