class Solution {
	private:
	bool isPrime(int n) {
		if (n <= 1)
			return false;
		if (n <= 3)
			return true;
		if (n % 2 == 0 || n % 3 == 0)
			return false;
		
		for (int i = 5; i * i <= n; i += 6) {
			if (n % i == 0 || n % (i + 2) == 0) {
				return false;
			}
		}
		return true;
	}
	public:
	int minStep(int num1, int num2) {
		// code here
		queue<pair<int, int>> q;
		q.push(make_pair(num1, 0));
		vector<long long> vis(100000, 0);
		vis[num1] = 1;
		while (!q.empty()) {
			pair<int, int> top = q.front();
			q.pop();
			int node = top.first;
			int steps = top.second;
		    if(node== num2){
		        return steps;
		    }
		    string str= to_string(node);
		    for(int i=0; i<4; i+=1){
		        char original= str[i];
		        for(char ch= '0'; ch<='9'; ch+=1){
		            if(i==0 and ch=='0'){
		                continue;
		            }
		            if(ch==original){
		                continue;
		            }
		            str[i]= ch;
		            int new_num= stoi(str);
		            if(!vis[new_num] and isPrime(new_num)){
		                q.push(make_pair(new_num, steps+1));
		                vis[new_num]=1;
		            }
		        }
		        str[i]= original;
		    }
			
		}
		return -1;
		
	}
};
