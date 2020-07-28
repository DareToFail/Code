#include <stdio.h>
 
#define MAX 10
#define DP_MAX (1 << MAX)
 
int a[MAX];
int dp[DP_MAX];
char used[MAX];
 
int find_solution(int bitmap, int total, char* used, int n)
{
    if (dp[bitmap])
        return dp[bitmap];
 
    int i, ret=0, mul, chosen, max = 0;
 
    if (total == n - 1)
    {
        // Find which one balloon is not shot yet
        for (i = 0; i < n; i++)
        {
            if (used[i] == 0)
            {
                dp[bitmap] = a[i];
                return dp[bitmap];
            }
        }
    }    
 
    for (i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            mul = 1;
            bitmap = (bitmap | (1 << i));
            used[i] = 1;
 
            // Find left side balloon
            chosen = i - 1;
            while (chosen >= 0 && used[chosen] == 1)
                chosen--;
 
            if (chosen >= 0)
                mul *= a[chosen];
 
            // Find right side balloon
            chosen = i + 1;
            while (chosen < n && used[chosen] == 1)
                chosen++;
 
            if (chosen < n)
                mul *= a[chosen];
 
            ret = mul + find_solution(bitmap, total + 1, used, n);
 
            /* Now backtrack */
            used[i] = 0;
            bitmap = (bitmap & ~(1 << i));
 
            if (ret > max)
                max = ret;
        }
    }
 
    dp[bitmap] = max;
    return dp[bitmap];
}
 
int main()
{
    int i, T, n, test;
 
    freopen("Test.txt", "r", stdin);
    scanf("%d", &T);
 
    for (test = 1; test <= T; test++)
    {
        scanf("%d", &n);
 
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            used[i] = 0;
        }
 
        for (i = 0; i < DP_MAX; i++)
            dp[i] = 0;
 
        printf("#%d %d\n", test, find_solution(0, 0, used, n));
 
        //for (i = 0; i < (1 << n); i++)
        //    printf("dp[%d] = %d\n", i, dp[i]);
    }
    return 0;
}


