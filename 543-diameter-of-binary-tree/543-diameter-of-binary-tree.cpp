#define height first
#define diameter second
#define getpair pair<int,int>

class Solution {
private:
	getpair diameterOfBinaryTreehelper(TreeNode *root) {
		if (!root) {
			getpair ans;
			ans.height = 0;
			ans.diameter = 0;
			return ans;
		}

		getpair leftAns = diameterOfBinaryTreehelper(root->left);
		getpair RightAns = diameterOfBinaryTreehelper(root->right);

		int leftDiameter = leftAns.diameter;
		int leftHeight = leftAns.height;
		int RightDiameter = RightAns.diameter;
		int RightHeight = RightAns.height;

		int finalHeight = 1 + max(leftHeight, RightHeight);
		int finalDiameter = max(leftHeight + RightHeight, max(leftDiameter, RightDiameter));

		getpair finalAns;
		finalAns.height = finalHeight;
		finalAns.diameter = finalDiameter;

		return finalAns;
	}

public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (!root)
			return 0;
		return diameterOfBinaryTreehelper(root).diameter;
	}
};