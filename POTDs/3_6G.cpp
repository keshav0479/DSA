class Solution {
    public:
      int lcs(string &s1, string &s2) {
          int x=s1.length();
          int y=s2.length();
          vector<vector<int>>dp(x+1,vector<int>(y+1,0));
          for(int i=1; i<=x; i++) {
               for(int j=1; j<=y; j++) {
                    if(s1[i-1]==s2[j-1]) 
                    dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
          }
          return dp[x][y];
      }
  };

//App- Using tabulation method to find longest common subsequence with 2D DP
//SC- O(x*y) for the 2D dp array where x and y are string lengths
//TC- O(x*y) for filling the dp table