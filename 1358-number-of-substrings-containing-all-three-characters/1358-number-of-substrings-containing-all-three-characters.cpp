class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, ans = 0;
        vector<int>count(3,0);
        for( int i = 0; i < s.size(); i++ ){
            count[s[i]-'a']++;
            while(count[0] > 0 && count[1] > 0 && count[2] > 0){
                ans += s.size() - i;
                count[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};