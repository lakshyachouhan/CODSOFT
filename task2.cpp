/*       TASK 2 - SIMPLE CALCULATOR 
Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform.
*/
/* NAME - LAKSHYA CHOUHAN
   ID: CS07WX75038         */
#include<iostream>
using namespace std ;

int main(){
    
    cout<<"Enter two numbers :"<<endl ;
    int num1 , num2 ;
    cin>>num1>>num2;
    cout<<endl ;

    cout<<"Choose the operation using options :"<<endl;
    cout<<"1.Addition  \n" <<"2.Subtraction \n"<<"3.Multiplication \n";
    cout<<"4.Division"<<endl ;

    int n ;
    cin>>n ;
    cout<<endl ;

    switch (n)
    {
    case 1:
        cout<< "Addition = "<< (num1+num2) <<endl;
        break;
    case 2:
        cout<< "Subtraction = "<< (num1-num2) <<endl;
        break;
    case 3:
        cout<< "Multiplication = "<< (num1*num2) <<endl;
        break;
    case 4:
        if(num2 != 0){
            cout<< "Division = "<<((float)num1/(float)num2) <<endl;
        }
        else{
            cout<<" Please enter valid numbers for selected operation"<<endl ; 
        }
        break;
    
    default:
        cout<<"Choose a valid operation";
        break;
    }


    return 0 ;
}