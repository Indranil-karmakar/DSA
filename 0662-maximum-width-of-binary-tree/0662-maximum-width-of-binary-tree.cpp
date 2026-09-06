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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        int maxwidth = 0;

        while (!q.empty()) {
            unsigned long long stindex = q.front().second;
            unsigned long long endindex = q.back().second;

            int currindex = q.size();

            maxwidth = max(maxwidth, (int)(endindex - stindex + 1));

            for (int i = 0; i < currindex; i++) {
                auto curr = q.front(); 
                q.pop();

                if (curr.first->left) {
                    q.push({curr.first->left, curr.second * 2 + 1});
                }
                if (curr.first->right) {
                    q.push({curr.first->right, curr.second * 2 + 2});
                }
            }
        }

        return maxwidth;
    }
};