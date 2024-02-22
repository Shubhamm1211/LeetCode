class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int np=players.size();
        int nt=trainers.size();
        int cnt=0;
        vector<int>vis(nt,0);
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int i=0,j=0;
        while(i<np && j<nt){
            if(players[i]<=trainers[j]){
                cnt++;
                i++;
                j++;
            }
            else j++;
        }
        return cnt;
    }
};