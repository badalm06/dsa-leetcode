class Solution {
public:
    double fun(double x, int n) {
        if(n==0) return 1;       // Base case

        double half = fun(x,n/2);     // Recursively calculate x^(n/2)

        if(n%2 == 0) return half * half;
        else return half * half * x;
    }
    double myPow(double x, int n) {
        
        long long power = n;

        if(power<0) {
            x = 1/x;
            power = -power;
        }

        return fun(x,power);
    }
};