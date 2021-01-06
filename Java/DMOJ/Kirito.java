import java.util.*;
import java.io.*;

public class Kirito{
    static long SENTINEL = (long)(1000000007);
    static node[] seg;
    static long[][] hash;
    static class node{
        int ptr;
        int val;
        public node(int x,int y){
            ptr = x;
            val = y;
        }
    }
    public static node query(int l, int r, int min, int max,int at){
        if(l>=min&&r<=max)return seg[at];
        if(r<min||l>max)return new node(-1,-1);
        int mid = (l+r)/2;
        node leftNode = query(l,mid,min,max,at*2);
        node rightNode = query(mid+1,r,min,max,at*2+1);
        if(leftNode.val == -1) return rightNode;
        if(rightNode.val == -1)return leftNode;
        int small = 0;
        int big = Math.min(leftNode.val, rightNode.val);
        int left = leftNode.ptr, right = rightNode.ptr;
        while(small<big){
            int med = (small+big)/2;
            if(hash[left][med] == hash[right][med]){
                small = med+1;
            }
            else{
                big = med;
            }
        }
        // System.out.println(l+ " "+ r + " "+at+" "+small+" "+leftNode.ptr);
        return new node( leftNode.ptr, small);
    }
    public static void change(int l, int r, int at, int newptr, int target){
        if(r<target||l>target)return;
        if(l==r){
            seg[at].ptr = newptr;
        }
        else{
            int mid = (l+r)/2;
            change(l,mid,at*2, newptr,target);
            change(mid+1,r,at*2+1, newptr,target);
             int small = 0;
            int big = Math.min(seg[at*2].val, seg[at*2+1].val);
            int left = seg[at*2].ptr, right = seg[at*2+1].ptr;
            while(small<big){
                int med = (small+big)/2;
                if(hash[left][med] == hash[right][med]){
                    small = med+1;
                }
                else{
                    big = med;
                }
            }
            seg[at].val = small;
            seg[at].ptr = left;
        }
        // System.out.println(l+ " "+ r + " "+at+" "+seg[at].val+" "+seg[at].ptr);
    }
    public static void init(int l, int r, int at){
        
        seg[at] = new node(0,0);
        if(l==r){
            seg[at].val = hash[0].length;
            seg[at].ptr = l;
        }
        else{
            int mid = (l+r)/2;
            init(l,mid,at*2);
            init(mid+1,r,at*2+1);
            int small = 0;
            int big = Math.min(seg[at*2].val, seg[at*2+1].val);
            int left = seg[at*2].ptr, right = seg[at*2+1].ptr;
            while(small<big){
                int med = (small+big)/2;
                if(hash[left][med] == hash[right][med]){
                    small = med+1;
                }
                else{
                    big = med;
                }
            }
            seg[at].val = small;
            seg[at].ptr = left;
        }
        // System.out.println(l+ " "+ r + " "+at+" "+seg[at].val+" "+seg[at].ptr);
    }
    public static void main(String[] args){
        FastReader sc = new FastReader();
        int row = sc.nextInt(), col = sc.nextInt();
        hash = new long[row][col];
        seg = new node[row*4];
        int[] list = new int[row];
        for(int i=0;i<row;i++){
            list[i] = i;
            long sum = 0;
            String next = sc.next();
            for(int j=0;j<col;j++){
                sum = (sum*2)%SENTINEL;
                if(next.charAt(j)=='1')sum+=1;
                hash[i][j] = sum;
            }
        }
        init(0,row-1,1);
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            int a = sc.nextInt(), b = sc.nextInt();
            System.out.println(query(0,row-1,a-1,b-1,1).val*(b-a+1));
            int first = list[a-1];
            int second = list[b-1];
            change(0, row-1, 1, first, b-1);
            change(0, row-1, 1, second, a-1);
            list[a-1] = second;
            list[b-1] = first;
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