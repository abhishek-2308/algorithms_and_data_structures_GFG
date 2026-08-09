

class Solution {
    private:
    int ans(int a, int b){
    //  if(a==b)return a;
    if(a==0)return b;
    if(b==0)return a;
     return ans(b, a%b);
    }
  public:
    int gcd(int a, int b) {
       return ans(a, b);
       
    }
};


