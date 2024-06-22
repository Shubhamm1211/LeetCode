class Solution {
public:
    int check(int day,vector<int>&p){
        int sum=0;
        for(int i=0;i<p.size();i++){
            sum=sum+ceil((double)p[i]/(double)day) ;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& p, int h) {
        int maxi=*max_element(p.begin(),p.end());
        int n=p.size(),mini=-1;
        int low=1,high=maxi;
        while(low<high){
            int mid=low+((high-low)/2);
            int c=check(mid,p);
            if(c>h) low=mid+1;
            else high=mid;
        }
        return low;
    }
};