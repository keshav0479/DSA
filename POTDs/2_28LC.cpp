class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            //ans is string which has both str1 and str2 as subseq and is 
            //smallest ,unique chars if like one is abc and other is def
            //so shortest common superseq will be like abcdef which is 
            //len1+len2 size 
            //order does matter in subseq , we will first find longest common 
            //subsequence b/w both strings then we will use that to find 
            //scs ,will be using bottom up approach to solve
            int m=str1.size();
            int n=str2.size();
            string ans="";
            vector<vector<int>>t(m+1,vector<int>(n+1));
    
            for(int i=0;i<m+1;i++){
                for(int j=0;j<n+1;j++){
                    if(i==0 || j==0) t[i][j]=i+j;
                    else if(str1[i-1]==str2[j-1]) t[i][j]=1+t[i-1][j-1];
                    else t[i][j]=1+min(t[i-1][j],t[i][j-1]);
                }
            }
            int i=m,j=n;
            while(i>0 && j>0){
                if(str1[i-1]==str2[j-1]){
                    ans.push_back(str1[i-1]);
                    i--;
                    j--;
                }
                else{
                    if(t[i-1][j]<t[i][j-1]){
                        ans.push_back(str1[i-1]);
                        i--;
                    }
                    else{
                        ans.push_back(str2[j-1]);
                        j--;
                    }
                }
            }
            while(i>0){
                ans.push_back(str1[i-1]);
                i--;
            }
            while(j>0){
                ans.push_back(str2[j-1]);
                j--;
            }
    
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };

//App- Using dynamic programming to find shortest common supersequence
//SC- O(m*n) for the DP table where m and n are string lengths
//TC- O(m*n) for filling DP table and reconstructing the answer
