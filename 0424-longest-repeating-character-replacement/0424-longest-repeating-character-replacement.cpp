class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> vec(26, 0);
        int l = 0, r = 0, maxi = 0;

        while(r < s.size()) {
            vec[s[r] - 'A']++;

            if(r - l + 1 - *max_element(vec.begin(), vec.end()) <= k) {
                maxi = max(maxi, r - l + 1);
            }

            while((r - l + 1) - *max_element(vec.begin(), vec.end()) > k) {
                vec[s[l] - 'A']--;
                l++;
            }

            r++;
        }

        return maxi;
    }
};