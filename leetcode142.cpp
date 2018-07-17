#include <iostream>

using namespace std;

ListNode *detectCycle(ListNode *head) {
	ListNode *p1, *p2;
	p1 = p2 = head;
	while (p2 && p2 -> next) {
		p1 = p1 -> next;
		p2 = p2 -> next -> next;
		if (p1 == p2) {
			p1 = head;
			while (p1 != p2) {
				p1 = p1 -> next;
				p2 = p2 -> next;
			}
			return p2;
		}
	}
	return NULL;
}