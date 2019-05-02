package _01;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class S1_KeepingScore {
	static int track(String in) {
		int add=0;
		if(in.length()==0) {
			add+=3;
		}
		else if(in.length()==1) {
			add+=2;
		}
		else if(in.length()==2) {
			add+=1;
		}
		for(int count=0;count<in.length();count++) {
			char next=in.charAt(count);
			System.out.print(next+" ");
			switch(next) {
			case 'A':
				add+=4;
				break;
			case 'Q':
				add+=2;
				break;
			case 'K':
				add+=3;
				break;
			case 'J':
				add+=1;
				break;
			}
		}
		System.out.println("     "+add);
		return add;
		
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String in=br.readLine();
		int total=0;
		System.out.println("Cards Dealt              Points");
		System.out.print("Clubs ");
		total+=track(in.substring(in.indexOf("C")+1, in.indexOf("D")));
		System.out.print("Diamonds ");
		total+=track(in.substring(in.indexOf('D')+1, in.indexOf('H')));
		System.out.print("Hearts ");
		total+=track(in.substring(in.indexOf('H')+1, in.indexOf('S')));
		System.out.print("Spades ");
		total+=track(in.substring(in.indexOf('S')+1));
		System.out.println("           Total "+total);
	}

}