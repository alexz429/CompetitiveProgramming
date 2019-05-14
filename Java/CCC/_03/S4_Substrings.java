package CCC._03;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;

public class S4_Substrings {
	static long SENTINEL=(long) 1.48764065e17;
	static  HashMap<Integer, Integer> hash=new HashMap<>();
	static void init() {
		int index=0;
		for(int i=48;i<58;i++) {
			hash.put(i, index);
			index++;
		}
		for(int i=65;i<91;i++) {
			hash.put(i, index);
			index++;
		}
		for(int i=97;i<123;i++) {
			hash.put(i, index);
			index++;
		}
	}
	static long roll(long prev, char next) {
		prev=(prev*62+hash.get((int)next))%SENTINEL;
		return prev;
	}
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		init();
		for(int count=0;count<max;count++) {
			String next=br.readLine();
			HashSet<Long> visited=new HashSet<>();
			visited.add((long)0);
			for(int count2=0;count2<next.length();count2++) {
				long init=0;
				for(int count3=count2;count3<next.length();count3++) {
					
					
					char nextC=next.charAt(count3);
					if(count3==count2) {
						init=hash.get((int)nextC);
					}
					else {
						init=roll(init, nextC);
					}
					visited.add(init);
				}
			}
			System.out.println(visited.size());
		}
	}

}
