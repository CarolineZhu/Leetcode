#include <iostream>
#include <vector>

using namespace std;

bool judgeCircle(string moves) {
	int vert = 0, horz = 0;
	for (int i = 0; i < moves.length(); i++) {
		switch(moves[i]) {
			case 'R': horz++; break;
			case 'L': horz--; break;
			case 'U': vert++; break;
			case 'D': vert--; break;
		}
	}
	if (vert == 0 && horz == 0) return true;
	else return false;
}

int main() {
	cout << judgeCircle("LL");
	return 0;
}