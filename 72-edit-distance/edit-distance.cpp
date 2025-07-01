class Solution {
public:
//bottom up approach
    int minDistance(string word1, string word2) {
        int len1=word1.length();
        int len2=word2.length();
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,-1));
        for(int j=0;j<=len2;j++){
            dp[len1][j]=len2-j;
        }
        for(int i=0;i<=len1;i++){
            dp[i][len2]=len1-i;
        }
        for(int i=len1-1;i>=0;i--){
            for(int j=len2-1;j>=0;j--){
                    int ans;
                if(word1[i]==word2[j]){
                    ans=dp[i+1][j+1];
                }else{
                //if not matches then three operations
                int insert=1+dp[i][j+1];
                int delet=1+dp[i+1][j];
                int replace=1+dp[i+1][j+1];
                ans=min(insert,min(delet,replace));
                }
            dp[i][j]=ans; 
            }
        }
        return dp[0][0];
    }
};