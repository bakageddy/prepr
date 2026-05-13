#include <set>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *hashSetGetIntersectionNode(ListNode *headA, ListNode *headB) {
		std::set<ListNode *> seen = {};
		ListNode *tempA = headA;
		ListNode *tempB = headB;
		while (tempA) {
			seen.insert(tempA);
			tempA = tempA -> next;
		}
		while (tempB) {
			if (seen.find(tempB) != seen.end()) {
				return tempB;
			}
			tempB = tempB -> next;
		}
		return nullptr;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *a = headA;
		ListNode *b = headB;
		while (a != b) {
			if (a == nullptr) a = headB;
			else a = a -> next;
			if (b == nullptr) b = headA;
			else b = b -> next;
		}
		return a; // you can also return b
	}
};
