class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        
        int i=0, j=size(people)-1;
        
        int boats = 0;
        
        while(i<=j)
        {
            int tot = (i == j) ? people[i] : people[i] + people[j];
            
            boats++;
            
            if(tot <= limit)
            {
                i++ , j--;
            }
            else
            {
                j--;
            }
        }
        
        
        
        return boats;
    }
};