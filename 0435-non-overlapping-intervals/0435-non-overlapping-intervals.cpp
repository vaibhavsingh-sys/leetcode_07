class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int i = 1;
        int n = intervals.size();
        int ans = 0;
        auto comparator = [&](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        };
        sort(intervals.begin(), intervals.end(), comparator);
        int j = intervals[0][1];
        while(i < n){
            if(intervals[i][0] < j){
                ans++;
            }else{
                j = intervals[i][1];
            }
            i++;
        }
        return ans;
    }
};