#include <iostream>
#include <vector>

using namespace std;

int leastInterval(vector<char>& tasks, int n) {
	int tot = 0;
	int alpha[26];
	memset(alpha, 0, 26 * sizeof(int));

	for (int i = 0; i < tasks.size(); i++) {
		alpha[tasks[i] - 'A']++;
	}

	int max_num = 0;
	// int times = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > max_num)
			max_num = alpha[i];
		// if (alpha[i])
		// 	times++;
	}

	int rem = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == max_num)
			rem ++;
	}
	// printf("%d\n", rem);
	tot = (n + 1) * (max_num - 1) + rem;
	return tot > tasks.size() ? tot : tasks.size();
}

int main() {
	// char a[10] = {'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E'};
	char a[6] = {'A', 'A', 'A', 'B', 'B', 'B'};
	vector<char> tasks(a, a+6);
	int n = 2;
	printf("%d\n", leastInterval(tasks, n));
	return 0;
}