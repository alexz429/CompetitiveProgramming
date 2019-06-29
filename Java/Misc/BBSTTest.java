package Misc;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BBSTTest{
	static class node{
		 int key;
		    node left,right;
		    int dupli, less, more, height;
			public node(int val) {
				key=val;
				left=right=null;
				less=more=0;
				dupli=1;
				height=1;
			}
		 
	}
	static int getNum(node n)
	{
	    return n == null ? 0 : (n.more + n.less + n.dupli);
	}
	static int getHeight(node n)
	{
	    return n == null ? 0 : n.height;
	}

	static int findDiff(node at){
	    if(at==null)return 0;
	    return getHeight(at.left)-getHeight(at.right);
	}
	
	static node rotateLeft(node at)
	{
	    node temp = at.right;
	    at.right = temp.left;
	    temp.left = at;
	    at.more = getNum(at.right);
	    temp.less = getNum(at);
	    at.height = Math.max(getHeight(at.left), getHeight(at.right)) + 1;
	    temp.height = Math.max(getHeight(temp.left), getHeight(temp.right)) + 1;
	    return temp;
	}
	static node rotateRight(node at)
	{

	    node temp = at.left;
	    at.left = temp.right;
	    temp.right = at;
	    at.less = getNum(at.left);
	    temp.more = getNum(at);
	    at.height = Math.max(getHeight(at.left), getHeight(at.right)) + 1;
	    temp.height = Math.max(getHeight(temp.left), getHeight(temp.right)) + 1;
	    return temp;
	}
	static node smallest(node at)
	{
	    node temp = at;
	    while (temp.left != null)
	    {
	        temp = temp.left;
	    }
	    return temp;
	}
	static node deleteNode(node at, int val, int amount)
	{
	    if (at == null)
	        return at;
	    if (at.key < val)
	    {
	        at.right = deleteNode(at.right, val,amount);
	        at.more = getNum(at.right);
	    }
	    else if (at.key > val)
	    {
	        at.left = deleteNode(at.left, val,amount);
	        at.less = getNum(at.left);
	    }
	    else
	    {
	        at.dupli-=amount;
	        if (at.dupli == 0)
	        {
	            if (at.left == null)
	            {
	                node temp = at.right;
	                return temp;
	            }
	            if (at.right == null)
	            {
	                node temp = at.left;
	                return temp;
	            }
	            node replacer = smallest(at.right);
	            at.key = replacer.key;
	            at.dupli = replacer.dupli;
	            at.right = deleteNode(at.right, at.key, at.dupli);
	            at.more = getNum(at.right);
	        }
	    }
	    int leftHeight = getHeight(at.left);
	    int rightHeight = getHeight(at.right);
	    at.height = Math.max(leftHeight, rightHeight) + 1;
	    int balance = leftHeight - rightHeight;
	    if (Math.abs(balance) < 2)
	    {
	        return at;
	    }
	    if (balance > 1 && findDiff(at.left)>=0)
	    {
	        return rotateRight(at);
	    }
	    else if (balance < -1 && findDiff(at.right)<=0)
	    {
	        return rotateLeft(at);
	    }
	    else if (balance > 1 && findDiff(at.left)<0)
	    {
	        at.left = rotateLeft(at.left);
	        return rotateRight(at);
	    }
	    else
	    {
	        at.right = rotateRight(at.right);
	        return rotateLeft(at);
	    }
	}
	static node push(node at, int val)
	{
	    if (at == null)return new node(val);
	    if (val == at.key)
	    {
	        at.dupli++;
	        return at;
	    }
	    else if (val > at.key)
	    {
	        at.more++;
	        at.right = push(at.right, val);
	    }
	    else
	    {
	        at.less++;
	        at.left = push(at.left, val);
	    }
	    int leftHeight = getHeight(at.left);
	    int rightHeight = getHeight(at.right);
	    at.height = Math.max(leftHeight, rightHeight) + 1;
	    int balance = leftHeight - rightHeight;
	    if (Math.abs(balance) < 2)
	    {
	        return at;
	    }
	    if (balance > 1 && val < at.left.key)
	    {
	        return rotateRight(at);
	    }
	    else if (balance < -1 && val > at.right.key)
	    {
	        return rotateLeft(at);
	    }
	    else if (balance > 1 && val > at.left.key)
	    {
	        at.left = rotateLeft(at.left);
	        return rotateRight(at);
	    }
	    else
	    {
	        at.right = rotateRight(at.right);
	        return rotateLeft(at);
	    }
	}
	static boolean type=false;
	static void output(node at)
	{
	    if (at == null)
	        return;
	    output(at.left);
	    for(int count=0;count<at.dupli;count++){

	    if(type){
	        System.out.printf(" ");
	    }
	    type=true;
	    System.out.printf("%d", at.key);
	    }
	    
	    output(at.right);
	    // printf(" UP");
	}
	static int valAt(node at, int order)
	{
//	    return order <= at.less ? valAt(at.left, order) : order > (at.less + at.dupli) ? valAt(at.right, order - (at.less + at.dupli)) : at.key;
	     if(order>at.less&&order<=(at.less+at.dupli)){
	         return at.key;
	     }
	     if(order<=at.less){
	         return valAt(at.left,order);
	     }
	     else{
	         return valAt(at.right,order-(at.less+at.dupli));
	     }
	}
	static void debugOutput(node at) {
		if(at==null)return;
		System.out.println(at.key+" "+at.less+" "+at.more+" "+at.height+" "+at.dupli);
		debugOutput(at.left);
		debugOutput(at.right);
	}
	static int indexOf(node at, int target, int order)
	{
	    if (at == null)
	        return -1;
	    if (at.key == target)
	    {
	        return order + at.less + 1;
	    }
	    if (at.key < target)
	    {
	        return indexOf(at.right, target, order + at.dupli + at.less);
	    }
	    return indexOf(at.left, target, order);
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] first=br.readLine().split(" ");
		int max=Integer.parseInt(first[0]), q=Integer.parseInt(first[1]);
	    node root =null;
	    String[] second=br.readLine().split(" ");
	    for (int count = 0; count < max; count++)
	    {
	    	root=push(root,Integer.parseInt(second[count]));
	    }
//	    output(root);
	    int prev=0;
	    for (int count = 0; count < q; count++)
	    {
	    	String[] nextLine=br.readLine().split(" ");
	        char com=nextLine[0].charAt(0);
	        int next=Integer.parseInt(nextLine[1]);
//	        System.out.printf("%c %d", com,next);
	        next=(next^prev);
	        int out;
	        // printf("%c %d\n", com, next);
	        switch (com)
	        {
	        case 'I':
	            root = push(root, next);
	            debugOutput(root);
	            break;
	        case 'R':
	            root = deleteNode(root, next,1);
	            debugOutput(root);
	            break;
	        case 'S':
	        out=valAt(root,next);
	           System.out.printf("%d\n", out);
	            prev=out;
	            break;
	        case 'L':
	        out=indexOf(root,next,0);
	           System.out.printf("%d\n",out);
	            prev=out;
	            break;
	        }
	    }
	    output(root);
	    System.out.println();
	}
}
