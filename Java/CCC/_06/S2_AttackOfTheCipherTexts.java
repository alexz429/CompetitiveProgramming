package CCC._06;
import java.util.Scanner;
public class S2_AttackOfTheCipherTexts {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		String first=sc.nextLine();
		String next=sc.nextLine();
		String last=sc.nextLine();
		char[] code= new char[27];
		int check=0;
		
		for(int count=0;count<27;count++){
			code[count]='.';
		}
		int num=0;
		char num2=' ';
		
		for(int count=0;count<first.length();count++){
			num=first.charAt(count)-65;
			if(num<0){
				code[26]=next.charAt(count);
			}
			else{
			code[num]=next.charAt(count);
			}
		}
		for(int count=0;count<last.length();count++){
			for(int count2=0;count2<27;count2++){
				if(code[count2]==last.charAt(count)){
					if(count2+65>90){
						System.out.print(" ");
						check=1;
					}
					else{
						num2+=count2+33;
						System.out.print(num2);
						num2=' ';
						check=1;
						}
				}
				
				
			}
			if(check==0){
				System.out.print(".");
			}
			check=0;
		}
		sc.close();
	}

}