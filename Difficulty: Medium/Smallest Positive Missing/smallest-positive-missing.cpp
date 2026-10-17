class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int i=0;
        while(i< arr.size()){
            if(arr[i]<=INT_MIN){
                i++;
                continue;
            }
            int index= arr[i]-1;
            if(index < arr.size() and index >=0 and index<INT_MAX and arr[index] != arr[i]){
                swap(arr[index], arr[i]);
            }
            else{
                i+=1;
            }
        }
        for(int i=0; i<arr.size(); i++){
            if(arr[i] != i+1){
                return i+1;
            }
        }
        return (int)arr.size()+1;
    }
};