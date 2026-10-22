class Solution {
    private:
    void set_zero(vector<vector<int>> &arr, int i, int j){
        for(int k=0; k<arr[i].size(); k++){
            arr[i][k]=0;
        }
        for(int k=0; k<arr.size(); k++){
            arr[k][j]=0;
        }
        
    }
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        vector<vector<int>> arr= mat;
        for(int i=0; i<mat.size(); i+=1){
            for(int j=0; j<mat[i].size(); j+=1){
                if(mat[i][j]==0){
                    set_zero(arr,i, j);
                }
            }
        }
        mat= arr;
    }
};