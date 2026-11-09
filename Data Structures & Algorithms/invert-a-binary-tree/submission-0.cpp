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
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        TreeNode* currNode;

        // Will also flip nullptrs, but wont add them to queue
        while (!nodes.empty() && (currNode = nodes.front())) {
            TreeNode* left = currNode->left;
            TreeNode* right = currNode->right;
            
            // Could also use std::swap
            currNode->left = right;
            currNode->right = left;

            if (left) nodes.push(left);
            if (right) nodes.push(right);

            nodes.pop();
        }

        return root;
    }
};
