class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        // if(n == 0)
        
        for(int i=0;i<size(flowerbed);)
        {
            if(n == 0) return true;
            if(flowerbed[i] == 1) i++;
            else if((i-1>=0 and flowerbed[i-1] == 1) || (i+1<size(flowerbed) and flowerbed[i+1] == 1))
                i++;
            else n-- , flowerbed[i] = 1 , i++;
            
            // if(n == 0) return true;
        }
        
        return n == 0;
    }
};