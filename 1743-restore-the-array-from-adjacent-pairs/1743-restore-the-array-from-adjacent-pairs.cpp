class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& ht, set<int>& visited, vector<int>& output, int key) {
        if(visited.count(key)) return;
        
        visited.insert(key);
        output.push_back(key);
        
        for(const auto& adj: ht[key]) {
            if(!visited.count(adj)) {
                dfs(ht, visited, output, adj);
            }
        }
        
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> ht;
        
        for(int i = 0; i < adjacentPairs.size(); i++) {
            ht[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            ht[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        
        int first;
        
        for(const auto& it: ht) {
            if(it.second.size() == 1) {
                first = it.first;
                break;
            }
        }
        
        vector<int> output;
        
        set<int> visited;
        
        dfs(ht, visited, output, first);
        
        return output;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)