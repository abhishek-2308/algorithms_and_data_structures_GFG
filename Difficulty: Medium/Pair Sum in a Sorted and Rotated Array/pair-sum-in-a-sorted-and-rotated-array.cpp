class Solution {
public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        int n = arr.size();

        int pivot = 0;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                pivot = i + 1;
                break;
            }
        }

        int l = pivot;
        int r = (pivot - 1 + n) % n;

        while (l != r) {
            int sum = arr[l] + arr[r];

            if (sum == target)
                return true;

            if (sum < target)
                l = (l + 1) % n;
            else
                r = (r - 1 + n) % n;
        }

        return false;
    }
};