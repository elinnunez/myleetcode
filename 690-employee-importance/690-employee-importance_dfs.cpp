/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(unordered_map<int,Employee*> &ht, int& id, int& sum) {
        sum+= ht[id]->importance;
        
        for(int i = 0; i < ht[id]->subordinates.size(); i++) {
            dfs(ht, ht[id]->subordinates[i],sum);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
      unordered_map<int,Employee*> ht;
        
        for(auto x: employees) { // O(n)
            ht[x->id] = x;
        }
        
        int total = 0;
        
        dfs(ht,id,total);
        
        return total;
    }
};

// Time Complexity: O(n)
// Space Compleexity: O(n)
