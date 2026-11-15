
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int even = 1, odd = 0;
        int sum = 0, ans = 0;

        for (int x : arr) {
            sum += x;

            if (sum % 2) {
                ans = (ans + even) % mod;
                odd++;
            } 
            else {
                ans = (ans + odd) % mod;
                even++;
            }
        }

        return ans;
    }
};
