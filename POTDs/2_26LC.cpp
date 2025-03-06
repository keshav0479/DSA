class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            //we will use kadane to calc max and minsum as whatever
            //is greater from both will be ans as later on abs is asked 
            //as it doesn't matter whether -ve or +ve 
            int n=nums.size();
            int maxsum=0,cursum1=0,minsum=0,cursum2=0;
            for(int i=0;i<n;i++){
                cursum1+=nums[i];
                cursum2+=nums[i];
                if(cursum1<0) cursum1=0;
                if(cursum2>0) cursum2=0;
    
                maxsum=max(cursum1,maxsum);
                minsum=min(cursum2,minsum);
           }
            return max(abs(maxsum),abs(minsum));
        }
    };

//App- Using modified Kadane's algorithm to find both maximum and minimum subarrays
//SC- O(1) using only variables regardless of input size
//TC- O(n) for single pass through the array