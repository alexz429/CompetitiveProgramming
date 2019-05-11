package _05;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class S1_SnowCalls {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		HashMap<String, Integer> convert=new HashMap<>();
		convert.put("A", 2);
		convert.put("B", 2);
		convert.put("C", 2);
		convert.put("D", 3);
		convert.put("E", 3);
		convert.put("F", 3);
		convert.put("G", 4);
		convert.put("H", 4);
		convert.put("I", 4);
		convert.put("J", 5);
		convert.put("K", 5);
		convert.put("L", 5);
		convert.put("M", 6);
		convert.put("N", 6);
		convert.put("O", 6);
		convert.put("P", 7);
		convert.put("Q", 7);
		convert.put("R", 7);
		convert.put("S", 7);
		convert.put("T", 8);
		convert.put("U", 8);
		convert.put("V", 8);
		convert.put("W", 9);
		convert.put("X", 9);
		convert.put("Y", 9);
		convert.put("Z", 9);
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		for(int count=0;count<max;count++) {
			String next=br.readLine();
			int haha=0;
			for(int count2=0;count2<next.length();count2++) {
				char lol=next.charAt(count2);
				if(lol=='-') {
					continue;
				}
				if(lol-'0'<10) {
					System.out.print(lol);
					haha++;
				}
				else if(lol-'A'<26) {
					System.out.print(convert.get(lol+""));
					haha++;
				}
				else {
					continue;
				}
				if(haha==3||haha==6) {
					System.out.print("-");
				}
				if(haha==10) {
					break;
				}
			}
			System.out.println();
		}
	}

}
