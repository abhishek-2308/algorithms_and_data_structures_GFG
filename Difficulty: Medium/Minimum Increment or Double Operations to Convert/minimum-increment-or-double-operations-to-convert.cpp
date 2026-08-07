class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        int incremenet_one=0;
        int double_the_ele= 0;
        for(int &i : arr){
            int double_operation=0;
            while(i>0){
                if(i & 1){
                    incremenet_one++;
                    i--;
                    
                }
                else{
                    double_operation++;
                    i= i/2;
                    
                }
            }
            double_the_ele= max(double_the_ele, double_operation);
            
        }
        return double_the_ele+ incremenet_one;
        
    }
};