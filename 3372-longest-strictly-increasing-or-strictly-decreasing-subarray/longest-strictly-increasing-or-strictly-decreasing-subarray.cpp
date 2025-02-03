class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        vector <int> v;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] < nums[i + 1]){
                v.push_back(1);
            }
            else if(nums[i] > nums[i + 1]){
                v.push_back(-1);
            }
            else v.push_back(0);
        }
        int cnt = 1, maxi = 1;
        for(int i = 0; i < v.size() - 1; i++){
            if(v[i] == v[i + 1] and v[i] != 0){
                cnt++;
                maxi = max(cnt,maxi);
            }
            else{
                cnt = 1;
                maxi = max(cnt,maxi);
            }
        }
        bool f = true;
        for(auto &x : v){
            cout << x << " ";
            if(x != 0) f = false;
        }
        cout << endl;
        cout << maxi << endl;
        if(f) return 1;
        return maxi + 1;
    }
};