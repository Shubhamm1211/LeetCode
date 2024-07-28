class Solution {
public:
    vector<int> generate(int n) {

        vector<bool> is_prime(n + 1, true);
        vector<int> primes;
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= n; ++i) {
            if (is_prime[i]) {
                primes.push_back(i);
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        return primes;
    }
    int nonSpecialCount(int l, int r) {
        int ul = sqrt(r);
        vector<int>v=generate(ul);
        int cnt=0;
        for (auto x : v) {
            int sq=x*x;
            if (sq>=l && sq<=r) {
                cnt++;
            }
        }
        int tot=r-l+1;
        return tot-cnt;
    }
};