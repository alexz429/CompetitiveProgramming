package CodeForces._564;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class P3_NauuoAndCards {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	int max=Integer.parseInt(br.readLine());
	br.readLine();
	String[] third=br.readLine().split(" ");
	int[] vals=new int[max];
	int worst=0;
	
	for(int count=0;count<max;count++) {
		vals[count]=Integer.parseInt(third[count]);
		
	}
	int offset=vals[max-1];
	int prev=-1;
	for(int count=max-1;count>=0;count--) {
		
		if(prev!=-1&&vals[count]!=prev-1) {
			offset=0;
			break;
		}
		if(vals[count]==1) {
			break;
		}
		prev=vals[count];
		
	}
//	System.out.println(offset);
	for(int count=0;count<max-offset;count++) {
		if(vals[count]==0)continue;
//		System.out.println(count+2-vals[count]);
		worst=Math.max(worst, count+2-vals[count]+offset);
	}
	if(worst>0) {
		worst=offset==0? worst:max-offset+1;
		System.out.println(worst+max);
	}
	else {

		System.out.println((worst+max-offset));
	}
	}

}
