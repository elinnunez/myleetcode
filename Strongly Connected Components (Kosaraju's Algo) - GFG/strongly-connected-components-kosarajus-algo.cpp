//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	void dfs(int i,vector<int> adj[], stack<int>& stk, vector<bool>& visited) {
	    visited[i] = true;
	    
	    for(auto edge : adj[i]) {
	        if(!visited[edge]) dfs(edge,adj,stk,visited);
	    }
	    
	    stk.push(i);
	}
	
	void dfs2(int i,vector<int> revadj[], vector<bool>& visited) {
	    visited[i] = true;
	    
	    for(auto edge : revadj[i]) {
	        if(!visited[edge]) dfs2(edge,revadj,visited);
	    }
	    
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> stk;
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) dfs(i,adj,stk,visited);
        }
        
        vector<int> revAdj[V];
        
        for(int i = 0; i < V; i++) {
            visited[i] = false; // resets visited array back to false for use again
            for(auto edge : adj[i]) {
                revAdj[edge].push_back(i);
            }
        }
        
        int count = 0;
        
        while(!stk.empty()) {
            int src = stk.top();
            stk.pop();
            
            if(!visited[src]) {
                count++;
                dfs2(src,revAdj,visited);
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends