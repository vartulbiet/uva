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
unsigned int length(char const* s) {
    unsigned int i = 0;
    while (s[i] != '\0')
        ++i;

    return i;
}
    bool isNumber(const char *s) {
		int n = strlen(s);
        for(int i =0;i<n;i++)
        {
		cout<<s[i];
        if(!(s[i]-48>=0 && s[i]-48<=9))
        return false;
        }
        return true;
        
    }
int main()
{
	char y[1000];
	char*z =y;
	gets(z);
	int n = strlen(z);
	cout<<isNumber(z);
	return 0;
}