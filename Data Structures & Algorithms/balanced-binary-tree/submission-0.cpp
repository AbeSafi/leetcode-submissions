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
    int maxDepth(TreeNode* node, bool& balanced) {
        if (!node) return 0;
        
        int leftDepth = maxDepth(node->left, balanced);
        int rightDepth = maxDepth(node->right, balanced);

        int difference = leftDepth - rightDepth;

        if (difference < -1 || difference > 1) balanced = false;

        return 1 + max(leftDepth, rightDepth);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        maxDepth(root, balanced);
        return balanced;
    }
};
