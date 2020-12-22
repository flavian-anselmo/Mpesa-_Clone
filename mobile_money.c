#include<stdio.h>
#include<stdlib.h>//used this library so that i can clear the screen 
#include<time.h>//this works as our seed in the random function 
#define N 12//The size of array getting the charges 
//function prototypes 
void main_menu();//finished 
void send_money();//finished
void withdraw_cash();//finished
void Buy_Airtime();//finished 
void Lipa_na_Mpesa();//finished
void My_Account();//still pending
void change_pin();//finished

int get_pin;//this is the global variable that stores our PIN
typedef struct mobile_money
{//structuture of mobile money
    /* data */
    float amount;
    int user_pin;//this is what the user will enter
    float charges;
    float balance;
    float transaction_cost;

}mobile;
//Below will be used to access the structure members using the dot opterator
mobile bal;//this is for balance
mobile amt;//this is  for amount
mobile charg;//this is for charges 
mobile pin;//this is for user_pin
mobile tran;//this id for transaction_cost
void change_pin(int option,int lower_code,int upper_code){
    //the user can chage their pin 
    /*i will write the PIN to a file 
    I will write an integer to a file 
    */
   FILE *FP;//This is the file pointer
   FP=fopen("pin.txt","w");
   //the file is opened in append mode
   //since the pin is an integer we shall use fprintf and fscanf to write an integerto a file 
   printf("Enter a PIN with numbers (0->9):");
   scanf("%d",&get_pin);
   fprintf(FP,"%d",get_pin);//write an integerto a file 
   fclose(FP);
   printf("Enter 0 to return to main menu or 1 to change again or press any value(2->9) to terminate:");
   scanf("%d",&option);
   if (option==0){
       //return to main menu
       system("cls");
       printf("your Account Balance is:%f\n",bal.balance);
       main_menu(option,lower_code,upper_code);
   }
   else if(option==1){
       //change password again
       system("cls");
       change_pin(option,lower_code,upper_code);
   }else{
       //exit from the system
       exit(0);
   }
   //sysntax of fprintf(file_pointer,specifier,variable)
}//end of function change pin

void send_money(int option,int lower_code,int upper_code){
    //function to be used when sending money

    //generate a random FOUR figure number from 1000 to RAND_MAX ->32767
    //use the time function in order to get random values after every call 
    //the time function will act as our seed 
    int send_random_code;//this is the value to display
    srand(time(0));
    send_random_code=(rand()%(upper_code-lower_code+1)+lower_code);//this line will get random values from 1024 to RAND_MAX
    //-----------------END OF RANDOM------------------------------
    printf("Enter the amount to send:");
    scanf("%f",&amt.amount);
    if(amt.amount>=1 && amt.amount<=100){
        charg.charges=0;
    }
    else if(amt.amount>100 && amt.amount<=500){
        charg.charges=11;
    }
    else if(amt.amount>500 && amt.amount<=1000){
        charg.charges=15;
    }
    else if(amt.amount>1000 && amt.amount<=1500){
        charg.charges=26;
    }
    else if(amt.amount>1500 && amt.amount<=2500){
        charg.charges=41;
    }
    else if(amt.amount>2500 && amt.amount<=3500){
        charg.charges=56;
    }
    else if(amt.amount>3500 && amt.amount<=5000){
        charg.charges=61;
    }
    else if(amt.amount>5000 && amt.amount<=7500){
        charg.charges=77;
    }
    else if(amt.amount>7500 && amt.amount<=10000){
        charg.charges=87;
    }
    else if(amt.amount>10000 && amt.amount<=15000){
        charg.charges=97;
    }
    else if(amt.amount>15000 && amt.amount<=20000){
        charg.charges=102;
    }
    else if(amt.amount>20000 && amt.amount<=70000){
        charg.charges=105;
    }
    else{
        printf("insufficient Funds!\n");
        printf("press 0 to return to main menu or press any number (1->9) to terminate:");
        scanf("%d",&option);
        if(option==0){
            system("cls");
            main_menu(option,lower_code,upper_code);
        } 
        else{
            //end the progrsm
            exit(0);
        }
    }
    if(bal.balance > (amt.amount+charg.charges)){
        //the balance should be greater than amount + charges for the user to enter the pin
        bal.balance=bal.balance-(amt.amount+charg.charges);
        //deduct the amount+charges sent from the previous balance
        printf("Enter Your PIN:");
        scanf("%d", &pin.user_pin);
    }

    if (pin.user_pin==get_pin){
        printf("[%d] confirmed You Have sent->%f\nYour Working Balance is->%f\nTransaction Charges is->%f\n***Thank You for using our services!***\n",send_random_code,amt.amount, bal.balance, charg.charges);
        printf("press (0) to return to main_menu or press any number(1->9) to terminate:");
        scanf("%d",&option);
        if (option==0){
            system("cls");
            printf("your cuurent Account Balance is:%f\n",bal.balance);//this will display the current balance in the system
            main_menu(option,lower_code,upper_code);
        }//the user will press any key to terminate the system
        else{
            exit(0);
        }
    }
    else{
        printf("Incorrect PIN!\nPress 0 to resend or press 1 to return to main menu:");
        scanf("%d",&option);
        //recover the amount that we had removed from the system
        bal.balance=bal.balance+(amt.amount+charg.charges);
        if (option==0){
            //recursion to call the function if the pin is incorrect
            send_money(option,lower_code,upper_code);
        }
        else if(option==1){
            system("cls");
            printf("your cuurent Account Balance is:%f\n",bal.balance);//this will display the current balance in the system
            main_menu(option,lower_code,upper_code);
        } 
        else{
            //if any number other than 1 or o the prog terminates 
            exit(0);//end the program
        }

    }
}//end of send_monney function

