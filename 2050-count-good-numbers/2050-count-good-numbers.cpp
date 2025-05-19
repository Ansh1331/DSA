class Solution {
public:
    const int mod=1e9+7;
    long long pow(long long x,long long n){
        if(n==0){
            return 1.0;
        }
        long long ans=pow(x,n/2);
        ans*= ans;
        ans %= mod;
        if(n%2==1){
            ans*=x;
            ans%=mod;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
      //  int count=0;
        long long evenindex= n/2;
        long long oddindex= n- evenindex;
        return (pow(4,evenindex) * pow(5,oddindex))%mod;

    }
};