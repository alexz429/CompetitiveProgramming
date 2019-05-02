package _03;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Scanner;

public class S5_TruckingTroubles {
	/*
	 * There are many ways to find the shortest path between two nodes in a network
	 * BFS: works on graphs where all edges have the same length, very simple
	 * Djikstra: Works on graphs where the edges have non-negative lengths, my favourite and (I think?) most commonly used
	 * Bellman ford:
	 * Floyd: return all pairs leading to the destination
	 * SFPA:
	 * 
	 * 
	 * All algorithms use the relaxation formula: d(u) -> the CURRENT shortest path from start to node u
	 * This one is the Djikstra way
	 * outputs all nodes, 0 to n-1, and their paths (from 0)
	 */
	
	
	
	static class pair implements Comparable<pair>{
		int to;
		int weight;
		public pair(int to, int weight) {
			this.to = to;
			this.weight = weight;
		}
		public int compareTo(pair other) {
			if(other.weight>=this.weight) {
				return 1;
			}
			return -1;
		}
	}
	static pair[] distances;
	static HashSet<Integer> visited;
	static PriorityQueue<pair> stuff;
	static HashMap<Integer, ArrayList<pair>> list;
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
			
			int nodes=sc.nextInt();
			int edges=sc.nextInt();
			int dests=sc.nextInt();
			int[] dest=new int[dests];
			distances=new pair[nodes];
			visited=new HashSet<Integer>();
			stuff=new PriorityQueue<pair>();
			list=new HashMap<Integer, ArrayList<pair>>();
			for(int count=0;count<nodes;count++) {
				distances[count]=new pair(count,Integer.MIN_VALUE);
			}
			for(int count=0;count<nodes;count++) {
				list.put(count, new ArrayList<pair>());
			}
			for(int count=0;count<edges;count++) {
				int from=sc.nextInt()-1;
				int to=sc.nextInt()-1;
				int weight=sc.nextInt();
				list.get(from).add(new pair(to,weight));
				list.get(to).add(new pair(from,weight));
			}
			for(int count=0;count<dests;count++) {
				dest[count]=sc.nextInt()-1;
			}
			distances[0].weight=Integer.MAX_VALUE;
			stuff.add(distances[0]);
			
			while(!stuff.isEmpty()) {
				
				int next=stuff.poll().to;
				if(visited.contains(next)) {
					continue;
				}
				//System.out.println(next+" "+distances[next].weight);
				
				visited.add(next);
				for(pair nextNode:list.get(next)) {
					if(nextNode.weight>distances[nextNode.to].weight) {
						distances[nextNode.to].weight=nextNode.weight;
						stuff.remove(distances[nextNode.to]);
						stuff.add(distances[nextNode.to]);
					}
					
				}
			}
			int best=Integer.MAX_VALUE;
			for(int count=0;count<dests;count++) {
				//System.out.println("run "+distances[dest[count]].weight);
				if(best>distances[dest[count]].weight) {
					best=distances[dest[count]].weight;
				}
			}
			System.out.println(best);
		sc.close();
	}

}