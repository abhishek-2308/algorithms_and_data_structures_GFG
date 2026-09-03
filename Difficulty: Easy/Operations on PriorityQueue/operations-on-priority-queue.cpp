class Solution {
  public:
  
    // Function to insert k into the priority queue q
    static void insert(priority_queue<int>& q, int k) {
        // code here
        q.push(k);
    }

    // Function to find an element k
    static bool find(priority_queue<int>& q, int k) {
        // code here
        // int ans=-1;
        
     vector<int> temp;

         while (!q.empty()) {
             int x = q.top();
             q.pop();

             if (x == k) {
                 for (int val : temp)
                     q.push(val);

                 q.push(x);

                 return true;
             }

             temp.push_back(x);
         }
         for (int val : temp)
             q.push(val);

         return false;
     }

    // Function to delete the max element from priority queue
    static int deleteValue(priority_queue<int>& q) {
        // code here
        if(!q.empty()){
            int top= q.top();
            q.pop();
            return top;
        }
        return -1;
        
    }
};