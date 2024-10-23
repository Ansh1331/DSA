class Solution {
public:
    void solve(string num, int target, vector<string> & res,string temp,int pos,long prev,long sum){
        if(pos==num.size()){
            if(sum==target){
                res.push_back(temp);
                return;
            }
        }

        for(int i=pos;i<num.size();i++){
            if(i>pos && num[pos]== '0') break;

            string part = num.substr(pos, i-pos+1);
            long current_num= stol(part);

            // If this is the first number, take it without any operator
            if(pos==0){
                solve(num,target,res,temp+part,i+1,current_num,current_num);
            }
            else{
                //Add
                solve(num,target,res,temp + '+' + part,i+1,current_num,sum+current_num);
                
                //Sub
                solve(num,target,res,temp + '-' + part,i+1,-current_num,sum-current_num);

                //Mul
                solve(num,target,res,temp + '*' + part,i+1,prev*current_num,sum-prev+prev*current_num);

            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> res;
        int pos=0;
        long prev=0,sum=0;
        string temp="";
        solve(num,target,res,temp,pos,prev,sum);
        return res;
    }
};