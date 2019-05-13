package CCC._03;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
public class S3_FloorPlan {
	static char[][] grid;
	static int max;
	static int Recurse( int X, int Y) {
		if(X<0||X>=grid.length||Y<0||Y>=grid[0].length) {
			return 0;
		}
		if(grid[X][Y]=='I') {
			return 0;
		}
		grid[X][Y]='I';
		int out=1;
		out+=Recurse(X-1,Y);
		out+=Recurse(X+1,Y);
		out+=Recurse(X,Y-1);
		out+=Recurse(X,Y+1);
		return out;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		max=sc.nextInt();
		int W=sc.nextInt();
		int L=sc.nextInt();
		ArrayList<Integer> sizes=new ArrayList<Integer>();
		
		grid=new char[W][L];
		for(int count=0;count<W;count++) {
			String in=sc.next();
		//	System.out.println(in.length());
			for(int count2=0;count2<L;count2++) {
				grid[count][count2]=in.charAt(count2);
			}
		}
		for(int count=0;count<W;count++) {
			for(int count2=0;count2<L;count2++) {
				if(grid[count][count2]!='I') {
					sizes.add(Recurse(count,count2));
				}
			}
		}
		Collections.sort(sizes);
		int count;
		for(count=0;sizes.size()>0&&sizes.get(sizes.size()-1)<=max;count++) {
			
			max-=sizes.get(sizes.size()-1);
			sizes.remove(sizes.size()-1);
		}
		if(count==1) {
			System.out.println(count+" room, "+max+" square metre(s) left over");
		}
		else {
			System.out.println(count+" rooms, "+max+" square metre(s) left over");
		}
		sc.close();
		
		
	}

}