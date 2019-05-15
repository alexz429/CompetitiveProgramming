package CCC._09;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class S5_Wireless {
	static int[][] diff;
	static void create() {
		for(int count=0;count<diff.length;count++) {
			int prev=0;
			for(int count2=0;count2<diff[0].length;count2++) {
				prev+=diff[count][count2];
				diff[count][count2]=prev;
			}
		}
	}
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int rows=Integer.parseInt(br.readLine());
		int cols=Integer.parseInt(br.readLine());
		diff=new int[rows][cols];
		int wires=Integer.parseInt(br.readLine());
		for(int count=0;count<wires;count++) {
			String[] next=br.readLine().split(" ");
			int x=Integer.parseInt(next[0])-1;
			int y=Integer.parseInt(next[1])-1;
			int range=Integer.parseInt(next[2]);
			int bit=Integer.parseInt(next[3]);
//			System.out.println("+++++++++++++++++++++++++++++++++++++");
			for(int count2=-range;count2<=range;count2++) {
				int nextY=count2+y;
				if(nextY<0||nextY>=diff.length) {
					continue;
				}
				int gap=(int)Math.sqrt(Math.pow(range, 2)-Math.pow(count2, 2));
//				System.out.println(gap);
				int leftX=x-gap;
				int rightX=x+gap+1;
//				System.out.println(nextY+" FROM "+leftX+" TO "+rightX+" "+gap+" "+count2);
				if(leftX>-1&&leftX<diff[0].length) {
					diff[nextY][leftX]+=bit;
				}
				else {
					diff[nextY][0]+=bit;
				}
				if(rightX>-1&&rightX<diff[0].length)diff[nextY][rightX]-=bit;
				
			}
		}
		int best=0;
		int tally=0;
		create();
		for(int[] next:diff) {
			for(int out:next) {
				if(out>best) {
					tally=1;
					best=out;
				}
				else if(out==best) {
					tally++;
				}
			}
		}
		System.out.println(best);
		System.out.println(tally);
	}

}
