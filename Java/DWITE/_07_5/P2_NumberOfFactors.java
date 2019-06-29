package DWITE._07_5;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class P2_NumberOfFactors {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		for(int count2=0;count2<5;count2++) {
			int OG=Integer.parseInt(br.readLine());
			if(OG==2) {
				System.out.println(0);
				continue;
			}
			int next=OG;
			int out=0;
			
			while(next%2==0) {
				out++;
				next/=2;
			}
			for(int count=3;count<=OG; count+=2) {
				while(next%count==0) {
					out++;
					next/=count;
				}
			}
			System.out.println(out);
			
		}
	}

}
