class Solution {
    private:
    const int mod= 1e9+7;
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
    priority_queue<int> pq;
    for(int i=0; i<arr.size(); i++){
        pq.push(arr[i]);
    }
    long long ans= 0;
    while(k-- and !pq.empty()){
        int top= pq.top();
        pq.pop();
        // ans= (ans+ top) %mod;
        ans = (ans + top) % mod;
        int left_tic= top-1;
        if(left_tic>0)
        pq.push(left_tic);
    }
    return (int) ans;
    
    }
};