package Olympiads.Jun08;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class MaxProfit {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		String[] second=br.readLine().split(" ");
		String[] third=br.readLine().split(" ");
		long tally=0;
		for(int count=0;count<max;count++) {
			tally+=(Math.max(Integer.parseInt(second[count])-Integer.parseInt(third[count]), 0));
		}
		System.out.println(tally);
	}

}
