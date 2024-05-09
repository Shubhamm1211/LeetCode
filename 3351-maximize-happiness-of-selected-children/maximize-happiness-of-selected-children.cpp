class Solution {
public:
    void modify(vector<int>&arr){
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                arr[i]--;
            }
        }
    }
    long long maximumHappinessSum(vector<int>& h, int k) {
        int n=h.size();
        sort(h.begin(),h.end());
        long long ans=0;
        int i=1;
        while(k--){
            
            if(h[h.size()-1]>0)ans=ans+h[h.size()-1];
            h.pop_back();
            if(h.size()>0)h[h.size()-1]=h[h.size()-1]-i;
            i++;
        }
        return ans;
        
    }
};