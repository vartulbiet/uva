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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class CandidatesSelectionEasy {
public:
	vector <int> sort(vector <string>, int);
};

vector <int> CandidatesSelectionEasy::sort(vector <string> score, int x) {
	vector< pair<int,int> >vec;
	for(int i =0;i<score.size();i++)
	{
		vec.push_back(make_pair('Z'-score[i][x-1],i));
	}
	sort(vec.begin(),vec.end());
	vector<int>ans;
	for(int i =0;i<vec.size();i++)
	ans.push_back(vec[i].second);
	return ans;
}


