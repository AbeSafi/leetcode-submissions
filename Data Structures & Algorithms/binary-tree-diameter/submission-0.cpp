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
    int dfs(TreeNode* currNode, int& diameter) {
        if (!currNode) return 0;

        TreeNode* leftNode = currNode->left;
        TreeNode* rightNode = currNode->right;

        int leftDepth = 0, rightDepth = 0;
        if (leftNode) leftDepth = 1 + dfs(leftNode, diameter);
        if (rightNode) rightDepth = 1 + dfs(rightNode, diameter);

        diameter = max(diameter, leftDepth + rightDepth);

        int maxDepth = max(leftDepth, rightDepth);
        return maxDepth;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }
};
