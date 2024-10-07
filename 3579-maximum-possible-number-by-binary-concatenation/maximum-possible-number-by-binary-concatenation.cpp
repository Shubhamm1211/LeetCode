class Solution {
public:
    string toBinary(int n){
        string r;
        while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
        return r;
    }
    int decimal(string s){
        int res =0;
        for(int i=0; i < s.length(); i++) {
            res = res*2 + (s[i]-'0');
        }
        return res;
    }
    void comb(int ind, vector<int>&nums, vector<vector<int>>&v){
        int n = nums.size();
        if(ind == n){
            v.push_back(nums);
            return ;
        }
        for(int i = 0; i < n; i++){
            swap(nums[i],nums[ind]);
            comb(ind + 1, nums, v);
            swap(nums[ind], nums[i]);
        }
    }
    int maxGoodNumber(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>v;
        // v.push_back(nums);
        // while(next_permutation(nums.begin(),nums.end())){
        //     v.push_back(nums);
        // }
        comb(0,nums,v);
        int maxi = 0;
        for(auto x : v){
            string temp = "";
            for(auto e : x){
                cout << e << " ";
                temp += toBinary(e);
            }
            cout << endl;
            maxi = max(maxi, decimal(temp));
        }
        return maxi;
    }
};