package DMOPC._18_4;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class P3_HenriAndIonization {

	static class electron implements Comparable<electron>{
		int a;
		int b;
		int diff;
		public electron(int a, int b) {
			super();
			this.a = a;
			this.b = b;
			diff=a-b;
		}

		public int compareTo(electron other) {
			return other.diff-diff;
		}
	}
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		String second[]=br.readLine().split(" ");
		String third[]=br.readLine().split(" ");
		electron stuff[]=new electron[max];
		for(int count=0;count<max;count++) {
			stuff[count]=new electron(Integer.parseInt(second[count]), Integer.parseInt(third[count]));
		}
		Arrays.sort(stuff);
//		System.out.println(stuff[0].a);
		int tally=0;
		int count=0;
		for(;count+1<max&&(stuff[count].diff+stuff[count+1].diff>=0);count+=2) {
			tally+=stuff[count].b+stuff[count+1].b;
		}
//		System.out.println(count);
		for(;count<max;count++) {
			tally+=stuff[count].a;
		}
		System.out.println(tally);
	}

}
