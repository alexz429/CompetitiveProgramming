package CCC._17;

import java.util.Scanner;
public class S1_SumGame {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int max=sc.nextInt();
		sc.nextLine();
		String one=sc.nextLine();
		String two=sc.nextLine();
		String[][] lol=new String[2][];
		lol[0]=one.split(" ");
		lol[1]=two.split(" ");
		int vals=0;
		int up=0;
		for(int count=0;count<max;count++) {
			vals+=Integer.parseInt(lol[0][count])-Integer.parseInt(lol[1][count]);
			if(vals==0) {
				up=count+1;
			}
		}
		
		
		System.out.println(up);
	}

}