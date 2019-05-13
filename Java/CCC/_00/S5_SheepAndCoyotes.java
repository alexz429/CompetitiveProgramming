package CCC._00;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class S5_SheepAndCoyotes {
	static class pair{
		double x;
		double y;
		public pair(double x, double y) {
			super();
			this.x = x;
			this.y = y;
		}
		
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		pair[] sheeps=new pair[max];
		boolean[] oof=new boolean[max];
		for(int count=0;count<max;count++) {
			sheeps[count]=new pair(Double.parseDouble(br.readLine()), Double.parseDouble(br.readLine()));
		}
		for(double count=0.00;count<=1000;count+=0.01) {
			double best=Integer.MAX_VALUE;
			int index=-1;
			for(int count2=0;count2<max;count2++) {
				double dis=Math.sqrt(Math.pow(Math.abs(count-sheeps[count2].x), 2)+Math.pow(sheeps[count2].y,2));
				if(dis<best) {
					best=dis;
					index=count2;
				}
			}
			oof[index]=true;
		}
		for(int count=0;count<max;count++) {
			if(oof[count]) {
				System.out.printf("The sheep at (%.2f, %.2f) might be eaten.\n", sheeps[count].x, sheeps[count].y);
			}
		}
		
		
	}
	

}
