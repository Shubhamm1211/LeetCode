class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ans=0;
        if(num<10){
            if(num%k==0)ans++;
        }
        else{
            int i=0;
            int j=i+k-1;
            string s=to_string(num);
            int n=s.size();
            for(int i=0;i<n-k+1;i++){
                string temp=s.substr(i,k);
                int itemp=stoi(temp);
                cout<<itemp<<" "<<endl;
                if(itemp!=0 and num%itemp==0)ans++;
            }
        }
        return ans;
    }
};