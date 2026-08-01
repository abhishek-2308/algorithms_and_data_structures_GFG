/*
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	
	Node(int x) {
		data = x;
		left = right = NULL;
	}
};
*/

class Solution {
	public:
	int maxGCD(Node* root) {
		if (!root)
			return 0;
		
		queue<Node*> q;
		q.push(root);
		
		int maxGcd = 0;
		int ans = 0;
		
		while (!q.empty()) {
			Node* front = q.front();
			q.pop();
			
			if (front->left)
				q.push(front->left);
			
			if (front->right)
				q.push(front->right);
			
			if (front->left && front->right) {
				int g = __gcd(front->left->data, front->right->data);
				
				if (g > maxGcd) {
					maxGcd = g;
					ans = front->data;
				}
				else if (g == maxGcd) {
					ans = max(ans, front->data);
				}
			}
		}
		
		return ans;
	}
};
