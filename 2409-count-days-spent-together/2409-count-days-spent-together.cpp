
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        unordered_map<int, int> mp;
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto convert = [&](string s) {
            int month = stoi(s.substr(0, 2));
            int day = stoi(s.substr(3, 2));

            for (int i = 0; i < month - 1; i++) {
                day += days[i];
            }
            return day;
        };

        int cnt1 = convert(arriveAlice);
        int cnt2 = convert(leaveAlice);
        int cnt3 = convert(arriveBob);
        int cnt4 = convert(leaveBob);

        for (int i = cnt1; i <= cnt2; i++) {
            mp[i]++;
        }

        for (int i = cnt3; i <= cnt4; i++) {
            mp[i]++;
        }

        int ans = 0;
        for (auto& p : mp) {
            if (p.second > 1) {
                ans++;
            }
        }

        return ans;
    }
};