void withdraw_cash(int option,int lower_code,int upper_code){
    //generate a random  figure number from 1024 to RAND_MAX ->32767
    //use the time function in order to get random values after every call 
    //the time function will act as our seed 
    int withdraw_random_code;//this is the value to display 
    srand(time(0));
    withdraw_random_code=(rand()%(upper_code-lower_code+1)+lower_code);//this line will get random values from 1024 to RAND_MAX
    //-----------------END OF RANDOM------------------------------
    int Agent_No;
    //function to be used when withdraw money
    printf("[1].From Agent\n[2].From ATM\n");
    printf("Your Option:");
    scanf("%d",&option);
    if (option==1 || option==2){
        //if option is either 1 0r 2 use the below transaction cost
        printf("Enter Agent Number:");
        scanf("%d",&Agent_No);//get the agent number

        printf("Enter the Amount to withdraw:");
        scanf("%f",&amt.amount);//the user will enter the amount he or she wants to withdraw
        if(amt.amount>=1 && amt.amount<=100){
            tran.transaction_cost=0;
        }
        else if(amt.amount>100 && amt.amount<=500){
            tran.transaction_cost=11;
        }
        else if(amt.amount>500 && amt.amount<=1000){
            tran.transaction_cost=15;
        }
        else if(amt.amount>1000 && amt.amount<=1500){
            tran.transaction_cost=26;
        }
        else if(amt.amount>1500 && amt.amount<=2500){
            tran.transaction_cost=41;
        }
        else if(amt.amount>2500 && amt.amount<=3500){
            tran.transaction_cost=56;
        }
        else if(amt.amount>3500 && amt.amount<=5000){
            tran.transaction_cost=61;
        }
        else if(amt.amount>5000 && amt.amount<=7500){
            tran.transaction_cost=77;
        }
        else if(amt.amount>7500 && amt.amount<=10000){
            tran.transaction_cost=87;
        }
        else if(amt.amount>10000 && amt.amount<=15000){
            tran.transaction_cost=97;
        }
        else if(amt.amount>15000 && amt.amount<=20000){
            tran.transaction_cost=102;
        }
        else if(amt.amount>20000 && amt.amount<=70000){
            tran.transaction_cost=105;
        }
        else{
            printf("insufficient Funds!\n");
            printf("press 0 to return to main menu or press any key to terminate:");
            scanf("%d",&option);
            if(option==0){
                system("cls");
                main_menu(option,lower_code,upper_code);
            }else{
                exit(0);
                //end the program if option is not 0
            } 
        }
        if(bal.balance > (amt.amount+tran.transaction_cost)){
            //the balance should be greater than amount + transaction_cost for the user to enter the pin
            bal.balance=bal.balance-(amt.amount+tran.transaction_cost);
            //deduct the amount+transaction_cost  from the previous balance
            printf("Enter Your PIN:");
            scanf("%d", &pin.user_pin);
        }
        if (pin.user_pin==get_pin){//base case for the recursion
            printf("[%d]confirmed You withdrew %ffrom the Agent number %d\nYour current Balance is->%f\nTransaction cost is->%f\n***Thank You for using our services!***\n",withdraw_random_code,amt.amount,Agent_No, bal.balance, tran.transaction_cost);
            //this should take us back to the main menu and the user can get other option
            printf("press (0) to return to main_menu:\n");
            scanf("%d",&option);
            if (option==0){
                system("cls");
                printf("your cuurent Account Balance is:%f\n",bal.balance);//this will display the current balance in the system
                main_menu(option,lower_code,upper_code);
            }//the user will press any key to terminate the system
            else{
                exit(0);
            }
        }
        else{
            printf("Incorrect PIN\nPress 0 to try again! or press 1 to return to main menu:");
            scanf("%d",&option);
            //recover the amount that we removed from the system
            bal.balance=bal.balance+(amt.amount+tran.transaction_cost);
            if (option==0){
                //recursion to call the function if the pin is incorrect
                withdraw_cash(option,lower_code,upper_code);
            }
            else if(option==1){
                system("cls");
                printf("your cuurent Account Balance is:%f\n",bal.balance);//this will display the current balance in the system
                main_menu(option,lower_code,upper_code);
            }
            else if(option!=1||option!=0){
                //if any key other than 0 or 1 is pressed end the program
                exit(0);
            }
        }

    }    
}//end of function withdraw cash

