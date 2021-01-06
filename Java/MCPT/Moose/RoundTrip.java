package MCPT.Moose;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class RoundTrip {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[]args) throws IOException {
       
        int n = readInt();
       
        int[] cost = new int [n];
        int[] gain = new int [n];
        int money = 0;
        int city = -1;
        int counter = 0;
        int adder = 0;
       
        for(int i = 0; i < n; i++) {
            cost[i] = readInt();
            gain[i] = readInt();
        }
    for(int k = 0; k<n;k++) {
        if(city==counter) {
            break;
        }
        for(int i = k; i <n*2; i++) {
            if(i>=n) {
                adder = i - n;
            }else {
                adder = i;
            }
            money+=gain[adder];
            money-=cost[adder];
            counter++;
            if(money<0) {
                i = n*2; money = 0; counter = 0; break;
            }
            if(n == counter) {
                city = k+1; break;
            }
           
        }
    }
   
    System.out.println(city);
       
    }
   
    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
 
    static long readLong() throws IOException {
        return Long.parseLong(next());
    }
 
    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }
 
    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }
 
    static char readCharacter() throws IOException {
        return next().charAt(0);
    }
 
    static String readLine() throws IOException {
        return br.readLine().trim();
    }
   
}