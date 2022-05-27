class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> ht;
        
        int left = 0;
        
        int count = 0;
        
        int maxnum = 0;
        
        for(int i = 0; i < s.size(); i++) {
            char cur = s[i];
            ht[cur]++;
            count++;
            
            while(ht[cur] > 1) {
                ht[s[left]]--;
                left++;
                count--;
            }
            
            maxnum = max(count, maxnum);
            
        }
        
        return maxnum;
        
    }
};

// Dynamic sliding window

// cur = a, i = 0, left = 0, ht[a] = 1, count = 1
//  maxnum = max(count = 1, maxnum = 0) -> maxnum = 1

// cur = l, i = 1, left = 0, ht[l] = 1, count = 2
//  maxnum = max(count = 2, maxnum = 1) -> maxnum = 2

// cur = h, i = 2, left = 0, ht[h] = 1, count = 3
//  maxnum = max(count = 3, maxnum = 2) -> maxnum = 3

// cur = l, i = 3, left = 0, ht[l] = 2, count = 4
// ---> ht[s[left=0]]-- : ht[a] = 0, left = 1, count = 3, ht[l] = 2 //still not good
// ---> ht[s[left=1]]-- : ht[l] = 1, left = 2, count = 2, ht[l] = 1 // good now
//  maxnum = max(count = 2, maxnum = 3) -> maxnum = 3

// cur = k, i = 4, left = 2, ht[k] = 1, count = 3
//  maxnum = max(count = 3, maxnum = 3) -> maxnum = 3

// cur = j, i = 5, left = 2, ht[j] = 1, count = 4
//  maxnum = max(count = 4, maxnum = 3) -> maxnum = 4

// cur = f, i = 6, left = 2, ht[f] = 1, count = 5
//  maxnum = max(count = 5, maxnum = 4) -> maxnum = 5

// cur = h, i = 7, left = 2, ht[h] = 2, count = 6
// --> ht[s[left=2]]-- : ht[h] = 1, left = 3, count = 5, ht[h] = 1, // good now
//  maxnum = max(count = 5, maxnum = 5) -> maxnum = 5

// cur = a, i = 8, left = 3, ht[a] = 1, count = 6
//  maxnum = max(count = 6, maxnum = 5) -> maxnum = 6

// cur = k, i = 9, left = 3, ht[k] = 2, count = 7
// ---> ht[s[left=3]]-- : ht[l] = 0, left = 4, count = 4