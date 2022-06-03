class NumArray {
    vector<int> seg;
    int n;
public:
    NumArray(vector<int>& nums) {
        seg.resize(size(nums)*4);
        n = size(nums);
        
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
        
        build(0,0,size(nums)-1);
    }
    
    int sumRange(int left, int right) {
        
        function<int(int,int,int)> search = [&](int idx,int l,int r){
            if(left <= l and right >= r)
            {
                return seg[idx];
            }
            else if(r < left or right < l)
                return 0;
            
            int mid = (l+r)>>1;
            int left_ans = search(2*idx + 1,l,mid);
            int right_ans = search(2*idx + 2,mid+1,r);
            
            return left_ans + right_ans;
        };
        
        
        return search(0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */