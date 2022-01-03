class Solution {
    public List<Integer> getRow(int rowIndex) {
        int[] arr = new int[rowIndex + 1];
        Arrays.fill(arr, 1);
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i - 1; j >= 1; j--) {
                arr[j] = arr[j] + arr[j - 1];
            }
        }
        ArrayList<Integer> out = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            out.add(arr[i]);
        }
        return out;
    }
}