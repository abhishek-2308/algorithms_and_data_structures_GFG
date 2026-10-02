class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        while(a != b){
            if(a < b){
                b= b-a;
            }
            else{
                a= a-b;
            }
        }
        return a;
    }
};
