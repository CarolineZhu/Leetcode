#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
	int digit = int(double(minutesToTest)/double(minutesToDie));
	int ans = ceil(log10(buckets) / log10(digit + 1));
	return ans;
}