void Buy_Airtime(int option,int lower_code,int upper_code){
    //the function will be used to guide the user to buy airtime 
    //when buying air time you can buy for your number or you can buy for another person 

    //generate a random FOUR figure number from 1000 to RAND_MAX ->32767
    //use the time function in order to get random values after every call 
    //the time function will act as our seed 
    int airtime_random_code;//this is the value to display 
    srand(time(0));
    airtime_random_code=(rand()%(upper_code-lower_code+1)+lower_code);//this line will get random values from 1024 to RAND_MAX

    printf("[1].Buy Airtime for My phone\n[2].Buy Airtime for Other Phone\n");
    printf("Your Options:");
    scanf("%d",&option);
    if(option==1){
        printf("----|buy airtime for your phone|----\n");
        printf("Enter Amount of Airtime:");
        scanf("%f",&amt.amount);
        if(bal.balance>(amt.amount)){
            //the amount of airtime should be less than the current balance in the account
            bal.balance=(bal.balance-amt.amount);//this will get the new balance to be stored in the system
            //now get the userpin
            printf("Enter the PIN:");
            scanf("%d",&pin.user_pin); 
        }
        if (pin.user_pin==get_pin){//This is the base case for the recurssion
            printf("[%d]confirmed Your new Airtime Balance is:%f\nYour Account Balance is:%f\n",airtime_random_code,amt.amount,bal.balance);
            //this should take us back to the main menu and the user can get other option
            printf("press (0) to return to main_menu or press any number (1->9)to terminate:");
            scanf("%d",&option);
            if (option==0){
                system("cls");
                printf(" your cuurent Account Balance is:%f\n",bal.balance);//this will display the current balance in the system
                main_menu(option,lower_code,upper_code);
            }//the user will press any key to terminate the system
            else{
                exit(0);
            }
        }
        else{
            printf("Incorrect PIN!\nPress 0 to resend! or press 1 to retrun to main menu:");
            scanf("%d",&option);
            //we should recover the amount removed from the system
            bal.balance=(bal.balance+amt.amount);
            if (option==0){
                //used recurssion to go back to the function if the PIN is INCORRECT
                Buy_Airtime(option,lower_code,upper_code);
            }else if(option==1){
                system("cls");
                //clear the screen 
                printf(" your cuurent Account Balance is:%f\n",bal.balance);//this will display the current balance in the system
                main_menu(option,lower_code,upper_code);
            }
            else{
                //if anumber other than 0 and 1 is pressed the program is terminated 
                exit(0);
            }
        }
    }//end of first option
    else if (option==2){
        int phone_number;//pnone number that will get the amount sent 
        printf("----|Buy Airtime for another Phone|------\n");

        printf("Enter the phone number:");
        scanf("%d",&phone_number);//get the phone number
        printf("Enter the Amount of Airtime:");
        scanf("%f",&amt.amount);//get the amount you wish to send
        if(bal.balance>amt.amount){
            bal.balance=(bal.balance-amt.amount);
            printf("Enter the pin:");
            scanf("%d",&pin.user_pin);
        }
        
        if(pin.user_pin==get_pin){
            printf("[%d]confirmed You Sent %f to this number:%d\n Your Account Balance is:%f\n",airtime_random_code,amt.amount,phone_number,bal.balance);
            //this should take us back to the main menu and the user can get other option
            printf("press (0) to return to main_menu:");
            scanf("%d",&option);
            if (option==0){
                system("cls");
                printf("your current Account Balance is:%f\n",bal.balance);//this will display the current balance in the system
                main_menu(option,lower_code,upper_code);
            }//the user will press any key to terminate the system
            else{
                exit(0);
            }
        }
        else{
            printf("Incorrect PIN!\nPress 0 to resend! or press 1 to return to main menu:");
            scanf("%d",&option);
            //get the balance that had been removed 
            bal.balance=(bal.balance+amt.amount);
            if (option==0){
                //the function calls itself of the pin is incorret
                Buy_Airtime(option,lower_code,upper_code);
            }else if(option==1){
                //the user will press any key to go to the main menu
                system("cls");
                //get the main menu
                printf("your cuurent Account Balance is:%f\n",bal.balance);//this will display the current balance in the system
                main_menu(option,lower_code,upper_code);
            }
            else{
                //program terminator
                exit(0);
            }
            
        }

    }//end of second option
}//end of buy airtime function

