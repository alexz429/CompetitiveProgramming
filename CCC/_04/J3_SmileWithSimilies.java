package _04;
import java.util.*;
public class J3_SmileWithSimilies {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int max=sc.nextInt();
		int max2=sc.nextInt();
		String[] a=new String[max];
		String[] b=new String[max2];
		for(int count=0;count<max;count++) {
			a[count]=sc.next();
		}
		for(int count=0;count<max2;count++) {
			b[count]=sc.next();
		}
		for(int count=0;count<max;count++) {
			for(int count2=0;count2<max2;count2++) {
				System.out.println(a[count]+" as "+b[count2]);
			}
		}
		sc.close();
	}

}
