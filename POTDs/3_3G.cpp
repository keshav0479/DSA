class Solution {
    public:
      vector<int> longestSubarray(vector<int>& a, int x) {
          //we have to pick a subarr which has atmax given x diff b/w any 
          //ele of that subarr ,we have to return that subarr 
          //condn is that it should be longest 
          multiset<int> st;
          int maxi = 0, curr = 0, ind = 0;
          int j = 0, n = a.size();
  
          for (int i = 0; i < n; i++) {
              st.insert(a[i]);
              curr++;
  
              while (*st.rbegin() - *st.begin() > x) {
                  st.erase(st.find(a[j++]));
                  curr--;
              }
  
              if (curr > maxi) {
                  maxi = curr;
                  ind = i;
              }
          }
          return vector<int>(a.begin() + ind - maxi + 1, a.begin() + ind + 1);
      }
  };

//App- Using multiset for sorting and sliding window to find longest subarray with max diff ≤ x
//TC- O(n log n) due to multiset operations
//SC- O(n) for storing elements in multiset
