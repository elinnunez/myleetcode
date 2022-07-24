class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> output;
        for(int i = 0; i < intervals.size(); i++) {
            if(newInterval[1] < intervals[i][0]) {
                output.push_back(newInterval);
                output.insert(end(output), begin(intervals)+i, end(intervals));
                return output;
            } else if(newInterval[0] > intervals[i][1]) {
                output.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        
        output.push_back(newInterval);
        
        return output;
        
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)
