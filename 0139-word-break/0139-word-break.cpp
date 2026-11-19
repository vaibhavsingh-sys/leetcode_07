class Solution {
public:
    unordered_set<string> st;
    int dp[301];
    int n;
    
    bool solve(string &s, int idx) {
        
        if(idx == n) {
            return true;
        }

        if(st.find(s.substr( idx , n - idx )) != st.end()) {
            return true;
        }
        
        if(dp[idx] != -1)
            return dp[idx];
        
        for(int l = 1; l<=n; l++) {
            
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(s, idx+l))
                return dp[idx] = true;
            
        }
        
        return dp[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        
        memset(dp, -1, sizeof(dp));
        
        for(string &word : wordDict) {
            st.insert(word);
        }
        
        return solve(s, 0);
    }
};