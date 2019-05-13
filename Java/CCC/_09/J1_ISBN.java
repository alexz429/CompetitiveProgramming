package CCC._09;
import java.util.Scanner;
public class J1_ISBN {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		int out=a*1+b*3+c*1+1;
		
			out=out+90;
			System.out.println("The 1-3-sum is "+out);
		sc.close();
	}

}
