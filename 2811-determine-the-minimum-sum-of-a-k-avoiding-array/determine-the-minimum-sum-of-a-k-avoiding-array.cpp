class Solution {
public:
    int minimumSum(int n, int k) {
        int sum=0,cnt=0,i=1;
        unordered_map<int,int>mp;
        while(cnt<n){
            if(mp.find(k-i)==mp.end()){
                cnt++;
                sum=sum+i;
                mp[i]++;
            }
            i++;
        }
        return sum;
    }
};