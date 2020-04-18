package CCC._04;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Spreadsheet {
	static int[][] graph = new int[10][9];
	static String[][] com = new String[10][9];
	static int solve(int x, int y) {// -2 as NA
		if(graph[x][y]>=0) {
			return graph[x][y];
		}
		if(graph[x][y] == -2) {
			return -2;
		}
		String[] commands = com[x][y].split("\\+");//A9, A1
		int tally = 0;
		graph[x][y] =-2;
		for(int i=0;i<commands.length;i++) {
			int nextX = commands[i].charAt(0)-'A';
			int nextY = commands[i].charAt(1)-'1';
			int temp = solve(nextX, nextY);
			if(temp == -2) {
				return -2;
			}
			tally += temp;
		}
		
		graph[x][y] = tally;
		return tally;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		for(int i=0;i<10;i++) {
			String[] next=br.readLine().split(" ");
			for(int j=0;j<9;j++) {
				if(next[j].charAt(0)>=48&&next[j].charAt(0)<=57) {
					graph[i][j] = Integer.parseInt(next[j]);
				}
				else {
					graph[i][j] = -1; // signal its a command
					com[i][j] = next[j];
				}
			}
		}
		for(int i=0;i<10;i++) {
			for(int j=0;j<9;j++) {
				if(graph[i][j]>=0) {
					System.out.print(graph[i][j]);	
				}
				else {
					graph[i][j] = solve(i,j);
					if(graph[i][j]==-2) {
						System.out.print("*");
					}
					else {
						System.out.print(graph[i][j]);
					}
				}
				if(j!=8) {
					System.out.print(" ");
				}
			}
			System.out.println();
		}
	}
}
