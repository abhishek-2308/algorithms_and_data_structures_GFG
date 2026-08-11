
// APProach 1
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


// Second approach

class Solution {
	public:
	int nthRoot(int n, int m) {
		// Code here
		if (m == 0)return 0;
		int l = 1;
		int h = m;
		while (l <= h) {
			int mid = l + (h - l)/2;
			if (pow(mid, n) == m) {
				return mid;
			}
			else if (pow(mid, n) > m) {
				h = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		return - 1;
	}
};

