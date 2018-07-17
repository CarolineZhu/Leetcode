#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
	ListNode *p1, *p2;
	for (int t = 0, p1 = head, p2 = head; p1 && p2; t++) {
		p1 = p1 -> next;
		if (p2 -> next) p2 = p2 -> next -> next;
		else return false;
		if ((p1 == p2) && t) return true;
	}
	return false;        
}