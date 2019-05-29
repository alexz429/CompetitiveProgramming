package Misc;

import java.util.Scanner;

public class UnevenSand {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		long small=1;
		long big=2000000000;
		long mid=1000000000;
		System.out.println(mid);
		String next=sc.next();
		while(!next.equals("OK")) {

			System.out.flush();
			if(next.equals("FLOATS")) {
				big=mid;
				
			}
			else {
				small=mid;
				
			}
			mid=(small+big)/2;
			System.out.println(mid);
			next=sc.next();
		}
		sc.close();
	}

}
