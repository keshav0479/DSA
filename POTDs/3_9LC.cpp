class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            //alternating is when color is different from left and right 
            //here instead of group of 3 we are provided with k length contigous
            //here we will check for each window of k size if it satisfies then 
            //we add that group to cnt ,also previously we pushed 
            //2 at end as k was 3 there ,but here k can go till size of arr
            //therefore we add k-1 at end to make cyclic 
            for(int i=0;i<k-1;i++){
                colors.push_back(colors[i]);
            }
            int n=colors.size();
            int cnt=0;
            int st=0,end=1;
    
            while(end<n){
                //if adjacent same we can't continue
                if(colors[end]==colors[end-1]){
                    st=end;
                    end++;
                    continue;
                }
                end++;
                if(end-st<k) continue;
    
                cnt++;
                st++;
            }
            return cnt;
        }
    };

// AP- sliding window approach to check for alternating groups of length `k`.
// TC- O(n),n is the size of the array after adding k-1 elements. The loop iterates through the array once.
// SC- O(k), as we append k-1 elements to the array temporarily.