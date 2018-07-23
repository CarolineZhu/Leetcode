#include <iostream>
#include <vector>

using namespace std;

ListNode* sum(ListNode* l1, ListNode* l2, int len1, int len2) {
	if (l1 == NULL && l2 == NULL) return NULL;
	if (len1 < len2) {
		ListNode* temp = sum(l1, l2 -> next, len1, len2 - 1);
		ListNode* cur = new ListNode(l2 -> val);
	} else if (len1 > len2) {
		ListNode* temp = sum(l1 -> next, l2, len1 - 1, len2);
		ListNode* cur = new ListNode(l1 -> val);
	} else {
		ListNode* temp = sum(l1 -> next, l2 -> next, len1 - 1, len2 - 1);
		ListNode* cur = new ListNode(l1 -> val, l2 -> val);
	}
	if (temp) {
		cur -> val += temp -> val / 10;
		temp -> val %= 10;
	}
	cur -> next = temp;
	return cur;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int len1 = 0, len2 = 0;
	ListNode *p1, *p2;
	for (p1 = l1, p2 = l2; p1 || p2;) {
		if (p1) {
			len1++;
			p1 = p1 -> next;
		}
		if (p2) {
			len2++;
			p2 = p2 -> next;
		}
	}
	Listnode* ret = sum(l1, l2, len1, len2);
	if ((ret -> val) / 10) {
		ListNode *h = new ListNode((ret -> val) / 10);
		ret -> val %= 10;
		h -> next = ret;
		ret = h;
	}
	return ret;
}