package CCC._17;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class S4_MinimumCostFlow {
	static class disjointSet {
		int[] link;
		public disjointSet(int max) {
			link=new int[max];
			for(int count=0;count<max;count++) {
				link[count]=count;
			}
		}
		public int getParent(int at) {
			if(link[at]==at) {
				return at;
			}
			int out=getParent(link[at]);
			link[at]=out;
			return out;
		}
		public void merge(int a, int b) {
			link[getParent(a)]=b;
		}
		public boolean connect(int a, int b) {
			return getParent(a)==getParent(b);
		}
	}
	static class path implements Comparable<path>{
		int from;
		int to;
		long cost;
		boolean enabled;
		public path(int from, int to, long cost, boolean enabled) {
			super();
			this.from = from;
			this.to = to;
			this.cost = cost;
			this.enabled = enabled;
		}
		public int compareTo(path other) {
			if(other.cost>cost) {
				return -1;
			}
			if(other.cost==cost) {
				return enabled? -1:1;
			}
			return 1;
			
		}
		public String toString() {
			return from+" "+to+" "+cost+" "+enabled;
		}
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] first=br.readLine().split(" ");
		int nodes=Integer.parseInt(first[0]);
		int edges=Integer.parseInt(first[1]);
		int enhance=Integer.parseInt(first[2]);
		int tally=0;
		disjointSet unions=new disjointSet(nodes);
		PriorityQueue<path> paths=new PriorityQueue<>();
		PriorityQueue<path> paths2=new PriorityQueue<>();
		
		long most=0;
		long trash=Long.MAX_VALUE;
		
		for(int count=0;count<edges;count++) {
			String[] next=br.readLine().split(" ");
			int from=Integer.parseInt(next[0])-1;
			int to=Integer.parseInt(next[1])-1;
			long cost=Long.parseLong(next[2]);
			paths.add(new path(from, to, cost, count<nodes-1));
			
			paths2.add(new path(from, to , cost, count<nodes-1));
		}
		int done=0;
		while(!paths.isEmpty()) {
			if(trash!=Long.MAX_VALUE&&done==nodes-1)break;
			path next=paths.poll();
		if(!unions.connect(next.from, next.to)) {
				unions.merge(next.from, next.to);
				done++;
				if(!next.enabled) {
					tally++;
				}
				most=next.cost;
			}
		else if(trash==Long.MAX_VALUE&&next.enabled) {
			trash=next.cost;
		}
		
			
		}
		unions=new disjointSet(nodes);

		while(!paths2.isEmpty()) {
			path next=paths2.poll();
		if(!unions.connect(next.from, next.to)) {
			if(next.cost<most||(next.cost==most&&next.enabled)) {
				unions.merge(next.from, next.to);
			}
			else if(next.cost<=enhance&&next.enabled) {
				System.out.println(tally-1);
				System.exit(0);
			}
			}
		
		
		
			
		}
		System.out.println(tally);
	}

}
