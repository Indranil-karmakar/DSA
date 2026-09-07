/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Serialize (BFS)
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL) {
                s.append("#,");
            } else {
                s.append(to_string(curr->val) + ",");
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Deserialize (BFS)
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // LEFT child
            if(!getline(ss, str, ',')) break;
            if(str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // RIGHT child
            if(!getline(ss, str, ',')) break;
            if(str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;  // ✅ FIXED
                q.push(rightNode);
            }
        }

        return root;
    }
};