void Lipa_na_Mpesa(int option,int lower_code,int upper_code){
    //from this function the user can be able to pay using M-pesa 

    //generate a random FOUR figure number from 1000 to RAND_MAX ->32767
    //use the time function in order to get random values after every call 
    //the time function will act as our seed 
    int mpesa_random_code;//this is the value to display 
    srand(time(0));
    mpesa_random_code=(rand()%(upper_code-lower_code+1)+lower_code);//this line will get random values from 1024 to RAND_MAX

    printf("[1].PayBill\n[2].BuyGoods and Services\n");
    scanf("%d",&option);
    if (option==1){
        //get the paybill if user option is 1
        int Business_No,Account_No;
        //Get the business numer
        printf("Enter the Business NUmber:");
        scanf("%d",&Business_No);
        //get the account number
        printf("Enter the Account Number:");
        scanf("%d",&Account_No);
        //get the amount
        printf("Enter The Amount:");
        scanf("%f",&amt.amount);
        //after getting the amout the userwill under go some charges 
        //below are the charges that the userwill under go
        if(amt.amount>=1 && amt.amount<=100){
            charg.charges=0;
        }
        else if(amt.amount>100 && amt.amount<=500){
            charg.charges=11;
        }
        else if(amt.amount>500 && amt.amount<=1000){
            charg.charges=15;
        }
        else if(amt.amount>1000 && amt.amount<=1500){
            charg.charges=26;
        }
        else if(amt.amount>1500 && amt.amount<=2500){
            charg.charges=41;
        }
        else if(amt.amount>2500 && amt.amount<=3500){
            charg.charges=56;
        }
        else if(amt.amount>3500 && amt.amount<=5000){
            charg.charges=61;
        }
        else if(amt.amount>5000 && amt.amount<=7500){
            charg.charges=77;
        }
        else if(amt.amount>7500 && amt.amount<=10000){
            charg.charges=87;
        }
        else if(amt.amount>10000 && amt.amount<=15000){
            charg.charges=97;
        }
        else if(amt.amount>15000 && amt.amount<=20000){
            charg.charges=102;
        }
        else if(amt.amount>20000 && amt.amount<=70000){
            charg.charges=105;
        }
        else{
            //this checks if the amount entered is higher than the current balance in the system
            printf("Failed,You do not have enough money in your account\nYour new mpesa balance is %f!\n",bal.balance);
            printf("press 0 to return to main menu or press any number(1->9) to terminate:");
            scanf("%d",&option);
            if(option==0){
                system("cls");
                main_menu(option,lower_code,upper_code);
            }    
            else{
                exit(0);
            }
        }
        if (bal.balance>amt.amount){
            bal.balance=(bal.balance-(amt.amount+charg.charges));
            //deduct the amount plus the charges form the current balance
            printf("Enter PIN:");
            scanf("%d",&pin.user_pin);
        }
        if(pin.user_pin==get_pin){
            //display the amount payed 
            printf("[%d]confirmed ksh%f send to [%d] for Account [%d]You were charged ksh %f\nNew Mpesa Blance is ksh%f\n",mpesa_random_code,amt.amount,Business_No,Account_No,charg.charges,bal.balance);
            printf("press (0) to return to main_menu or press any number (1->9) to terminate:");
            scanf("%d",&option);
            if (option==0){
                system("cls");
                printf("your current Account Balance is:%f\n",bal.balance);//this will display the current balance in the system
                main_menu(option,lower_code,upper_code);
            }//the user will press any key to terminate the system
            else{
                exit(0);
            }
        }else{
            //if the user entersa wrong password 
            printf("Incorrect PIN\nPress 0 to try again! or press 1 to retrurn to main menu:");
            scanf("%d",&option);
            //recover the amount that we removed from the system
            bal.balance=bal.balance+(amt.amount+charg.charges);
            if (option==0){
                //recursion to call the function if the pin is incorrect
                Lipa_na_Mpesa(option,lower_code,upper_code);
            }
            else if(option==1){
                system("cls");
                printf("your cuurent Account Balance is:%f\n",bal.balance);//this will display the current balance in the system
                main_menu(option,lower_code,upper_code);
            }
            else{
                //end th program
                //press any number(1-9) to end the program
                exit(0);
            }
        }
    }//end of first otpion

    else if (option==2){
        int Till_No;
        printf("Enter the Till NUmber:");
        scanf("%d",&Till_No);
        //get the amount
        printf("Enter The Amount:");
        scanf("%f",&amt.amount);
        if (bal.balance>amt.amount){
            bal.balance=(bal.balance-(amt.amount+charg.charges));
            //deduct the amount plus the charges form the current balance
            printf("Enter PIN:");
            scanf("%d",&pin.user_pin);
        }
        else if(amt.amount>bal.amount){
            printf("insufficient Funds");
        }

        if(pin.user_pin==get_pin){
            //display the amount payed 
            printf("[%d]confirmed ksh%f paid to [%d] You were charged ksh %f\nNew Mpesa Blance is ksh%f\n",mpesa_random_code,amt.amount,Till_No,charg.charges,bal.balance);
            printf("press (0) to return to main_menu or press any number (1->9) to terminate:\n");
            scanf("%d",&option);
            if (option==0){
                system("cls");
                printf("your current Account Balance is:%f\n",bal.balance);//this will display the current balance in the system
                main_menu(option,lower_code,upper_code);
            }//the user will press any key to terminate the system
            else{
                exit(0);
         
            }
        }
        else{
            //if the user enters a wrong password 
            printf("Incorrect PIN\nPress 0 to try again! or press 1 to retrurn to main menu:");
            scanf("%d",&option);
            //recover the amount that we removed from the system
            bal.balance=bal.balance+(amt.amount+charg.charges);
            if (option==0){
                //recursion to call the function if the pin is incorrect
                Lipa_na_Mpesa(option,lower_code,upper_code);
            }
            else if(option==1){
                system("cls");
                printf("your cuurent Account Balance is:%f\n",bal.balance);//this will display the current balance in the system
                main_menu(option,lower_code,upper_code);
            }
            else{
                //end th program
                //press any number(1-9) to end the program
                exit(0);
            }
        }    


    }//END OF SECOND OPTION
   
}//end of lipa na mpesa function

