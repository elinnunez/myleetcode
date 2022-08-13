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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> bag;
        if(root == nullptr) {
            return bag;
        } else {
            TreeNode* cur = root;
            
            queue<TreeNode*> qbag;
            qbag.push(cur);
            
            while(!qbag.empty()) {
                int size = qbag.size();
                vector<int> tbag;
                for(int i = 0; i < size; i++) {
                    TreeNode* temp = qbag.front();
                    qbag.pop();
                    tbag.push_back(temp->val);
                    
                    if(temp->left) {
                        qbag.push(temp->left);
                    }
                    
                    if(temp->right) {
                        qbag.push(temp->right);
                    }
                    
                }
                
                bag.push_back(tbag);
            }
            
            return bag;
        }
        
    }
};