package CodeForces.Global3;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class A {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] in=br.readLine().split(" ");
		long a=Integer.parseInt(in[0]);
		long b=Integer.parseInt(in[1]);
		long c=Integer.parseInt(in[2]);
		long out=c*2;
		 out+=(Math.min(a, b))*2;
		if(a!=b) {
			out++;
		}
		System.out.println(out);
	}

}
