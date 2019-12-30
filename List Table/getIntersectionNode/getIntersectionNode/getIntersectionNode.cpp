#include <stdio.h>

#include<iostream>
#include<set>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//��������A��������A�еĽڵ��Ӧ��ָ���ַ������set
		std::set<ListNode*>node_set;     //���ò��Ҽ���node_set
		while (headA) {
			node_set.insert(headA);
			headA = headA->next;     //��������A
		}
		while (headB) {
			if (node_set.find(headB) != node_set.end()) {
				return headB;      //����headB���ҵ���һ��������node_set�еĽڵ�ʱ
			}
			headB = headB->next;    //��������B
		}
		return NULL;
	}
};

int main() {
	ListNode a(1);
	ListNode b(3);
	ListNode c(7);

	ListNode d(6);
	ListNode e(7);
	ListNode f(8);

	a.next = &b;
	b.next = &c;

	d.next = &e;
	e.next = &f;

	Solution solve;
	ListNode *result = solve.getIntersectionNode(&a, &d);
	while(result){
		printf("%d", result->val);
	}

	system("pause");
}