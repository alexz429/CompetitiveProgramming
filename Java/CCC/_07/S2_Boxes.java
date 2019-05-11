package _07;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class S2_Boxes {
	static class box implements Comparable<box>{
		int x;
		int y;
		int z;
		int vol;
		public box(int x, int y, int z) {
			int[] lol= {x,y,z};
			Arrays.sort(lol);
			this.x=lol[0];
			this.y=lol[1];
			this.z=lol[2];
			vol=x*y*z;
		}
		public boolean bigger(box Other) {
			if(Other.x<x&&Other.y<y&&Other.z<z) {
				return true;
			}
			return false;
		}
		public int compareTo(box other) {
			return vol-other.vol;
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		box[] boxes=new box[max];
		for(int count=0;count<max;count++) {
			String[] next=br.readLine().split(" ");
			boxes[count]=new box(Integer.parseInt(next[0]),Integer.parseInt(next[1]),Integer.parseInt(next[2]));
		}
		int max2=Integer.parseInt(br.readLine());
		box[] items=new box[max2];
		Arrays.sort(boxes);
		for(int count=0;count<max2;count++) {

			String[] next=br.readLine().split(" ");
			items[count]=new box(Integer.parseInt(next[0]),Integer.parseInt(next[1]),Integer.parseInt(next[2]));
//			System.out.println(items[count].z+" "+items[count].y+" "+items[count].x);
		}
		for(int count=0;count<max2;count++) {
			boolean got=false;
			for(int count2=0;count2<max;count2++) {
				if(items[count].x<=boxes[count2].x&&items[count].y<=boxes[count2].y&&items[count].z<=boxes[count2].z) {
					got=true;
					System.out.println(boxes[count2].vol);
					break;
				}
			}
			if(!got) {
				System.out.println("Item does not fit.");
			}
		}
		
	}

}
