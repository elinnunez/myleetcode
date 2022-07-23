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
    
    TreeNode* dummy = new TreeNode();
    TreeNode* cur = dummy;
    
    
    void fill(TreeNode* root) {
        if(!root) {
            return;
        }
        
        fill(root->left);
        cur->right = new TreeNode(root->val);
        cur = cur->right;
        fill(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) {
            return root;
        }
        
        fill(root);
        
        return dummy->right;
    }
};