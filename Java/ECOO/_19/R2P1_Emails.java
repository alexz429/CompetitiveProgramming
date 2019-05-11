package _19;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class R2P1_Emails {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
//		BufferedReader br=new BufferedReader(new FileReader("C:\\Users\\alex.zhang\\Desktop\\DATA12.txt"));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		for(int i=0;i<10;i++) {
			int max=Integer.parseInt(br.readLine());
			HashSet<String> stuff=new HashSet<>();
			for(int count=0;count<max;count++) {
				String in2=br.readLine().toLowerCase();
//				System.out.println(in2);
//				System.out.println(in2.indexOf("@"));
				String[] in= in2.split("@");
				String out="";
				for(int count2=0;count2<in[0].length();count2++) {
					if(in[0].charAt(count2)!='.') {
						out+=in[0].charAt(count2);
					}
				}
//				System.out.println(in[0]+" a");
				String actual;

				int index=in[0].indexOf("+");
				if(index==-1) {
					actual=out;
				}
				else {
					actual=out.substring(0, out.indexOf("+"));
				}
				actual+="@";
				actual+=in[1];
//				System.out.println(actual);
				stuff.add(actual);
				
			}
			System.out.println(stuff.size());

		}
	}
	

}
