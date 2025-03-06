class Solution {
    public:
        bool checkPowersOfThree(int n) {
            //we have to check if distinct powers of 3 when summed up can 
            //represent given value of n or not 
            //to check we can check for all possible answers
            //we have as they are limited another way to view is that 
            //if we consider case of divisibilty by 2 we can ignore those cases
            //and pass only if all give 1 or 0 as remainder as if at any pt 
            //we get 2 remainder then not possible
            while(n>0){
                if(n%3==2) return false;
                n/=3;
            } 
            return true;
    
        }
    };

//App- Using base-3 representation and checking for remainders of 2
//SC- O(1) as we use constant space regardless of input
//TC- O(log n) as we divide n by 3 repeatedly