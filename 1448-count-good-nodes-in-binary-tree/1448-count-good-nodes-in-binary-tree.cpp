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
    void check(TreeNode* root, int curMax, int& count) {
        if(root == nullptr) return;
        
        if(root->val >= curMax) {
            count++;
            curMax = root->val;
        }
        check(root->left,curMax,count);
        check(root->right,curMax,count);
    }
    
    int goodNodes(TreeNode* root) {
        int count = 0;
        
        check(root,INT_MIN,count);
        
        return count;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n) recursive stack