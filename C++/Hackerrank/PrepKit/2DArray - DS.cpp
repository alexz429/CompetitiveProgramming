int hourglassSum(vector<vector<int>> arr) {
    int max=-1000000;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            max=std::max(max,arr[i][j]+arr[i-1][j]+arr[i-1][j-1]+arr[i-1][j+1]+arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1]);
        }
    }
    return max;

}