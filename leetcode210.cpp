#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<set<int> >record(numCourses);
	vector<int> ret;
	vector<bool> used(numCourses, false);
	for (int i = 0; i < prerequisites.size(); i++) {
		record[prerequisites[i].first].insert(prerequisites[i].second);
	}
	int j = 0;
	bool flg;
	while (ret.size() < numCourses) {
		if (j == 0) flg = false;
		if (!used[j] && record[j].size() == 0) {
			flg = true;
			ret.push_back(j);
			used[j] = true;
			for (int k = 0; k < numCourses; k++)
				if (k != j)
					record[k].erase(j);
		}
		j++;
		if (j == numCourses) {
            if (!flg) {
                ret.clear();
                return ret;
            }
            j = 0;
        }
	}
	return ret;
}

int main() {
	return 0;
}