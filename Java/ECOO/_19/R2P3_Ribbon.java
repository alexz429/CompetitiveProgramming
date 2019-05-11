package _19;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

public class R2P3_Ribbon {
	static class diffArray{
		HashMap<Integer, Integer> array=new HashMap<>();
		
		
		public int[] build() {
			int[] out=new int[array.size()];
			int count=0;
			for(int next:array.keySet()) {
				out[count]=next;
				count++;
				
			}
			Arrays.sort(out);
			int[] output=new int[out[out.length-1]-out[0]];
			int length=out[out.length-1]-out[0];
			int prev=0;
			int best=0;
			for(count=0;count<out.length;count++) {

				prev+=array.get(out[count]);
				
				best=Math.max(prev, best);
				
			}
			System.out.println(length+" "+best);
			return output;
		}
		public diffArray(int num) {
			array.put(1, 1);
			
			array.put(num+1, -1);
		}
		public String toString() {
			String huh="";
			for(int next:array.keySet()) {
				huh+=next+" "+array.get(next)+" ";
			}
			return huh;
		}
		public void fold(int index, boolean dir) {//false is right
			HashMap<Integer, Integer> newHash=new HashMap<>();  
			if(dir) {
				int totalFold=0;
				for(int next:array.keySet()) {
					int val=array.get(next); 
					if(val==0)continue;
					if(next<index) {
						
						 int target=index*2-next;
						 totalFold+=val;
						 if(target==index)continue;
						 val=-val;
						 if(newHash.containsKey(target)) {
							 val+=newHash.get(target);
						 }
						 
						 newHash.put(target, val);

//							System.out.println("1:PUT "+val+" INTO "+(target));
					 }
					 else {
						 if(newHash.containsKey(next)) {
							 val+=newHash.get(next);
						 }
						 newHash.put(next, val);
//						 System.out.println("2:PUT "+val+" INTO "+(next));
					 }
				}
				
				
					array=newHash;
					totalFold*=2;
					if(array.containsKey(index)) {
						totalFold+=array.get(index);
					}
					array.put(index, totalFold);
//					System.out.println("3:PUT "+(totalFold)+" INTO "+(index));
				
			}
			else {
				int totalFold=0;
				int extraFold=0;
				for(int next:array.keySet()) {
				
					int val=array.get(next);

//					System.out.println(next+" "+index);
					if(val==0) continue;
					if(next>index+1) {
						int target=index*2+2-next;
						
//						System.out.println(target);
						if(target==index+1)continue;
						val=-val;
						if(newHash.containsKey(target)) {
							val+=array.get(target);
//							System.out.println("4: ADD "+array.get(target));
							
						}
//						if(val!=0) {
							newHash.put(target,val);	
//						}

//							System.out.println("1:PUT "+val+" INTO "+(target));
					}
					else {
						if(next==index+1) {
							extraFold=val;
						}
						else {
							totalFold+=val;
						}
						 if(newHash.containsKey(next)) {
							 val+=newHash.get(next);
						 }
						 newHash.put(next, val);

//						 System.out.println("2:PUT "+val+" INTO "+(next));
					 }
				}
				//				newHash.put(size,Integer.MIN_VALUE);
				
					array=newHash;
//					System.out.println((totalFold)+" "+(totalFold+extraFold));
					totalFold*=2;
					totalFold+=extraFold;
					array.put(index+1, -totalFold);
//					System.out.println("3:PUT "+(totalFold)+" INTO "+(index+1));
				
			}
			
			
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
//		BufferedReader br=new BufferedReader(new FileReader("C:\\Users\\alex.zhang\\Desktop\\DATA31.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		for(int x=0;x<10;x++) {
			String[] first=br.readLine().split(" ");
			
			int max=Integer.parseInt(first[0]);
			int folds=Integer.parseInt(first[1]);
			diffArray diff=new diffArray(max);
			for(int count=0;count<folds;count++) {
				String[] next=br.readLine().split(" ");
				int index=Integer.parseInt(next[0]);
				boolean in=false;
				if(next[1].equals("L")) {
					in=true;
				}
				diff.fold(index, in);
				
			}
			diff.build();
			
		}
		
		
	}
}
