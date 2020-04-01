int climbStairs(int n) {
    if(n <= 2) 
        return n;

    int prev = 2, prev_prev = 1, sum;
    for(int i = 3; i <= n; i++)
    {
        sum = prev + prev_prev;
        prev_prev = prev;
        prev = sum;
    }
    return sum;
}