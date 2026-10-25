class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int ele;
        int count=0;
        for(int i=0; i<arr.size(); i+=1){
            if(count==0){
                count=1;
                ele= arr[i];
            }
            else if(arr[i]== ele){
                count++;
            }
            else{
                count--;
            }
        }
        count=0;
        for(auto i: arr){
            if(ele== i){
                count+=1;
            }
        }
        // if(count > (int)arr.size()/2)return ele; r
        return count > (int) arr.size()/2 ? ele : -1;
    }
};