class Solution {
    private:
    void get_ans(vector<int> &arr, int maxi, int mini, int &index, int &count){
        if(index>=arr.size())return ;
        if(arr[index]<= mini or arr[index]>=maxi){
            return ;
        }
        int val= arr[index];
        index++;
        
        count++;
        get_ans(arr, val, mini,index, count);
        get_ans(arr, maxi, val,index, count); 
    }
  public:
    bool canRepresentBST(vector<int> &arr) {
        // code here
        int index= 0;
        int count=0;
        get_ans(arr,INT_MAX, INT_MIN, index, count);
        return count==(int)arr.size();
        // return 
        
    }
};