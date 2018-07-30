#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) {
	sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int minR, head;
    minR = 0;
    head = heaters[0] - houses[0];
    int i, j;
    for (i = 1, j = 0; i < heaters.size() && j < houses.size();) {
        if (houses[j] < heaters[i - 1]) j++;
        else if ((houses[j] >= heaters[i - 1]) && (houses[j] <= heaters[i])) {
            if (min(houses[j] - heaters[i - 1], heaters[i] - houses[j]) > minR)
                minR = min(houses[j] - heaters[i - 1], heaters[i] - houses[j]);
            j++;
        } else i++;
    }
    if (j < houses.size()) minR = max(minR, houses[houses.size() - 1] - heaters[heaters.size() - 1]);
    minR = max(minR, head);
    return minR;
}

int main() {
	return 0;
}