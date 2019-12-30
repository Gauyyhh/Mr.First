#include<stdio.h>

#include<iostream>

struct ListNode {
	int val;       //�洢Ԫ�ص�������
	ListNode *next;    //�洢��һ���ڵ��ָ����
	ListNode(int x):val(x),next(NULL) {}
};

class Solution {
public:
	ListNode *reverseList(ListNode *head) {
		//�����������ú��ͷ�ڵ�
		ListNode *new_head = NULL;
		while (head) {
			ListNode *next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
		}
		return new_head;

	}
};

int main() {
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	Solution solve;
	ListNode *head = &a;
	printf("Before reverse:\n");
	while (head) {
		printf("%d\n", head->val);
		head = head->next;
	}
	head = solve.reverseList(head);
	printf("After reverse:\n");
	while (head) {
		printf("%d\n", head->val);
		head = head->next;
	}
	system("pause");
	return 0;
}

