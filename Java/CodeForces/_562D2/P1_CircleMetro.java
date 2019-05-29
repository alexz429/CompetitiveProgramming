package CodeForces._562D2;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class P1_CircleMetro {
	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] in=br.readLine().split(" ");
		int max=Integer.parseInt(in[0]);
		int starta=Integer.parseInt(in[1])-1;
		int enda=Integer.parseInt(in[2])-1;
		int startb=Integer.parseInt(in[3])-1;
		int endb=Integer.parseInt(in[4])-1;
		
		for(int count=0;true;count++) {
			int nexta=(starta+count+max)%max;
			int nextb=(startb-count+max)%max;
			System.out.println(nexta+" "+nextb);
			if(nextb==nexta) {
				System.out.println("YES");
				System.exit(0);
			}
			if(nexta==enda||nextb==endb) {
				break;
			}
		}
		System.out.println("NO");
	}
}
