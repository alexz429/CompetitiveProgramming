package DMPG._18;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class B4_Shimnanigans {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] buf = br.readLine().split(" ");
		int n = Integer.parseInt(buf[0]), m=Integer.parseInt(buf[1]), x=Integer.parseInt(buf[2]);
		buf = br.readLine().split(" ");
		double tally = 0;
		int max = 0;
		for(int i=0;i<n;i++) {
			int next = Integer.parseInt(buf[i]);
			tally+=next;
			max= Math.max(max, next);
		}
		int best = 10000;
		double lim= 10000;
		buf = br.readLine().split(" ");
		for(int i=0;i<m;i++) {
			
			int next = Integer.parseInt(buf[i]);
			if(next<max)continue;
			
			double ans = tally/(double)(next*n);
			ans*=100;
			if(ans<50)continue;
			if(Math.abs(ans-x)<lim) {
				lim = Math.abs(ans-x);
				best = next;
			}
		}
		System.out.println((best==10000?"Shimnanigans have failed":best));
	}

}
