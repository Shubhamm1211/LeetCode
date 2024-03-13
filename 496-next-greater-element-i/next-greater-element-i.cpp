class Solution {
public:
    int search(int k,vector<int>arr){
        for(int i=0;i<arr.size();i++){
            if(k==arr[i])return i;
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>ans(n1,-1);
        for(int i=0;i<n1;i++){
            int si=search(nums1[i],nums2);
            for(int j=si;j<n2;j++){
                if(nums2[j]>nums1[i]){
                ans[i]=nums2[j];
                break;
                }
            }
        }
        return ans;
    }
};