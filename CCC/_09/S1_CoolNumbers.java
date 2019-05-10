package _09;

import java.util.HashSet;
import java.util.Scanner;
public class S1_CoolNumbers {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int from=sc.nextInt();
		int to=sc.nextInt();
		int square1=(int)Math.sqrt(from);
		int square2=(int)Math.sqrt(to);
		if(square1*square1!=from){
			square1++;
		}
		
		int cube1=(int)Math.cbrt(from);
		int cube2=(int)Math.cbrt(to);
	if(cube1*cube1*cube1!=from){
			cube1++;
		}
		
		HashSet<Integer> square=new HashSet<Integer>();
		/*System.out.println(cube1);
		System.out.println(cube2);
		System.out.println(square1);
		System.out.println(square2);*/
		int cool=0;
		for(int count=square1;count<=square2;count++){
			square.add(count*count);
			
		}
		
		//System.out.println(square.size());
		for(int count=cube1;count<=cube2;count++){
			if(square.contains(count*count*count)){
				cool++;
				//System.out.println(count*count*count);
			}
		}
		
		
		
		System.out.println(cool);
		sc.close();
	}

}