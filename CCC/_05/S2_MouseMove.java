package _05;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class S2_MouseMove {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] first=br.readLine().split(" ");
		int x=Integer.parseInt(first[0]);
		int y=Integer.parseInt(first[1]);
		int nx=0;
		int ny=0;
		while(true) {
			String[] next=br.readLine().split(" ");
			int ax=Integer.parseInt(next[0]);
			int ay=Integer.parseInt(next[1]);
			if(ax==0&&ay==0) {
				break;
			}
			nx+=ax;
			ny+=ay;
			nx=Math.min(x, nx);
			nx=Math.max(nx, 0);
			ny=Math.min(y, ny);
			ny=Math.max(ny, 0);
			System.out.println(nx+" "+ny);
		}
	}

}
