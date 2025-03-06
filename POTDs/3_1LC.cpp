class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            //we have to n-1 ops if equal nums[i]==nums[i+1] nums[i]*2 and 
            //nums[i+1] becomes 0 or otherwise we skip op
            int n=nums.size();
            for(int i=0;i<n;i++){
                if(i+1<n && nums[i]==nums[i+1]){
                    nums[i]*=2;
                    nums[i+1]=0;
                }
            }
            //now in 1 pass we move all zeroes to end 
            int k=0;
            for(int i=0;i<n;i++){
                if(nums[i]!=0){
                    swap(nums[i],nums[k]);
                    k++;
                }
            }
            return nums;
        }
    };

//App- Using two passes: first to apply operations, second to move zeros to end
//SC- O(1) as we modify the array in-place
//TC- O(n) for two passes through the array