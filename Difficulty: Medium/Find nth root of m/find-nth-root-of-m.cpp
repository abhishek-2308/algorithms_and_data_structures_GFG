class Solution {
	public:
	int nthRoot(int n, int m) {
		// Code here
		int root = round(pow(m, 1.0 / n));
		
		if (pow(root, n) == m)
			return root;
		else
			return - 1;
	}
};
