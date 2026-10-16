class Solution {
  public:
    int digitsInFactorial(int n) {
        // code here
        double sum=0.0;
        for(int i=2; i<=n; i+=1){
            sum+= log10(i);
        }
    
        return (int) sum+1;
    }
    
};