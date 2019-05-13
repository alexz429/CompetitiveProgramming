package CCC._03;
import java.util.*;
public class J2_PicturePerfect {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int next=sc.nextInt();
		while(next!=0) {
			int left=(int)Math.sqrt(next);
			while(next%left!=0) {
				left--;
			}
			int right=next/left;
			System.out.println("Minimum perimeter is "+(left*2+right*2)+" with dimensions "+left+" x "+right);
			next=sc.nextInt();
		}
		sc.close();
	}

}
