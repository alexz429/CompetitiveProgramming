package Qualifiers2019;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class P2_YouCanGoYourOwnWay {
	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		for(int i=0;i<max;i++) {
			String in=br.readLine();
			System.out.print("Case #"+(i+1)+": ");
			for(int count=0;count<in.length();count++) {
				if(in.charAt(count)=='E') {
					System.out.print('S');
				}
				else {
					System.out.print('E');
				}
			}
			System.out.println();
		}
	}
}
