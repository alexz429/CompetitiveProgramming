int minimumSwaps(vector<int> arr) {
    int tally=0;
    for(int i=0;i<arr.size();i++){
        while(arr[i] != i+1){
            int temp = arr[i];
            arr[i] = arr[temp-1];
            arr[temp-1] = temp;
            tally++;
        }
    }
    return tally;

}