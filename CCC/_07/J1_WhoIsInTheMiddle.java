package _07;
import java.util.*;
public class J1_WhoIsInTheMiddle {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int[] num=new int[3];
		for(int count=0;count<3;count++) {
			num[count]=sc.nextInt();
		}
		Arrays.sort(num);
		System.out.println(num[1]);
		sc.close();
	}

}
