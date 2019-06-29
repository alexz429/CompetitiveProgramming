package DMOPC._18_1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class P3_Sorting {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		String[] second=br.readLine().split(" ");
		int[] vals=new int[max];
		for(int count=0;count<max;count++) {
			vals[count]=Integer.parseInt(second[count]);
		}
		int total=0;
		Queue<Queue<Integer>> out=new LinkedList<>();
		for(int count=0;count<max;count++) {
			if(vals[count]==count+1) continue;
//			System.out.println("_----");
			Queue<Integer> next=new LinkedList<>();
		
			HashSet<Integer> at=new HashSet<>();
			int trace=count;
			while(!at.contains(trace)) {
//				System.out.println(trace+" "+(vals[trace]-1));
				next.add(trace+1);
				total++;
				at.add(trace);
				int temp=vals[trace];
				vals[trace]=trace+1;
				trace=temp-1;
			}
			out.add(next);
		}
		if(out.size()<=2) {
			System.out.println(out.size());
			for(Queue<Integer> next:out) {
				System.out.print(next.size());
				for(int output:next) {
					System.out.print(" "+output);
				}
				System.out.println();
			}
		}
		else {
			for(int count=0;count<max;count++) {
				vals[count]=Integer.parseInt(second[count]);
			}
			System.out.println(2);
			int prev=-1;
			int firstIndex=0;
			System.out.print(out.size());
			while(!out.isEmpty()) {
				Queue<Integer> next=out.poll();
				int nextNum=next.poll()-1;
				if(prev==-1) {
					prev=vals[nextNum];
					firstIndex=nextNum;
				}
				else {
					int temp=vals[nextNum];
					vals[nextNum]=prev;
					prev=temp;
				}
				System.out.print(" "+(nextNum+1));
			}
			System.out.println();
			
			vals[firstIndex]=prev;
//			for(int output:vals) {
//				System.out.print(output+" ");
//			}
//			System.out.println();
			Queue<Integer> last=new LinkedList<>();
			for(int count=0;count<max;count++) {
				if(vals[count]==count+1) continue;
//				System.out.println("_----");
				
				HashSet<Integer> at=new HashSet<>();
				int trace=count;
				while(!at.contains(trace)) {
//					System.out.println(trace+" "+(vals[trace]-1));
					last.add(trace+1);
					at.add(trace);
					int temp=vals[trace];
					vals[trace]=trace+1;
					trace=temp-1;
				}
				break;
			}
			System.out.print(last.size());
			for(int next:last) {
				System.out.print(" "+next);
			}
			
		}
		
		
	}

}
