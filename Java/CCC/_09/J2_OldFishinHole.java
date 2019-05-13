package CCC._09;
import java.util.Scanner;
public class J2_OldFishinHole {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		int pike=sc.nextInt();
		int pick=sc.nextInt();
		int total=sc.nextInt();
		int out=0;
		for(int count=0;count*t<=total;count++) {
			for(int count2=0;count2*pike<=total;count2++) {
				for(int count3=0;count3*pick<=total;count3++) {
					if(count!=0||count2!=0||count3!=0) {
						if(count*t+count2*pike+count3*pick<=total) {
							System.out.println(count+" Brown Trout, "+count2+" Northern Pike, "+count3+" Yellow Pickerel");
							out++;
						}
					}
					
				}
			}
		}
		System.out.println("Number of ways to catch fish: "+out);
		sc.close();
		
	}
}