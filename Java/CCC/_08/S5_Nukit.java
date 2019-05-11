package _08;

import java.util.Scanner;
public class S5_Nukit {
	static boolean[][][][] wins=new boolean[31][31][31][31];
	static boolean determine(int a, int b, int c, int d) {
		if((a-2>=0&&b-1>=0&&d-2>=0)&&(wins[a-2][b-1][c][d-2]==false)) {
			return true;
		}
		if((a-1>=0&&b-1>=0&&c-1>=0&&d-1>=0)&&(wins[a-1][b-1][c-1][d-1]==false)) {
			return true;
		}
		if((a>=0&&b>=0&&c-2>=0&&d-1>=0)&&(wins[a][b][c-2][d-1]==false)) {
			return true;
		}
		if((a>=0&&b-3>=0&&c>=0&&d>=0)&&(wins[a][b-3][c][d]==false)) {
			return true;
		}
		if((a-1>=0&&b>=0&&c>=0&&d-1>=0)&&(wins[a-1][b][c][d-1]==false)) {
			return true;
		}
		return false;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		for(int count=0;count<31;count++) {
			for(int count2=0;count2<31;count2++) {
				for(int count3=0;count3<31;count3++) {
					for(int count4=0;count4<31;count4++) {
						wins[count][count2][count3][count4]=determine(count,count2,count3,count4);
					}
				}
			}
		}
		//System.out.println("done");
		int max=sc.nextInt();
		for(int count=0;count<max;count++) {
			int a=sc.nextInt();
			int b=sc.nextInt();
			int c=sc.nextInt();
			int d=sc.nextInt();
			if(wins[a][b][c][d]) {
				System.out.println("Patrick");
			}
			else {
				System.out.println("Roland");
			}
		
		}
		sc.close();
	}

}