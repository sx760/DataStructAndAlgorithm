#ifndef STEP_H
#define STEP_H

class Step
{
public:
    typedef long long ll;
    static ll SolverByRecursion(int n)
    {
        return recursion(n);
    }
    static ll SolverByDP(int n) 
    {
        return dynaProgram(n);
    }

private:
    static ll recursion(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }

        return recursion(n - 1) + recursion(n - 2);
    }

    static ll dynaProgram(int n)
    {
        ll *dp = new ll[n];
        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i < n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};

#endif /* STEP_H */
