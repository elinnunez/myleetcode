//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> inDeg(V, 0);
        for(int i = 0; i < V; i++) {
            for(auto edge : adj[i]) {
                inDeg[edge]++;
            }
        }
        
        queue<int> pq;
        
        for(int i = 0; i < inDeg.size(); i++) {
            if (inDeg[i]==0) pq.push(i);
        }
        
        int count = 0;
        
        while(!pq.empty()) {
            int src = pq.front();
            pq.pop();
            
            count++;
            
            for(auto edge : adj[src]) {
                inDeg[edge]--;
                if(inDeg[edge] == 0) pq.push(edge);
            }
        }
        
        if(count == V) return false;
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends