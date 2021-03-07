class NumArray {
    int[] tree;
    int n;
    
    public void buildSegmentTree(int[] tree,int[] arr,int index,int start,int end)
    {
        if(start > end) return;
        
        if(start == end)
        {
            tree[index] = arr[start];
            return;
        }
        
        int mid = (start + end)/2;
        
        buildSegmentTree(tree,arr,2*index,start,mid);
        
        buildSegmentTree(tree,arr,2*index + 1,mid+1,end);
        
        tree[index] = tree[2*index] + tree[2*index + 1];
    }
    
    public NumArray(int[] nums) {
        n = nums.length;
        
        tree = new int[4*n + 1];
        
        buildSegmentTree(tree,nums,1,0,n-1);
    }
    
    public void updateSegmentTree(int[] tree,int index,int start,int end,int i,int val)
    {
        if(i < start || i > end) return;
        
        if(start == end)
        {
            tree[index] = val;
            return;
        }
        
        int mid = (start + end)/2;
        
        updateSegmentTree(tree,2*index,start,mid,i,val);
        
        updateSegmentTree(tree,2*index + 1,mid+1,end,i,val);
        
        tree[index] = tree[2*index] + tree[2*index + 1];
    }
    
    public void update(int index, int val) {
        updateSegmentTree(tree,1,0,n-1,index,val);
    }
    
    public int query(int[] tree,int index,int start,int end,int qs,int qe)
    {
        if(qe < start || qs > end) return 0;
        
        if(qs <= start && qe >= end)
        {
            return tree[index];
        }
        
        int mid = (start+end)/2;
        
        int leftAns = query(tree,2*index,start,mid,qs,qe);
        
        int rightAns = query(tree,2*index + 1,mid+1,end,qs,qe);
        
        return leftAns + rightAns;
    }
    
    public int sumRange(int left, int right) {
        return query(tree,1,0,n-1,left,right);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */