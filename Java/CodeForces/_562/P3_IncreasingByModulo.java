package CodeForces._562;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class P3_IncreasingByModulo {

	static boolean works(int best) {
		int prev=0;
		for(int count=0;count<vals.length;count++) {
			if(prev<=vals[count]) {
				if(best<prev+(mod-vals[count])) {
					prev=vals[count];
				}
			}
			else {
				if(prev-vals[count]>best) {
					return false;
				}
			}
		}
		return true;
	}
	static int[] vals;
	static int mod;
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] first=br.readLine().split(" ");
		int max=Integer.parseInt(first[0]);
		 mod=Integer.parseInt(first[1]);
		String[] second=br.readLine().split(" ");
		 vals=new int[max];
		for(int count=0;count<max;count++) {
			vals[count]=Integer.parseInt(second[count]);
		}
		int left=0; int right=mod;
		while(left<right) {
//			System.out.println(left+" "+right);
			int mid=(left+right)/2;
			if(works(mid)) {
				right=mid;
				
			}
			else {
				left=mid+1;
			}
			
		}
		System.out.println(right);
	}

}
