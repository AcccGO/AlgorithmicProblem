class Solution
{
public:
    double Power(double base, int exponent)
    {
        //         return pow(base, exponent);
        double ans = 1.0;
        int d_base = base;
        int t      = exponent;
        while (t) {
            if (t & 1) {
                ans *= d_base;
            }
            d_base *= d_base;
            t /= 2;
        }

        return exponent >= 0 ? ans : 1.0 / ans;
    }
};