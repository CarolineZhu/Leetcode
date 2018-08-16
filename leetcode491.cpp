#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int> > findSubsequences(vector<int>& nums) {
	set<vector<int> > cddt;
    vector<vector<int> > res;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) {
            cddt.insert(vector<int> (1, nums[i]));
            continue;
        }
        set<vector<int> > stmp, pre;
        pre = cddt;
        for (set<vector<int> >::iterator it = pre.begin(); it != pre.end(); it++) {
            stmp.insert(vector<int> (1, nums[i]));
            if ((*it)[(*it).size() - 1] <= nums[i]) {
                vector<int> tmp;
                tmp.assign((*it).begin(), (*it).end());
                tmp.push_back(nums[i]);
                stmp.insert(tmp);
            }                    
        }
        set_union(stmp.begin(), stmp.end(), pre.begin(), pre.end(), inserter(cddt, cddt.end()));
    }
    for (set<vector<int> >::iterator it = cddt.begin(); it != cddt.end(); it++) {
        if ((*it).size() >= 2)
            res.push_back((*it));
    }
    return res;
}

int main() {
	
}