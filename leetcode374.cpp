#include <iostream>
#include <vector>

int guess(int num);

int guessInterval(long long h, long long t) {
	if (h == t) return h;
	if (guess((h + t) / 2) == 0) return (h + t) / 2;
	if (guess((h + t) / 2) == 1) return guessInterval((h + t) / 2 + 1, t);
	else return guessInterval(h, (h + t) / 2);
}

int guessNumber(int n) {
	return guessInterval(1, n);
}