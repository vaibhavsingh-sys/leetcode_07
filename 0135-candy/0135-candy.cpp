class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>ans(ratings.size(), 1);
        vector<int>ans2(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] <= ratings[i-1]){
                continue;
            }else{
                ans[i] = ans[i-1]+1;
            }
        }
        for(int i = ratings.size()-2; i >= 0; i--){
            if(ratings[i] <= ratings[i+1]){
                ans2[i] = 1;
            }else{
                if(ratings[i] > ratings[i+1]){
                    ans2[i] = ans2[i+1] + 1;
                }
            }
        }
        int fAns = 0;
        for(int i = 0; i < ratings.size(); i++){
            if(ans[i] == ans2[i]){
                fAns += ans[i];
            }else{
                fAns += max(ans[i], ans2[i]);
            }
        }
        return fAns;
    }
};