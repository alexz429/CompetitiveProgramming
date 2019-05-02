package _05;
import java.util.*;
public class J2_RSANumbers {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int from=sc.nextInt();
		
		int to=sc.nextInt();
		int out=0;
		for(int count=from;count<=to;count++){
			int RSA=0;
			for(int count2=1;count2<=count;count2++){
				if(count%count2==0){
					RSA++;
					if(RSA>4){
						break;
					}
				}
			}
			if(RSA==4){
				out++;
			}
		}
		System.out.println("The number of RSA numbers between "+from+" and "+to+" is "+out);
		sc.close();
	}

}
