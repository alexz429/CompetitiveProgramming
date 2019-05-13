package CCC._01;

import java.util.Scanner;
public class J1_DressingUp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int max=sc.nextInt();
		for(int count=0;count<(max/2)+1;count++){
			System.out.println();
			for(int count2=0;count2<count*2+1;count2++){
				System.out.print("*");
			}
			for(int count2=0;count2<max*2-(count*2+1)*2;count2++){
				System.out.print(" ");
			}
			for(int count2=0;count2<count*2+1;count2++){
				System.out.print("*");
			}
		}
		for(int count=0;count<max/2;count++){
			System.out.println();
			for(int count2=0;count2<max-(count+1)*2;count2++){
				System.out.print("*");
			}
			for(int count2=0;count2<(count+1)*4;count2++){
				System.out.print(" ");
			}
			for(int count2=0;count2<max-(count+1)*2;count2++){
				System.out.print("*");
			}
		}
		sc.close();
	}

}
