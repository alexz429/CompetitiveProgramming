import java.io.*;
import java.util.*;

/*
 * To execute Java, please define "static void main" on a class
 * named Solution.
 *
 * If you need more classes, simply define them inline.
 */

public class Solution {
  
  
  public static void main(String[] args) {
    FastReader sc = new FastReader();
    int n = sc.nextInt(), k=sc.nextInt();
    int[] arr = new int[n];
    for(int i=0;i<n;i++){
      arr[i]=sc.nextInt(); 
    }
    int[] freq = new int[n+1];
    int l = 0;
    int r = 0;
    freq[arr[0]]++;
    int distinct = 1;
    long output = 0;
    boolean found = false;
    while(true){
      if(distinct<k){
        if(found){
          output += l; 
        }
        r++;
        if(r==n)break;
        freq[arr[r]]++;
        if(freq[arr[r]]==1){
          distinct++; 
        }
      }
      else{
        found = true;
        freq[arr[l]]--;
        if(freq[arr[l]]==0){
          distinct--; 
        }
        l++;
      }
    }
    System.out.println(output);
  }
  public static class FastReader {
    BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = null;
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}