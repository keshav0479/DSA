class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<int> sievearr = sieve(right);
    
            vector<int> primeNums;
            for (int num = left; num <= right; num++) {
                if (sievearr[num] == 1) {
                    primeNums.push_back(num);
                }
            }
    
            if (primeNums.size() < 2)
                return {-1, -1};
    
            int minDiff = INT_MAX;
            vector<int> closestPair(2, -1);
    
            for (int idx = 1; idx < primeNums.size(); idx++) {
                int diff = primeNums[idx]- primeNums[idx-1];
                if (diff < minDiff) {
                    minDiff = diff;
                    closestPair[0] = primeNums[idx - 1];
                    closestPair[1] = primeNums[idx];
                }
            }
    
            return closestPair;
        }
    
        vector<int> sieve(int right) {
            vector<int> sieve(right+1,1);
            sieve[0] = 0;
            sieve[1] = 0;
    
            for (int num = 2; num * num <= right; num++) {
                if (sieve[num] == 1) {
                   
                    for (int j = num * num; j<= right;j+= num) {
                        sieve[j] = 0;
                    }
                }
            }
            return sieve;
        }
    };

// AP- Sieve of Eratosthenes to generate all prime numbers till`right. Then, it filters out the primes in the range `[left, right]`. After collecting these primes, it finds the pair of primes with the smallest difference by iterating through the list of primes.
// TC-
// 1:Generating the sieve takes O(n log(log(n))), where `n` is `right`.  
// 2:Filtering primes in the range `[left, right]` takes O(n).  
// 3:Finding the closest pair of primes takes O(p), where `p` is the number of primes in `[left, right]`.  
// Overall: O(n log(log(n))) + O(n) + O(p). For large ranges, this simplifies to O(n log(log(n))).
// SC- O(n), where `n` is `right`, due to the space used by the sieve arr.