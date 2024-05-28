class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int i=0,j=0,sum=0,count=0;
        int maxi=INT_MIN;
        while(j<n){
            sum+=(abs(s[j] - t[j]));
            while(sum>maxCost and i<=j){
                sum-=(abs(s[i]-t[i]));
                i++;
            }
            maxi=max(j-i+1,maxi);
            j++;
        }
        return maxi;
    }
};