class Solution {     // ->>>> Space Optimization of Tabulation dp  ->>>> TC - O(N)   SC - O(1) (Space upgraded  from O(N) TO  O(1))
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev = nums[0];
        for(int i = 1; i < n; i++){
            int take = nums[i];
            if(i > 1){
                take += prev2;
            }
            int nonTake = 0 + prev;
            int curri = max(take, nonTake);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};