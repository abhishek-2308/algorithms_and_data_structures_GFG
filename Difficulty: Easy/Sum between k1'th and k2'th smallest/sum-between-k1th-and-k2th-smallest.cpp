class Solution {
  public:
    int sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
        // code here
        priority_queue<int> pq1, pq2;
        for(int i=0; i<arr.size(); i++){
            pq1.push(arr[i]);
            pq2.push(arr[i]);
            
            if(pq1.size()>k1){
                pq1.pop();
            }
            if(pq2.size()>=k2){
                pq2.pop();
            }
        }
        int total1=0;
        int total2=0;
        while(!pq1.empty()){
            total1+=pq1.top();
            pq1.pop();
        }
        while(!pq2.empty()){
            total2+=pq2.top();
            pq2.pop();
        }
        return total2-total1;
        
    }
};