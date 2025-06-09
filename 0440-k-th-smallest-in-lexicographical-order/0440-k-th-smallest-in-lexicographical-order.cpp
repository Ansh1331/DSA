class Solution 
{
public:
    int findKthNumber(int n, int k) 
    {
        // Step 1: Start from 1
        int curr = 1; 
        k -= 1;       // Already visited the first number

        // Step 2: Continue until k reaches 0
        while (k > 0) 
        {
            long long steps = countSteps(n, curr, curr + 1); // Count steps under current prefix

            if (steps <= k) 
            {
                // Step 3: Skip subtree
                curr += 1; 
                k -= steps;
            } 
            else 
            {
                // Step 4: Go deeper
                curr *= 10; 
                k -= 1;
            }
        }

        // Step 5: Final result
        return curr; 
    }

private:
    long long countSteps(int n, long long curr, long long next) 
    {
        long long steps = 0;
        while (curr <= n) 
        {
            steps += min((long long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        
        return steps;
    }
};