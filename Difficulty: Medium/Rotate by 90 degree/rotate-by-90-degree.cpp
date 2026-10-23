class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        //so  tramsopose the matrix
        for(int i=0; i<mat.size(); i+=1){
            for(int j= i+1; j<mat.size(); j+=1){
                swap(mat[i][j], mat[j][i]);
            }
        }
        //rverse
        int i=0;
        int j= mat.size()-1;
        while(i< j){
            for(int col=0; col<mat.size(); col+=1){
                swap(mat[i][col], mat[j][col]);
            }
            i+=1;
            j--;
        }
    }
};
