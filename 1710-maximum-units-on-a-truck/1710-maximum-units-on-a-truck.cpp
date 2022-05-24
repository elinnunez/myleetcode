class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(),
          boxTypes.end(),
          [] (const std::vector<int> &a, const std::vector<int> &b)
          {
              return a[1] < b[1];
          });
        
        int leftover = truckSize;
        
        int maxunits = 0;
        
        for(int i = boxTypes.size() - 1; i >= 0; i--) {
            
            if(leftover > boxTypes[i][0]) {
                maxunits += (boxTypes[i][0] * boxTypes[i][1]);
                leftover -= boxTypes[i][0];
            } else {
                maxunits += (leftover * boxTypes[i][1]);
                break;
            }
        }
        
        return maxunits;
        
    }
};