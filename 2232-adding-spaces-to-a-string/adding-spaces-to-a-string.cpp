class Solution {
public:
    string addSpaces(string s, vector<int>& nums) {
        string ans = "";
        int n = nums.size();
        int start = 0;
        for(int i = 0; i < n; i++){
            string sub = s.substr(start,nums[i] - start);
            ans += sub + " ";
            start = nums[i];
        }
        int sn = s.size();
        ans += s.substr(start, sn - start);
        return ans;
    }
};