package Misc;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Tester {
	public static long createValue(String in){
		long start=0;
		for(int count=0;count<in.length();count++) {
			start=(start*HASH+(in.charAt(count)-'a'))%MODULUS;

		}
		return start;
	}
	public static long roll(long was, char prev, char after) {
		was=(was+MODULUS-(POWER*(prev-'a'))%MODULUS)%MODULUS;
		was=(was*HASH+(after-'a'))%MODULUS;
		return was;
	}
	// the length of the substring to find
	static int HASH=26;
		static int LENGTH;
		//randomly chosen prime value to act as modulus
		static long MODULUS=Long.parseLong("8278737391");
		//saved value to remove the trailing letters (equal to (26^LENGTH-1)%MODULUS) to prevent recomputing times
		static long POWER=1;
	public static void main(String[] args) throws Exception{
		for(int count=0;count<LENGTH-1;count++) {
			POWER=(POWER*(long)26)%MODULUS;
		}
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String next=br.readLine();
		String next2=br.readLine();
		long nextVal2=createValue(next2);
		long nextVal=createValue(next);
		
		nextVal/=HASH;
		System.out.println(nextVal+" "+nextVal2);
	}
}	
