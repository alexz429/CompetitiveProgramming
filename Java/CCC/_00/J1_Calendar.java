
import java.util.*;
public class J1_Calendar {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int start=sc.nextInt();
		int days=sc.nextInt();
		System.out.println("Sun Mon Tue Wed Thr Fri Sat");
		for(int count=0;count<start-1;count++){
			System.out.print("    ");
		}
	
		int week=start-1;
		int lol=1;
		while(lol!=days+1){
			week++;
			//System.out.print(week);
			if(week>7){
				System.out.println();
				week=1;
			}
			//if(lol<days+1) {
				System.out.print(" ");
			//}
			
			if(lol<10){
				System.out.print(" ");
			}
			System.out.print(lol);
			if(week!=7&&lol<days){
				System.out.print(" ");
			}
			if(lol==days) {
				System.out.println();
			}
			lol++;
			
		}
		sc.close();
	}

}
