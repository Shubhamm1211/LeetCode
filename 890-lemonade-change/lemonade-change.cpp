class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0,cnt10=0;
        for(auto x:bills){
            if(x==5)cnt5++;
            else if(x==10){
                if(cnt5>0){
                cnt10++;
                cnt5--;
                }
                else return false;
            }
            else{
                if(cnt5>0 and cnt10>0){
                    cnt5--;
                    cnt10--;
                }
                else if(cnt5>2){
                    cnt5-=3;
                }
                else return false;
            }
        }
        return true;
    }
};