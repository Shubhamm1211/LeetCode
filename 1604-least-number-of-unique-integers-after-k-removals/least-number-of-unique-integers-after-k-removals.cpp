class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int>freq;
        for(auto x:mp){
            freq.push_back(x.second);
        }
        sort(freq.begin(),freq.end());
        for(int i=0;i<freq.size();i++){
            if(k>0){
                int j=k;
                k=k-freq[i];
                freq[i]=freq[i]-j;
            }
            else break;
        }
        int ans=0;
        for(int i=0;i<freq.size();i++){
            if(freq[i]>0){
                ans++;
            }
        }
        return ans;
    }
};