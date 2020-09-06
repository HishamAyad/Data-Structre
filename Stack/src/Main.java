import java.awt.print.Printable;
import java.util.Scanner;

public class Main {
	
	final static int N = 100;
	static int arr []=new int [N];
	static int size ;
	static Scanner input =new Scanner(System.in);
	
	public static boolean empty()
	{
		return size==0;
	}
	
	public static void push (int i)
	{
		arr[size++]=i;
	}
	
	public static  void pop()
	{
		if(empty())
		{
			System.out.println("Error : Cannot delete from an empty stack ");
		}
		else
		{
			size--;
		}
	}
	
	public static void top()

	{
		if(empty())
		{
			System.out.println("Error : the stack is empty");
		}
		else
		{
			System.out.println("The top iteam is : "+ arr[--size]);
			size++;
		}
	}
	
	public static void print ()
	{
		if(empty())
		{
			System.out.println("Error: The stack is empty");
		}
		else {
			for(int i=0;i<size;i++)
			{
				System.out.print(arr[i]+" ");
			}
			System.out.print("\n");
		}
	}
	
	public static void sizeofstack ()
	{
		System.out.println(size==0? "There is no iteams":( (size>1 ? "There is " : "There are " )+ size +" iteam(s)"));
	}
	
	public static void choice (int c)
	{
		if(c==1)
		{
			System.out.println("please enter a number to insert");
			int x;
			x=input.nextInt();
			push(x);
			System.out.println("Successfully inserted (1) iteam");
		}
		else if(c==2)
		{
			pop();
			System.out.println("Successfully deleted (1) iteam");
		}
		else if(c==3)
		{
			sizeofstack();
		}
		else if(c==4)
		{
			top();
		}
		else if (c==5)
		{
			print();
		}
	}
	public static void main (String args[])
	{
		int c;
		System.out.println("----- Welcome -----");
		do
		{
			System.out.println("please chosse the operation that you would like to preform");
			System.out.println("1- Insert an iteam");
			System.out.println("2- Delete the top iteam");
			System.out.println("3- print the number of iteams");
			System.out.println("4- print the top iteam");
			System.out.println("5- print all iteams");
			System.out.println("0- Exit");
			System.out.println("");
			c=input.nextInt();
			choice(c);
			System.out.println("");
			System.out.println("---------------------------------------");
		}while(c!=0);
	}
}
