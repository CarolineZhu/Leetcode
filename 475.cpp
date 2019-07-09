class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int i = 0, j = 0;
        int dist = 0;
        int cur;
        while (i < houses.size()) {
            while (j < heaters.size() - 1 && abs(heaters[j + 1] - houses[i]) <= abs(heaters[j] - houses[i])) j++;
            cur = abs(heaters[j] - houses[i]);
            if (cur > dist) dist = cur;
            i++;
        }
        return dist;
    }
};