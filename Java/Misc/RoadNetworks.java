package Misc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class RoadNetworks {

	static int[][] loc= new int[1001][2];
	static int[] connect= new int[1001];
	static int findParent(int at){
	    if(connect[at]==at)return at;
	    return connect[at]= findParent(connect[at]);
	}
	static boolean connected(int a, int b){
	    return findParent(a) == findParent(b);
	}
	static void merge(int a, int b){
	    connect[findParent(a)] = b;
	}
	static double len(int a, int b){
	    return Math.sqrt(Math.pow(loc[a][0]-loc[b][0],2)+Math.pow(loc[a][1]-loc[b][1],2));
	}

	// vector<vector<pair<int,double>>> graph;
	static int nodes, edges, a,b, index=0;
	static class wrap implements Comparable<wrap>{
		int a;

		@Override
		public int compareTo(wrap arg0) {
			return (int) (len(a/10000, a%10000)-len(arg0.a/10000, arg0.a%10000));
		}

		public wrap(int a) {
			super();
			this.a = a;
		}
		
	}
	public static void main(String[] args) throws IOException{
	    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	    String[] first=br.readLine().split(" ");
		int nodes= Integer.parseInt(first[0]), edges = Integer.parseInt(first[1]);
	    for(int i=0;i<nodes;i++){
	        connect[i]=i;
	    }
	    wrap[] pq = new wrap[(nodes*(nodes-1))/2];
	    for(int count=1;count<=nodes;count++){
	        String[] second=br.readLine().split(" ");
	    	loc[count][0] = Integer.parseInt(second[0]);
	    	loc[count][1]=Integer.parseInt(second[1]);
	        for(int i=1;i<count;i++){
	        	pq[index++] = new wrap(count*10000+i);
	        }
	    }
	    for(int i=0;i<edges;i++){
	    	String[] second=br.readLine().split(" ");
	    	a = Integer.parseInt(second[0]);
	    	b =Integer.parseInt(second[1]);
	        merge(a,b);
	    }
	    Arrays.sort(pq);
	    double output=0;
	    for(wrap next2:pq){
	    	int next= next2.a;
	        // cout<<len(pq[i]%10000,pq[i]/10000)<<endl;
	        if(connected(next%10000,next/10000))continue;
	        output+=len(next%10000,next/10000);
	        merge(next%10000,next/10000);
	    }
	    System.out.printf("%.2f", output);


	}

}
