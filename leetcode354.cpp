#include <iostream>
#include <vector>

using namespace std;

static bool cmp1(pair<int, int>a, pair<int, int>b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

bool cmp(pair<int, int>a, pair<int, int>b) {
    if (a.first < b.first && a.second < b.second) return true;
    return false;
}

int biSearch(vector<pair<int, int> >v, int m, int n, pair<int, int> x) {
    if (m == n) return m;
    if (!cmp(v[(m + n) / 2], x)) return biSearch(v, m, (m + n) / 2, x);
    else return biSearch(v, (m + n) / 2 + 1, n, x);
}

int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    vector<pair<int, int> > cnt;
    if (envelopes.size() == 0) return 0;
    sort(envelopes.begin(), envelopes.end(), cmp1);
    cnt.push_back(envelopes[0]);
    for (int i = 1; i < envelopes.size(); i++) {
        if (cmp(envelopes[i], cnt[0]))
            cnt[0] = envelopes[i];
        else if (cmp(cnt[cnt.size() - 1], envelopes[i]))
            cnt.push_back(envelopes[i]);
        else {
            int pos = biSearch(cnt, 0, cnt.size() - 1, envelopes[i]);
            cnt[pos] = envelopes[i];
        }
    }
    return cnt.size();
}

