class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l = s1.length();
        int m = s2.length();
        int n = s3.length();
        if(l + m != n)
            return false;
        int ans[l+1][m+1];
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i <= l; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 && j == 0)
                    ans[i][j] = 1;
                else if(i == 0){
                    if(s2[j-1] == s3[j-1])
                        ans[i][j] = ans[i][j-1];
                }                
                else if(j == 0){
                    if(s1[i-1] == s3[i-1])
                        ans[i][j] = ans[i-1][j];
                }
                else if(s1[i-1] == s3[i+j-1] && s2[j-1] != s3[i+j-1])
                    ans[i][j] = ans[i-1][j];
                else if(s2[j-1] == s3[i+j-1] && s1[i-1] != s3[i+j-1])
                    ans[i][j] = ans[i][j-1];
                else if(s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1])
                    ans[i][j] = ans[i-1][j] || ans[i][j-1];
            }
        }
        return (bool)ans[l][m];
    }
};
