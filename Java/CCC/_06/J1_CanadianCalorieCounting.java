package _06;
import java.util.*;
public class J1_CanadianCalorieCounting {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int num=sc.nextInt();
		int total=0;
		if(num==1) {
			total+=461;
		}
		else {
			if(num==2) {
				total+=431;
			}
			else {
				if(num==3) {
					total+=420;
				}
			}
		}
		num=sc.nextInt();
		//System.out.println(total);
		if(num==1) {
			total+=100;
		}
		else {
			if(num==2) {
				total+=57;
			}
			else {
				if(num==3) {
					total+=70;
				}
				
			}
		}
		num=sc.nextInt();
		//System.out.println(total);
		if(num==1) {
			total+=130;
		}
		else {
			if(num==2) {
				total+=160;
			}
			else {
				if(num==3) {
					total+=118;
				}
			}
		}
		
		num=sc.nextInt();
		//System.out.println(total);
		if(num==1) {
			total+=167;
		}
		else {
			if(num==2) {
				total+=266;
			}
			else {
				if(num==3) {
					total+=75;
				}
			}
		}
		System.out.println("Your total Calorie count is "+total+".");
		sc.close();
	}

}
