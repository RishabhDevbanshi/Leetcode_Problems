// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    
    typedef long long ll;
    
    ll cnt = 0;
    
    void merge(ll arr[],ll left,ll mid,ll right)
    {
        ll i=left,j=mid;
        for(i=left;i<mid;i++)
        {
            while(j<=right and arr[j] < arr[i]) j++;
            
            cnt += (j - mid);
        }
        
        ll temp[right - left + 1];
        
        i=left, j=mid;
        int k=0;
        
        while(i<mid and j<=right)
        {
            if(arr[i] < arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
        
        while(i<mid)
            temp[k++] = arr[i++];
        while(j<=right)
            temp[k++] = arr[j++];
            
            
        k=0;
        for(ll i=left;i<=right;i++)
            arr[i] = temp[k++];
    }
    
    void mergeSort(ll arr[],ll left,ll right)
    {
        if(left >= right)
            return;
        
        ll mid = left + (right-left)/2;
        
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid+1,right);
    }
    
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr,0,N-1);
        return cnt;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends