class Solution {
  public:
    int noOfDigits(int n) {
        // Binet's formula + logarithms..
        // Formulae-> Fn= phi ^ n/ sqrt(5)
        //where phi= (1+sqrt(5))/2;
        // i.e dig(Fn)= [nlog10 (phi)- log10(sqrt(5))]+1;
        // for n>=2
        if(n<=1)return 1;
        long double phi= (1.0L+sqrt(5.0L))/2.0L;
        long double digit= n*log10l(phi)-log10l(sqrtl(5.0L));
        return (int)floorl(digit)+1;
        
        
    }
};