/*      
 * AUTHOR:  Stacey Ivanovic
 *
 * CONTACT INFORMATION: email; stacey.ivanovic007@gmail.com
 *                      phone; 604-897-2860
 *
 * CREATION DATE: 02.10.14
 *
 * PROBLEM STATEMENT:  Write a program which will run as a
 *                     calculator and be able to perform
 *                     simple calculations from user input.
 * 
 * PROGRAM DESCRIPTION: This is a calculator that will ask
 *                      for specific inputs and do some
 *                      basic math to output the result of
 *                      whatever the user decided to input.                     
 *
 * RUN INSTRUCTIONS: The operands entered must be numeric,
 *                   and the operation must be one from the
 *                   options given. Enter them as the program
 *                   prompts you to. 'Q' may be entered at any
 *                   point to end the program. Otherwise, an 
 *                   ERROR message will apear. If the Log 
 *                   operation is chosen, the program will test
 *                   to see if the operand is negative of not.
 *                   If it is negative, it will multiply it by
 *                   -1 to make it positive then continue.
 *                    
 */


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;


     //*** --- FUNCTION PROTOTYPES:

     // Gets the user to choose an operator from the menu.
char getOperatorMenu(void); 

     // Gets Operand
double getOperand(void); 

    // Adds two numbers.
double addNumbers(double, double); 

    // Subtracts y from x.
double subNumbers(double, double); 

    // Multiplies two numbers.
double multNumbers(double, double); 

    // Divides x by y.
double divNumbers(double, double); 

    // Calculates x to the poer of y.
double expoNumber(double, double);

    // Finds the factorial of x.
int factNumber(int); 

    // Finds log base 10 of x.
double logNumber(double); 

    // Find the remainder of x/y.
int remNumbers(int, int);

  
  
 /*
  * Task:	    Contains the code to be executed.
  * Accepts:  Nothing.
  * Returns:  Returns 0 if successfull.
  * Modifies:	Nothing.
  */
 
int main()
{
  
  double x;          // The first operand.
  double y;          // The second operand.
  double r;          // The result of the operation.
  int i;             // Only used in the for loops
  char operation;    // The operation the user chooses 
                     // to input from the given choices.
  string dummy;      // Used when testing if the user input
                     // was 'Q', 'q' or just invalid.
  
  
  
  cout << "Welcome to Calculator.\n";
  cout << "Press q at any point to quit.\n";
  
  /* 
   * A do...while function is used because the program
   * is supposed to run on repeat until the user 
   * decides to press 'Q' to quit. However, it has to 
   * execute at least once before the user can quit.
   */
  
  do
  {
    
    x = getOperand();
    
    /* 
     * The following if/else statement is used to determine
     * if the input for x is either numeric or 'Q'.
     * If it a usable value, it moves on to ask for the operation,
     * otherwise, it will ask for another operand.
     * This also gives the user the option to quit the 
     * program at this point.
     */
    
    if(cin.fail())
    {
      cin.clear();
      cin >> dummy;
      if((dummy == "Q") || (dummy == "q"))
          break;
      cout << "ERROR: Operand must be numberic. "
           << "Please try again.\n";
      continue;
    }

    operation = getOperatorMenu();

   /*
    * An if else statement is used to check whether the
    * input is allowed, and to check if the operator the
    * user chose needs a second operand to execute properly.
    * Also checks to see if the user has entered 'Q' to quit 
    * the program.
    */
    
      if (operation == '+'|| operation == '-'|| 
          operation == '*'|| operation =='^'||
          operation =='/' || operation == '%')
      {    
          y = getOperand();
          
          if ( y != 'q' && y != 'Q')
          {
            cout << x << operation << y << " = ";
          }     
      }
      else if((operation == 'q') || (operation == 'Q'))
      {
          break;
      }
      else if (operation != '!' && operation != 'L')
      {
          cout << "ERROR: Unknown operation. "
               << "Please try again: \n";
          continue;
      }
      
      
    
    /*
     * A switch is used to tell the program what to do
     * depending on the operator the user chooses. 'Q'
     * is an option so the user can chose to quit the 
     * program from this point as well.
     */

    switch(operation)
    {
      case '+':  
        cout << addNumbers(x, y);
        break;

      case '-': 
        cout << subNumbers(x, y); 
        break;
       
      case '*': 
        cout << multNumbers(x, y); 
        break;
      
      case '/': 
        cout << divNumbers(x, y); 
        break;
     
      case '^': 
        cout << expoNumber(x, y);
        break;
      
      case '%': 
        cout << remNumbers(x, y); 
        break;
      
      case 'L':  
        cout << "log(" << x << ") = " << logNumber(x);
        break;
        
      case '!':  
        cout  << x << "! = " << factNumber(x);
        break;

      case 'q': case 'Q': 
        break;

      default: 
        cout << "ERROR: Unknown operation." 
             << "Please try again:\n"; 
        continue;
    }

    cout << endl;
    
  }
  while((operation != 'Q') && (operation != 'q'));
  
  cout << "Program Terminated.\n";

  system ("PAUSE");
  return EXIT_SUCCESS;
  
}

  /*
   * TASK:     Calculates the sum of x and y.
   * ACCEPTS:  Accepts any integers.
   * RETURNS:  The sum of x and y.
   * MODIFIES: Nothing.
   * LOCAL:    r.
   */
   
