package CCC._02;
import java.util.Scanner;
public class S2_FractionAction {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=a%b;
		a=a/b;
		int bash=1;
		while(bash!=0) {
			bash=0;
			for(int count=2;count<=c;count++) {
				//System.out.println(c+" "+b);
				if(c%count==0&&b%count==0) {
					bash=1;
					c=c/count;
					b=b/count;
					break;
				}
			}
		}
		if(a>0) {
			if(c>0) {
				System.out.println(a+" "+c+"/"+b);
			}
			else {
				System.out.println(a);
			}
		}
		else {
			if(c>0) {
				System.out.println(c+"/"+b);
			}
		}
		sc.close();
	}

}
