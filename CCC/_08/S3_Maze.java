package _08;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class S3_Maze {
	static class pair{
		int x;
		int y;
		public pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		for(int count3=0;count3<max;count3++) {

			int tall=Integer.parseInt(br.readLine());
			int length=Integer.parseInt(br.readLine());
			char[][] grid=new char[tall][length];
			for(int count=0;count<tall;count++) {
				String next=br.readLine();
				for(int count2=0;count2<length;count2++) {
					grid[count][count2]=next.charAt(count2);
				}
			}
			Queue<pair> queue=new LinkedList<>();
			queue.add(new pair(0,0));
			int steps=0;
			boolean done=false;
			while(!queue.isEmpty()) {
				int max2=queue.size();
				steps++;
				for(int count=0;count<max2;count++) {
					pair next=queue.poll();
					if(next.x<0||next.y<0||next.x==tall||next.y==length) {
						continue;
					}

//					System.out.println(next.x+ " "+next.y+" "+grid[next.x][next.y]);
					if(grid[next.x][next.y]=='*') {
						continue;
					}
					
					if(next.x==tall-1&&next.y==length-1) {
//						System.out.println("got");
						done=true;
						break;
					}
					if(grid[next.x][next.y]=='+') {
						queue.add(new pair(next.x-1,next.y));
						queue.add(new pair(next.x+1,next.y));
						queue.add(new pair(next.x,next.y-1));
						queue.add(new pair(next.x,next.y+1));
						
					}
					else if(grid[next.x][next.y]=='-') {
//						System.out.println("Accross");
						queue.add(new pair(next.x,next.y-1));
						queue.add(new pair(next.x,next.y+1));
						
					}
					else {
						queue.add(new pair(next.x-1,next.y));
						queue.add(new pair(next.x+1,next.y));
						
					}
					grid[next.x][next.y]='*';
				}
				if(done) {
					break;
				}
			}
			if(done) {
				System.out.println(steps);
					
			}
			else {
				System.out.println(-1);
			}
			
		}
	}

}
