package CCC._09;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.PriorityQueue;

public class S4_ShopAndShip {
	static class pair implements Comparable<pair>{
		int at;
		int weight;
		
		public pair(int at, int weight) {
			super();
			this.at = at;
			this.weight = weight;
		}

		public int compareTo(pair other) {
			return this.weight-other.weight;
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		int max2=Integer.parseInt(br.readLine());
		int[][] direct=new int[max][max];
		for(int count=0;count<max2;count++) {
			String[] next=br.readLine().split(" ");
			int from=Integer.parseInt(next[0])-1;
			int to=Integer.parseInt(next[1])-1;
			int weight=Integer.parseInt(next[2]);
			if(direct[from][to]!=0) {
				weight=Math.min(direct[from][to], weight);
			}
			direct[from][to]=weight;
			direct[to][from]=weight;
		}
		int max3=Integer.parseInt(br.readLine());
		HashMap<Integer, Integer> prices=new HashMap<>();
		for(int count=0;count<max3;count++) {
			String[] next=br.readLine().split(" ");
			int at=Integer.parseInt(next[0])-1;
			int weight=Integer.parseInt(next[1]);
			prices.put(at, weight);
		}
		pair[] dis=new pair[max];
		PriorityQueue<pair> queue=new PriorityQueue<>();
		for(int count=0;count<max;count++) {
			dis[count]=new pair(count,Integer.MAX_VALUE);
		}
		int start=Integer.parseInt(br.readLine())-1;
		dis[start].weight=0;
		queue.add(dis[start]);
		while(!queue.isEmpty()) {
			pair next=queue.poll();
			for(int count=0;count<max;count++) {
				if(direct[next.at][count]==0||next.at==count) {
					continue;
				}
				if(next.weight+direct[next.at][count]<dis[count].weight) {
					dis[count].weight=next.weight+direct[next.at][count];
					queue.remove(dis[count]);
					queue.add(dis[count]);
				}
			}
				
			
		}
		int best=Integer.MAX_VALUE;
		for(int next:prices.keySet()) {
//			System.out.println?])
			best=Math.min(best, dis[next].weight+prices.get(next));
		}
		System.out.println(best);
	}

}