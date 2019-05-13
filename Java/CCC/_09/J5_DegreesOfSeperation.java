package CCC._09;

import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
public class J5_DegreesOfSeperation {
	static HashMap<Integer, HashSet<Integer>> direct=new HashMap<>();
	static void setup() {
		for(int count=1;count<=50;count++) {
			direct.put(count, new HashSet<Integer>());
		}
		connect(1,6);

		connect(2,6);

		connect(7,6);
		connect(5,6);
		connect(4,6);
		connect(3,6);
		connect(4,5);
		connect(4,3);
		connect(3,5);
		connect(3,15);
		connect(15,13);
		connect(13,14);
		connect(13,12);
		connect(12,11);
		connect(11,10);
		connect(10,9);

		connect(9,12);
		connect(9,8);
		connect(8,7);
		connect(18,16);
		connect(18,17);
		connect(16,17);
	}// fml
	static void connect(int x, int y) {
		direct.get(x).add(y);
		direct.get(y).add(x);
		
	}
	static void remove(int x, int y) {
		direct.get(x).remove(y);
		direct.get(y).remove(x);
	}
	static void size(int x) {
		System.out.println(direct.get(x).size());
	}
	static void second(int x) {
		HashSet<Integer> checked=new HashSet<>();
		checked.add(x);
		int tally=0;
		for(int next:direct.get(x)) {
			checked.add(next);
		}
		for(int next:direct.get(x)) {
			for(int lol:direct.get(next)) {
				if(!checked.contains(lol)) {
					checked.add(lol);
					tally++;
				}
			}
		}
		System.out.println(tally);
	}
	static void sep(int x, int y) {
		HashSet<Integer> checked=new HashSet<>();
		Queue<Integer> queue=new LinkedList<Integer>();
		queue.add(x);
		int tally=0;
		while(!queue.isEmpty()) {
			int max=queue.size();
			for(int count=0;count<max;count++) {
				int next=queue.poll();
				if(checked.contains(next)) {
					continue;
				}
				if(next==y) {
					System.out.println(tally);
					return;
				}
				checked.add(next);
				for(int adj:direct.get(next)) {
					queue.add(adj);
				}
			}
			tally++;
		}
		System.out.println("Not connected");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		setup();
		while(sc.hasNext()) {
			String com=sc.next();
			switch(com) {
			case "q":
				return;
			case "i":
				connect(sc.nextInt(),sc.nextInt());
				break;
			case "d":
				remove(sc.nextInt(),sc.nextInt());
				break;
			case "n":
				size(sc.nextInt());
				break;
			case "f":
				second(sc.nextInt());
				break;
			case "s":
				sep(sc.nextInt(),sc.nextInt());
				break;
			}
			
		}
		sc.close();
	}

}
