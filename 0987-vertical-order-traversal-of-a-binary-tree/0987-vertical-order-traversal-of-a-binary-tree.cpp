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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // col -> row -> values
        map<int, map<int, multiset<int>>> nodes;

        // queue: node, {row, col}
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int row = it.second.first;
            int col = it.second.second;

            nodes[col][row].insert(node->val);

            if(node->left)
                q.push({node->left, {row+1, col-1}});
            
            if(node->right)
                q.push({node->right, {row+1, col+1}});
        }

        vector<vector<int>> ans;

        for(auto p : nodes) {                 // traverse columns
            vector<int> colNodes;

            for(auto q : p.second) {          // traverse rows
                colNodes.insert(colNodes.end(), q.second.begin(), q.second.end());
            }

            ans.push_back(colNodes);
        }

        return ans;
    }
};