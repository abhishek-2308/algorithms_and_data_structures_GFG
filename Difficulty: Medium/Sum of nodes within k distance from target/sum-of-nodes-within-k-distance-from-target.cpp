/*
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};
*/

class Solution {
	private:
	unordered_map<Node*, Node*> parent;
	
	unordered_map<Node*, bool> visited;
	
	Node* target_node = nullptr;
	
	void connect_parent(Node* root, int &target) {
		queue<Node*> q;
		q.push(root);
		parent[root] = nullptr;
		while (!q.empty()) {
			Node* curr = q.front();
			q.pop();
			if (curr->data == target) {
				target_node = curr;
			}
			if (curr->left) {
				q.push(curr->left);
				parent[curr->left] = curr;
			}
			if (curr->right) {
				q.push(curr->right);
				parent[curr->right] = curr;
			}
			
		}
	}
	public:
	int kDistSum(Node* root, int target, int k) {
		// code here
		connect_parent(root, target);
		queue<Node*> q;
		q.push(target_node);
		
		visited[target_node] = 1;
		int sum = 0;
		int dis = 0;
		while (!q.empty() and dis <= k) {
			int size = q.size();
			
			while (size--) {
				Node* front = q.front();
				sum += front->data;
				q.pop();
				if (front->left and !visited[front->left]) {
					visited[front->left] = true, q.push(front->left);
					
				}
				if (front->right and !visited[front->right]) {
					q.push(front->right), visited[front->right] = true;
				}
				if (parent[front] and !visited[parent[front]]) {
					q.push(parent[front]), visited[parent[front]] = true;
				}
				
			}
			dis++;
		}
		return sum;
		
	}
};
