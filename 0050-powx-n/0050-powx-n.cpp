class Solution {
public:
    // Function to calculate power of a number efficiently using recursion
    double myPow(double x, long long n) {
        // Base case: if power is 0, return 1
        if (n == 0) {
            return 1.0;
        }
        // If power is negative, take reciprocal of result of recursion with positive power
        if (n < 0) {
            return 1.0 / myPow(x, -n);
        }
        // Recursively calculate power of x raised to half of n
        double halfPow = myPow(x, n / 2);
        // If n is even, result is square of half power, else multiply by x once more
        return (n % 2 == 0) ? halfPow * halfPow : halfPow * halfPow * x;
    }
};