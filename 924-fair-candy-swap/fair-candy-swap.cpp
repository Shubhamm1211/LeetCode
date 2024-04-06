class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int f=accumulate(a.begin(), a.end(), 0);
        int sec=accumulate(b.begin(), b.end(), 0);

        int sum=(f+sec)/2;

        unordered_set<int>sa(a.begin(), a.end());
        unordered_set<int>sb(b.begin(), b.end());
        for(int n:sb)
        {
            int temp = sum - (sec - n);
            if(sa.count(temp))
            {
                return {temp, n};
            }
        }
        return {};
    }
};