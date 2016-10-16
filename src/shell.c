#include "../include/shell.h"
void launchShell(int n)
{
	string ch = (string) malloc(200); // util.h
	int counter = 0;
	do
	{
	    if(n > 0)
	    {
	        print("(");
	        print(int_to_string(n));
	        print(") ");
        }
        print("erikOS> ");
		ch = readStr(); //memory_copy(readStr(), ch,100);
		if(strEql(ch,"cmd"))
		{
		    print("\nYou are allready in cmd. A new recursive shell is opened\n");
		    launchShell(n+1);
		}
		else if(strEql(ch,"clear"))
	    {
	        clearScreen();
		}
		    else if(strEql(ch,"sum"))
		    {
		    	sum();
		    }
		    else if(strEql(ch,"exit"))
		    {
		    	print("\nClosing shell\n");
		    	break;
		    }
		    else if(strEql(ch,"echo"))
		    {
		    	echo();
		    }
		    else if(strEql(ch,"sort"))
		    {
		    	sort();
		    }
		    else if(strEql(ch,"fibonaci"))
		    {
		    	fibonaci();
		    }
		    else if(strEql(ch,"gcd"))
		    {
		    	gcd();
		    }
		    else if(strEql(ch,"help"))
		    {
		    	help();
		    }
		    else if(strEql(ch,"color"))
		    {
		    	setBackgroundColor();
		    }
		    else if(strEql(ch,"multiply"))
		    {
		    	multiply();
		    }
		    
		    
		    else
		    {
		        print("\n\"");
		        print(ch);
		        print("\" is not recognized as a command or operation.\n");
		    } 
	} while (1);
}



void sum()
{
	print("\nHow many numbers: ");
	int n = str_to_int(readStr());
	int i =0;
	print("\n");
	int arr[n];
	fill_array(arr,n);
	int s = sum_array(arr,n);
	print("Result: ");
	print(int_to_string(s));
	print("\n");
}
void echo()
{
	print("\n");
	string str = readStr();
	print("\n");
	print(str);
	print("\n");
}
void sort()
{
	int arr[100];
	print("\nArray size: ");
	int n = str_to_int(readStr());
	print("\n");
	fill_array(arr,n);
	print("Before sorting:\n");
	print_array(arr,n);
	print("\nOrder: (1 for increassing/ 0 for decreassing): ");
	int order = str_to_int(readStr());
	insertion_sort(arr,n,order);
	print("\nAfter sorting:\n");
	print_array(arr,n);
}

void fill_array(int arr[],int n)
{
	int i = 0;
	for (i = 0;i<n;i++)
	{
		print("ARR[");
		print(int_to_string(i));
		print("]: ");
		arr[i] = str_to_int(readStr());
		print("\n");
	}
}
void print_array(int arr[],int n)
{
	int i = 0;
	for (i = 0;i<n;i++)
	{
		/*print("ARR[");
		print(int_to_string(i));
		print("]: ");*/
		print(int_to_string(arr[i]));
		print("   ");
	}
	print("\n");
}
void insertion_sort(int arr[],int n,int order) //1 is increassing, 0 is descreassing
{
	int i = 0;
	for (i = 1;i<n;i++)
	{
		int aux = arr[i];
		int j = i;
		while((j > 0) && ((aux < arr[j-1]) && order ))
		{
			arr[j] = arr[j-1];
			j = j -1;
		}
		arr[j] = aux;
	}
}
int sum_array(int arr[],int n)
{
	int i = 0;
	int s = 0;
	for (i = 0;i<n;i++)
	{
		s += arr[i];
	}
	return s;
}
void fibonaci()
{
	print("\nHow many Elements: ");
	int n = str_to_int(readStr()); 
	print("\n");
	int i = 0;
	for(i =0;i<n;i++)
	{
		print("Fibo ");
		print(int_to_string(i));
		print(" : ");
		print(int_to_string(fibo(i)));
		print("\n");
	}
	
}
int fibo(int n)
{
	if(n <2)
		return 1;
	else 
		return fibo(n-1) + fibo(n-2);
}
int gcdCouple(int a,int b)
{
	if(b == 0)
		return 1;
	if(a % b ==0) 
		return b;
	else 
		return gcdCouple(b,a % b);
}
void gcd()
{
	print("\nHow many numbers: ");
	int n = str_to_int(readStr());
	int i =0;
	print("\n");
	int arr[n];
	int matrix[n][n];
	fill_array(arr,n);
	for (i = 0;i<n;i++)
	{
		matrix[0][i] = arr[i];
	}
	int j = 0;
	for (i =1;i<n;i++)
	{
		for (j=0;j<n-1;j++)
		{
			matrix[i][j] = gcdCouple(matrix[i-1][j] , matrix[i-1][j+1]);
		}
	}
	print("Result: ");
	print(int_to_string(matrix[n-1][0]));
	print("\n");
}
void print_matrix(int matrix[][100],int rows,int cols)
{
	int i =0;
	int j = 0;
	for (i = 0;i<rows;i++)
	{
		for(j =0;j<cols;j++)
		{
			print(int_to_string(matrix[i][j]));
			print("   ");
		}
		print("\n");
	}
}
void setBackgroundColor()
{
	print("\nColor codes : ");
	print("\n0 : black");
	printColored("\n1 : blue",1,0);   // screen.h
	printColored("\n2 : green",2,0);
	printColored("\n3 : cyan",3,0);
	printColored("\n4 : red",4,0);
	printColored("\n5 : purple",5,0);
	printColored("\n6 : orange",6,0);
	printColored("\n7 : grey",7,0);
	printColored("\n8 : dark grey",8,0);
	printColored("\n9 : blue light",9,0);
	printColored("\n10 : green light",10,0);
	printColored("\n11 : blue lighter",11,0);
	printColored("\n12 : red light",12,0);
	printColored("\n13 : rose",13,0);
	printColored("\n14 : yellow",14,0);
	printColored("\n15 : white",15,0);
	
	print("\n\n Text color ? : ");
	int textColor = str_to_int(readStr());
	print("\n\n Background color ? : ");
	int bgColor = str_to_int(readStr());
	setScreenColor(textColor,bgColor);
	clearScreen();
}

void multiply()
{
	print("\nNum 1 :");
	int num1 = str_to_int(readStr());
	print("\nNum 2 :");
	int num2 = str_to_int(readStr());
	print("\nResult : ");
	print(int_to_string(num1*num2)); // util.h
	print("\n");
}

void help()
{
	print("\ncmd       : Launch a new recursive Shell");
	print("\nclear     : Clears the screen");
	print("\nsum       : Computes the sum of n numbers");
	print("\necho      : Reprint a given text");
	print("\nsort      : Sorts a given n numbers");
	print("\nfibonaci  : Prints the first n numbers of fibonaci");
	print("\ngcd       : Computes the grand common divider of n given numbers");
	print("\nexit      : Quits the current shell");
	print("\ncolor     : Changes the colors of the terminal");
	
	print("\n\n");
}

