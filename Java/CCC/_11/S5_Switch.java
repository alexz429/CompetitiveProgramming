package _11;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
public class S5_Switch {
	
	static int clear(int in, int limit, int at) {
		int streak=0;
		int l;
		int r;
		for(r=at;r<limit+1;r++) {
			int next=(in>>r)&1;
			//System.out.print(next);
			if(next==1) {
				streak++;
			}
			else {
			
				break;
			}
		}
		r--;
		for(l=at-1;l>=0;l--) {
			int next=(in>>l)&1;
			if(next==1) {
				streak++;
			}
			else {
				break;
			}
		}
		l++;
		if(streak>=4) {
//			System.out.println(l+" to "+r);
			for(int count=l;count<=r;count++) {
				in^=(1<<count);
			}
		}
		
		return in;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		byte length=Byte.parseByte(br.readLine());
		int start=0;
		for(int count=0;count<length;count++) {
			start+=(1<<count)*Integer.parseInt(br.readLine());
		}
		boolean[] visited=new boolean[32505856];
		Queue<Integer> queue=new LinkedList<>();
		queue.add(start);
		int step=0;
		while(!queue.isEmpty()) {
			int max=queue.size();
			
			for(int count=0;count<max;count++) {
				int next=queue.poll();
				if(visited[next]) {
					continue;
				}
visited[next]=true;
				
				
				if(next==0) {
					System.out.println(step);
					
					return;
				}
				for(int count2=0;count2<length;count2++) {
					if(((1<<count2)&next)==0) {
						queue.add(clear(next+(1<<count2), length, count2));
					}
					
				}
				
				
			}
			step++;
		}
	}

}