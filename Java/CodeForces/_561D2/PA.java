package CodeForces._561D2;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class PA {
	static int choose2(int num) {
		int out=num*(num-1);
		return out/2;
	}
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		for(int count=0;count<=50;count++) {
			System.out.println(choose2(count));
		}
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int[] students=new int[26];
		int max=Integer.parseInt(br.readLine());
		for(int count=0;count<max;count++) {
			char next=br.readLine().charAt(0);
			students[next-'a']++;
		}
		int tally=0;
		for(int next:students) {
			if(next%2!=0) {
				tally+=choose2(next/2);
				tally+=choose2(next/2+1);
			}
			else {
				tally+=(choose2(next/2)*2);
			}
		}
		System.out.println(tally);
	}

}
