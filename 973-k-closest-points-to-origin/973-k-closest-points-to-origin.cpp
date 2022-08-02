class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<pair<int,vector<int>>> bag;
        
        for(int i = 0; i < points.size(); i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int distance = pow(x1-0,2) + pow(y1,2);
            
            pair<int,vector<int>> p;
            p.first = distance;
            p.second = points[i];
            
            bag.push_back(p);
        }
        
        sort(bag.begin(), bag.end());
        
        vector<vector<int>> output;
        
        for(int i = 0; i < k; i++) {
            output.push_back(bag[i].second);
        }
        
        return output;
        
    }
};

//points are x1,y1
// origin are x2,y2

/*

loop through points array
-> use the euclidean distance formula to calculate the distance
-> pair{distance,arr[int]}
->pull the second element and push to separate arary and return k elements;
*/