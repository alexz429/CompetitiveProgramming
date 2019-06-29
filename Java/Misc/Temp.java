package Misc;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Temp {
	
	
	
	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String next=br.readLine();
		int max=Integer.parseInt(br.readLine());
		String best=next.substring(0, max);
		for(int count=1;count<=next.length()-max;count++) {
			String comp=next.substring(count, count+max);
			if(best.compareTo(comp)>0) {
				best=comp;
			}
		}
		System.out.println(best);
	
	}

}
