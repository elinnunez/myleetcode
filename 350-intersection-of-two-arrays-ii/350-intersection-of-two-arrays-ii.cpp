class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
     unordered_map<int,int> ht;
        
        for(int i = 0; i < nums1.size(); i++) {
            ht[nums1[i]]++;
        }
        
        vector<int> out;
        
        for(int i = 0; i < nums2.size(); i++) {
            if(ht.count(nums2[i])) {
                ht[nums2[i]]--;
                out.push_back(nums2[i]);
                if(ht[nums2[i]] == 0) {
                    ht.erase(nums2[i]);
                }
            }
        }
        
        return out;
    }
};