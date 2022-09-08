class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& myMap, set<int>& visited, int course) {
        if(visited.count(course)) {
            return false;
        }
        
        if(myMap[course].size() == 0) {
            return true;
        }
        
        visited.insert(course);
        
        for(int i = 0; i < myMap[course].size(); i++) {
            if(dfs(myMap, visited, myMap[course][i]) == false) {
                return false;
            }
        }
        
        visited.erase(course);
        
        myMap[course] = {};
        
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> myMap;
        
        for(int i = 0; i < prerequisites.size(); i++) {
            myMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        set<int> visited;
        
        for(int i = 0; i < numCourses; i++) {
            if(dfs(myMap, visited, i) == false) {
                return false;
            }
        }
        
        return true;
    }
};
// Time Complexity: O(n+p) where p is the prerequisites
// Space Complexity: O(n)