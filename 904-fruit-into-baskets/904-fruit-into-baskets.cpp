class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int curr = 0, a=0 , b=0 , count_b = 0 , res = 0;
        for(auto fruit : fruits)
        {
            curr = fruit == a || fruit == b ? curr + 1 : count_b+1;
            count_b = fruit == b ? count_b + 1 : 1;
            if(b != fruit) a = b , b = fruit;
            
            res = max(res,curr);
        }
        
        return res;
    }
};