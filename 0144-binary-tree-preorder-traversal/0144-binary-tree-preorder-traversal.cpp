class Solution {
public:
    void preorder(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;

        result.push_back(root->val);  // Root
        preorder(root->left, result); // Left
        preorder(root->right, result); // Right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
};