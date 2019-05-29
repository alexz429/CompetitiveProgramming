package Misc;

import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Autocomplete {
	static int tally=0;
	static class node{
		char val;
		int children=0;
		node[] nodes;
		int depth;
		public node(int size, int depth, char val) {
			super();
			nodes=new node[size];
			this.depth=depth;
			this.val=val;
		}
		public int type(String in, int at) {
//			System.out.println(val);
			
			if(at>=in.length())return depth;
			if(children<=1)return depth;
			int next=in.charAt(at)-'a';
			return nodes[next].type(in, at+1);
		}
		public void add(String in, int at) {
			children++;
//			System.out.println(children+" "+depth+" "+val);
			if(at>=in.length())return;
			int next=in.charAt(at)-'a';
			
			if(nodes[next]==null) {
				nodes[next]=new node(26, depth+1, (char)(next+'a'));
			}
			nodes[next].add(in, at+1);
		}
		
	}
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	
		int max=Integer.parseInt(br.readLine());
		for(int count=0;count<max;count++) {
			int words=Integer.parseInt(br.readLine());
			tally=0;
			node head=new node(26,0,' ');
			for(int count2=0;count2<words;count2++) {
				String next=br.readLine();
				head.add(next, 0);
				int add=head.type(next, 0);
				tally+=add;
//				System.out.println(add);
			}
			System.out.printf("Case #%d: %d\n",count+1, tally+1);
		}
	}

}
