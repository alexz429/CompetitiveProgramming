package _02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class S4_BridgeCrossing {
	static class person{
		String name;
		int time;
		public person(String name, int time) {
			super();
			this.name = name;
			this.time = time;
		}
		
	}
	static int best=Integer.MAX_VALUE;
	static person[] group;
	static int max;
	static String out="";
	public static void recurse(int index, int at, String flow) {
		if(at>best) {
			return;
		}
		if(index>=group.length) {
			best=at;
			out=flow;
			return;
		}
		for(int count=1;count<=max;count++) {
			int worst=Integer.MIN_VALUE;
			for(int count2=0;index+count2<group.length&&count2<count;count2++) {
				worst=Math.max(worst, group[index+count2].time);
			}
			recurse(index+count, at+worst, flow+count);
		}
	}
	public static void printAll() {
		int index=0;
		for(int count=0;count<out.length();count++) {
			int next=out.charAt(count)-'0';
			for(int count2=0;index<group.length&&count2<next;count2++) {
				System.out.print(group[index].name);
				if(count2<next-1) {
					System.out.print(" ");
				}
				index++;
			}
			System.out.println();
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		max=Integer.parseInt(br.readLine());
		int ppl=Integer.parseInt(br.readLine());
		group=new person[ppl];
		for(int count=0;count<ppl;count++) {
			group[count]=new person(br.readLine(),Integer.parseInt(br.readLine()));
		}
		recurse(0,0,"");
		System.out.println("Total Time: "+best);
		printAll();
	}

}
