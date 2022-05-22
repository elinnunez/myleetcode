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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root->val == p->val || root->val == q->val) {
            return root;
        } else if (!root->left && !root->right) {
            return NULL;
        }
        
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        
        if(root->left) {
            left = lowestCommonAncestor(root->left, p, q);
        }
        if(root->right) {
            right = lowestCommonAncestor(root->right, p, q);
        }
        
        if(left && right) {
            return root;
        } else if(left == NULL) {
            return right;
        } else {
            return left;
        }
        
        
//         TreeNode* cur = root;
        
//         while(cur) {
//             if(p->val > cur->val && q->val > cur->val) {
//                 cur = cur->right;
//             } else if (p->val < cur->val && q->val < cur->val) {
//                 cur = cur->left;
//             } else {
//                 break;
//             }
//         }
        
//         return cur;
    }
};