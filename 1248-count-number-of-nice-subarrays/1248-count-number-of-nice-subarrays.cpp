class Solution {
public:
    int solve(vector<int>& nums, int k){
        int cnt = 0, l = 0, r = 0, ans = 0;
        unordered_map<int, int>mp;
        while(r < nums.size()){
            if(nums[r] % 2 != 0){
                cnt++;
            }
            mp[nums[r]]++;
            while(cnt > k){
                if(nums[l] % 2 != 0){
                    cnt--;
                }
                mp[nums[l]]--;
                l++;    
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};