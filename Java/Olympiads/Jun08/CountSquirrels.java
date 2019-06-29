package Olympiads.Jun08;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class CountSquirrels {

	static int[][] dp;
	static int k;
	static int[] parent;
	static HashMap<Integer, ArrayList<Integer>> direct=new HashMap<>();
	
	static void process(int at) {
		for(int next:direct.get(at)) {
			if(parent[at]==next)continue;
			parent[next]=at;
			process(next);
			for(int count=1;count<=k;count++) {
				dp[at][count]+=dp[next][count-1];
			}
		}
	}
	static void reverse(int at) {
		if(parent[at]!=at) {
			for(int count=k;count>=2;count--) {
				dp[at][count]+=dp[parent[at]][count-1];
				dp[at][count]-=dp[at][count-2];
			}

			dp[at][1]+=dp[parent[at]][0];
		}
		for(int next:direct.get(at)) {
			if(parent[at]!=next)
			reverse(next);
		}
	}
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] first = br.readLine().split(" ");
		int max = Integer.parseInt(first[0]);
		parent = new int[max];
		k = Integer.parseInt(first[1]);
		dp=new int[max][k+1];
		for(int count=0;count<max;count++) {
			direct.put(count, new ArrayList<>());
			
		}
		for(int count=0;count<max-1;count++) {
			String[] next=br.readLine().split(" ");
			int from=Integer.parseInt(next[0])-1;
			int to=Integer.parseInt(next[1])-1;
			direct.get(from).add(to);
			direct.get(to).add(from);
		}
		for(int count=0;count<max;count++) {
			int next=Integer.parseInt(br.readLine());
			Arrays.fill(dp[count], next);
		}
		parent[0]=0;
		process(0);
		reverse(0);
//		for(int[] next:dp) {
//			for(int output:next) {
//				System.out.print(output+" ");
//			}
//			System.out.println();
//		}
		for(int count=0;count<max;count++) {
			System.out.println(dp[count][k]);
		}
		
	}

}
