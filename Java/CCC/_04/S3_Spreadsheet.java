package CCC._04;
import java.util.*;
public class S3_Spreadsheet {
	static long[][] grid;
	
	static String[][] orders=new String[10][9];

	static long solve(int x, int y) {
		if(grid[x][y]==-2) {
			return -2;
		}
		if(grid[x][y]!=-1) {
			return grid[x][y];
		}
		else {
			grid[x][y]=-2;
			long out=0;
			String[] adds=orders[x][y].split("\\+");
			for(int count=0;count<adds.length;count++) {
				int x2=adds[count].charAt(0)-65;
				adds[count]=adds[count].substring(1, 2);
				int y2=Integer.parseInt(adds[count])-1;
				
				long next=solve(x2,y2);
				if(next==-2) {
					return -2;
				}
				else {
					out+=next;
				}
				
			}
			grid[x][y]=out;
			return out;
		}
	
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		grid=new long[10][9];
		
		for(int count=0;count<10;count++) {
			String next=sc.nextLine();
			String[] lol=next.split(" ");
			for(int count2=0;count2<9;count2++) {
				if(lol[count2].charAt(0)>64&&lol[count2].charAt(0)<91) {
					orders[count][count2]=lol[count2];
					grid[count][count2]=-1;
					
				}
				else {
					int nextnum=Integer.parseInt(lol[count2]);
					grid[count][count2]=nextnum;
				}
			}
		}
		for(int count=0;count<10;count++) {
			for(int count2=0;count2<9;count2++) {
				long next=solve(count,count2);
				if(next!=-2) {
					System.out.print(next);
				}
				else {
					System.out.print("*");
				}
				if(count2<8) {
					System.out.print(" ");
				}
			}
			System.out.println();
		}
		sc.close();
	}

}
