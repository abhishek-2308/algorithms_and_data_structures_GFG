class Solution {
  public:
    int findMin(int N) {
        // code here
        vector<int> coins= {10, 5,2,1};
        int  i=0;
   int size=0;
        while(N){
            int coinN= coins[i];
            if(N>=coins[i]){
              size++;
                // ans.push_back(coins[i]);
                N= N-coinN;
            }
            else{
                while(N<coins[i]){
                    i++;
                }
                // ans.push_back(i);
                size++;
                N= N-coins[i];
            }
        }
        return size;
    }
};