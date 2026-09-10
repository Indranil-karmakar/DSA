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
 class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;

    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (!reverse)
            pushAll(node->right);
        else
            pushAll(node->left);

        return node->val;
    }
};
class Solution {
public:
     bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, false); // smallest
        BSTIterator r(root, true);  // largest

        int i = l.next();
        int j = r.next();

        while (i < j) {
            int sum = i + j;

            if (sum == k)
                return true;
            else if (sum < k)
                i = l.next();
            else
                j = r.next();
        }

        return false;
    }
};