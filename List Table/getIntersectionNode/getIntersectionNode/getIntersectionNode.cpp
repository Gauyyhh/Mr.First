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
		//遍历链表A，将链表A中的节点对应的指针地址，插入set
		std::set<ListNode*>node_set;     //设置查找集合node_set
		while (headA) {
			node_set.insert(headA);
			headA = headA->next;     //遍历链表A
		}
		while (headB) {
			if (node_set.find(headB) != node_set.end()) {
				return headB;      //当在headB中找到第一个出现在node_set中的节点时
			}
			headB = headB->next;    //遍历链表B
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