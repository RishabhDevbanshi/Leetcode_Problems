class Solution {
public:
    #define debarr2(arr) for(auto v : arr){ for(auto x : v) cout<<x<<" "; cout<<endl; }
    #define loop(i, k, n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)

    void rotate(vector<vector<int>>& arr) {
        loop(i, 0, arr.size())
	{
		loop(j, i, arr.size())
		swap(arr[i][j], arr[j][i]);
	}

	loop(i, 0, arr.size())
	{
		int start_col = 0;
		int end_col  = arr.size() - 1;
		while (start_col < end_col)
		{
			swap(arr[i][start_col] , arr[i][end_col]);
			start_col++; end_col--;
		}
	}


	debarr2(arr);
    }
};