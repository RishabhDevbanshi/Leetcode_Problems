class Solution {
    
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0 , j=0;
        
        while(i < size(pushed) and j < size(popped))
        {
            if(pushed[i] == popped[j])
            {
                int dummy = i;
                while(dummy >=0 and pushed[dummy] == popped[j])
                {
                    pushed[dummy] = -1;
                    dummy--;
                    j++;
                    while(dummy >=0 and pushed[dummy] == -1)
                        dummy--;
                }
                i++;
            }
            else i++;
        }
        
        return i == size(pushed) and j == size(popped);
    }
};