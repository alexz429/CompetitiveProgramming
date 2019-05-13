package CCC._08;
import java.util.*;
public class J1_BodyMassINdex {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int weight=sc.nextInt();
		double high=sc.nextDouble();
		high=weight/(high*high);
		System.out.println(high);
		if(high>25) {
			System.out.println("Overweight");
		}
		else if(high<18.5) {
			System.out.println("Underweight");
		}
		else {
			System.out.println("Normal weight");
		}
		sc.close();
	}
	

}
