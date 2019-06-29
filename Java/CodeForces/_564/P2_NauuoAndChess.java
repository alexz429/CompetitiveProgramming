package CodeForces._564;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class P2_NauuoAndChess {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		int target=max/2+1;
		System.out.println(target);
		for(int count=1;count<=max;count++) {
			if(count<=target) {
				System.out.println(1+" "+(count));
			}
			else {
				System.out.println((count-target+1)+" "+target);
			}
		}
	}

}
