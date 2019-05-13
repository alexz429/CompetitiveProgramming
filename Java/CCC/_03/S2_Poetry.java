package CCC._03;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class S2_Poetry {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		String huh="aeiou";
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		for(int count=0;count<max;count++) {
			String[] lol=new String[4];
			for(int count2=0;count2<4;count2++) {
				String next=br.readLine().toLowerCase();
				for(int count3=next.length()-1;count3>=0;count3--) {
					if(huh.contains(next.charAt(count3)+"")) {
						lol[count2]=next.substring(count3);
						break;
					}
					else if(next.charAt(count3)==' ') {
						lol[count2]=next.substring(count3+1);
						break;
					}
				}
				if(lol[count2]==null) {
					lol[count2]=next;
				}
//				System.out.println(lol[count2]);
			}
			if(lol[0].equals(lol[1])&&lol[1].equals(lol[2])&&lol[3].equals(lol[2])) {
				System.out.println("perfect");
			}
			else if(lol[0].equals(lol[1])&&lol[2].equals(lol[3])) {
				System.out.println("even");
			}
			else if(lol[0].equals(lol[2])&&lol[1].equals(lol[3])) {
				System.out.println("cross");
			}
			else if(lol[1].equals(lol[2])&&lol[0].equals(lol[3])) {
				System.out.println("shell");
			}
			else {
				System.out.println("free");
			}
		}
	}

}
