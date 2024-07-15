#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void free_list(struct ListNode *head) {
	free(head -> next);
	free(head);
}

struct ListNode *new_node(int val) {
	struct ListNode *node = malloc(sizeof(*node));
	assert(node != NULL);
	node -> next = NULL;
	node -> val = val;
}

struct ListNode *node_append(struct ListNode *head, struct ListNode *node) {
	assert(node != NULL);
	if (head == NULL) return node;
	struct ListNode *temp = head;
	while (temp -> next != NULL) {
		temp = temp -> next;
	}
	temp -> next = node;
	node -> next = NULL;
}

int list_to_int(struct ListNode *l) {
	assert(l != NULL);
	int num = 0;
	struct ListNode *temp = l;
	while (temp != NULL) {
		num = num * 10 + temp -> val;
		temp = temp -> next;
	}
	return num;
}

struct ListNode *int_to_list(int num) {
	struct ListNode *head = NULL;
	while (num != 0) {
		int val = num % 10;
		struct ListNode *temp = new_node(val);
		temp -> next = head;
		head = temp;
		num /= 10;
	}
	return head;
}

struct ListNode *sum(struct ListNode *l1, struct ListNode *l2) {
	int num1 = list_to_int(l1);
	int num2 = list_to_int(l2);
	int sum = num1 + num2;
	return int_to_list(sum);
}

int main(void) {
	return 0;
}
