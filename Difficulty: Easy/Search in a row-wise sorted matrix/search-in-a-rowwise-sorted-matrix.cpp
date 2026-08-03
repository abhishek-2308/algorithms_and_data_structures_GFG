

class Solution {
    private:
    bool binary_serch(vector<int> &mat, int &tar){
        int s= 0;
        int e= mat.size()-1;
        while(s<=e){
            int mid= s+(e-s)/2;
            if(mat[mid]==tar)return 1;
            else if(mat[mid]>tar){
                e= mid-1;
            }
            else{
                 s= mid+1;
            }
        }
        return false;
    }
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
     for(int i=0; i<mat.size(); i++){
         if(binary_serch(mat[i], x))return 1;
         
     }   
     return false;
    }
};