void get_min(stack<int> &s, int &mini){
    if(s.empty())return;
    int top= s.top();
    mini= min(mini, top);
    s.pop();
    get_min(s, mini);
    s.push(top);
}
void push(stack<int>& s, int a) {
    // Your code goes here
    s.push(a);
    
    return;
}

bool isFull(stack<int>& s, int n) {
    // Your code goes here
    return s.size()==n;
}

bool isEmpty(stack<int>& s) {
    // Your code goes here
    return s.empty();
}

int pop(stack<int>& s) {
    // Your code goes here
    if(!s.empty()){
        int top= s.top();
        s.pop();
        return top;
    }
}

int getMin(stack<int>& s) {
    int mini=INT_MAX;
get_min(s, mini);
return mini;

}