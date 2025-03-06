class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            //to maintain relative order we will use two ptr swap
            //less ptr from st and more ptr from end 
            int n=nums.size();
            vector<int>ans(n);
            int less=0;
            int more=n-1;
            for(int i=0,j=n-1;i<n;i++,j--){
                if(nums[i]<pivot){
                    ans[less]=nums[i];
                    less++;
                }
                if(nums[j]>pivot){
                    ans[more]=nums[j];
                    more--;
                }
            }
            while(less<=more){
                ans[less]=pivot;
                less++;
            }
            return ans;
        }
    };

//App- Using two-pointer technique to partition array around pivot and maintain order
//SC- O(n) for creating result array
//TC- O(n) for single pass through array