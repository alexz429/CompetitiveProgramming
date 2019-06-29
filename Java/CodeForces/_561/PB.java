package CodeForces._561;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class PB {
	static class pair {
		int a;
		int b;

		public pair(int a, int b) {
			super();
			this.a = a;
			this.b = b;
		}

		public String toString() {
			return a + " " + b;
		}
	}

	static pair fo5(int in) {
		for (int count = (int) (Math.sqrt(in)) + 1; count >= 5; count--) {
			if (in % count == 0) {
				if (in / count >= 5) {
					return new pair(count, in / count);
				}
			}
		}
		return null;
	}
	static char[][] set= {{'a','e','i','o','u'},{'e','a','o','u','i'},{'i','u','a','e','o'},{'o','i','u','a','e'},{'u','o','e','i','a'}};
	static void fill(int x, int y, char[][] output) {
		for(int count=0;count<5;count++) {
			for(int count2=0;count2<5;count2++) {
				output[count+x][count2+y]=set[count][count2];
			}
		}
	}
	static void fillVert(int x, char[][] output) {
		for(int count=0;count<5;count++) {
			output[x][count]=set[0][count];
		}
	}
	static void fillHori(int x, char[][] output) {
		for(int count=0;count<5;count++) {
			output[count][x]=set[0][count];
		}
	}
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int in = Integer.parseInt(br.readLine());
		pair process = fo5(in);
//		System.out.println(process);
		if (process == null) {
			System.out.println(-1);
			System.exit(0);
		}
		char[][] out=new char[process.a][process.b];
		for(int count=0;count<out.length;count++) {
			Arrays.fill(out[count], 'a');
		}
		for(int count=0;5+count*5<=process.a;count++) {
			for(int count2=0;5+count2*5<=process.b;count2++) {
				fill(count*5, count2*5, out);
			}
		}
		for(int count=0;count<process.a%5;count++) {
			fillVert(process.a-count-1, out);
		}
		for(int count=0;count<process.b%5;count++) {
			fillHori(process.b-count-1, out);
		}
		for(char[] next:out) {
			for(char oof:next) {
				System.out.print(oof);
			}
			
		}
	}

}
