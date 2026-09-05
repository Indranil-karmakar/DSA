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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = minDepth(root->left);
        int rh = minDepth(root->right);
         // If left subtree is missing
        if (lh == 0) return 1 + rh;

        // If right subtree is missing
        if (rh == 0) return 1 + lh;
        return 1 + min(lh, rh);
    }
};