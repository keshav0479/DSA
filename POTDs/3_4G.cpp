class Solution {
    public:
      int dp[1001][1001];
      int n;
      int lis(vector<int>& arr) {
          //we will use take and skip approach to solve use 
          //recursion+memoization 
          n=arr.size();
          memset(dp,-1,sizeof(dp));//setting vals as -1 can use for loop also
          return solve(arr,0,-1);
      }
      
      int solve(vector<int>&arr,int idx,int prev){
          if(idx>=n) return 0; //bounds check 
          
          if(prev!=-1 && dp[idx][prev]!=-1) return dp[idx][prev];
          
          int take=0;
          if(prev==-1 || arr[idx]>arr[prev]){
              take=1+solve(arr,idx+1,idx);
          }
          
          int skip=solve(arr,idx+1,prev);
          
          if(prev!=-1) dp[idx][prev]=max(take,skip);
          
          return max(take,skip);
      }
  };

//App- Using dynamic programming with memoization for take and skip approach for LIS
//TC- O(n^2) where n is the array size
//SC- O(n^2) for the dp array storage
