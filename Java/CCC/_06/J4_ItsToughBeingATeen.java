package CCC._06;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class J4_ItsToughBeingATeen {
	static HashMap<Integer, ArrayList<Integer>> limit=new HashMap<>();
	static HashMap<Integer,ArrayList<Integer>> lock=new HashMap<>();
	
	static void add(int from, int to) {
		limit.get(from).add(to);
		lock.get(to).add(from);
	}
	static int scan() {
		for(int count=1;count<8;count++) {
			if(!canDo.contains(count)) {
				if(lock.get(count).size()==0) {
					return count;
				}
			}
			
		}
		return -1;
	}
	static HashSet<Integer> canDo=new HashSet<Integer>();
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		
		for(int count=1;count<8;count++) {
			limit.put(count, new ArrayList<Integer>());
			lock.put(count, new ArrayList<Integer>());
		}
		add(1,7);
		add(1,4);
		add(2,1);
		add(3,4);
		add(3,5);
		int from=sc.nextInt();
		int to=sc.nextInt();
		while(from!=0&&to!=0) {
			add(from,to);
			//System.out.println("ok");
			from=sc.nextInt();
			to=sc.nextInt();
			
		}
		int[] out=new int[7];
		for(int count=0;count<7;count++) {
			int lol=scan();
			if(lol==-1) {
				break;
			}
			
			ArrayList<Integer> next=limit.get(lol);
			Integer secLol=lol;
			for(int release:next) {
				
				lock.get(release).remove(secLol);
			}
			out[count]=lol;
			
			canDo.add(lol);
		}
		if(canDo.size()==7) {
			for(int next:out) {
				System.out.println(next);
			}
		}
		else {
			System.out.println("Cannot complete these tasks. Going to bed.");
		}
		sc.close();
	}
	
}
