package Misc;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Temp {
	
	
	
	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		for(int count=0;count<max;count++) {
			long next=Long.parseLong(br.readLine());
			next=(long)(Math.sqrt(next*2)+1.5);
			System.out.println(next);
		}
	
	}

}
