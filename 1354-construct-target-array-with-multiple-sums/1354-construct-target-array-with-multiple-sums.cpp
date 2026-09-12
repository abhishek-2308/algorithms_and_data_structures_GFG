class Solution {
public:
    bool isPossible(vector<int>& target) {
       priority_queue<long long> pq;
       long long total_sum=0;
       for(int i : target){
        pq.push(i);
        total_sum+= i;
       }
       while(!pq.empty() and pq.top()!=1){
        long long max_ele= pq.top();
        pq.pop();
        long  long  remaining_Sum= total_sum- max_ele;
        if(remaining_Sum <=0 or remaining_Sum >=max_ele){
            return false;
        }
        long long ele= max_ele % remaining_Sum;
        if(ele==0){
            if(remaining_Sum != 1){
                return false;
            }
            else
            return 1;
        }
        total_sum= remaining_Sum + ele;
        pq.push(ele);
       }
    return 1;
    }
};