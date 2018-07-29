#include <iostream>
#include <vector>

using namespace std;

vector<string> urls;

string encode(string longUrl) {
	urls.push_back(longUrl);
	return to_string(urls.size() - 1);
}


string decode(string shortUrl) {
	return urls[atoi(shortUrl.c_str())];
}

int main() {
	return 0;
}