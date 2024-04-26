class Solution {
public:
   bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        vector<string>p;
        for(int i=0;i<=30;i++){
            int pt=pow(2,i);
            p.push_back(to_string(pt));
        }
        for(int i=0;i<=30;i++){
            sort(p[i].begin(),p[i].end());
        }
        for(int i=0;i<=30;i++){
            if(p[i]==s)return true;
        }
        return false;
    }
};