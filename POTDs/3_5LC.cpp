class Solution {
    public:
        long long coloredCells(int n) {
            //1 then 1+4=5 then 1+4+8=13 then 1+4+8+12=25 so on
            //   4            8            12           16       ......
            return 1+ (long long)n*(n-1)*2;
        }
    };

//App- Using  formula to find the pattern of colored cells growth
//SC- O(1) as we only use variables regardless of input size
//TC- O(1) 