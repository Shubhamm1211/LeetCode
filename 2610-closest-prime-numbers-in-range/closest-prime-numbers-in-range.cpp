class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = right - left + 1;
        vector <bool> isprime(1e6 + 1, true);
        isprime[0] = false;
        isprime[1] = false;
        for(int i = 2; i*i <= 1e6; i++){
            if(isprime[i]){
                for(int j = i * i; j <= 1e6; j += i){
                    isprime[j] = false;
                }
            }
        }
        vector <int> temp;
        for(int i = left; i <= right; i++){
            if(isprime[i]) temp.push_back(i);
        }
        for(auto &x : temp) cout << x << " ";
        if(temp.size() <= 1) return {-1,-1};
        int mini = INT_MAX;
        vector <int> ans;
        for(int i = 1; i < temp.size(); i++){
            if(temp[i] - temp[i - 1] < mini){
                ans.clear();
                ans.push_back(temp[i - 1]);
                ans.push_back(temp[i]);
                mini = temp[i] - temp[i - 1];
            }
        }
        return ans;
    }
};