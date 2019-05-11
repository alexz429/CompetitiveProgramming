package _08;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class S1_ItsColdHere {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int best=Integer.MAX_VALUE;
		String name="";
		while(true) {
			String[] in=br.readLine().split(" ");
			if(Integer.parseInt(in[1])<best) {
				best=Integer.parseInt(in[1]);
				name=in[0];
			}
			if(in[0].equals("Waterloo")) {
				break;
			}
		}
		System.out.println(name);
	}

}
