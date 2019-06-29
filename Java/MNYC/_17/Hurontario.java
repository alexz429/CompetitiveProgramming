package MNYC._17;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Hurontario {

	
	
	static long MODULUS=Long.parseLong("8278737391");
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] first=br.readLine().split(" ");
		String left=first[0];
		String right=first[1];
		long leftH=0;
		int mem=left.length();
		int best=-1;
		long rightH=0;
		long power=1;
		
		int length=Math.min(left.length(), right.length());
		for(int count=0;count<length;count++) {
			leftH=(leftH+(left.charAt(mem-count-1)-'A')*power+MODULUS)%MODULUS;
			power=(power*26)%MODULUS;
			rightH=(rightH*26+right.charAt(count)-'A'+MODULUS)%MODULUS;
//			System.out.println(leftH+" "+rightH);
			if(leftH==rightH) {
				best=count;
			}
		}
		System.out.println(left+right.substring(best+1));
	}

}
