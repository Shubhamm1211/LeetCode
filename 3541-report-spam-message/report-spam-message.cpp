class Solution {
public:
    bool reportSpam(vector<string>& msg, vector<string>& ban) {
        int cnt=0;
        set <string> b;
        for(int i=0;i<ban.size();i++){
            b.insert(ban[i]);
        }
        for(int i=0;i<msg.size();i++){
            if(b.find(msg[i])!=b.end())cnt++;
        }
        if(cnt>=2)return true;
        else return false;
    }
};