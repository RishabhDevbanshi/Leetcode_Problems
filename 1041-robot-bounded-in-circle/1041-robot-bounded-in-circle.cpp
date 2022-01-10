class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        char dir = 'N';
        
        int x=0 , y=0;
        
        for(auto &ch : instructions)
        {
            
            if(ch == 'G')
            {
                
                if(dir == 'N') y++;
                else if(dir == 'S') y--;
                else if(dir == 'E') x++;
                else x--;
                
            }
            else if(ch == 'L')
            {
                
                if(dir == 'N') dir = 'W';
                else if(dir == 'W') dir = 'S';
                else if(dir == 'S') dir = 'E';
                else dir = 'N';
                
            }
            else
            {
                if(dir == 'N') dir = 'E';
                else if(dir == 'E') dir = 'S';
                else if(dir == 'S') dir = 'W';
                else dir = 'N';
            }
            
        }
        
        bool atOrigin = (x==0) and (y==0);
        return atOrigin || (dir != 'N');
    }
};