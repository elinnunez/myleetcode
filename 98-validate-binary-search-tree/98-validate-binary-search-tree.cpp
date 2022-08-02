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
        // if left node has a val >= root node
        if(left != nullptr && root->val <= left->val) {
            return false;
        }
        // if right node has a val <= root node
        if(right != nullptr && root->val >= right->val) {
            return false;
        }
        
        return isBST(root->left, left, root) && isBST(root->right, root, right);
    }
    
    bool isValidBST(TreeNode* root) {
        return isBST(root);
    }
};

// root = 5, left = null, right = null
// isbst(1,null,5) = true && isbst(4,5,null) == false ------> true && false == (false)
//  -> root = 1, left = null, right = 5
//    -> isbst(null,null,1) && isbst(null,1,5) == true
//       -> return true      && return true 
//  -> root = 4, left=5, right = null
//    -> left != null && 4 <= 5 -> return false