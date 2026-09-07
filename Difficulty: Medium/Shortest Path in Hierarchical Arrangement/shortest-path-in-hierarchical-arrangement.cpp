class Solution {
  public:
    int shortestPath(int x, int y) {
        // code here
       int ans=0;
       while(x != y){
           if(x>y){
               x= x/2;
           }
           else{
               y= y/2;
           }
           ans++;
       }
       return ans;
        
    }
};