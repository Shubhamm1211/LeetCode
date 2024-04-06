class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int>v= {a, b, c};
        int ans = 0;

        while (true) {
            sort(v.begin(),v.end(),greater<int>());
            if (v[1] == 0) break;
            v[0]--;
            v[1]--;
            ans++;
        }

        return ans;
    }
};