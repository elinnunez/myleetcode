class Solution {
public:
    bool hasPath(unordered_map<int,vector<int>>& adj, int src, int dst, set<int>& visited) {
        if(src == dst) {
            return true;
          }
        
        if(visited.count(src)) {
            return false;
          }
        
        visited.insert(src);
        
        for(int i = 0; i < adj[src].size(); i++) {
            if(hasPath(adj, adj[src][i], dst, visited) == true) {
              return true;
            }
          }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.size() <= 0) {
            return true;
        }
        
        unordered_map<int,vector<int>> adj;
        
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        set<int> visited;
        
        return hasPath(adj, source, destination, visited);
    }
};
