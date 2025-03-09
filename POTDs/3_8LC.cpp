class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            //we have to tell min num of recolor req to make k conseq black blocks
            //we can solve this with help of graph ,shortest path to reach 
            //final state which is having k min number of black blocks together 
            //that way we can do otherwise we can do by iteration simply 
            int n=blocks.size();
            vector<int>dis(n-k+1,0);
    
            for(int st=0;st<=n-k;st++){
                int wcnt=0;
                for(int i=st;i<st+k;i++){
                    if(blocks[i]=='W') wcnt++;
                }
                dis[st]=wcnt;
            }
            int mini=dis[0];
            for(int i=1;i<dis.size();i++){
                mini=min(mini,dis[i]);
            }
            return mini;
        }
    };

// AP- sliding a window of size `k` across the string `blocks`. For each window, we count number of blocks ('W') that need to be recolored to make all blocks in that window black ('B'), we return  min count among all wins.
// TC- O(n * k), where `n` is the length of the string and `k` is the size of the window. For each starting position of the window, we iterate through `k` eles to cnt white blocks. There are (n - k + 1) wins in total.
// SC- O(n - k + 1), as we use a vector `dis` to store the number of white blocks for each window.