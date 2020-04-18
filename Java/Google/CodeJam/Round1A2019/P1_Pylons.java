package CodeJam.Round1A2019;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class P1_Pylons {
	
	static boolean recurse(int x, int y, boolean[][] visited, int step) {
//		System.out.println(step);
		if(step==rows*cols) {
			command.add((x+1)+" "+(y+1));
			return true;
		}
		
		for(int count=0;count<rows;count++) {
			for(int count2=0;count2<cols;count2++) {
				if(visited[count][count2]||count==x||count2==y||x-y==count-count2||x+y==count+count2) {
					continue;
				}
				visited[count][count2]=true;
				if(recurse(count, count2, visited, step+1)) {
					command.add((x+1)+" "+(y+1));
					return true;
				}
				visited[count][count2]=false;
			}
		}
		return false;
	}
	static int rows;
	static int cols;
	static Queue<String> command;
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
	
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		for(int count=0;count<max;count++) {
			String[] in=br.readLine().split(" ");
			rows=Integer.parseInt(in[0]);
			cols=Integer.parseInt(in[1]);
			boolean[][] visited=new boolean[rows][cols];
			boolean good=false;
			command=new LinkedList<>();
			for(int count3=0;count3<rows&&!(good);count3++) {
				for(int count2=0;count2<cols&&!(good);count2++) {
					
					visited[count3][count2]=true;
					if(recurse(count3, count2, visited, 1)) {
						System.out.println("Case #"+(count+1)+": POSSIBLE");
						for(String next:command) {
							System.out.println(next);
						}
						good=true;
					}
						visited[count3][count2]=false;
					
				}
			}
			if(!good) {
				System.out.println("Case #"+(count+1)+": IMPOSSIBLE");
			}
		}
	}

}
