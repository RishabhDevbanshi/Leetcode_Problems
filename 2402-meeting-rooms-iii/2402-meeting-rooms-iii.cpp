class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        typedef pair<long,long> pii;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        
        sort(meetings.begin(),meetings.end());
        
        // unordered_map<long,long> mp;
        vector<int> freq(n+1);
        
        set<int> st;
        for(int i=0;i<=n;i++) st.insert(i);
        
        for(int i=0;i<size(meetings);i++)
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
            freq[*st.begin()]++;
            st.erase(st.begin());
        }
        
        long maxi = 0 , room = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            // cout << freq[i] << " ";
            if(freq[i] > maxi) maxi = freq[i] , room = i;
        }
        
        return room;
    }
};