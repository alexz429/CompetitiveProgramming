package _00;
import java.util.*;
public class J3_SlotMachines {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int max=sc.nextInt();
		int first=sc.nextInt();
		int second=sc.nextInt();
		int third=sc.nextInt();
		int total=0;
		while(max!=0){
			total+=max;
			int cycle=max/3;
			for(int count=0;count<cycle;count++){
				first++;
				second++;
				third++;
			}
			max%=3;
			if(max==1){
				first++;
			}
			else{
				if(max==2){
					second++;
					first++;
				}
			}
			max=0;
			while(first>=35){
				first-=35;
				max+=30;
			}
			while(second>=100){
				second-=100;
				max+=60;
			}
			while(third>=10){
				third-=10;
				max+=9;
			}
				
		}
		System.out.println("Martha plays "+total+" times before going broke.");
		sc.close();
	}

}
