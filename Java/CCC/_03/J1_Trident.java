package CCC._03;
import java.util.*;
public class J1_Trident {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int tines=sc.nextInt();
		int space=sc.nextInt();
		int handle=sc.nextInt();
		
		for(int count=0;count<tines;count++){
			System.out.print("*");
			for(int count2=0;count2<space;count2++){
				System.out.print(" ");
			}
			System.out.print("*");
			for(int count2=0;count2<space;count2++){
				System.out.print(" ");
			}
			System.out.print("*");
			System.out.println();
		}
		int mid=(space*2)+3;
		for(int count=0;count<mid;count++){
			System.out.print("*");
		}
		System.out.println();
		int mid2=mid/2;
		for(int count=0;count<handle;count++){
			for(int count2=0;count2<mid;count2++){
				if(count2==mid2){
					System.out.print("*");
				}
				else{
					System.out.print(" ");
				}
			}
			System.out.println();
		}
		sc.close();
	}

}