double addNumbers(double x, double y)
{ 
   double r;
   r=x + y;
   return r;
}

  /*
   * TASK:     Calculates the differance of x and y.
   * ACCEPTS:  Accepts any integers.
   * RETURNS:  The differance of x and y.
   * MODIFIES: Nothing.
   * LOCAL:    r.
   */
   
double subNumbers(double x, double y)
{
   double r;
   r = x - y;
   return r;
}

  /*
   * TASK:     Calculates the value of x to the power
   *           of the value of y.
   * ACCEPTS:  Accepts any integers.
   * RETURNS:  The value of x to the power of y.
   * Modifies: Nothing.
   * LOCAL:    r.
   */
   
double divNumbers(double x, double y)
{
   double r;  
   r = x / y;
   return r;
}

  /*
   * TASK:    Multiplies x and y.
   * ACCEPTS: Two operands.
   * RETURNS: The product of x and y.
   * LOCAL:   r
   */
   
double multNumbers(double x, double y)
{
   double r;
   r = x * y;
   return r;
}

  /*
   * TASK:     Calculates the value of x to the power
   *           of the value of y.
   * ACCEPTS:  Accepts any integers.
   * RETURNS:  The value of x to the power of y.
   * MODIFIES: i and r are modified.
   * LOCAL:    r, i.
   */

double expoNumber(double x, double y)
{
   double r = 1;
  
   if ( y > 0)
     for (double i = 0; i < y; i++)
       r *= x;
   else
     for (double i = 0; i > y; i--)
       r /= x;
   return r;
}

  /*
   * TASK:     Calculates the factorial of a given value.
   * ACCEPTS:  One operand.
   * RETURNS:  The factorial of the integer.
   * MODIFIES: i is modified.
   * Local:    r, i.
   */

int factNumber(int x)
{
   int i, r = 1;
   for(i=1;i<=x;i++) 
   {   
       r = r * i; 
   } 
   return r;
}

  /*
   * TASK:     Calculates the log to base 10 of a value.
   * ACCEPTS:  One operand.
   * RETURNS:  The log of base 10 of a given value.
   * MODIFIES: Nothing.
   * Local:    r
   */

double logNumber(double x)
{
   double r;
   r = log10(x<0?-1*x:x);
   return r;
}

 /*
  * Task:	    Calculates the remainder of x/y.
  * Accepts:	Two operands.
  * Returns:  The remainder of x/y.
  * Modifies:	Nothing
  * Locals:   r
  */
  
int remNumbers(int x, int y)
{
  int r;
  r = x%y;
  return r;
}


  /*
   * TASK:     Asks the user for an operation from the given menu.
   * ACCEPTS:  Accepts any integers.
   * RETURNS:  The operation.
   * MODIFIES: 
   * Local:    operation.
   */
   
char getOperatorMenu()
{
   char operation;  
   cout << "Select the Operation: \n";
   cout << "+,-,*,/,!,^,L,% \n";
   cout << "> ";
   cin >> operation;
   return operation;
}
 
 
  /*
   * TASK:     Prompts the user for an operand.
   * ACCEPTS:  Nothing.
   * RETURNS:  The operand.
   * MODIFIES: Nothing.
   * LOCAL:    x.  
   */       
  
double getOperand()
{
   double x;
   cout << "Enter an operand: \n";
   cin >> x;
   return x;  
}
  
