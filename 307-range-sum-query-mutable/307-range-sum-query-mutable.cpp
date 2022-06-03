class NumArray {
    vector<int> seg;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = size(nums);
        seg.resize(4*n);
         
        function<void(int,int,int)> build = [&](int idx,int left,int right){
            if(left == right)
            {
                seg[idx] = nums[left];
                return;
            }
            
            int mid = (left + right)>>1;
            build(2*idx + 1,left,mid);
            build(2*idx + 2,mid+1,right);
            
            seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
        };
        
        
        build(0,0,n-1);
    }
    
    void update(int index, int val) {
        
        function<void(int,int,int)> upd = [&](int idx,int left,int right){
            if(left == right)
            {
                seg[idx] = val;
                return;
            }
            
            int mid = (left + right)>>1;
            
            if(left <= index and index <= mid)
                upd(2*idx + 1,left,mid);
            else
                upd(2*idx + 2,mid+1,right);
            
            seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
        };
        
        upd(0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        
        function<int(int,int,int)> query = [&](int idx,int l,int r){
            if(left <= l and r <= right)
                return seg[idx];
            if(r < left or right < l)
                return 0;
            
            int mid = (l + r) >>1; 
            
            int left_ans = query(2*idx + 1,l,mid);
            int right_ans = query(2*idx + 2,mid+1,r);
            
            return left_ans + right_ans;
        };
        
        return query(0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */