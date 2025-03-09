

class Solution {
    public:
      int x[1001][1001];
      bool ispal(int st,int end,string& s){
          if(st>=end) return true;
          
          if(x[st][end]!=-1) return x[st][end];
          if(s[st]==s[end]){
              return x[st][end]=ispal(st+1,end-1,s);
          }
          return x[st][end]=false;
      }
      int countPS(string &s) {
          //we have to count all palindromic substr where len>=2
          //we just start j from i+1 position as that will 
          //automatically make min len >=2
          memset(x,-1,sizeof(x));
          int n=s.size();
          int cnt=0;
          for(int i=0;i<n;i++){
              for(int j=i+1;j<n;j++){
                  cnt+=ispal(i,j,s);
              }
          }
          return cnt;
      }
  };

// AP- recursion with memoization to check if a substring is a palindrome. we iterate over all possible substr of length >= 2 using loops. For each pair we check if the substr s[i...j] is a palindrome and increments the cnt
// TC- O(n^2), n is the length of the string,loops iterate over all pairs. Each call to ispal is memoized, so each substr is processed at most once.
// SC- O(n^2), due to the DP table x of size n x n used for memoization.
