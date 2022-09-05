/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) {
            return {};
        }
        
        queue<Node*> q;
        q.push(root);
        
        vector<vector<int>> output;
        
        while(!q.empty()) {
            vector<int> temp;
            
            int qSize = q.size();
            
            for(int i = 0; i < qSize; i++) {
                Node* curNode = q.front();
                q.pop();
                
                temp.push_back(curNode->val);
                
                for(int j = 0; j < curNode->children.size(); j++) {
                    q.push(curNode->children[j]);
                }
            }
            
            output.push_back(temp);
        }
        
        return output;
        
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)