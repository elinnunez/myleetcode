class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count = 0;
        
        while(maxDoubles != 0 && target > 0) {
            if(target % 2 == 1) {
                target--;
            } else {
                target /= 2;
                maxDoubles--;
            }
            count++;
        }

        return count + target - 1;
        
    }
};