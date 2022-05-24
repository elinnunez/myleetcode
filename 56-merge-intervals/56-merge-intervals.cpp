class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> bag;
        
        int low = intervals[0][0];
        int curmax = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++) {
            int clow = intervals[i][0];
            int chi = intervals[i][1];
            
            if(clow > curmax) {
                
                vector<int> temp;
                temp.push_back(low);
                temp.push_back(curmax);
                
                bag.push_back(temp);
                
                low = clow;
            }
            curmax = max(curmax,chi);
        }
        
        vector<int> temp;
        temp.push_back(low);
        temp.push_back(curmax);
        
        bag.push_back(temp);
        
        return bag;
    }
};