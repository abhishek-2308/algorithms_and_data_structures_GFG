class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        // code here
        int d= b*b - 4*a*c;
        if(d<0)return {-1};
        double r1= (-b + sqrt(d))/(2.0 *a);
        double r2= (-b - sqrt(d))/(2.0 *a);
        int root1= floor(r1);
        int root2= floor(r2);
        if(root1>=root2){
            return {root1, root2};
        }
        return {root2, root1};
    }
};