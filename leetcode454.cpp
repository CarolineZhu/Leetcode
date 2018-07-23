#include <iostream>
#include <vector>
#include <map>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	map<int, int> record;
	int cnt = 0;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			if (record.find(A[i] + B[j]) != record.end())
				record[A[i] + B[j]]++;
			else
				record[A[i] + B[j]] = 1;
		}
	}
	for (int i = 0; i < C.size(); i++) {
		for (int j = 0; j < D.size(); j++) {
			if (record.find(-C[i]-D[j]) != record.end())
				cnt += record[-C[i]-D[j]];
		}
	}
	return cnt;
}

int main() {
}