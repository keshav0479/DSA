class Solution {
    public:
        string originalDigits(string s) {
            vector<string>words={"zero","one","two","three","four", "five", "six", "seven", "eight", "nine"};
        
            vector<int> freq(26, 0);
            for(char c : s)  freq[c - 'a']++;
            vector<int> digits(10, 0);
    
            //unique letters
            if(freq['z' - 'a'] > 0) { // zero has 'z'
                int count = freq['z' - 'a'];
                digits[0] = count;
                subWord(freq, words[0], count);
            }
            if(freq['w' - 'a'] > 0) { // two has 'w'
                int count = freq['w' - 'a'];
                digits[2] = count;
                subWord(freq, words[2], count);
            }
            if(freq['u' - 'a'] > 0) { // four has 'u'
                int count = freq['u' - 'a'];
                digits[4] = count;
                subWord(freq, words[4], count);
            }
            if(freq['x' - 'a'] > 0) { // six has 'x'
                int count = freq['x' - 'a'];
                digits[6] = count;
                subWord(freq, words[6], count);
            }
            if(freq['g' - 'a'] > 0) { // eight has 'g'
                int count = freq['g' - 'a'];
                digits[8] = count;
                subWord(freq, words[8], count);
            }
            
            //unique ones are removed
            if(freq['h' - 'a'] > 0) { // three has 'h' 8 removed
                int count = freq['h' - 'a'];
                digits[3] = count;
                subWord(freq, words[3], count);
            }
            if(freq['f' - 'a'] > 0) { // five has 'f' 4 removed
                int count = freq['f' - 'a'];
                digits[5] = count;
                subWord(freq, words[5], count);
            }
            if(freq['s' - 'a'] > 0) { // seven has 's' 6 removed
                int count = freq['s' - 'a'];
                digits[7] = count;
                subWord(freq, words[7], count);
            }
            if(freq['o' - 'a'] > 0) { // one has 'o' 1,2,4 rem
                int count = freq['o' - 'a'];
                digits[1] = count;
                subWord(freq, words[1], count);
            }
            if(freq['i' - 'a'] > 0) { // nine has 'i' 5,6,8 rem
                int count = freq['i' - 'a'];
                digits[9] = count;
                subWord(freq, words[9], count);
            }
        
            string ans="";
            for(int i = 0; i < 10; i++) {
                ans+= string(digits[i], '0' + i);
            }
            
            return ans;
        }
    
        void subWord(vector<int>& freq, string word, int count) {
            for(char c : word) {
                freq[c - 'a'] -= count;
            }
        }
    };
    //greedy approach doesn't work 
    
    //AP-we remove unique combs which when present points that 
    //particular word will be present ,then we check after removal
    //of unique letters which are not specific to particular words
    //and form ans
    //TC- O(n) 
    //SC- O(1)