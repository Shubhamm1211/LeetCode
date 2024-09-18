bool cmp(int a,int b){
    string s1=to_string(a);
    string s2=to_string(b);
    if(s1+s2>s2+s1)return true;
    return false;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        if(nums[0]==0)return "0";
        string ans="";
        for(auto x:nums){
            ans=ans+to_string(x);
        }
        return ans;
    }
};