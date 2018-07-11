#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
	vector<int> mleft(height.size(), 0);
	vector<int> mright(height.size(), 0);
	int ret = 0;

	for (int i = 1; i < height.size(); i++) {
		if (height[i - 1] > mleft[i - 1])
			mleft[i] = height[i - 1];
		else
			mleft[i] = mleft[i - 1];
	}	        
	for (int i = height.size() - 2; i >= 0; i--) {
		if (height[i + 1] > mright[i + 1])
			mright[i] = height[i + 1];
		else
			mright[i] = mright[i + 1];
	}

	for (int i = 0, inc = 0; i < height.size(); i++) {
		inc = (mleft[i] < mright[i] ? mleft[i] : mright[i]) - height[i];
		if (inc > 0) 
		ret += inc;
	}
	return ret;
}				

int main() {
	int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> v(a, a + (sizeof(a)/sizeof(a[0])));
	cout << trap(v) <<endl;
	return 0;
}