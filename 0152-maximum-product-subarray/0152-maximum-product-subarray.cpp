class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefixProd = 1, suffixProd = 1;
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(prefixProd == 0){
                prefixProd = 1;
            }
            if(suffixProd == 0){
                suffixProd = 1;
            }
            prefixProd = prefixProd*nums[i];
            suffixProd = suffixProd*nums[nums.size()-i-1];
            ans = max(ans, max(prefixProd, suffixProd));
        }
        return ans;
    }
};