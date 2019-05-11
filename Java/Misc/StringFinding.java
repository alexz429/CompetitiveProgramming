import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class StringFinding {
	public static long createValue(String in){
		long start=0;
		for(int count=0;count<in.length();count++) {
			start=(start*26+(in.charAt(count)-'a'))%MODULUS;

		}
		return start;
	}
	public static long roll(long was, char prev, char after) {
		was=(was+MODULUS-(POWER*(prev-'a'))%MODULUS)%MODULUS;
		was=(was*26+(after-'a'))%MODULUS;
		return was;
	}
	// the length of the substring to find
	static int LENGTH;
	//randomly chosen prime value to act as modulus
	static long MODULUS=Long.parseLong("8278737391");
	//saved value to remove the trailing letters (equal to (26^LENGTH-1)%MODULUS) to prevent recomputing times
	static long POWER=1;
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String first=br.readLine();
		String second=br.readLine();
		LENGTH=second.length();
		
		//compute POWER
		for(int count=0;count<LENGTH-1;count++) {
			POWER=(POWER*(long)26)%MODULUS;
		}
		
		//generate values for the compared string, and the first substring in main string
		long compare=createValue(second);
		long other=createValue(first.substring(0, second.length()));

		for(int count=0;count+LENGTH<first.length();count++) {
			if(other==compare) {//returns the index if the compare is true
				System.out.println(count);
				System.exit(0);
			}
			
			//roll across to next rolling hash
			other=roll(other, first.charAt(count), first.charAt(count+LENGTH));
			
		}
		if(other==compare) {//checks the last substring to see if it is equal
			System.out.println(first.length()-LENGTH);
			System.exit(0);
		}
		System.out.println(-1);
	}

}
