package CodeJam.Qualifiers2019;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P1_ForegoneSolution {
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int num=Integer.parseInt(br.readLine());
		for(int i=0;i<num;i++) {
		String in=br.readLine();
		boolean found=false;
		String other="";
		for(int count=0;count<in.length();count++) {
			if(in.charAt(count)=='4') {
				other=other+'1';
				found=true;
			}
			else if(found) {
				other=other+'0';
			}
		}
		System.out.println("Case #"+(i+1)+": "+in.replaceAll("4", "3")+" "+other);
		}
		}

}
