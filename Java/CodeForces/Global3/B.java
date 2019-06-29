package CodeForces.Global3;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class B {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	String[] first=br.readLine().split(" ");
	int max=Integer.parseInt(first[0]);
	int max2=Integer.parseInt(first[1]);
	int time=Integer.parseInt(first[2]);
	int time2=Integer.parseInt(first[3]);
	int cancel=Integer.parseInt(first[4]);
	String[] second=br.readLine().split(" ");
	String[] third=br.readLine().split(" ");
	int[] A=new int[max];
	int[] B=new int[max2];
	for(int count=0;count<max;count++) {
		A[count]=Integer.parseInt(second[count]);
	}
	for(int count=0;count<max2;count++) {
		B[count]=Integer.parseInt(third[count]);
	}
	long worst=0;
	int prev=0;
	if(cancel>=max||cancel>=max2) {
		System.out.println(-1);
		return;
	}
	for(int count=0;count<=cancel;count++) {
		long calc=A[count]+time;
		while(B[prev]<calc) {
			
			prev++;
			if(prev>=max2) {
				System.out.println(-1);
				return;
			}
		}
		if(prev+cancel-count>=max2) {
			System.out.println(-1);
			return;
		}
		
		calc=B[prev+(cancel-count)]+time2;
		worst=Math.max(worst, calc);
	}
	System.out.println(worst);
	}

}
