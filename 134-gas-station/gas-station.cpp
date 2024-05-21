class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tg=0,tc=0;
        for(int i=0;i<n;i++){
            tg=tg+gas[i];
            tc=tc+cost[i];
        }
        int t=0;
        int ans=0;
        if(tg<tc)return -1;
        else{
            for(int i=0;i<n;i++){
            t=t+gas[i]-cost[i];
            if(t<0){
                t=0;
                ans=i+1;
            }
            }
        }
        return ans;
    }
};