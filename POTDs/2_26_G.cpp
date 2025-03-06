class Solution {
    public:
      vector<int> maxOfMins(vector<int>& arr) {
          //we will use same max sliding window approach that will help us 
          //make in monotonic order this is brute now we will go for optimal
          // int n=arr.size();
          // vector<int>ans(n,0);
          // for(int k=1;k<=n;k++){
          //     deque<int>dq;
          //     vector<int>minvals;
          //     for(int i=0;i<n;i++){
          //         while(!dq.empty() && dq.front()<=i-k){
          //             dq.pop_front();
          //         }
              
          //         while(!dq.empty() && arr[i]<=arr[dq.back()]){
          //             dq.pop_back();
          //         }
          //         dq.push_back(i);
              
          //         if(i>=k-1){
          //             minvals.push_back(arr[dq.front()]);
          //         }
          //     }
          //     ans[k-1]=*max_element(minvals.begin(),minvals.end());
          // }
          // return ans;
          
          //optimal
           int n = arr.size();
          vector<int> ans(n, 0); 
          vector<int> prev(n, -1), next(n, n); 
  
          stack<int> st;
  
          for (int i = 0; i < n; i++) {
              while (!st.empty() && arr[st.top()] >= arr[i]) {
                  st.pop();
              }
              if (!st.empty()) prev[i] = st.top();
              st.push(i);
          }
  
          while (!st.empty()) st.pop(); 
  
          for (int i = n - 1; i >= 0; i--) {
              while (!st.empty() && arr[st.top()] >= arr[i]) {
                  st.pop();
              }
              if (!st.empty()) next[i] = st.top();
              st.push(i);
          }
  
          vector<int> maxMin(n + 1, 0);
          for (int i = 0; i < n; i++) {
              int len = next[i] - prev[i] - 1;  
              maxMin[len] = max(maxMin[len], arr[i]); 
          }
  
          for (int k = n - 1; k >= 1; k--) {
              maxMin[k] = max(maxMin[k], maxMin[k + 1]);
          }
  
          for (int k = 1; k <= n; k++) {
              ans[k - 1] = maxMin[k];
          }
  
          return ans;
      }
  };

  
//App- Using nearest smaller element concept. For each element, find the largest window where it's the minimum, 
//     then track the maximum of minimums for each window size k.
//TC- O(n) where n is the size of the input array, as we do three linear passes through the array.
//SC- O(n) for storing prev, next, maxMin arrays and the stack.