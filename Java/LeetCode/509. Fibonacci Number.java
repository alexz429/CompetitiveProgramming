class Solution {
    public int fib(int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            int c = b + a;
            a = b;
            b = c;
        }
        return a;
    }
}