package CCC._06;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class J3_CellPhoneMessaging {
	static class letter{
		int keys;
		HashSet<String> other=new HashSet<>();
		letter(int keys, HashSet<String> in){
			
			this.keys=keys;
			other=in;
		}
		
	}
	static void init(){
		HashSet<String> next= new HashSet<>();
		next.add("b");
		next.add("a");
		next.add("c");
		direct.put("a", new letter(1,next));
		direct.put("b", new letter(2,next));
		direct.put("c", new letter(3,next));
		next=new HashSet<>();
		next.add("d");
		next.add("e");
		next.add("f");
		direct.put("d", new letter(1,next));
		direct.put("e", new letter(2,next));
		direct.put("f", new letter(3,next));
		next=new HashSet<>();
		next.add("g");
		next.add("h");
		next.add("i");
		direct.put("g", new letter(1,next));
		direct.put("h", new letter(2,next));
		direct.put("i", new letter(3,next));
		next=new HashSet<>();
		next.add("j");
		next.add("k");
		next.add("l");
		direct.put("j", new letter(1,next));
		direct.put("k", new letter(2,next));
		direct.put("l", new letter(3,next));
		next=new HashSet<>();
		next.add("m");
		next.add("n");
		next.add("o");
		direct.put("m", new letter(1,next));
		direct.put("n", new letter(2,next));
		direct.put("o", new letter(3,next));
		next=new HashSet<>();
		next.add("p");
		next.add("q");
		next.add("r");
		next.add("s");
		direct.put("p", new letter(1,next));
		direct.put("q", new letter(2,next));
		direct.put("r", new letter(3,next));
		direct.put("s", new letter(4,next));
		next=new HashSet<>();
		next.add("t");
		next.add("u");
		next.add("v");
		direct.put("t", new letter(1,next));
		direct.put("u", new letter(2,next));
		direct.put("v", new letter(3,next));
		next=new HashSet<>();
		next.add("w");
		next.add("x");
		next.add("y");
		next.add("z");
		direct.put("w", new letter(1,next));
		direct.put("x", new letter(2,next));
		direct.put("y", new letter(3,next));
		direct.put("z",new letter(4,next));
		
	}//god this was painful
	static HashMap<String,letter> direct=new HashMap<>();
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		init();
		while(sc.hasNext()) {
			String next=sc.next();
			if(next.equals("halt")) {
				sc.close();
				return;
			}
			int tally=0;
			char prev='?';
			for(int count=0;count<next.length();count++) {
				char stuff=next.charAt(count);
				if(prev!='?'&&direct.get(prev+"").other.contains(stuff+"")) {
					tally+=2;
				}
				//System.out.println(stuff+"");
				tally+=direct.get(stuff+"").keys;
				prev=stuff;
			}
			System.out.println(tally);
		}
		sc.close();
		
	}

}