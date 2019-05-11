package _07;
import java.util.*;
public class J3_DealOrNoDeal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int[] vals=new int[10];
		vals[0]=100;
		vals[1]=500;
		vals[2]=1000;
		vals[3]=5000;
		vals[4]=10000;
		vals[5]=25000;
		vals[6]=50000;
		vals[7]=100000;
		vals[8]=500000;
		vals[9]=1000000;
		int max=sc.nextInt();
		for(int count=0;count<max;count++) {
			vals[sc.nextInt()-1]=0;
		}
		double ave=0;
		for(int count=0;count<10;count++) {
			ave+=vals[count];
		}
		ave/=(10-max);
		if(ave>sc.nextInt()) {
			System.out.println("no deal");
		}
		else {
			System.out.println("deal");
		}
		sc.close();
	}

}
