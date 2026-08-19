// This Problem was Asked in Accenture...

class Solution {
  public:
    vector<vector<int>> spiralFill(int n, int m, vector<int> &arr) {
        // code here
        vector<vector<int>> mat(n, vector<int> (m, -1));
        int startingRow=0;
        int endingRow= n-1;
        int startingCol= 0;
        int endingCol= m-1;
        int index=0;
        while(index< arr.size()){
            for(int i=startingCol; i<= endingCol and index<arr.size(); i++){
                mat[startingRow][i]= arr[index++];
            }
            startingRow++;
            for(int i= startingRow; i<= endingRow and index< arr.size(); i++){
                mat[i][endingCol]= arr[index++];
            }
            endingCol--;
            for(int i= endingCol; i>=startingCol and index< arr.size(); i--){
                mat[endingRow][i]= arr[index++];
            }
            endingRow--;
            for(int i= endingRow; i>= startingRow and index< arr.size(); i--){
                mat[i][startingCol]= arr[index++];
            }
            startingCol++;
            
        }
        return mat;
    }
};
