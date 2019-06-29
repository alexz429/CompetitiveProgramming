package Olympiads.Jun08;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;

public class CommonDivisor {
	
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] third=br.readLine().split(" ");
		long a=Long.parseLong(third[0]);
		long b=Long.parseLong(third[1]);
		int digit=Integer.parseInt(third[2]);
		HashSet<Long> left=new HashSet<>();
		HashSet<Long> right=new HashSet<>();
		left.add(a);
		right.add(b);
		for(long count=2;count<=Math.sqrt(a);count++) {
			if(a%count==0) {
				left.add(count);
				left.add(a/count);
			}	
		}
		for(long count=2;count<=Math.sqrt(b);count++) {
			if(b%count==0) {
				right.add(count);
				right.add(b/count);
			}
		}
		HashSet<Long> hit=new HashSet<>();
		hit.add((long)1);
		for(long next:left) {
			if(right.contains(next)) {
				hit.add(next);
			}
		}
		long[] convert=new long[hit.size()];
//		System.out.println(convert.length);
		int index=0;
		for( long next:hit) {
//			System.out.println(next);
			convert[index]=next;
			index++;
		}
		Arrays.sort(convert);
		if(convert.length-digit<0) {
			System.out.println(-1);
			return;
		}
		System.out.println(convert[convert.length-digit]);
	}

}
