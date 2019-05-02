package _03;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class S1_SnakesAndLadders {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int pos=1;
		while(true) {
			int next=Integer.parseInt(br.readLine());
			if(next==0) {
				System.out.println("You Quit!");
				break;
			}
			pos+=next;
			if(pos==54) {
				pos=19;
			}
			else if(pos==90) {
				pos=48;
			}
			else if(pos==99) {
				pos=77;
			}
			else if(pos==9) {
				pos=34;
			}
			else if(pos==40) {
				pos=64;
			}
			else if(pos==67) {
				pos=86;
			}
			else if(pos>100) {
				pos-=next;
			}
			System.out.println("You are now on square "+pos);
			if(pos==100) {
				System.out.println("You Win!");
				break;
			}
		}
		
	}

}
