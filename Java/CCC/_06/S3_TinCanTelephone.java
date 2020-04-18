package CCC._06;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class S3_TinCanTelephone {
	public static class Vector{
		int x,y;

		public Vector(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		public String toString() {
			return x+" "+y;
		}
		public boolean equals(Vector other) {
			if(x==other.x&&y==other.y) {
				return true;
			}
			return false;
		}
	}
	static class House{
		Vector[] points;
		public House(int in) {
			points=new Vector[in];
		}
	}
	static boolean Cross(Vector start, Vector end, Vector[] next) {
		
		Vector[] points=next;
		if(!intersect(start, end, points[0], points[points.length-1]))return false;
		for(int count=0;count<points.length-1;count++) {
			if(!intersect( start, end, points[count],points[count+1]))return false;
		}
		
		return true;
	}
	static boolean intersect(Vector start, Vector end, Vector left, Vector right) {
		if(start.equals(left)||start.equals(right)||end.equals(left)||end.equals(right)) {
			return false;
		}
//		System.out.println("__________________"+start+" "+end+" "+left+" "+right);
		boolean cross=false;
		int a=crossProd(start, end, left);
		
		int b=crossProd(start, end, right);
//		System.out.println(a+" "+b);
		if(a*b<0||a==0||b==0) {
//			System.out.println("pop");
			cross=true;
		}
		
		a=crossProd(left, right, end);
		b=crossProd(left, right, start);
//		System.out.println(a+" "+b);
		if(a*b<0) {
//			System.out.println("pop");
			if(cross) {
				return false;
			}
			
		}
		
		Vector rand=new Vector((int)((Math.random()*2000)-1000),(int)((Math.random()*2000)-1000));
		while(crossProd(start, end, rand)==0) {
			rand=new Vector((int)((Math.random()*2000)-1000),(int)((Math.random()*2000)-1000));
		}
		if((a==0&&crossProd(rand, left, end)*crossProd(rand, right, end)<0)||(b==0&&crossProd(rand, left, start)*crossProd(rand, right, start)<0)) {
			return false;
		}
		
		return true;
	}
	public static int crossProd(Vector a, Vector b, Vector c) {//if 0, AB parallel to AC; if > 0, AB Counter ClockWise of AC; if <0, AB ClockWise of AC
		return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] first=br.readLine().split(" ");
		
		int startX=Integer.parseInt(first[0]);
		int startY=Integer.parseInt(first[1]);
		int endX=Integer.parseInt(first[2]);
		int endY=Integer.parseInt(first[3]);
		Vector start=new Vector(startX, startY);
		Vector end=new Vector(endX, endY);
		int houses=Integer.parseInt(br.readLine());
		
		int add=0;
		for(int count=0;count<houses;count++) {
			String[] next=br.readLine().split(" ");
			
			Vector[] points=new Vector[Integer.parseInt(next[0])];
			for(int count2=0;count2<Integer.parseInt(next[0]);count2++) {
				points[count2]=new Vector(Integer.parseInt(next[1+2*count2]),Integer.parseInt(next[2+2*count2]));
			}
			if(!Cross(start,end,points)) {
				add++;
				
			}
		}
		System.out.println(add);
		
	}

}
