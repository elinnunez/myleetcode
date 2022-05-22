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
    
    int findheight(TreeNode* cur) {
        if(cur == NULL) {
            return -1;
        } else {
            return max(findheight(cur->left), findheight(cur->right)) + 1;
        }
    }
    
    bool isBalanced(TreeNode* cur) {
        
        if(cur == NULL) {
            return true;
        } else {
            int bf = findheight(cur->left) - findheight(cur->right);
            
            if(bf < -1 || bf > 1) {
                return false;
            } else {
                return isBalanced(cur->left) && isBalanced(cur->right);
            }
        }
    }
};