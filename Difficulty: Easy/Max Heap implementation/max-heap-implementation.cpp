class maxHeap {
  private:
    // Initialize your data members
    priority_queue<int> q;
  public:

    void push(int x) {
        // Insert x into the heap
        q.push(x);
    }

    void pop() {
        // Remove the top (maximum) element
        if(q.empty())return;
        q.pop();
    }

    int peek() {
        // Return the top element or -1 if empty
        if(q.empty())return -1;
        return q.top();
    }

    int size() {
        // Return the number of elements in the heap
        return q.size();
    }
};