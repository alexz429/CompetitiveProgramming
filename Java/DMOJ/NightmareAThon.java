import java.util.*;
import java.io.*;

public class NightmareAThon{
    public static void main(String[] args){
        FastReader sc = new FastReader();
        int n = sc.nextInt(), q = sc.nextInt();
        int[] max = new int[n+1];
        int[] freq = new int[n+1];
        for(int i=1;i<=n;i++){
            int next=sc.nextInt();
            if(next>max[i-1]){
                max[i] = next;
                freq[i] = 1;
            }
            else if(next == max[i-1]){
                max[i] = next;
                freq[i]=1+freq[i-1];
            }
            else{
                max[i] = max[i-1];
                freq[i] = freq[i-1];
            }
            // System.out.println(max[i]+" "+freq[i]);
        }
        for(int i=0;i<q;i++){
            int a = sc.nextInt(), b = sc.nextInt();
            int leftTal = freq[a-1];
            int leftMax = max[a-1];
            int rightTal = freq[n] - (max[n]==max[b]?freq[b]:0);
            int rightMax = max[n];
            System.out.println(leftTal+" "+rightTal);
            if(leftMax==rightMax){
                System.out.println(leftMax+" "+(leftTal+rightTal));
            }
            else if(rightTal==0||(leftMax>rightMax&&leftTal!=0)){
                System.out.println(leftMax+" "+leftTal);
            }
            else{
                System.out.println(rightMax +" "+rightTal);
            }
        }
    }
    public static class FastReader {
        BufferedReader br;
            StringTokenizer st;
    
            public FastReader() {
                br = new BufferedReader(new InputStreamReader(System.in));
            }//https://www.youtube.com/watch?v=_-5vJdAKuHE
    //https://www.youtube.com/watch?v=_-5vJdAKuHE
            String next() {//https://www.youtube.com/watch?v=_-5vJdAKuHE
                while (st == null || !st.hasMoreElements()) {
                    try {
                        st = new StringTokenizer(br.readLine());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
              //https://www.youtube.com/watch?v=_-5vJdAKuHE
                return st.nextToken();
            }
    //https://www.youtube.com/watch?v=_-5vJdAKuHE
            int nextInt() {
                return Integer.parseInt(next());
            }
            long nextLong() {
                return Long.parseLong(next());
            }
    
            double nextDouble() {
                return Double.parseDouble(next());
            }
    //https://www.youtube.com/watch?v=_-5vJdAKuHE
            String nextLine() {
                String str = null;
                try {
                    str = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }//https://www.youtube.com/watch?v=_-5vJdAKuHE
                return str;
            }
        }
}