package _07;
import java.util.*;
public class S1_FederalVotingAge {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int max=sc.nextInt();
		for(int count=0;count<max;count++){
			int y=sc.nextInt();
			int m=sc.nextInt();
			int d=sc.nextInt();
			int age=2007-y;
			if(m>2||(m==2&&d>27)){
			age--;
			}
			if(age>=18){
				System.out.println("Yes");
			}
			else{
				System.out.println("No");
			}
			sc.close();
		}
	}

}
