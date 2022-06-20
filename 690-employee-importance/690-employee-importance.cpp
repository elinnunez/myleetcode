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
        int total = 0;
        
        for(Employee* emp: employees) {
            if(emp->id == id) {
                total += emp->importance;
                for(int sub: emp->subordinates) {
                    total += getImportance(employees, sub);
                }
                break;
            }
        }
        
        return total;
    }
};

// Time Complexity: O(n)
// Space Compleexity: O(n)