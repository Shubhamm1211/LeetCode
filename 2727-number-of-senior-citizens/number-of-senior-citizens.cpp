class Solution {
public:
    int countSeniors(vector<string>& d) {
        int cnt=0;
        for(int i=0;i<d.size();i++){
            string s=d[i];
            string sage=s.substr(11,2);
            int age=stoi(sage);
            if(age>60)cnt++;
        }
        return cnt;
    }
};