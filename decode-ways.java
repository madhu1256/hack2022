class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        int dp[] = new int[n];
        if(s.charAt(0) != '0'){
            dp[0] = 1;
        }else dp[0] =0;
        
        for(int i=1; i<n; i++){
            char fch = s.charAt(i-1);
            char sch = s.charAt(i);
            if(fch == '0' && sch =='0'){
                dp[i] = 0;
                
            }else if(fch == '0' && sch !='0'){
                dp[i] = dp[i-1]; 
                    
            }else if(fch != '0' && sch =='0'){
                if(fch =='1' || fch =='2'){
                    dp[i] = (i>=2?dp[i-2]:1);
                }else {
                    dp[i] = 0;
                }
                
            }else {
                if(Integer.parseInt(s.substring(i-1, i+1)) <=26 ){
                    dp[i] = dp[i-1] + (i>=2?dp[i-2]:1);
                }else {
                    dp[i] = dp[i-1];
                }
            }
        }
        return dp[n-1];
    }
}
