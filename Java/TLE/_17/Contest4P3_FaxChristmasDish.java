package TLE._17;

import java.util.Scanner;
public class Contest4P3_FaxChristmasDish {
	static int[] dir;
	static int[] req;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int nodes=sc.nextInt();
		int edges=sc.nextInt();
		int days=sc.nextInt();
		dir = new int[nodes+1];
		req = new int[nodes+1];
		for(int count=0;count<edges;count++) {
			int item=sc.nextInt();
			req[item]=sc.nextInt();
			for(int count2=0;count2<req[item];count2++) {
				int next=sc.nextInt();
				dir[next]=item;
			}
		}
		for(int count=0;count<days;count++) {
		int next=sc.nextInt();
		req[next] = 0;
		while(req[next] == 0 && dir[next]!=0) {
			req[dir[next]]--;
			int temp = next;
			next = dir[next];
			dir[temp] = 0;
		}
		if(req[1]==0) {
			System.out.println(count+1);
			return;
		}
		}
		System.out.println(-1);
		
	}

}