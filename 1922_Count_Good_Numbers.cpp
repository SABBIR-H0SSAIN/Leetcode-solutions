// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/count-good-numbers

const int MOD=1e9+7;

class Solution {
public:
    int binexpo(long long n,long long k){
        int ans=1;
        while(k>0){
            if(k&1){
                ans=(ans*1ll*n)%MOD;
            }
            n=(n*1ll*n)%MOD;
            k>>=1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        if(n==1) return 5;

        long long even_count=(n+1)/2;
        long long odd_count=n/2;

        int odd=binexpo(4,odd_count);
        int even=binexpo(5,even_count);

        return (odd*1ll*even)%MOD;
    }
};
