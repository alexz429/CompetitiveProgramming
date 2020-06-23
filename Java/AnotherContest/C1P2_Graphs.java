package _1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class P2_Graphs {

	static void merge(int a, int b) {
		set[set[a]] = set[b];
	}

	static int findParent(int a) {
		if (set[a] == a) {
			return a;
		}

		int next = findParent(set[a]);
		set[a] = next;
		return next;

	}

	static class path {
		int at;
		int from;

		public path(int at, int from) {
			super();
			this.at = at;
			this.from = from;
		}

	}

	static int connect(int from, int to) {
		if (findParent(from) != findParent(to)) {
			return -1;
		}
		Queue<path> A = new LinkedList<>();
		Queue<path> B = new LinkedList<>();
		HashSet<Integer> visited = new HashSet<>();
		A.add(new path(from,-1));
		B.add(new path(to,-1));
		int step = 1;
		while (true) {
			int max = A.size();
			for (int count = 0; count < max; count++) {
				path next = A.poll();
				if (visited.contains(next.at)) {
					return step * 2 - 1;
				}
				visited.add(next.at);
				for(int nextInt:direct.get(next.at)) {
					if(nextInt==next.from)continue;
					A.add(new path(nextInt, next.at));
				}
			}
			max = B.size();
			for (int count = 0; count < max; count++) {
				path next = B.poll();
				if (visited.contains(next.at)) {
					return step * 2;
				}
				visited.add(next.at);
				for(int nextInt:direct.get(next.at)) {
					if(nextInt==next.from)continue;
					B.add(new path(nextInt, next.at));
				}

			}
		}
	}

	static HashMap<Integer, ArrayList<Integer>> direct = new HashMap<Integer, ArrayList<Integer>>();
	static int[] set;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] first = br.readLine().split(" ");
		int nodes = Integer.parseInt(first[0]);
		int edges = Integer.parseInt(first[1]);
		int q = Integer.parseInt(first[2]);
		set = new int[nodes];
		for (int count = 0; count < nodes; count++) {
			direct.put(count, new ArrayList<>());
			set[count] = count;
		}
		for (int count = 0; count < edges; count++) {
			String[] next = br.readLine().split(" ");
			int from = Integer.parseInt(next[0]) - 1;
			int to = Integer.parseInt(next[1]) - 1;
			direct.get(from).add(to);
			direct.get(to).add(from);
			merge(from, to);
		}
//		for(int count=0;count<nodes;count++) {
//			System.out.println(set[count]);
//		}
		for (int count = 0; count < q; count++) {

			String[] next = br.readLine().split(" ");
			System.out.println(connect(Integer.parseInt(next[0]) - 1, Integer.parseInt(next[1]) - 1));
		}
	}

}