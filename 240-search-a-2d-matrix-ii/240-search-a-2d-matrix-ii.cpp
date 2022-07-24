class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int i = 0, j = arr[0].size() - 1;
	while (i<arr.size() and j >= 0)
	{
		int val = arr[i][j];
		if (val == target) return true;
		else if (val < target) i++;
		else j--;
	}
	return false;
    }
};