package _05;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class S5_PinballRanking {
	static class node{
		int value;
		int height;
		int amount;
		node left;
		node right;
		int l;
		int r;
		public node(int value, int height, node left, node right) {
			super();
			this.value = value;
			this.height = height;
			this.left = left;
			this.right = right;
		}
		public node(int value, int height) {
			this.value=value;
			this.height=height;
			
		}
		public node(int value) {
			this.value=value;
			height=1;
			l=0;
			r=0;
			amount=1;
		}
		
	}
	static class bbst{
		node head;
		int val=0;
		public node rotateRight(node at) {
			node temp=at.left;
			at.left=at.left.right;
			temp.right=at;
			at.l=getNum(at.left);
			temp.r=getNum(at);
			at.height=Math.max(getHeight(at.left), getHeight(at.right))+1;
			temp.height=Math.max(getHeight(temp.left), getHeight(at.right))+1;
			return temp;
		}
		public node rotateLeft(node at) {
			node temp=at.right;
			at.right=at.right.left;
			temp.left=at;
			at.r=getNum(at.right);
			temp.l=getNum(at);

			at.height=Math.max(getHeight(at.left), getHeight(at.right))+1;
			temp.height=Math.max(getHeight(temp.left), getHeight(at.right))+1;
			return temp;
		}
		public int addTop(int key) {
			val=0;
			if(head==null) {
				head=new node(key);
				return 1;
			}
			head=pass(head, key);
			
			return val+1;
		}
		static int getNum(node n) {
			return n==null? 0:(n.l+n.r+n.amount);
		}
		static int getHeight(node n) {
			return n==null? 0:n.height;
		}
		public node pass(node at, int key) {
			
			if(at==null) {
				return new node(key);
			}
//			System.out.println(at.value);
			if(key<at.value) {
//				System.out.println(at.value+" l "+(at.r+at.amount));
				at.l++;

				val+=at.r+at.amount;
				at.left=pass(at.left, key);
			}
			else if (key==at.value){
				at.amount++;
				val+=at.r;
				return at;
			}
			else {
//				System.out.println(at.value+" r");
				at.r++;
				at.right=pass(at.right,key);
			}
			int leftHeight=getHeight(at.left);
			int rightHeight=getHeight(at.right);
			at.height=1+Math.max(leftHeight,rightHeight);
			int balance=leftHeight-rightHeight;
//			System.out.println(balance+" a "+at.value);
			if(Math.abs(balance)<2) {
				return at;
			}
			if(balance>1&&key<at.left.value) {
				return rotateRight(at);
			}
			else if(balance<-1&&key>at.right.value) {
				return rotateLeft(at);
			}
			else if(balance>1&&key>at.left.value) {
				at.left=rotateLeft(at.left);
				return rotateRight(at);
			}
			else {
				at.right=rotateRight(at.right);
				return rotateLeft(at);
			}
			
			
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int max=Integer.parseInt(br.readLine());
		bbst tree=new bbst();
		long tally=0;
		for(int count=0;count<max;count++) {
			int next=Integer.parseInt(br.readLine());
			int add=tree.addTop(next);
//			System.out.println(add);
			tally+=add;
		}
		tally*=1000;
		tally=(int)((double)tally/max);
		if(tally%10>4) {
			tally+=10;
		}
		tally/=10;
		System.out.print(tally/100+".");
		if(tally%100==0) {
			System.out.println("00");
		}
		else {
			System.out.println(tally%100);
		}
	}

}
