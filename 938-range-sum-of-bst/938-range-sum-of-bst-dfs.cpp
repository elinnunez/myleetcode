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
    void dfs(TreeNode* root, int& total, int& low, int& high) {
        if(!root) {
            return;
        }
        
        if(low <= root->val && root->val <= high) {
            total += root->val;
        }
        
        dfs(root->left, total, low, high);
        dfs(root->right, total, low, high);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int total = 0;
        dfs(root, total, low, high);
        
        return total;
    }
};
