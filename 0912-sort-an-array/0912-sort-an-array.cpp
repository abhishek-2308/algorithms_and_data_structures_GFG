class Solution {
private:
void merge(vector<int> &arr, int s, int e){
    int mid= s+(e-s)/2;
    int len1= mid-s+1;
    int len2= e-mid;
    int *first= new int[len1];
    int *second= new int[len2];
    int start= s;

    for(int i=0; i<len1; i+=1){
        first[i]= arr[start++];
    }
    start= mid+1;
    for(int i=0; i<len2; i+=1){
        second[i]= arr[start++];
    }
    int index1=0;
    int index2= 0;
    int arrIndex= s;
    while(index1< len1 and index2< len2){
        if(first[index1] < second[index2]){
            arr[arrIndex++]= first[index1++];
        }
        else{
            arr[arrIndex++]= second[index2++];
        }
    }
    while(index1<len1){
           arr[arrIndex++]= first[index1++];
           
    }
   while(index2<len2){
    arr[arrIndex++]= second[index2++];
           
   }
   return;
}
void merge_sort(vector<int> &arr, int s, int e){
    if(s>=e)return;
    int mid= s+(e-s)/2;
    merge_sort(arr, s, mid);
    merge_sort(arr, mid+1, e);
    merge(arr, s, e);

}
public:

    vector<int> sortArray(vector<int>& nums) {
         merge_sort(nums, 0, nums.size()-1);
         return nums;
    }
};