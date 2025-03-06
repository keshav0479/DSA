class Solution {
    int mini;
    stack<int>st;
  public:
    Solution() {
        mini=INT_MAX;
    }

    // Add an element to the top of Stack
    void push(int x) {
       if(st.empty()){
           mini=x;
           st.push(x);
       }
       else{
           if(x<mini){
               st.push(2*x-mini);
               mini=x;
           }
           else st.push(x);
       }
    }

    // Remove the top element from the Stack
    void pop() {
        if(st.empty()) return;
        int topval=st.top();
        st.pop();
        if(topval<mini) mini=2*mini-topval;
    }

    // Returns top element of the Stack
    int peek() {
        if(st.empty()) return -1;
        int topval=st.top();
        return topval<mini ? mini:topval;
    }

    // Finds minimum element of Stack
    int getMin() {
        return st.empty() ? -1:mini;
    }
};

//App- Using clever stack encoding to track minimum value without extra space
//TC- O(1) for all operations (push, pop, peek, getMin)
//SC- O(n) for the stack storage of n elements
