/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    
    let ht = {};
    
    let final = [];
    
    for(let idx in nums) {
        if(!ht[target - nums[idx]]) {
            ht[nums[idx]] = idx;
        } else {
            final.push(parseInt(ht[target-nums[idx]]));
            final.push(parseInt(idx));
        }
    }
    
    return final;
    
};