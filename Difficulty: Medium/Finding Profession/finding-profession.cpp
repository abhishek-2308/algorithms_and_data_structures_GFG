// Approach1
class Node{
    public:
    char child;
    Node* left;
    Node* right;
    Node(char child){
       this->child= child;
       left= nullptr;
       right= nullptr;
    }
};
class Solution {
  public:
    string profession(int level, int pos) {
          // code here
        queue<pair<Node*, pair<int, int>>> q;
        Node* node= new Node('E');
        q.push(make_pair(node, make_pair(1, 1)));
        char ans;
        while(!q.empty()){
            int size= q.size();
            int count=0;
            bool flag= false;
            while(size--){
            pair<Node*, pair<int , int>> front= q.front();
            q.pop();
            Node* node= front.first;
            int lev= front.second.first;
            int posi= front.second.second;
            if(lev==level and pos==posi){
                ans= node->child;
                flag= true;
                break;
            }
            if(node->child=='E'){
                count++;
                Node* temp= new Node('E');
                node->left= temp;
                // q.push(make_pair(temp, make_pair(lev+1, count))));
                q.push(make_pair(temp, make_pair(lev+1, count)));
                
                count++;
                temp= new Node('D');
                node->right= temp;
                // q.push(make_pair(temp, make_pair(lev+1, make_pair(count))));
                q.push(make_pair(temp, make_pair(lev+1, count)));
                
            }
            else if(node->child=='D'){
                 count++;
                Node* temp= new Node('D');
                node->left= temp;
                // q.push(make_pair(temp, make_pair(lev+1, make_pair(count))));
                q.push(make_pair(temp, make_pair(lev+1, count)));
                
                count++;
                temp= new Node('E');
                node->right= temp;
                // q.push(make_pair(temp, make_pair(lev+1, make_pair(count))));
                q.push(make_pair(temp, make_pair(lev+1, count)));
            }
            }
            if(flag)break;
        }
        return ans=='D' ? "Doctor" : "Engineer";
    }
};



// Approqach 2 Optimal

class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        int change= __builtin_popcount(pos-1);
        if(change & 1){
            return "Doctor";
        }
        return "Engineer";
    }
};
