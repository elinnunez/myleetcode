class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        int dirX, dirY;
        dirX = 0;
        dirY = 1;
        
        int x, y;
        x = y = 0;
        
        for(int i = 0; i < instructions.size(); i++) {
            char curChar = instructions[i];
            int temp;
            
            if(curChar == 'L') {
                temp = dirY;
                dirY = dirX;
                dirX = -1*temp;
            } else if (curChar == 'R') {
                temp = dirX;
                dirX = dirY;
                dirY = -1*temp;
            } else {
                x+= dirX;
                y+= dirY;
            }
        }
        
        if (x == 0 && y == 0 || dirX != 0 || dirY != 1) {
            return true;
        }
        
        return false;
    }
};