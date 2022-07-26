class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(edges.size() <= 0) {
            return true;
        }
        
        unordered_map<int,vector<int>> adjList;
        
        for(int i = 0; i < edges.size(); i++) {
            int num1 = edges[i][0];
            int num2 = edges[i][1];
            
            adjList[num1].push_back(num2);
            adjList[num2].push_back(num1);
        }
        
        stack<int> stk;
        set<int> found;
        stk.push(source);
        found.insert(source);
        
        while(!stk.empty()) {
            int cur = stk.top();
            stk.pop();
            
            for(int i = 0; i < adjList[cur].size(); i++) {
                if(adjList[cur][i] == destination) {
                    return true;
                }
                if(!found.count(adjList[cur][i])) {
                    found.insert(adjList[cur][i]);
                    stk.push(adjList[cur][i]);
                }
            }
        }
        
        return false;
    }
};