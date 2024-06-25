class Solution {
public:
    bool solve(vector<int>&v,int m,int k,long long int day){
        int ans=0,cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=day){
                cnt++;
            }
            else{
                ans=ans+cnt/k ;
                cnt=0;
            }
        }
        ans=ans+cnt/k;
        if(ans>=m)return true;
        return false;
    }
    int minDays(vector<int>& v, int m, int k) {
        if((long long)m*k>v.size())return -1;
        int low=*min_element(v.begin(),v.end());
        int high=*max_element(v.begin(),v.end());
        while(low<=high){
            long long int mid=low+(high-low)/2;
            if(solve(v,m,k,mid)){
                high=mid-1;
            }
            else{
            low=mid+1;
            }
        }
        return low;
    }
};
// //tc->O(n*log(max_day))
// //sc->O(1)