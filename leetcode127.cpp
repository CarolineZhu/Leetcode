#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool isConverted(string a, string b) {
	int diff = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i])
			diff++;
		if (diff > 1) return false;
	}
	if(diff == 1) return true;
	else return false;
}

vector<vector<bool> > constructGraph(vector<string>& wordList) {
	vector<vector<bool> > g(wordList.size(), vector<bool> (wordList.size(), false));
	for (int i = 0; i < wordList.size(); i++) {
		for (int j = i + 1; j < wordList.size(); j++) {
			if (isConverted(wordList[i], wordList[j])) {
				g[i][j] = true;
				g[j][i] = true;
			}
		}
	}
	return g;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

	vector<int> dist(wordList.size(), 10000);
	int i;
	for (i = 0; i < wordList.size(); i++) {
		if (wordList[i] == endWord) break;
	}
	if (i == wordList.size()) return 0;
	int t = i;
	vector<vector<bool> > g = constructGraph(wordList);
	set<int> undo;
	for (int i = 0; i < wordList.size(); i++) {
		undo.insert(i);
		if (isConverted(beginWord, wordList[i])) {
			dist[i] = 1;
		}
	}

	int minDist, minPos;

	while (undo.size()) {
		minDist = 10001;
		minPos = 0;

		for (set<int>:: iterator it = undo.begin(); it != undo.end(); it++) {
			if (dist[(*it)] < minDist) {
				minDist = dist[(*it)];
				minPos = *it;
			}
		}
		undo.erase(minPos);

		for (set<int>:: iterator it = undo.begin(); it != undo.end(); it++) {
			if (g[minPos][(*it)] && (dist[(*it)] > dist[minPos] + 1))
				dist[(*it)] = dist[minPos] + 1;
		}
	}
	if (dist[t] == 10000) {
		return 0;
	}
	return dist[t] + 1;
}


int main() {
	string s[] = {"hot", "dot", "log", "dog","lot", "hig", "cog", "hog"};
	vector<string> wl(s, s + 8);
	cout << ladderLength("hit", "cog", wl);
	return 0;
}