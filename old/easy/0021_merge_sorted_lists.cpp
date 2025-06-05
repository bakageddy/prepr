struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {};
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(int x, ListNode *_next) : val(x), next(_next) {};
};

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == nullptr && l2 == nullptr) return nullptr;
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		auto list1 = l1;
		auto list2 = l2;

		ListNode *result_head = nullptr;
		ListNode *result_tail = nullptr;
		if (list1 -> val <= list2 -> val) {
			result_head = list1;
			list1 = list1 -> next;
		} else {
			result_head = list2;
			list2 = list2 -> next;
		}
		result_tail = result_head;

		while (list1 != nullptr && list2 != nullptr) {
			if (list1 -> val <= list2 -> val) {
				result_tail -> next = list1;
				list1 = list1 -> next;
			} else {
				result_tail -> next = list2;
				list2 = list2 -> next;
			}
			result_tail = result_tail -> next;
		}
		while (list1 != nullptr) {
			result_tail -> next = list1;
			list1 = list1 -> next;
		}
		while (list2 != nullptr) {
			result_tail -> next = list2;
			list2 = list2 -> next;
		}
		return result_head;
	}
};
