
class Solution {
    public:
      string longestPalindrome(string &s) {
          int n=s.size();
          int st=0,maxlen=1;
          auto expand=[&](int l,int r){
              while(l>=0 && r<n && s[l]==s[r]){
                  if(r-l+1>maxlen){
                      st=l;
                      maxlen=r-l+1;
                  }
                  l--;
                  r++;
              }  
          };
          for(int i=0;i<n;i++){
              expand(i,i);//odd case handle
              expand(i,i+1);//even
          }
          return s.substr(st,maxlen);
      }
  };

// AP- expanding around center, For each char in the str, we consider it as  center of a potential palindrome and expands outward to check for both odd-len and even-len palindromes.  longest is returned
// TC- O(n^2),n is len of the str. For each character in str, we expand outward to check for palindromes, which takes O(n) time in the worst case. Since we do this for all n chars, the overall is O(n^2).
// SC- O(1), as no extra space
