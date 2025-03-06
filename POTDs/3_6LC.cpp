class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            //wehave to tell repeating first then missing this format 
            //a arr ,we store all vals and check is map 
            //which doesn't map or freq=0 and which has freq of 2 
            unordered_map<int,int>frq;
            int n=grid.size();
            int miss=-1,rep=-1;
            for(auto &i:grid){
                for(auto &j:i){
                    frq[j]++;
                }
            }
            for(int i=1;i<=n*n;i++){
                if(!frq.count(i)) miss=i;
                else if(frq[i]==2) rep=i;
            }
            return {rep,miss};
        }
    };

//App- Using hashmap to count occurrences, finding the repeated value (freq=2) and missing value (freq=0)
//SC- O(n^2) for storing n^2 elements in the hashmap
//TC- O(n^2) for iterating through the grid and checking values 1 to n*n