/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getRef(TreeNode* clone, TreeNode* target) {
        if(clone == nullptr) {
            return nullptr;
        }
        
        if(clone->val == target->val) {
            return clone;
        }
        
        TreeNode* left = getRef(clone->left,target);
        TreeNode* right = getRef(clone->right,target);
        
        if(left) {
            return left;
        } else {
            return right;
        }
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        return getRef(cloned, target);
    }
};