class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> hm = new HashMap<Integer, Integer>();
        
        int[] temp = new int[2];
        
        for(int i = 0; i < nums.length; i++) {
            if(hm.containsKey(target-nums[i])) {
                temp[0] = hm.get(target-nums[i]);
                temp[1] = i;
            } else {
                hm.put(nums[i], i);
            }
        }
        
        return temp;
        
    }
}