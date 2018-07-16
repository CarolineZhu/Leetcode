#include <iostream>
#include <vector>

using namespace std;

static bool cmp (pair<int, int> x, pair<int, int> y) {
	if (x.first < y.first) return false;
    if (x.first > y.first) return true;
    return x.second < y.second;
}

vector<pair<int, int>> reconstructQueue(vector<pair<int, int> >& people) {
	vector<pair<int, int> > ret;
	sort(people.begin(), people.end(), cmp);
	for (int i = 0; i < people.size(); i++) {
		ret.insert(ret.begin() + people[i].second, people[i]);
	}        
	return ret;
}

int main() {
	return 0;
}