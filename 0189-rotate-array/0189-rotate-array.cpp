class Solution {
public:
    void rotate(vector<int>& nu, int k) {
        int n=nu.size();
        k=k%n;
        reverse(nu.begin()+n-k,nu.end());
        reverse(nu.begin(),nu.begin()+n-k);
        reverse(nu.begin(),nu.end());
    }
};