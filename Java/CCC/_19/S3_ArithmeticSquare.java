package CCC._19;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class S3_ArithmeticSquare {
	static boolean forceFill() {
		boolean changed=false;
		long[][] shadow=new long[3][3];
		for(int count=0;count<3;count++) {
			Arrays.fill(shadow[count], Long.MAX_VALUE);
		}
		for(int count=0;count<3;count++) {
			if(tallies[0][count]==2) {
				changed=true;
				if(num[count][0]== Long.MAX_VALUE) {
					long up=num[count][1]*2-num[count][2];
					if(shadow[count][0]!=Long.MAX_VALUE&&shadow[count][0]!=up) {
						return false;
					}
					shadow[count][0]=up;
					blanks--;
				}
				else if(num[count][1]== Long.MAX_VALUE) {
					long up=(num[count][0]+num[count][2])/2;
					if(up!=(double)(num[count][0]+num[count][2])/2||(shadow[count][1]!=Long.MAX_VALUE&&shadow[count][1]!=up)) {
						return false;
					}
					shadow[count][1]=up;
					blanks--;
				}
				else {
					long up=(num[count][1]*2-num[count][0]);
					if(shadow[count][2]!=Long.MAX_VALUE&&shadow[count][2]!=up) {
						return false;
					}
					shadow[count][2]=up;
					blanks--;
				}
			}
		}
		for(int count=0;count<3;count++) {
			if(tallies[1][count]==2) {
				changed=true;
				if(num[0][count]== Long.MAX_VALUE) {
					long up=num[1][count]*2-num[2][count];
					if(shadow[0][count]!=Long.MAX_VALUE&&shadow[0][count]!=up) {
						return false;
					}
					shadow[0][count]=up;
					blanks--;
				}
				else if(num[1][count]== Long.MAX_VALUE) {
					long up=(num[0][count]+num[2][count])/2;
					if(up!=(double)(num[0][count]+num[2][count])/2||(shadow[1][count]!=Long.MAX_VALUE&&shadow[1][count]!=up)) {
						return false;
					}
					shadow[1][count]=up;
					blanks--;
				}
				else {
					long up=(num[1][count]*2-num[0][count]);
					if(shadow[2][count]!=Long.MAX_VALUE&&shadow[2][count]!=up) {
						return false;
					}
					shadow[2][count]=up;
					blanks--;
				}
			}
		}
		//apply changed
		for(int count=0;count<3;count++) {
			for(int count2=0;count2<3;count2++) {
				if(shadow[count][count2]!=Long.MAX_VALUE) {
					add(count, count2, shadow[count][count2]);
				}
			}
		}
		if(changed) {
			return forceFill();
		}
		return true;
	}
	static boolean add(int x, int y, long val) {
		if(num[x][y]!=Long.MAX_VALUE) {
			if(val==num[x][y])return true;
			return false;
		}
		else {
			
		
		num[x][y]=val;
		tallies[0][x]++;
		tallies[1][y]++;
		}
		return true;
	}
	static boolean third() {
		if(blanks!=7) {
			return false;
			
		}
//		System.out.println("run");
		if(num[1][1]!=Long.MAX_VALUE) {
			if(num[0][0]!=Long.MAX_VALUE) {
				add(1,0,0);
				add(0,1,0);
			}
			else if(num[2][2]!=Long.MAX_VALUE) {
				add(1,2,0);
				add(2,1,0);
			}
			else if(num[0][2]!=Long.MAX_VALUE) {
				add(1,2,0);
				add(0,1,0);
			}
			else if(num[2][0]!=Long.MAX_VALUE) {
				add(1,0,0);
				add(2,1,0);
			}
			
		}
		else {
			add(1,1,0);
			blanks--;
			forceFill();
//			System.out.println(blanks);
			if(blanks==6) {
				add(0,1,0);
			}
			else {
				first();
			}
		}
		forceFill();
		return true;
	}
	static boolean second() {
		if(blanks!=6) {
			return false;
		}
		if(num[1][1]!=Long.MAX_VALUE) {
			add(0,1,num[1][1]);
			forceFill();
			return true;
		}
		else {
			if(num[0][1]!=Long.MAX_VALUE) {
				add(1,1,num[0][1]);
			}
			else if(num[2][1]!=Long.MAX_VALUE) {
				add(1,1,num[2][1]);
			}
			else if(num[1][0]!=Long.MAX_VALUE) {
				add(1,1,num[1][0]);
			}
			else {
				add(1,1,num[1][2]);
			}
			forceFill();
			return true;
		}
		
	}
	static boolean first() {
		//rows
		
		for(int count=0;count<3;count++) {
			if(tallies[0][count]==3) {
				long diff=-1;
				for(int count2=0;count2<3;count2++) {
					if(diff!=-1)break;
					if(count2==count)continue;
					for(int count3=0;count3<3;count3++) {
						if(num[count2][count3]!=Long.MAX_VALUE) {
							diff=(num[count2][count3]-num[count][count3])/(count-count2);
//							System.out.println(diff);
							break;
						}
					}
				}
				for(int count2=0;count2<3;count2++) {
					for(int count3=0;count3<3;count3++) {
						if(num[count2][count3]==Long.MAX_VALUE) {
							add(count2, count3, num[count][count3]+(diff*(count-count2)));
							
						}
					}
				}
				return true;
			}
		}
		//cols
		for(int count=0;count<3;count++) {
			if(tallies[1][count]==3) {
				long diff=-1;
				for(int count2=0;count2<3;count2++) {
					if(diff!=-1)break;
					for(int count3=0;count3<3;count3++) {

						if(count3==count)continue;
						if(num[count2][count3]!=Long.MAX_VALUE) {
							diff=(num[count2][count3]-num[count2][count])/(count-count3);
							break;
						}
					}
				}
				for(int count2=0;count2<3;count2++) {
					for(int count3=0;count3<3;count3++) {
						if(num[count2][count3]==Long.MAX_VALUE) {
							add(count2, count3, num[count2][count]+(diff*(count-count3)));
							
						}
					}
				}
				return true;
			}
		}
		return false;
	}
	static int blanks=0;
	static byte[][] tallies=new byte[2][3];
	static long[][] num=new long[3][3];
	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		long hit=0;
		for(int count=0;count<3;count++) {
			Arrays.fill(num[count],Long.MAX_VALUE);
			String[] next=br.readLine().split(" ");
			for(int count2=0;count2<3;count2++) {
				if(next[count2].equals("X")) {
					blanks++;
				}
				else {
					add(count, count2, Long.parseLong(next[count2]));
					hit=Long.parseLong(next[count2]);
				}
				
			}
		}
		forceFill();
		if(blanks!=0) {
			
			if(!first()) {
				if(!second()) {
					if(!third()) {
						if(blanks>=8) {
							for(int count=0;count<3;count++) {
								for(int count2=0;count2<3;count2++) {
									System.out.print(hit+" ");
								}
								System.out.println();
							}
							System.exit(0);
						}
						else {
							System.out.println("OW");	
						}
						
					}
				}
				
			}
		}
		for(long[] nextRow:num) {
			for(long next:nextRow) {
				System.out.print(next+" ");
			}
			System.out.println();
		}
		
		
	}
}
