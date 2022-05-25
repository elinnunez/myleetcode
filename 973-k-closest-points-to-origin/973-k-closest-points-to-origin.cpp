class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> temp;
        
        for(int i = 0; i < points.size(); i++) {
            int euc = pow(points[i][0],2) + pow(points[i][1],2);
        
            vector<int> bag = {euc, i};
            temp.push_back(bag);
        }
        
        sort(temp.begin(), temp.end());
        
        vector<vector<int>> kclose;
        
        int count = 0;
        
        while(count != k) {
            int ptsIdx = temp[count][1];
            kclose.push_back(points[ptsIdx]);
            count++;
        }
        
        return kclose;
    }
};