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
    void addPath(TreeNode* root, vector<string>& output, string cur) {
        if(!root || (!root->left && !root->right)) {
            if(root) {
                cur+= to_string(root->val);
            }
            
            output.push_back(cur);
            return;
        }
        
        cur+= (to_string(root->val) + "->");

        if(root->left) {
            addPath(root->left, output, cur);
        }
        
        if(root->right) {
            addPath(root->right, output, cur);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> output;
        string cur = "";
        
        addPath(root,output,cur);
        
        return output;
        
    }
};