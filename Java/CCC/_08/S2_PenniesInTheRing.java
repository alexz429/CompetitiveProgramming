package CCC._08;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class S2_PenniesInTheRing {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int next=Integer.parseInt(br.readLine());
		while(next!=0) {
			int total=2*next+1;
//			System.out.println(total);
			for(int count=1;count<=next;count++) {
				total+=2*((int)Math.sqrt((Math.pow(next, 2)-Math.pow(count, 2)))*2+1);
//				System.out.println(total);
			}
			System.out.println(total);
			next=Integer.parseInt(br.readLine());
		}
	}

}
