class Solution {
public:
    bool solve(int dis,vector<int>&pos,int m){
        int cnt=1,lp=pos[0];
        for(int i=1;i<pos.size();i++){
            if(pos[i]-lp>=dis){
                cnt++;
                lp=pos[i];
            }
            if(cnt>=m)return true;
        }
        return false;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int l=1;
        int h=(pos.back()-pos[0])/(m-1);
        int ans=1;
        while(l<=h){
            int mid=l+((h-l)/2);
            if(solve(mid,pos,m)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};