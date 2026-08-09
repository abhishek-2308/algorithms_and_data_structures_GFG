class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        vector<vector<int>> vec(parent.size());
        vector<int> depth(nums.size());
        for(int i=1; i<parent.size(); i++){
            vec[parent[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        depth[0]=1;
        int height= 1;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto i : vec[node]){
                depth[i]= depth[node] +1;
                height= max(height, depth[i]);
                q.push(i);
            }
        }
        long long answer=0;
        for(int i=0; i<nums.size(); i++){
            answer= answer + 1LL *nums[i]* (height- depth[i] +1);
        }
        return answer;
        
    }
};