void My_Account(int option,int lower_code,int upper_code){
    //get the random code 
    int account_random_code;//this is the value to display 
    srand(time(0));
    account_random_code=(rand()%(upper_code-lower_code+1)+lower_code);//this line will get random values from 1024 to RAND_MAX
    //this function will be used to get account information
    /*
    display the following:
        ->ministatement
        ->check balance 
        ->change PIN
    get the transactions done on that day
    for example the paybill,send money,mshwari ,get the charges and the transaction cost   
    */ 
   printf("[1].Mini_statement\n[2].check_Blance\n[3].change_PIN\n");
   printf("Your option:");
   scanf("%d",&option);
   if (option==1){
       //option one will get the ministatement or account information
       printf("mini statenemt\n");
        //pending->still working on it 

    }
    else if(option==2){
        //here one can check the balance in the account
        printf("[%d]confirmed your Mpesa new balance is ksh:%f\n",account_random_code,bal.balance);
        printf("Enter 0 to return to main menu or any number from 1->9 to terminaate the program");
        scanf("%d",&option);
        if (option==0){
            system("cls");
            printf("your current balance is:%f\n",bal.balance);
            main_menu(option,lower_code,upper_code);
        }else{
            exit(0);
            //terminate the program
        }
        //finished 
    }
    else if(option==3){
        //call the function to change the pin 
        change_pin(option,lower_code,upper_code);
        //finished 
    }

}//end of function

