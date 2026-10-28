#include <deque>
#include <vector>
using std::vector;

class Node {
  public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
  public:
    // Recursive
    //    vector<int> preorder(Node *root) {
    // 	if (root == nullptr) {
    // 		return {};
    // 	}
    //
    // 	vector<int> result = {root -> val};
    // 	for (auto child : root -> children) {
    // 		auto children = preorder(child);
    // 		result.insert(result.end(), children.begin(), children.end());
    // 	}
    //
    // 	return result;
    // }
    vector<int> preorder(Node *root) {
        if (root == nullptr) {
            return {};
        }
        std::deque<Node *> stack = {root};
        std::vector<int> result = {};
        while (!stack.empty()) {
            Node *temp = stack.back();
            stack.pop_back();
            result.push_back(temp->val);
            stack.insert(stack.end(), temp->children.rbegin(), temp->children.rend());
        }
        return result;
    }
};
