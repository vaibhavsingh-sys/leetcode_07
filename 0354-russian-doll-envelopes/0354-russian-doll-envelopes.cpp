
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if(a[0] == b[0]) {
                    return a[1] > b[1];
                }
                return a[0] < b[0];
            });

        vector<int> dp;

        for(int i = 0; i < envelopes.size(); i++) {

            int h = envelopes[i][1];

            int idx = lower_bound(dp.begin(), dp.end(), h) - dp.begin();

            if(idx == dp.size()) {
                dp.push_back(h);
            }
            else {
                dp[idx] = h;
            }
        }

        return dp.size();
    }
};
