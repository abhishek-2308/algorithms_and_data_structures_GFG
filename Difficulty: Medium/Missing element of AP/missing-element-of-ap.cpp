class Solution {
	public:
	int findMissing(vector<int> &arr) {
		// code here
		/* APPROACH - 1
		int n = arr.size();
		int diff = (arr[1]-arr[0]);
		for (int i = 2; i<n; i++) {
			if ((arr[i]-diff) != arr[i - 1]) {return arr[i]-diff; }
		}
		return arr[n - 1]+diff; */
		
		int n = arr.size();
		int diff = (arr[1]-arr[0]);
		for (int i = 2; i<n; i++) {
			if ((arr[i]-arr[i - 1]) != diff) {return arr[i]-diff; }
		}
		return arr[n - 1]+diff;
		
	}
};
