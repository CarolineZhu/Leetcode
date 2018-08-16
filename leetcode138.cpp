#include <iostream>
#include <vector>

using namespace std;

RandomListNode *copyRandomList(RandomListNode *head) {
	RandomListNode *r, *nhead = NULL, *next;
	for (r = head; r != NULL; r = next) {
		next = r -> next;
		RandomListNode* n = new RandomListNode(r -> label);
		n -> next = r -> next;
		r -> next = n;
	}
	for (r = head; r != NULL; r = r -> next -> next) {
		if (r -> random) r -> next -> random = r -> random -> next;
		else r -> next -> random = NULL;
	}
	for (r = head; r != NULL; r = next) {
		if (r == head) nhead = r -> next;
		next = r -> next;
		if (r -> next)
			r -> next = r -> next -> next;
		else r -> next = NULL;
	}
	return nhead;
}