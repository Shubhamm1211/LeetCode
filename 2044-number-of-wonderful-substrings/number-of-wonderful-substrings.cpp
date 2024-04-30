class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        int n = word.size();
        vector<int> count(1 << 10, 0);
        count[0] = 1;
        int mask = 0;
        for (char ch : word) {
            mask ^= (1 << (ch - 'a'));
            ans += count[mask];
            count[mask]++;
            for (int i = 0; i < 10; ++i) {
                ans += count[mask ^ (1 << i)];
            }
        }
        return ans;
    }
};

