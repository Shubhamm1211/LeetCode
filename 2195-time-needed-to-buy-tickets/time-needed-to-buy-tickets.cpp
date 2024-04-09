class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int req=tickets[k];
        int n=tickets.size();
        int ans=0;
        while(true){
        for(int i=0;i<n;i++){
            if(tickets[i]>0){
                tickets[i]--;
                ans++;
            }
            if(tickets[i]==0 && i==k)
            return ans;
        }
        }
        return 0;
    }
};