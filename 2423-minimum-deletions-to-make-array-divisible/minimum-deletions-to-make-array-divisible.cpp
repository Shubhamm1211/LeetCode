class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n2=nums2.size();
        int ans=nums2[0];
        for(int i=1;i<n2;i++){
            ans=gcd(ans,nums2[i]);
        }
        int cnt=0;
        int mini=ans;
        bool flag=false;
        for(auto x:nums1){
            if(ans%x==0){
                flag=true;
                mini=min(mini,x);
            }
        }
        cout<<mini;
        for(auto x:nums1){
            if(x<mini)cnt++;
        }
        if(!flag)return -1;
        return cnt;
    }
};