void main_menu(int option,int lower_code,int upper_code){
    //this will display the main window 
    //this is where the user will enter keyboard entries 
    printf("Select: \n");
    printf("1.Send money\n2.withdraw cash\n3.Buy airtime\n4.loans and savings\n5.Lipa na m-pesa\n6.My account\n");
    printf("---|press  0 to end the program|---\n");
    printf("Your Option:");
    scanf("%d", &option);
    if (option==1){
        send_money(option,lower_code,upper_code);
        //send mmoney
    }
    else if(option==2){
        withdraw_cash(option,lower_code,upper_code);
        //withdraw cash
    }
    else if(option==3){
        Buy_Airtime(option,lower_code,upper_code);
        //buy airtime
    }
    else if(option==5){
        Lipa_na_Mpesa(option,lower_code,upper_code);
        //lipa na mpesa 
    }
    else if (option==6){
        My_Account(option,lower_code,upper_code);
        //get the account information
    }
    else if(option==0){
        exit(0);
        //end the program
    }
}//end of main_finction

int main(){
    int option; 
    int lower_code=1024;//this will be the lowest codethat can be generated 
    int upper_code=RAND_MAX;//this is the maximum number that can be generated
    //scan the pin.txt file an fetch the new pin 
    FILE *FK;//file pointer
    FK=fopen("pin.txt","a+");
    //open the file in  append mode so that a file can be created if it does not exist  
    while(!feof(FK)){
        //while not at the end of file scan the file 
        //use the feof()->function
        //fetch the account pin once the program is run since the main function is compiled first
        fscanf(FK,"%d",&get_pin);
        //this will peint the password on the screen
        printf("The password is:%d\n",get_pin);
        if(get_pin==0){
            //this informs the user that the file has no password 
            printf("Kindly press option [6] to register For a password after entering the balance!\n");
        }
    }
    fclose(FK);//close the file with the password 


    printf("------Welcome to our mobile Money!-----\n");
    printf("Enter your balance:");
    scanf("%f",&bal.balance);
    main_menu(option,lower_code,upper_code);
    return 0;
 
}//end of program
