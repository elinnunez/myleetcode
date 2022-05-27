/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let ht = {};
    
    let left = 0;
    let count = 0;
    
    let maxcount = 0;
    
    for(let i in s) {
        if(!ht[s[i]]) {
            ht[s[i]] = 1;
        } else {
            ht[s[i]]+=1;
        }
        
        count++;
        
        while(ht[s[i]] > 1) {
            ht[s[left]]--;
            left++;
            count--;
        }
        
        maxcount = Math.max(count, maxcount);
    }
    
    return maxcount;
};