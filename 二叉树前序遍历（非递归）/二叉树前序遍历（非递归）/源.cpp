/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		std::stack<TreeNode*> stack;
		vector<int> vec;
		TreeNode* cur = root;
		while (cur != NULL || !stack.empty()) {
			while (cur != NULL) {
				stack.push(cur);
				vec.push_back(cur->val);
				cur = cur->left;
			}
			cur = stack.top();
			stack.pop();
			cur = cur->right;
		}
		return vec;
	}
};