class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int n = v.size();
        int maxi1 = v[0] + 0;
        int maxi2 = INT_MIN;

        for(int i = 1; i < n; i++){
            maxi2 = max(maxi2, maxi1 + v[i] - i);
            maxi1 = max(maxi1, v[i] + i);
        }
        return maxi2;
    }
};