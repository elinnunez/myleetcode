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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) {
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        int total = 0;
        
        while(!q.empty()) {
            int qSize = q.size();
            
            for(int i = 0; i < qSize; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(low <= temp->val && temp->val <= high) {
                    total+=temp->val;
                }
                
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
        }
        
        return total;
        
    }
};