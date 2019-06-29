package Olympiads.Jun08;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class DMOJBridgesAreFallingDown {

	static class pair {
		int a;
		int b;
		public pair(int a, int b) {
			super();
			this.a = a;
			this.b = b;
		}
		
	}
	static class data{
		int index;
		long size;
		public data(int index, int size) {
			super();
			this.index = index;
			this.size = size;
			
		}
		
	}
	static int findParent(int a) {
		if(parent[a]==a)return a;
		parent[a]=findParent(parent[a]);
		return parent[a];
	}
	static void link(int a, int b) {
		int left=findParent(a);
		int right=findParent(b);
		if(left==right) {
			return;
		}
		init-=(node[left].size*node[right].size);
		node[left].size+=node[right].size;
		parent[right]=left;
	}
	static int[] parent;
	static data[] node;
	static long init;
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] first=br.readLine().split(" ");
		int nodes=Integer.parseInt(first[0]);
		int edges=Integer.parseInt(first[1]);
		
		init=((long)nodes*((long)nodes-1))/2;
		pair[] edge=new pair[edges];
		node=new data[nodes];
		parent=new int[nodes];
		for(int count=0;count<nodes;count++) {
			node[count]=new data(count,1);
			parent[count]=count;
		}
		for(int count=0;count<edges;count++) {
			String[] next=br.readLine().split(" ");
			edge[count]=new pair(Integer.parseInt(next[0])-1,Integer.parseInt(next[1])-1);
			
		}
		long[] ans=new long[edges+1];
		ans[edges]=init;
		for(int count=edges-1;count>=0;count--) {
			link(edge[count].a,edge[count].b);
			ans[count]=init;
		}
		for(int count=1;count<=edges;count++) {
			System.out.println(ans[count]);
		}
	}

}
