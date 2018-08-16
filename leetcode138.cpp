#include <iostream>
#include <vector>

using namespace std;

RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == NULL) return NULL;
	RandomListNode* pre = NULL;
	vector<RandomListNode*> nodeVo, nodeVn;
	int i = 0;
	for (RandomListNode* r = head; r != NULL; r = r -> next, i++) {
		RandomListNode* n = new RandomListNode(r -> label);
		nodeVn.push_back(n);
		r -> label = i;
		if (pre != NULL) pre -> next = n;
		pre = n;
	}
	for (RandomListNode* r = head; r != NULL; r = r -> next) {
		nodeVo.push_back(r -> random);
	}
	i = 0;
	for (RandomListNode* r = nodeVn[0]; r != NULL; r = r -> next, i++) {
		if (nodeVo[i]) 
			r -> random = nodeVn[nodeVo[i] -> label];
		else 
			r -> random = NULL;
	}
	return nodeVn[0];
}