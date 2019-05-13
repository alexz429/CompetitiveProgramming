package CCC._04;
import java.util.*;
public class J2_TermsOfOffice {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int from=sc.nextInt();
		int to=sc.nextInt();
		int lol=to-from;
		
		for(int count=0;count<=lol;count+=60){
			int out=count+from;
			System.out.println("All positions change in year "+out);
		}
		sc.close();
	}

}
