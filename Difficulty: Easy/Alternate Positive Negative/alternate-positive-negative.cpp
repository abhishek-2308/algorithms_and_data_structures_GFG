class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int> v1, v2;
        for(auto i: arr){
            if(i>=0){
                v1.push_back(i);
            }
            else{
                v2.push_back(i);
            }
        }
        int i=0;
        int j=0;
        bool is_flag= true;
        int k=0;
        while(i< v1.size() and j< v2.size()){
            if(is_flag){
                arr[k++]= v1[i++];
            }
            else{
                arr[k++]= v2[j++];
            }
            is_flag= !is_flag;
        }
        while(i< v1.size()){
            arr[k++]= v1[i++];
        }
        while(j < v2.size()){
            arr[k++]= v2[j++];
        }
    
    }
};