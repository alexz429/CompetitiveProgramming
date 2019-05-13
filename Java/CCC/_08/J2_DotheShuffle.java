package CCC._08;
import java.util.*;
public class J2_DotheShuffle {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int b=sc.nextInt();
		int n=sc.nextInt();
		ArrayList<String> lol=new ArrayList<>();
		lol.add("A");
		lol.add("B");
		lol.add("C");
		lol.add("D");
		lol.add("E");
		while(b!=4) {
			switch(b) {
			case 1:
				for(int count=0;count<n;count++) {
					lol.add(lol.remove(0));
				}
				
				break;
			case 2:
				for(int count=0;count<n;count++) {
					lol.add(0,lol.remove(lol.size()-1));
				}
				break;
			case 3:
				if(n%2!=0) {
					lol.add(0,lol.remove(1));
				}
			}
			b=sc.nextInt();
			n=sc.nextInt();
				
				
		}
		for(int count=0;count<5;count++) {
			System.out.print(lol.get(count));
			if(count!=0||count!=4) {
				System.out.print(" ");
			}
		}
		sc.close();
	}

}
