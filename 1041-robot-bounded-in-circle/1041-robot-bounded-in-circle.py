class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        dirX, dirY = 0,1
        
        x,y = 0,0
        
        for step in instructions:
            if step == 'L':
                dirX,dirY = -1*dirY,dirX
            elif step == 'R':
                dirX,dirY = dirY,-1*dirX
            else:
                x+=dirX
                y+=dirY
        
        if (x,y) == (0,0) or dirX != 0 or dirY != 1:
            return True
        
        return False