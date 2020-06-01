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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			vector<int> v;
			int len = q.size();
			for (int i = 0; i < len; i++)
			{
				TreeNode* r = q.front();
				q.pop();
				if (r)
					v.push_back(r->val);
				if (r->left)
					q.push(r->left);
				if (r->right)
					q.push(r->right);
			}
			res.push_back(v);
		}
		return res;
	}
};