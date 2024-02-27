bool comp(vector<int>a,vector<int>b){
    return a[1]>b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int ans=0;
        for(int i=0;i<n;i++){
            int temp=boxTypes[i][0];
            if(truckSize>0){
                while(temp!=0 && truckSize>0){
                    ans=ans+boxTypes[i][1];
                    temp--;
                    truckSize--;
                }
            }
        }
        return ans;
    }
};