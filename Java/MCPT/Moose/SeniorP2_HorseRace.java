package MCPT.Moose;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;
public class SeniorP2_HorseRace {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	public static double poi(int m1,int m2, int x1,int x2) {
		int diff = m1-m2;
		int progress= x2-x1;
//		System.out.println(diff+" "+progress);
		return (double)progress/diff;
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int n = readInt();
		int number = 0;
		int time = 0;
		int place = 0;
		int min = 10000000;
		int[][] horses = new int [n][2];
		
		for(int i = 0; i < n; i++) {
			horses[i][0] = readInt();
			horses[i][1] = readInt();
			min = Math.min(min, horses[i][0]+horses[i][1]);
		}
		HashMap<Integer, Integer> vals= new HashMap<>();
		int most = 1;
		int times = 1;
		int dis = min;
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				double next = poi(horses[i][1], horses[j][1], horses[i][0], horses[j][0]);
//				System.out.println(next);
				if(next>0&&next==(int)next) {
//					System.out.println(i+" "+j+" "+next);
					vals.put((int)next, vals.containsKey((int)next)?vals.get((int)next)+1:2);
				}
			}
//			System.out.println();
			for(int next: vals.keySet()) {
				int nextVal = vals.get(next);

//				System.out.print(next+" "+nextVal);
				if(nextVal>most) {
					most = nextVal;
					times = next;
					dis = next*horses[i][1]+horses[i][0];
				}
				else if(nextVal==most) {
					if(times>next) {
						most = nextVal;
						times = next;
						dis = next*horses[i][1]+horses[i][0];
					
					}
					else if(times==next) {
						if(dis>next*horses[i][1]+horses[i][0]) {
							most = nextVal;
							times = next;
							dis = next*horses[i][1]+horses[i][0];
						}
					}
				}
			}
			vals = new HashMap<>();
		}
		System.out.println(most+" "+times+" "+dis);

	}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static char readCharacter() throws IOException {
		return next().charAt(0);
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}
