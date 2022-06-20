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
    int getImportance(vector<Employee*> employees, int id) {
      unordered_map<int,Employee*> ht;
        
        for(auto x: employees) {
            ht[x->id] = x;
        }
        
        queue<Employee*> bag;
        bag.push(ht[id]);
        
        int total = 0;
        
        while(!bag.empty()) {
            Employee* temp = bag.front();
            bag.pop();
            total+= temp->importance;
            int subSize = temp->subordinates.size();
            for(int i = 0; i < subSize; i++) {
                bag.push(ht[temp->subordinates[i]]);
            }
        }
        
        return total;
    }
};