#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* reverseBetween(ListNode* head, int m, int n) {
	LListNode *p = NULL, *pre, *pnext, *t = NULL, *p1;
        int i;
        if (m == n) return head;
        if (m == 1) p1 = NULL;
        for (i = 0, pre = head; pre != NULL && i < n - 1; i++) {
            if (i == m - 2) p1 = pre;
            if (i < m - 1) {
                pre = pre -> next;
                continue;
            }
            if (i == m - 1) {
                p = pre -> next;
                pnext = p -> next;
                t = pre;
            }
            p -> next = pre;
            pre = p;
            p = pnext;
            if (pnext)
                pnext = pnext -> next;
        }
        if(p1) {
            p1 -> next = pre;
        } else {
            head = pre;
        }
        t -> next = p;
        return head;
}

int main() {
	return 0;
}