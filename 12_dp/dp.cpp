#include "Timer.h"
#include "Step.h"
#include "LongestCommonSubsequence.h"
#include "MinimumPathSum.h"

#include <iostream>

void testStepByRecursion(int n)
{
    using namespace std;
    TIME_UTIL();
    cout << Step::SolverByRecursion(n) << "\n";
}

void testStepByDP(int n)
{
    using namespace std;
    TIME_UTIL();
    cout << Step::SolverByDP(n) << "\n";
}

void testLCS()
{
    using namespace std;
    string s1 = "abc123", s2 = "asd123abc123"; 
    cout << "LCS: " << LCS::solver(s1, s2) << endl;
}

void testMinSumPath()
{
    using namespace std;
    int grid[3][3] = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << "MinsSumPath: " << MinPathSum::solver(grid, 3, 3) << endl;
}

int main(int argc, char const *argv[])
{
    using namespace std;

    int n;
    cout << "please input a number: ";
    cin >> n;
    testStepByRecursion(n);
    testStepByDP(n);
    testLCS();
    testMinSumPath();

    return 0;
}
