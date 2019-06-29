package Olympiads.Jun08;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BinaryCrash {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String OG=br.readLine();
		int one=0;
		int zero=0;
		for(int count=0;count<OG.length();count++) {
			if(OG.charAt(count)=='0') {
				zero++;
			}
			else {
				one++;
			}
		}
		System.out.println(OG.length()-Math.abs(zero-one));
		
	}

}
