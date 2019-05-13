package CCC._01;
import java.util.*;
public class J2_ModInverse {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int x=sc.nextInt();
		int y=sc.nextInt();
		int got=0;
		for(int count=0;count<y;count++) {
			if((x*count)%y==1) {
				System.out.println(count);
				got=1;
				break;
			}
		}
		if(got==0) {
			System.out.println("No such integer exists.");
		}
		sc.close();
		}

}
