package _15;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class R1P2_WordWrap {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		for(int count3=0;count3<10;count3++) {
			int max=Integer.parseInt(br.readLine());
			String[] next=(br.readLine()).split(" ");
			int temp=max;
			boolean flag=false;
			for(int count=0;count<next.length;count++) {
				if(temp<next[count].length()) {
					
					System.out.println();
					while(next[count].length()>max) {
						System.out.println(next[count].substring(0, max));
						next[count]=next[count].substring(max);
					}
					temp=max;
				}
				else if(flag){
					System.out.print(" ");
				}
				else {
					flag=true;
				}
				System.out.print(next[count]);
				temp-=next[count].length();
				temp--;
			}
			System.out.println();
			System.out.println("=====");
		}
	
	}

}
