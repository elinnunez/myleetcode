class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> hash;
        
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        
        vector<vector<int>> temp;
        
        for(const auto& it: hash) {
            vector<int> bag = {it.second, it.first};
            temp.push_back(bag);
        }
        
        sort(temp.begin(), temp.end());
        
        vector<int> baggie;
        
        int i = temp.size() - 1;
        while(k != 0) {
            baggie.push_back(temp[i][1]);
            k--;
            i--;
        }
        
        return baggie;
        
    }
};