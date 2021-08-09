class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size();
        int s=-1,e=-1;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i] > arr[i+1])
            {
                s = i;
                break;
            }
        }
        
        if(s == -1) return 0;
        
        for(int i=n-1;i>0;i--)
        {
            if(arr[i] < arr[i-1])
            {
                e = i;
                break;
            }
        }
        // cout<<s<<" "<<e;
        int mn = arr[s] , mx = arr[s];
        for(int i=s+1;i<=e;i++)
        {
            if(arr[i] < mn) mn = arr[i];
            else if(arr[i] > mx) mx = arr[i];
        }
        
        for(int i=0;i<s;i++)
        {
            if(arr[i] > mn)
            {
                s = i;
                break;
            }
        }
        
        for(int i=n-1;i>e;i--)
        {
            if(arr[i] < mx)
            {
                e = i;
                break;
            }
        }
        return (e-s+1);
    }    
};