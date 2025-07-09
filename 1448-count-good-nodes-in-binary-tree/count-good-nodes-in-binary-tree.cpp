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
    int DFS(TreeNode* root, int maxval) {
        if (!root)
            return 0;

        int count = 0;
        if (root->val >= maxval) {
            count = 1;
            maxval = root->val;
        }

        count += DFS(root->left, maxval);
        count += DFS(root->right, maxval);

        return count;
    }

    int goodNodes(TreeNode* root) { return DFS(root, INT_MIN); }
};
