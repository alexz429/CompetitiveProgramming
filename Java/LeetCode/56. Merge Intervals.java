class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, new java.util.Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[0], b[0]);
            }
        });
        int curInd = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] <= intervals[curInd][1]) {
                intervals[curInd][1] = Math.max(intervals[i][1], intervals[curInd][1]);
            } else {
                curInd++;
                intervals[curInd] = intervals[i];
            }
        }
        int[][] out = new int[curInd + 1][2];
        for (int i = 0; i < out.length; i++) {
            out[i] = intervals[i];
        }
        return out;
    }
}