#include<stdio.h>
#include<iostream>
#include<set>

int main() {
	std::set<int> set_list;

	const int A_len = 7;
	const int B_len = 8;

	int a[A_len] = { 5,1,4,8,10,1,3 };
	int b[B_len] = {2,7,6,3,1,6,0,1};

	for (int i = 0; i < A_len; i++) {
		set_list.insert(a[i]);    //将数组a的元素插入set
	}
	for (int i = 0; i < B_len; i++) {
		if (set_list.find(b[i]) != set_list.end()) {
			printf("b[%d] %d in Array a\n", i, b[i]);
		}
	}
	return 0;
}