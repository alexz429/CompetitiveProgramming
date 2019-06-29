package Misc;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Kirito {
	static class node{
		int id;
		boolean leaf;
		int min;
		public node(int id, boolean leaf) {
			this.id=id;
			this.leaf=leaf;
		}
		public node(int min, int id) {
			this.min=min;
			this.id=id;
			leaf=false;
		}
	}
	static class segTree {
		node[] vals;
		int maxIndex;
		int size;
		long[] initArray;
		public segTree(int num) {
			size=num;
			maxIndex = 2 * (1 << Integer.toBinaryString(num).length());
			struct(1,0,size-1);
		}
		public void struct(int at, int left, int right) {
			if(left==right) {
				vals[at]=new node(right, true);
			}
			int mid = (left + right) / 2;
			struct(at * 2 + 1, mid+1, right);
			struct(at * 2, left, mid);
			if(vals[at*2].leaf&&vals[at*2+1].leaf) {
				vals[at]=new node( lcp(vals[at*2].id,vals[at*2+1].id), vals[at*2].id);
			
			}
			else if(vals[at*2].leaf) {
				vals[at]=new node(Math.min(vals[at*2+1].min, lcp(vals[at*2].id, vals[at*2+1].id)), vals[at*2].id);
			}
			else if(vals[at*2+1].leaf) {
				vals[at]=new node(Math.min(vals[at*2].min, lcp(vals[at*2+1].id, vals[at*2].id)), vals[at*2+1].id);
			}
			else {
				vals[at]=new node(Math.min(vals[at*2].min, vals[at*2+1].min), vals[at*2].id);
			}
		}
		public int get(int at, int left, int right, int l, int r) {
			if(left>r||right<l) {
				return Integer.MAX_VALUE;
			}
			if(left>=l&&right<=r) {
				return vals[at].min;
			}
			int mid=(left+right)/2;
			int a=get(at*2, left, mid, l,r);
			int b=get(at*2+1, mid+1, right, l,r);
			return Math.min(a, b);
		}
		public void change(int target,int id, int at, int left, int right) {
			if(left==right&&right==target) {
				vals[at].id=id;
				return;
			}
			
		}
	}
	static long[] createValue(String in) {
		long start=0;
		long[] huh=new long[in.length()];
		
		for(int count=0;count<in.length();count++) {
			start=(start*HASH+in.charAt(count)-'0')%MODULUS;
			huh[count]=start;
		}
		return huh;
	}
	static int lcp(int a, int b) {
		int l=0,r=LENGTH;
		
		while(l<r) {
			int mid=(l+r)/2;
			if(hashes[a][mid]==hashes[b][mid]) {
				l=mid+1;
			}
			else {
				r=mid;
			}
		}
		return r;
	}
	static long[][] hashes;
	static long HASH=2;
	static long POWER=1;
	static int LENGTH;
	static long MODULUS=Long.parseLong("8278737391");
	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] first=br.readLine().split(" ");
		int rows=Integer.parseInt(first[0]);
		LENGTH=Integer.parseInt(first[1]);
		for(int count=0;count<LENGTH;count++) {
			POWER=(POWER*HASH)%MODULUS;
		}
		hashes=new long[rows][LENGTH];
		for(int count=0;count<rows;count++) {
			hashes[count]=createValue(br.readLine());
		}
		
				
	}
}
