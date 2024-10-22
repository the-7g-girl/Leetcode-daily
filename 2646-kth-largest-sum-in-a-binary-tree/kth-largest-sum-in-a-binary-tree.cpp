/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        while (!q.empty()) {
            int n = q.size();
            long long s = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                s += t->val;
                q.pop();
                if (t->left != NULL)
                    q.push(t->left);
                if (t->right != NULL)
                    q.push(t->right);
            }
            pq.push(s);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.size() == k ? pq.top() : -1;
    }
};