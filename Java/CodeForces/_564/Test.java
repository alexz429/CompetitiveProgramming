package CodeForces._564;

import java.util.Scanner;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int x=sc.nextInt();
		int y=sc.nextInt();
		int z=sc.nextInt();
		if(x>y+z) {
			System.out.println("+");
			return;
		}
		if(y>x+z) {
			System.out.println("-");
			return;
		}
		if(x==y&&z>0) {
			System.out.println("?");
			return;
		}
		if(x==y&&z==0) {
			System.out.println("0");
			return;
		}
		if(x==y+z) {
			System.out.println("?");
			return;
		}
		if(y==x+z) {
			System.out.println("?");
			return;
		}
		
	}

}
