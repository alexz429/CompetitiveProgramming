package Misc;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class XORMinimum {

	static class node{
		node one;
		node zero;

		int location=-1;
		public node(int val) {
			super();
		}
		public void add(int num, int index, int location) {
			if(index<0) {
				if(this.location==-1) {
					this.location=location;
				}
				return;
			}
			if((num&(pres[index]))==0) {
						
				if(zero==null) {
					zero=new node(0);
				}
				zero.add(num, index-1, location);
			}
			else {
				if(one==null) {
					one=new node(1);
				}
				one.add(num, index-1, location);
			}
			
		}
		public boolean contains(int num,  int index) {
			if(index<0)return true;
			if((num&(pres[index]))==0) {
				if(zero==null)return false;
				return zero.contains(num, index-1);
			}
			if(one==null)return false;
			return one.contains(num, index-1);
		}
		public void query(int comp, int index) {
			if(index<0) {
				System.out.println(location);
				return;
			}
			if((comp&(pres[index]))==0) {
				if(zero!=null) {
					zero.query(comp, index-1);
				}
				else {
					one.query(comp, index-1);
				}
			}
			else {
				if(one!=null) {
					one.query(comp, index-1);
				}
				else {
					zero.query(comp, index-1);
				}
			}
		}
		public void update(int comp, int index) {
			if(index<0)return;
			if((comp&(pres[index]))==0) {
				if(one!=null) {
					one.update(comp, index-1);
				}
				if(zero!=null) {
					zero.update(comp, index-1);
				}
			}
			else {
				node temp=one;
				node temp2=zero;
				one=temp2;
				zero=temp;
				if(one!=null) {
					one.update(comp, index-1);
				}
				if(zero!=null) {
					zero.update(comp, index-1);
				}
			}
		}
	}
	static class trie{
		node head=new node(0);
	int length;
	public trie(int length) {
		this.length=length;
	}
		public void add(int num, int index) {
			
			head.add(num, length, index);
		}
		public boolean contains(int num) {
			return head.contains(num, length);
		}
		public void query(int comp) {
			head.query(comp, length);
			
		}
		public void update(int comp) {
			head.update(comp, length);
		}
	}
	static int[] pres=new int[32];
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		int prev=0;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] first=br.readLine().split(" ");
		int max=Integer.parseInt(first[0]);
		int q=Integer.parseInt(first[1]);
		String[] second=br.readLine().split(" ");
		trie lol=new trie(31);
		for(int count=0;count<32;count++) {
			pres[count]=(1<<count);
		}
		for(int count=0;count<max;count++) {
			lol.add(Integer.parseInt(second[count]), count);
//			System.out.println(trace);
//			System.out.println(lol.contains(Integer.parseInt(second[count])));
		}
		for(int count=0;count<q;count++) {
			int next=Integer.parseInt(br.readLine());
			prev^=next;
			lol.query(prev);
		}
	}
	

}
