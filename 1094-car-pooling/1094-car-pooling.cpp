class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        typedef vector<int> vi;
        
        priority_queue<vi,vector<vi>,greater<vi>> pq;
        
        sort(trips.begin(),trips.end(),[](auto &a,auto &b){
            return a[1] < b[1];
        });
        
        // for(auto &v : trips)
        // {
        //     for(auto &val : v) cout<<val<<" ";
        //     cout<<"\n";
        // }
        
        int persons = 0,day=0;
        pq.push({trips[0][2],trips[0][1],trips[0][0]});
        persons = trips[0][0] , day = trips[0][1];
        
        if(persons > capacity) return false;
        
        for(int i=1;i<size(trips);i++)
        {
            day = trips[i][1];
            // cout<<pq.top()[0]<<" "<<day<<" ";
            while(!pq.empty() and pq.top()[0] <= day) 
            {
                persons -= pq.top()[2];
                pq.pop();
            }
            
            // cout<<persons<<" ";
            // cout<<size(pq);
            
            if(capacity - persons >= trips[i][0])
            {
                persons += trips[i][0];
                pq.push({trips[i][2],trips[i][1],trips[i][0]});
            }
            else return false;
            
        }
            
            
            
        return true;
    }
};