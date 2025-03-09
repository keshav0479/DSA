class Solution {
    public:
        int longestPalinSubseq(string &s) {
            int n = s.size();
            if (n == 0) return 0;
            
            vector<vector<int>> dp(n, vector<int>(n, 0));
            
            // Every single character is a palindrome of length 1
            for (int i = 0; i < n; i++) {
                dp[i][i] = 1;
            }
            
            // Fill the dp table
            for (int len = 2; len <= n; len++) {
                for (int i = 0; i <= n - len; i++) {
                    int j = i + len - 1;
                    if (s[i] == s[j] && len == 2) {
                        dp[i][j] = 2;
                    }
                    else if (s[i] == s[j]) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                    else {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
            
            return dp[0][n - 1];
        }
    };

// AP- dp to find the longest.we build a DP table `dp[i][j]` where `dp[i][j]` represents the length of the longest palindromic subsequence in the substring `s[i...j]`. The table is filled iteratively based on whether characters at indices `i` and `j` match or not.
// TC- O(n^2), n is the length of the string. The DP table has size `n x n`, and each cell is computed in constant time.
// SC- O(n^2), as we use a DP table of size `n x n` to store intermed res.