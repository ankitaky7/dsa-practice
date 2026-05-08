class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        if(x == 1 || N == 0) return 1;
        if(N == 1) return x;

        if(N < 0){
            x = 1 / x;
            N = abs(N);
        }

        double temp = myPow(x, N / 2);
        return(N % 2 == 1) ? temp * temp * x : temp * temp;
    }
};