class Solution {
public:
    int solve(vector<int>&w,int cap){
        int day=1,load=0,n=w.size();
        for(int i=0;i<n;i++){
            if(w[i]+load>cap){
                day++;
                load=w[i];
            }
            else{
                load=load+w[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int low=*max_element(w.begin(),w.end());
        int high=accumulate(w.begin(),w.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int cap=solve(w,mid);
            if(cap<=days){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};