class NumArray {
public:
    int *tree;
    int n;
    
    void buildTree(vector<int> &nums,int index,int start,int end)
    {
        if(start > end) return;
        
        if(start == end)
        {
            tree[index] = nums[start];
            return;
        }
        
        int mid = (start + end)/2;
        
        buildTree(nums,2*index,start,mid);
        
        buildTree(nums,2*index + 1,mid+1,end);
        
        tree[index] = tree[2*index] + tree[2*index + 1];
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        
        tree = new int[4*n + 1];
        buildTree(nums,1,0,n-1);
    }
    
    void updateTree(int index,int start,int end,int i,int val)
    {
        if(i < start or i > end) return;
        
        if(start == end)
        {
            tree[index] = val;
            return;
        }
        
        int mid = (start + end)/2;
        
        updateTree(2*index,start,mid,i,val);
        
        updateTree(2*index + 1,mid+1,end,i,val);
        
        tree[index] = tree[2*index] + tree[2*index + 1];
    }
    
    void update(int index, int val) {
        updateTree(1,0,n-1,index,val);
    }
    
    int query(int index,int start,int end,int qs,int qe)
    {
        if(qe < start or qs > end) return 0;
        
        if(qs <= start and qe >= end) 
        {
            return tree[index];
        }
        
        int mid = (start + end)/2;
        
        int leftAns = query(2*index,start,mid,qs,qe);
        
        int rightAns = query(2*index + 1,mid+1,end,qs,qe);
        
        return leftAns + rightAns;
    }
    
    int sumRange(int left, int right) {
        return query(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */