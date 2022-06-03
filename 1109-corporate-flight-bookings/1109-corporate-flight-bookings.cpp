class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<long> seg(4*n), lazy(4*n);
        
        // int start = 0 , end = 0 , val = 0;
        
        function<void(int,int,int,int,int,int)> update = [&](int idx,int left,int right,int start,int end,int val){
            
            if(lazy[idx] != 0)
            {
                seg[idx] += 1LL * (right - left + 1) * lazy[idx];
                if(left != right)
                    lazy[2*idx + 1] += lazy[idx] , lazy[2*idx + 2] += lazy[idx];
                lazy[idx] = 0;
            }
            
            if(right < start or left > end or left > right)
                return;
            
            if(start <= left and right <= end)
            {
                seg[idx] += (right - left + 1) * val;
                if(left != right)
                    lazy[2*idx + 1] += val , lazy[2*idx + 2] += val;
                return;
            }
            
            int mid = (left + right) >> 1;
            update(2*idx + 1,left,mid,start,end,val);
            update(2*idx + 2,mid+1,right,start,end,val);
            
            seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
        };
        
        function<int(int,int,int,int,int)> search = [&](int idx,int left,int right,int start,int end)->long{
            if(lazy[idx] != 0)
            {
                seg[idx] += 1LL * (right - left + 1) * lazy[idx];
                if(left != right)
                    lazy[2*idx + 1] += lazy[idx] , lazy[2*idx + 2] += lazy[idx];
                lazy[idx] = 0;
            }
            
            if(end < left or right < start or left > right)
                return 0;
            
            if(start <= left and right <= end)
            {
                return seg[idx];
            }
            
            int mid = (left + right) >> 1;
            int left_ans = search(2*idx + 1,left,mid,start,end);
            int right_ans = search(2*idx + 2,mid+1,right,start,end);
            
            return left_ans + right_ans;
        };
        
        for(auto &v : bookings)
        {
            int start = v[0]-1 , end = v[1]-1 , val = v[2];
            update(0,0,n-1,start,end,val);
            // for(auto &val : seg) cout << val << " ";
            // cout << "\n";
        }
        
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            // start = i ,end = i;
            // cout << start << " " << end << "\n";
            int x = search(0,0,n-1,i,i);
            // cout << x << "\n";
            res[i] = x;
        }
        
        return res;
    }
};