class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        typedef pair<long,long> pii;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        
        sort(meetings.begin(),meetings.end());
        
        unordered_map<long,long> mp;
        
        set<long> st;
        for(long i=0;i<n;i++) st.insert(i);
        
        for(long i=0;i<size(meetings);i++)
        {
            while(!pq.empty() and pq.top().first <= meetings[i][0])
            {
                st.insert(pq.top().second);
                pq.pop();
            }
            
            long add = 0;
            
            if(size(pq) == n)
            {
                add = pq.top().first - meetings[i][0];
                st.insert(pq.top().second) , pq.pop();
            }
            
            pq.push({meetings[i][1] + add,*st.begin()});
            mp[*st.begin()]++;
            // cout<<"room = " << (*st.begin()) <<  "\n";
            st.erase(st.begin());
        }
        
        long maxi = 0 , room = INT_MAX;
        
        for(auto &[key,value] : mp)
        {
            // cout << key << " " << value << "\n";
            if(value > maxi)
                maxi = value , room = key;
            else if(value == maxi) room = min(room,key);
        }
        
        return room;
    }
};