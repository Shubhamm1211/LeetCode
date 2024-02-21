class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++){
            set<char>s;
            for(auto c:words[i]){
                s.insert(c);
            }
            string temp="";
            for(auto it:s){
                temp=temp+it;
            }
            words[i]=temp;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(words[i]==words[j])cnt++;
            }
        }
        return cnt;
        
    }
};