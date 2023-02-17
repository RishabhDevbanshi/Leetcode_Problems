//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int N, int M, string arr){
        int ans=0;

        int s=0;

        int e=0;

        int c=0;

        int m=M;

        while(e<N)

        {

            if(arr[e]=='A')

            {c++;e++;}

            else if(m!=0)

            {

                m--;

                c++;

                e++;

            }

            else

            {   

                if(arr[s]=='O')

                {

                    s++;c--;m++;

                    continue;

                }

                ans=max(c,ans);

                while(arr[s]!='O' && s<e)

                {

                    s++;

                    c--;

                    

                }

           }

     }

        return max(c,ans);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends