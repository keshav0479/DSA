class Solution {
    public:
      string decodedString(string &s) {
          //we will start opening from inside eg:
          //3[b2[ca]] in this first we open 2 ca --caca then bcaca is there which
          //will be repeated 3 times bcacabcacabcaca  
          //so brute will be opening like that ,we will use backtracking to 
          //open from inside out 
          int i=0;
          return backtrack(s,i);
      }
      string backtrack(string&s,int &i){
          string ans="";
          while(i<s.size() && s[i]!=']'){
              if(isdigit(s[i])){
                  int num=0;
                  
                  while(i<s.size() && isdigit(s[i])){
                      num=num*10+s[i]-'0';
                      i++;
                  }
                  i++;
                  
                  string part=backtrack(s,i);
                  
                  while(num--) ans+=part;
                  
                  i++;
              }
              else{
                  ans+=s[i];
                  i++;
              }
          }
          return ans;
      }
  };

//App- Using backtracking to decode nested strings with repetition counts
//TC- O(n * k) where n is string length and k is maximum repetition value
//SC- O(n) for recursion stack and result string
