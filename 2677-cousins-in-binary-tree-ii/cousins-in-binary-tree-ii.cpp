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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> arr;
        arr.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1;
        while (!q.empty()) {
            int s = q.size();
            int sum = 0;
            for (int i = 0; i < s; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (t->right != NULL) {
                    sum += t->right->val;
                    q.push(t->right);
                }
                if (t->left != NULL) {
                    sum += t->left->val;
                    q.push(t->left);
                }
            }
            arr.push_back(sum);
            lvl++;
        }
        root->val = 0;
        q.push(root);
        for (int j = 1; j < lvl; j++) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* t = q.front();
                q.pop();
                int sum = 0;
                if (t->right != NULL) {
                    sum += t->right->val;
                    q.push(t->right);
                }
                if (t->left != NULL) {
                    sum += t->left->val;
                    q.push(t->left);
                }
                if (t->right != NULL) {
                    t->right->val = arr[j] - sum;
                }
                if (t->left != NULL) {
                    t->left->val = arr[j] - sum;
                }
            }
        }
        return root;
    }
};