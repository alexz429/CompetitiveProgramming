package CodeForces.Global3;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class C {
	static void swap(int from, int to) {
		int temp = vals[from];
		vals[from] = vals[to];
		vals[to] = temp;
		int a=from+1;
		int b=to+1;
		if (max <= Math.abs(from - to) * 2) {
			tally++;
			com.add(a);
			com.add(b);
		} else {
			
			if (from < max / 2) {
				if(to<max/2) {
					tally += 3;
					com.add(a);
					com.add(max);
					com.add(b);
					com.add(max);
					com.add(a);
					com.add(max);
				}
				else {
					tally += 5;
					com.add(a);
					com.add(max);
					com.add(b);
					com.add(1);
					com.add(max);
					com.add(1);
					com.add(a);
					com.add(max);
					com.add(b);
					com.add(1);
					
				}
			} else {
				if(to<max/2) {
					tally += 5;
					com.add(a);
					com.add(1);
					com.add(b);
					com.add(max);
					com.add(max);
					com.add(1);
					com.add(a);
					com.add(1);
					com.add(b);
					com.add(max);
				}
				else {
					tally += 3;
					com.add(a);
					com.add(1);
					com.add(b);
					com.add(1);
					com.add(a);
					com.add(1);
				}
			}
		}
		
	}

	static int tally;
	static Queue<Integer> com;
	static int[] vals;
	static int max;

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		max = Integer.parseInt(br.readLine());
		String[] second = br.readLine().split(" ");
		vals = new int[max];
		for (int count = 0; count < max; count++) {
			vals[count] = Integer.parseInt(second[count]);
		}

		com = new LinkedList<>();
		int count = 0;
		while (count < max) {
			if (vals[count] - 1 == count) {
				count++;
			} else {
				swap(vals[count] - 1, count);
//				for(int next:vals) {
//					System.out.print(next+" ");
//					
//				}
//				System.out.println();
			}
		}
		System.out.println(tally);
		while(!com.isEmpty()) {
			System.out.println(com.poll()+" "+com.poll());
		}
	}

}
