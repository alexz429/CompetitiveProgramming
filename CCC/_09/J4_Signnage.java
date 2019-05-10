package _09;
import java.util.Scanner;
public class J4_Signnage {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int max=sc.nextInt();
		int processed=-1;
		String[] words=new String[6];
		words[0]="WELCOME";
		words[1]="TO";
		words[2]="CCC";
		words[3]="GOOD";
		words[4]="LUCK";
		words[5]="TODAY";
		while(processed!=5) {
			//char[] out=new char[max]; 
			int tally=0;
			//System.out.println(processed+" PPP");
			int pos=0;
			int count=processed+1;
			for(;count<6;count++) {
			
				//System.out.println(tally+" "+count);
				tally+=words[count].length()+1;
				if(tally-1>max) {
					tally-=words[count].length()+1;
					//System.out.println(pos+" got");
					
					break;
				}
			}
			
			pos=count-1;
			int wordSize=0;
			for(int count2=processed+1;count2<pos+1;count2++) {
				wordSize+=words[count2].length();
			}
			int spaces=max-wordSize;
			
			int wordNum=pos-processed;
			//spaces+=wordNum-1;
			//System.out.println(spaces);
			//System.out.println(wordNum);
			if(wordNum==1) {
				System.out.print(words[processed+1]);
				for(int count2=0;count2<spaces;count2++) {
					System.out.print(".");
				}
				//System.out.println();
			}
			else {
				int even=spaces/(wordNum-1);
				int more=spaces%(wordNum-1);
				//System.out.println(even);
				//System.out.println(more);
				//System.out.println();
				for(int count2=0;count2<wordNum;count2++) {
					System.out.print(words[processed+count2+1]);
					if(!(count2<wordNum-1)) {
						
					}
					else {
						for(int count3=0;count3<even;count3++) {
							System.out.print(".");
						}
						if(count2<more) {
							System.out.print(".");
						}
					}
				}
			}
			System.out.println();
			processed=pos;
			//System.out.println("END");
		}
		sc.close();
	}
}
