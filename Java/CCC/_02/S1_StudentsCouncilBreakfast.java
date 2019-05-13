package CCC._02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class S1_StudentsCouncilBreakfast {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int a=Integer.parseInt(br.readLine());
		int b=Integer.parseInt(br.readLine());
		int c=Integer.parseInt(br.readLine());
		int d=Integer.parseInt(br.readLine());
		int end=Integer.parseInt(br.readLine());
		int tally=0;
		int best=Integer.MAX_VALUE;
		for(int count=0;count*a<=end;count++) {
			
			for(int count2=0;count2*b<=end;count2++) {
				for(int count3=0;count3*c<=end;count3++) {
					for(int count4=0;count4*d<=end;count4++) {
						if(count*a+count2*b+count3*c+count4*d==end) {
							System.out.println("# of PINK is "+count+" # of GREEN is "+count2+" # of RED is "+count3+" # of ORANGE is "+count4);
							tally++;
							best=Math.min(best, count+count2+count3+count4);
						}
					}
				}
			}
		}
		System.out.println("Total combinations is "+tally+".");
		System.out.println("Minimum number of tickets to print is "+best+".");
	}

}
