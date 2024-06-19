class Solution {
public:
    bool solve(vector<int>&v,int m,int k,long long int day){
        int ans=0;
        for(int i=0;i<v.size();i++){
            int cnt=0;
            while(i<v.size() and cnt<k and v[i]<=day){
                cnt++;
                i++;
            }
            if(cnt==k){
                ans++;
                i--;
            }
            if(ans>=m)return true;
        }
        return false;
    }
    int minDays(vector<int>& v, int m, int k) {
        if((long long)m*k>v.size())return -1;
        int low=*min_element(v.begin(),v.end());
        int high=*max_element(v.begin(),v.end());
        while(low<high){
            long long int mid=low+(high-low)/2;
            if(solve(v,m,k,mid)){
                high=mid;
            }
            else{
            low=mid+1;
            }
        }
        return low;
    }
};