package ECOO._14;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class R2P3_EasySweeper {
	static class pair {
		int x;
		int y;
		int require;

		public pair(int x, int y, int require) {
			super();
			this.x = x;	
			this.y = y;
			this.require = require;
		}

		static boolean check(pair at, int[][] grid) {
			int blank = 0;
			int hit = 0;
			for (int count = 0; count < 3; count++) {
				for (int count2 = 0; count2 < 3; count2++) {
					int x = at.x - 1 + count;
					int y = at.y - 1 + count2;
					if (x < 0 || y < 0 || x >= grid.length || y >= grid.length) {

						continue;
					}
					if (grid[x][y] == 1) {
						hit++;
					} else if (grid[x][y] == 0) {
						blank++;
					}
				}
			}
			if (hit == at.require) {
				for (int count = 0; count < 3; count++) {
					for (int count2 = 0; count2 < 3; count2++) {
						int x = at.x - 1 + count;
						int y = at.y - 1 + count2;
						if (x < 0 || y < 0 || x >= grid.length || y >= grid.length) {
							continue;
						}
						if (grid[x][y] == 0) {
							grid[x][y] = -1;
						}
					}
				}
				return true;
			} else if (hit + blank == at.require) {
				for (int count = 0; count < 3; count++) {
					for (int count2 = 0; count2 < 3; count2++) {
						int x = at.x - 1 + count;
						int y = at.y - 1 + count2;
						if (x < 0 || y < 0 || x >= grid.length || y >= grid.length) {
							continue;
						}
						if (grid[x][y] == 0) {
							grid[x][y] = 1;
						}
					}
				}
				return true;
			}
			return false;
//			return tally==at.require;

		}

	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int i = 0; i < 5; i++) {
			int max = Integer.MAX_VALUE;
			int[][] grid = null;
			Queue<pair> queue = new LinkedList<>();
			boolean set = false;
			for (int count = 0; count < max; count++) {
//				System.out.println(count);
				String in = br.readLine();
				if (!set) {
					max = in.length();
					grid = new int[max][max];
					set = true;
				}
				for (int count2 = 0; count2 < max; count2++) {

					char next = in.charAt(count2);
					if (next != '-') {
						queue.add(new pair(count, count2, next - '0'));
					}
				}

			}
//			System.out.println("done");
			while (!queue.isEmpty()) {
				pair next = queue.poll();
				if (pair.check(next, grid)) {
//					System.out.println("finished "+next.x+" "+next.y);
				} else {
					queue.add(next);
				}
			}
			for (int count = 0; count < max; count++) {
				for (int count2 = 0; count2 < max; count2++) {
					System.out.print(grid[count][count2] == 1 ? "M" : ".");
				}
				System.out.println();
			}

		}

	}
}
