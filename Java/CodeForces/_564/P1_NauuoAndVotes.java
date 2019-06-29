package CodeForces._564;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class P1_NauuoAndVotes {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] in=br.readLine().split(" ");
		int a=Integer.parseInt(in[0]);
		int b=Integer.parseInt(in[1]);
		int c=Integer.parseInt(in[2]);
		int out=a-b;
		if(c!=0&&Math.abs(out)<=c) {
			System.out.println("?");
		}
		else {
			if(out<0) {
				System.out.println("-");
			}
			else if(out==0) {
				System.out.println("0");
			}
			else {
				System.out.println("+");
			}
		}
	}

}
