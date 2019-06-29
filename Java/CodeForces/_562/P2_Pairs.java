package CodeForces._562;
//NOT DONE
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;

public class P2_Pairs {
	static class pair {
		int x;
		int y;

		public pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		public boolean contains(int num) {
			return (x == num || y == num);
		}
	}

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] first = br.readLine().split(" ");
		int pairs = Integer.parseInt(first[1]);
		pair[] set = new pair[pairs];
		for (int count = 0; count < pairs; count++) {
			String[] next = br.readLine().split(" ");
			set[count] = new pair(Integer.parseInt(next[0]), Integer.parseInt(next[1]));

		}
		int test = set[0].x;
		int out = -1;
//		System.out.println(test);
		HashSet<Integer> done = new HashSet<>();
		done.add(0);
		for (int count = 1; count < pairs; count++) {
			if (set[count].contains(test)) {
				done.add(count);
			} else {
				out = out == -1 ? count : out;
			}
		}
		if (out == -1) {
			System.out.println("YES");
			return;
		}
		int test2 = set[out].x;
		int tally = done.size();

//		System.out.println(test2);
		for (int count = out; count < pairs; count++) {
			if (done.contains(count))
				continue;
			if (set[count].contains(test2)) {
				tally++;
			}
		}
		if (tally == pairs) {
			System.out.println("YES");
			return;
		}
		test2 = set[out].y;
		tally = done.size();

//		System.out.println(test2);
		for (int count = out; count < pairs; count++) {
			if (done.contains(count))
				continue;
			if (set[count].contains(test2)) {
				tally++;
			}
		}
		if (tally == pairs) {
			System.out.println("YES");
			return;
		}
		test = set[0].y;
		out = -1;
		done = new HashSet<>();
		done.add(0);
//		System.out.println(test);
		for (int count = 1; count < pairs; count++) {
			if (set[count].contains(test)) {
				done.add(count);
			} else {
				out = out == -1 ? count : out;
			}
		}
		if (out == -1) {
			System.out.println("YES");
			return;
		}
		test2 = set[out].x;
		tally = done.size();

//		System.out.println(test2);
		for (int count = out; count < pairs; count++) {
			if (done.contains(count))
				continue;
			if (set[count].contains(test2)) {
				tally++;
			}
		}
		if (tally == pairs) {
			System.out.println("YES");
			return;
		}
		test2 = set[out].y;
		tally = done.size();

//		System.out.println(test2+" "+tally);
		for (int count = out; count < pairs; count++) {
			if (done.contains(count))
				continue;
			if (set[count].contains(test2)) {
				tally++;
			}
		}
//		System.out.println(tally);
		if (tally == pairs) {
			System.out.println("YES");
			return;
		}
		System.out.println("NO");

	}

}
