class Solution {
    public:
      int evaluate(vector<string>& arr) {
          // code here
          stack<int> st;
          int n = arr.size();
          
          for(int i = 0;i<n;i++){
              if((arr[i] != "+") && (arr[i] != "-") && (arr[i] != "*") && (arr[i] != "/")){
                  st.push(stoi(arr[i]));
              }else{
                  int x = st.top();
                  st.pop();
                  int y = st.top();
                  st.pop();
                  
                  if(arr[i] == "+"){
                      st.push(y+x);
                  }else if(arr[i] == "-"){
                      st.push(y-x);
                  }else if(arr[i] == "*"){
                      st.push(y*x);
                  }else{
                      st.push(y/x);
                  }
              }
          }
          
          return st.top();
      }
  };
  
  
//App- Using stack to evaluate postfix expression by processing operators and operands
//TC- O(n) where n is the number of tokens in the expression
//SC- O(n) for the stack storage
