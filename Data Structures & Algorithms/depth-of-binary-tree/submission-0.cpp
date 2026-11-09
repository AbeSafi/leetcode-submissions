/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private: 
    int dfs(TreeNode* currNode) {
        if (!currNode) return 0;
        
        int leftDepth = dfs(currNode->left);
        int rightDepth = dfs(currNode->right);

        return 1 + max(leftDepth, rightDepth);
    }
public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};
