class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int minPos= INT_MAX;
        int minNeg= INT_MAX;
        int zero= 0;
        int negitive=0;
        int product= 1;
        for(auto i: arr){
            if(i==0){
                zero++;
                continue;
            }
            product= product * i;
            if(i<0){
                negitive++;
                minNeg= min(minNeg, abs(i));
            }
            else{
               minPos= min(minPos, i); 
            }
        }
        if(negitive==0 and minPos== INT_MAX)return 0;
        else if(negitive>0){
        
            if(negitive&1) return product;
            return product / - minNeg;
        }
        if(zero>0)return 0;
        return minPos;
    }
};