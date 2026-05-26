class Solution {
public:
    int M = 1000000007;
    long long findPower(long long x, long long n){
        if(x == 1 || n == 0) return 1;
        if(n == 1) return x;
        long long temp = findPower(x, n / 2);
        return (n % 2 == 1) ? ((temp * temp) % M * x) % M : (temp * temp) % M;
    }

    int countGoodNumbers(long long n) {
        return (long long)findPower(5,(n+1)/2) * findPower(4,n /2) % M;
    }
};