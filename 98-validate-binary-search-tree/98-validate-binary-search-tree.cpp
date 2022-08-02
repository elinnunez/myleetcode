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
    bool isBST(TreeNode* root, TreeNode* left = nullptr, TreeNode* right = nullptr) {
        if(!root) {
            return true;
        }
        if(left != nullptr && root->val <= left->val) {
            return false;
        }
        if(right != nullptr && root->val >= right->val) {
            return false;
        }
        
        return isBST(root->left, left, root) && isBST(root->right, root, right);
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root);
    }
};