package _06;
import java.util.*;
public class J2_RollTheDice {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int m=sc.nextInt();
		int n=sc.nextInt();
		if(m>10){
			m=10;
		}
		if(n>10){
			n=10;
		}
		int out=0;
		for(int count=1;count<=m;count++){
			for(int count2=1;count2<=n;count2++){
				if(count+count2==10){
					out++;
				}
			}
		}
		if(out==1){
			System.out.println("There is 1 way to get the sum 10.");
		}
		else{
			System.out.println("There are "+out+" ways to get the sum 10.");
		}
		sc.close();
	}

}
