class Solution {
    public:
      int longestStringChain(vector<string>& words) {
          // Code here
           int ans=1;
          vector<unordered_set<string>> arr(11);
          unordered_map<string, int> m;
          for(auto &s:words) {
              if(s.size()==1) m[s]=1;
              arr[s.size()].insert(s);
          }
          for(int i=2;i<=10;i++) {
              for(auto &s:arr[i]) {
                  m[s]=1;
                  for(int j=0;j<s.size();j++) {
                      string ns=s.substr(0,j) + s.substr(j+1);
                      if(arr[i-1].count(ns)) m[s]=max(m[s],1+m[ns]);
                      ans=max(ans, m[s]);
                  }
              }
          }
          return ans;
      }
  };

//App- Using hashmap and sets to build string chains by removing one character at a time
//TC- O(L * n * L) where L is max string length and n is number of words
//SC- O(n) for hashmap and sets storage