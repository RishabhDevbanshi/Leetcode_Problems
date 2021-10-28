#define vi vector<int>
#define pi pair<int,int> 
#define fs first
#define sc second

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k) {
        priority_queue<vi,vector<vi> , greater<vi>> pq;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        set<vi> st;

        pq.push({A[0] + B[0], 0 , 0});

        int cnt = 0;
        vector<vi> res;
        st.insert({0,0});
        while(!pq.empty() && cnt < k)
        {
            cnt++;
            vi arr = pq.top() ; pq.pop();
            int sum = arr[0] , fidx = arr[1] , sidx = arr[2];
            res.push_back({A[fidx] , B[sidx]});
            if(fidx+1 < A.size() and sidx < B.size() and st.find({fidx+1,sidx}) == st.end())
            {
                sum = A[fidx+1] + B[sidx];
                pq.push({sum,fidx+1,sidx});
                st.insert({fidx+1,sidx});
            }
            if(fidx < A.size() and sidx+1 < B.size() and st.find({fidx,sidx+1}) == st.end())
            {
                sum = A[fidx] + B[sidx + 1];
                pq.push({sum,fidx,sidx+1});
                st.insert({fidx,sidx+1});
            }
        }

        return  res;
    }
};