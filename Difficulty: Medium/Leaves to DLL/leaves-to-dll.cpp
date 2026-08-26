/* Binary Tree Node Structure
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

//  Approach 1 not Optimal but works....
class Solution {
	private:
	Node* remove_leve_nodes(Node* root, vector<Node*> &vec) {
		if (!root) {
			return nullptr;
		}
		if (!root->left and !root->right) {
			vec.push_back(root);
			return nullptr;
		}
		root->left = remove_leve_nodes(root->left, vec);
		root->right = remove_leve_nodes(root->right, vec);
		return root;
	}
	public:
	Node* convertToDLL(Node* root) {
		// code here
		vector<Node*> vec;
		Node* real_root = remove_leve_nodes(root, vec);
		if (vec.empty()) {
			return real_root;
		}
		
		vec[0]->left = nullptr;
		
		for (int i = 1; i < vec.size(); i++) {
			vec[i]->left = vec[i - 1];
			vec[i - 1]->right = vec[i];
		}
		
		vec.back()->right = nullptr;
		
		return vec[0];
	}
};



//  Optimal Expected Approach..
/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
       data = val;
       left = right = nullptr;
    }
};
*/
class Solution {
    private:
    Node* prev= nullptr;
    Node* head= nullptr;
  public:
  Node* get_DLL(Node* root){
      if(!root){
          return nullptr;
      }
      if(!root->left and !root->right){
          if(!head){
              head= root;
          }
          if(prev){
              prev->right= root;
              root->left= prev;
          }
          prev= root;
          return nullptr;
      }
     root->left= get_DLL(root->left);
     root->right= get_DLL(root->right);
     return root;
  }
    Node* convertToDLL(Node* root) {
        // code here
        get_DLL(root);
        if(prev){
            prev->right = nullptr;
        }
        return head;
    }
};
