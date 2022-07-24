class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n+1,0);
        steps[0] = 1;
        steps[1] = 1;
        
        if(n == 0 || n == 1) { // 0 steps away or 1 step away
            return steps[n];
        }
        
        for(int i = 2; i <= n ; i++) { // i is the steps away from target n
            steps[i] = steps[i-1] + steps[i-2];
        }
        
        return steps[n];
    }
};