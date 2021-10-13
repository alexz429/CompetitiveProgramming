class Solution {
    public int myAtoi(String s) {
        int i = 0;
        long val = 0;
        long lowBound = Integer.MIN_VALUE;
        long highBound = Integer.MAX_VALUE;
        int adjust = 1;
        while (i < s.length() && s.charAt(i) == ' ') {
            i++;
        }
        if (i < s.length() && (s.charAt(i) == '-' || s.charAt(i) == '+')) {
            if (s.charAt(i) == '-') {
                adjust = -1;
            }
            i++;
        }
        while (i < s.length() && s.charAt(i) - '0' >= 0 && s.charAt(i) - '9' <= 0) {
            val = val * 10 + s.charAt(i) - '0';
            i++;
            if ((val * adjust) < lowBound) {
                val = lowBound;
                return (int) val;
            }
            if ((val * adjust) > highBound) {
                val = highBound;
                return (int) val;
            }
        }
        val = val * adjust;
        if (val < lowBound)
            val = lowBound;
        if (val > highBound)
            val = highBound;
        System.out.println(lowBound + " " + highBound);
        return (int) val;
    }
}