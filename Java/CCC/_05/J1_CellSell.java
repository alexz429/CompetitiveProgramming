package CCC._05;
import java.util.*;
public class J1_CellSell {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		double day=sc.nextDouble();
		double eve=sc.nextDouble();
		double end=sc.nextDouble();
		double a=0;
		if( day>100){
			 a=(day-100)*25+eve*15+end*20;
		}
		else{
			 a=eve*15+end*20;
		}
		a/=100;
		System.out.println("Plan A costs "+a);
		double b=0;
		if(day>250){
			 b=(day-250)*45+eve*35+end*25;
		}
		else{
			b=eve*35+end*25;
		}
		b/=100;
		System.out.println("Plan B costs "+b);
		if(b>a){
			System.out.println("Plan A is cheapest.");
		}
		else{
			if(a>b){
				System.out.println("Plan B is cheapest.");
			}
			else{
				System.out.println("Plan A and B are the same price.");
			}
		}
		sc.close();
	}

}
