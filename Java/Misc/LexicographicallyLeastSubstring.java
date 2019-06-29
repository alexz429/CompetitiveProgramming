package Misc;
//NOT DONE
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class LexicographicallyLeastSubstring {
	
	
	
	
	
	static long[] powers;
	static long[] powers2;
	static int length;
	static long mod=Long.parseLong("921504606846523");
	static long mod2=Long.parseLong("921504676846573");
	public static void main(String[] args)throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String in=br.readLine();
		length=Integer.parseInt(br.readLine());
		powers=new long[length+1];
		powers2=new long[length+1];
		long power=1;
		long power2=1;
		long hash=0;
		long hash2=0;
		long hashes[]=new long[in.length()];
		long hashes2[]=new long[in.length()];
		for(int count=0;count<in.length();count++) {
			hash=((hash*26)%mod+(in.charAt(count)-'a')%mod)%mod;
			hash2=((hash2*40)%mod2+(in.charAt(count)-'a')%mod2)%mod2;
//			System.out.println(hash);
			hashes[count]=hash;
			hashes2[count]=hash2;
		}
		for(int count=0;count<=length;count++) {
			powers[count]=power;
			powers2[count]=power2;
			power=(power*26)%mod;
			power2=(power2*40)%mod2;
		}
		
		int best=0;
		
		for(int count=1;count<=in.length()-length;count++) {
			
//			System.out.println(count);
			if(in.charAt(best)<in.charAt(count))continue;
			if(in.charAt(best)>in.charAt(count)) {
				best=count;
				continue;
			}
			int left=0, right=length-1;
			while(left<right) {
//				System.out.println(left+" "+right);
				int mid=(left+right)/2;
				long prev;
				long prev2;
				
				if(best==0) {
					prev=hashes[best+mid];
					prev2=hashes2[best+mid];
				}
				else {
					 prev=(hashes[best+mid]-(hashes[best-1]*powers[mid+1])%mod+mod)%mod;
					 prev2=(hashes2[best+mid]-(hashes2[best-1]*powers2[mid+1])%mod2+mod2)%mod2;
				}
				long cur=(hashes[count+mid]-(hashes[count-1]*powers[mid+1])%mod+mod)%mod;

				long cur2=(hashes2[count+mid]-(hashes2[count-1]*powers2[mid+1])%mod2+mod2)%mod2;
//				System.out.println(cur+" "+prev);
				if(prev==cur&&prev2==cur2) {
					left=mid+1;
				}
				else {
					right=mid;
				}
				
			}
			
//			System.out.println(right+""+best+" Comp "+in.charAt(best+right)+in.charAt(count+right));
			
			
			if(in.charAt(best+right)>in.charAt(count+right)) {
//				System.out.println("OOF");
				best=count;
			}
		}
		System.out.println(in.substring(best, best+length));
//		long test=make(in, length);
//		System.out.println(test);
//		System.out.println(roll(test, 'a', 'd'));
		
	}

}
