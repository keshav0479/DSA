class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            //fibonacci like is when prev 2 values add up to give next val 
            //we have to return length of longest such subsequence 
            //by default min length is any exist should be 3 as fibonacci can be
            //formed by using two prev vals and one their sum val
            int n=arr.size();
            unordered_map<int,int>mp;
            int maxlen=0;
            for(int i=0;i<n;i++) mp[arr[i]]=i;
    
            for(int i=1;i<n;i++){
                for(int j=0;j<i;j++){
                    int prev1=arr[j];
                    int prev2=arr[i];
                    int len=2;
                    
                    while(mp.find(prev1+prev2)!=mp.end()){
                        int sum=prev1+prev2;
                        prev1=prev2;
                        prev2=sum;
                        len++;
                    }
                    
                    maxlen=max(maxlen,len);            
                }
            }
            return maxlen>=3 ? maxlen:0;
            
        }
    };

//App- Using hashmap to track potential Fib sequences starting from every pair
//SC- O(n) for storing array elements in the hashmap
//TC- O(n^2*log(max)) where max is the largest possible Fibonacci value