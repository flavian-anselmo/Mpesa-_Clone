#include<stdio.h>
#include<stdlib.h>//used this library so that i can clear the screen
#include<time.h>//this works as our seed in the random function
//#include "mobile_login.h"//this is an external library for login
#define N 12//The size of array getting the charges
//function prototypes
void main_menu();//finished
void send_money();//finished
void withdraw_cash();//finished
void Buy_Airtime();//finished
void Lipa_na_Mpesa();//finished
void My_Account();//finished
void change_pin();//finished
void Login_to_Account();//finished
void Loans_and_savings();//pending

int get_pin;//global variable for storing our PIN
char account_name[N];//global variable for storing our username

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
mobile amt_save;//save to mshwari
mobile amt_send;//this is  for amount_sent->finished
mobile amt_tran;//this is for amount_transacted->
mobile amt_lipa;//this is the amount in lipa na mpesa
mobile amt_buy;//this is the amount when buying airtime-
mobile charg_send;//this is for charges for amount sent-
mobile charg_lipa;//this are the charges for amount in lipa na mpesa
mobile pin;//this is for user_pin
mobile tran;//this id for transaction_cost

void Login_to_Account(int option,int lower_code,int upper_code){
        //if the user has no password he or she will register for a new one
    FILE *FK;
    FILE *FN;
    char name[N];//This variable will be used during scanning the file to fetch the username in username.txt file
    printf("----|WELCOME TO OUR MOBILE MONEY|----\n");
    printf("[+]]Press [0] to LOGIN or [1] to REGISTER for Account PIN:");
    scanf("%d",&option);
    if(option==1){
        //the user will register for a new PIN
        FK=fopen("pin.txt","a+");
        FN=fopen("username.txt","a+");
        //open the file in append mode
        printf("Enter your user_name:");
        scanf("%s",account_name);
        fprintf(FN,"%s\n",account_name);//write the user_name
        printf("Enter your PIN:");
        scanf("%d",&get_pin);
        fprintf(FK,"%d\n",get_pin);//write the pin
        //close all files after writing to them
        fclose(FK);
        fclose(FN);
        system("cls");
        //now scan to get the PIN and user_name
        //open the two files and login
        FK=fopen("pin.txt","a+");
        FN=fopen("username.txt","a+");
        while((!feof(FK)) && (!feof(FN))){
            //while not at the EOF scan and get the PIN
            //!feof(FK)
            fscanf(FK,"%d\n",&get_pin);
            fscanf(FN,"%s\n",name);
            //get the username and the PIN
        }//end of scan
        //now try and login
        printf("----|WELCOME TO OUR MOBILE MONEY|----user_name[%s]\n",name);
        printf("user_name:%s\n",name);
        printf("Enter PIN:");
        scanf("%d",&pin.user_pin);//get the pin from the user
        if(pin.user_pin==get_pin){//validate that the pin is correct
            printf("----|LOGIN SUCCESSFULL!|-----\n");//log in
            printf("Enter your balance:");
            scanf("%f",&bal.balance);
            system("cls");
            printf("----|LOGIN SUCCESSFULL!|-----\n");
            printf("your Balance is:%f\n",bal.balance);
            main_menu(option,lower_code,upper_code);
        }
        else{
            //if pin is wrong call the function recursively
            system("cls");
            printf("Access was Denied! Try Again!\n");
            Login_to_Account(option,lower_code,upper_code);

        }
        //close the two files
        fclose(FK);
        fclose(FN);
    } //end of option 1

    else if(option==0){
        //open the TWO files storing the username and the PIN
        FK=fopen("pin.txt","a+");
        FN=fopen("username.txt","a+");
        while((!feof(FK)) && (!feof(FN))){
            //while not at the EOF scan and get the PIN
            //!feof(FK)
            fscanf(FK,"%d",&get_pin);
            fscanf(FN,"%s",name);
            //get the username and the PIN
        }
        //now check if the credentials are the same
        printf("----|WELCOME TO OUR MOBILE MONEY|----user_name[%s]\n",name);
        printf("user_name:%s\n",name);
        printf("Enter PIN:");
        scanf("%d",&pin.user_pin);
        if(pin.user_pin==get_pin){//check if the PIN IS correct
            printf("----|LOGIN SUCCESSFULL!|-----\n");
            printf("Enter your balance:");//login successfully
            scanf("%f",&bal.balance);
            system("cls");
            printf("----|LOGIN SUCCESSFULL!|-----\n");
            printf("your Balance is:%f\n",bal.balance);
            main_menu(option,lower_code,upper_code);
        }
        else{
            //if the password is wrong call the function recursively
            system("cls");
            printf("Access was Denied! Try Again!\n");
            Login_to_Account(option,lower_code,upper_code);

        }
    } //end of option 0
}//end of login function

void change_pin(int option,int lower_code,int upper_code){
    //the user can chage their pin
    /*i will write the PIN to a file
    I will write an integer to a file
    */
   FILE *FP;//This is the file pointer for pin.txt
   FILE *FN;//file pointer to the username.txt
   FN=fopen("username.txt","a+");
   FP=fopen("pin.txt","a+");

   //the file is opened in append mode
   //since the pin is an integer we shall use fprintf and fscanf to write an integerto a file
   printf("Enter Your User_Name:");
   scanf("%s",account_name);//i used the scanset so that the user can have a space in his or her name
   fprintf(FN,"%s\n",account_name);

   printf("Enter a PIN with numbers (0->9):");
   scanf("%d",&get_pin);
   fprintf(FP,"%d\n",get_pin);//write an integerto a file

   fclose(FP);
   fclose(FN);
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
    scanf("%f",&amt_send.amount);
    if(amt_send.amount>=1 && amt_send.amount<=100){
        charg_send.charges=0;//
    }
    else if(amt_send.amount>100 && amt_send.amount<=500){
        charg_send.charges=11;//
    }
    else if(amt_send.amount>500 && amt_send.amount<=1000){
        charg_send.charges=15;//
    }
    else if(amt_send.amount>1000 && amt_send.amount<=1500){
        charg_send.charges=26;//
    }
    else if(amt_send.amount>1500 && amt_send.amount<=2500){
        charg_send.charges=41;//
    }
    else if(amt_send.amount>2500 && amt_send.amount<=3500){
        charg_send.charges=56;//
    }
    else if(amt_send.amount>3500 && amt_send.amount<=5000){
        charg_send.charges=61;//
    }
    else if(amt_send.amount>5000 && amt_send.amount<=7500){
        charg_send.charges=77;//
    }
    else if(amt_send.amount>7500 && amt_send.amount<=10000){
        charg_send.charges=87;//
    }
    else if(amt_send.amount>10000 && amt_send.amount<=15000){
        charg_send.charges=97;//
    }
    else if(amt_send.amount>15000 && amt_send.amount<=20000){
        charg_send.charges=102;//
    }
    else if(amt_send.amount>20000 && amt_send.amount<=70000){
        charg_send.charges=105;//
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
    //write to file this will be used later in the mini statement
    if(bal.balance > (amt_send.amount+charg_send.charges)){
        //the balance should be greater than amount + charges for the user to enter the pin
        bal.balance=bal.balance-(amt_send.amount+charg_send.charges);
        //deduct the amount+charges sent from the previous balance
        printf("Enter Your PIN:");
        scanf("%d", &pin.user_pin);
    }

    if (pin.user_pin==get_pin){
        printf("[%d] confirmed You Have sent->%f\nYour Working Balance is->%f\nTransaction Charges is->%f\n***Thank You for using our services!***\n",
                                                                                                                                    send_random_code,
                                                                                                                                    amt_send.amount,
                                                                                                                                    bal.balance, 
                                                                                                                                    charg_send.charges);
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
        bal.balance=bal.balance+(amt_send.amount+charg_send.charges);
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
        scanf("%f",&amt_tran.amount);//the user will enter the amount he or she wants to withdraw
        if(amt_tran.amount>=1 && amt_tran.amount<=100){
            tran.transaction_cost=0;//
        }
        else if(amt_tran.amount>100 && amt_tran.amount<=500){
            tran.transaction_cost=11;//
        }
        else if(amt_tran.amount>500 && amt_tran.amount<=1000){
            tran.transaction_cost=15;//
        }
        else if(amt_tran.amount>1000 && amt_tran.amount<=1500){
            tran.transaction_cost=26;//
        }
        else if(amt_tran.amount>1500 && amt_tran.amount<=2500){
            tran.transaction_cost=41;//
        }
        else if(amt_tran.amount>2500 && amt_tran.amount<=3500){
            tran.transaction_cost=56;//
        }
        else if(amt_tran.amount>3500 && amt_tran.amount<=5000){
            tran.transaction_cost=61;//
        }
        else if(amt_tran.amount>5000 && amt_tran.amount<=7500){
            tran.transaction_cost=77;//
        }
        else if(amt_tran.amount>7500 && amt_tran.amount<=10000){
            tran.transaction_cost=87;//
        }
        else if(amt_tran.amount>10000 && amt_tran.amount<=15000){
            tran.transaction_cost=97;//
        }
        else if(amt_tran.amount>15000 && amt_tran.amount<=20000){
            tran.transaction_cost=102;//
        }
        else if(amt_tran.amount>20000 && amt_tran.amount<=70000){
            tran.transaction_cost=105;//
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
         //write to file this will be used later in the mini statement
        if(bal.balance > (amt_tran.amount+tran.transaction_cost)){
            //the balance should be greater than amount + transaction_cost for the user to enter the pin
            bal.balance=bal.balance-(amt_tran.amount+tran.transaction_cost);
            //deduct the amount+transaction_cost  from the previous balance
            printf("Enter Your PIN:");
            scanf("%d", &pin.user_pin);
        }
        if (pin.user_pin==get_pin){//base case for the recursion
            printf("[%d]confirmed You withdrew %ffrom the Agent number %d\nYour current Balance is->%f\nTransaction cost is->%f\n***Thank You for using our services!***\n",
                                                                                        withdraw_random_code,
                                                                                        amt_tran.amount,
                                                                                        Agent_No, bal.balance, 
                                                                                        tran.transaction_cost);
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
            bal.balance=bal.balance+(amt_tran.amount+tran.transaction_cost);
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
        scanf("%f",&amt_buy.amount);
        if(bal.balance>(amt_buy.amount)){
            //the amount of airtime should be less than the current balance in the account
            bal.balance=(bal.balance-amt_buy.amount);//this will get the new balance to be stored in the system
            //now get the userpin
            printf("Enter the PIN:");
            scanf("%d",&pin.user_pin);
        }
        if (pin.user_pin==get_pin){//This is the base case for the recurssion
            printf("[%d]confirmed Your new Airtime Balance is:%f\nYour Account Balance is:%f\n",airtime_random_code,amt_buy.amount,bal.balance);
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
            bal.balance=(bal.balance+amt_buy.amount);
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
        scanf("%f",&amt_buy.amount);//get the amount you wish to send
        if(bal.balance>amt_buy.amount){
            bal.balance=(bal.balance-amt_buy.amount);
            printf("Enter the pin:");
            scanf("%d",&pin.user_pin);
        }

        if(pin.user_pin==get_pin){
            printf("[%d]confirmed You Sent %f to this number:%d\n Your Account Balance is:%f\n",
                                                                            airtime_random_code,
                                                                            amt_buy.amount,
                                                                            phone_number,
                                                                            bal.balance);
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
            bal.balance=(bal.balance+amt_buy.amount);
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
        scanf("%f",&amt_lipa.amount);
        //after getting the amout the userwill under go some charges
        //below are the charges that the userwill under go
        if(amt_lipa.amount>=1 && amt_lipa.amount<=100){
            charg_lipa.charges=0;//
        }
        else if(amt_lipa.amount>100 && amt_lipa.amount<=500){
            charg_lipa.charges=11;//
        }
        else if(amt_lipa.amount>500 && amt_lipa.amount<=1000){
            charg_lipa.charges=15;//
        }
        else if(amt_lipa.amount>1000 && amt_lipa.amount<=1500){
            charg_lipa.charges=26;//
        }
        else if(amt_lipa.amount>1500 && amt_lipa.amount<=2500){
            charg_lipa.charges=41;//
        }
        else if(amt_lipa.amount>2500 && amt_lipa.amount<=3500){
            charg_lipa.charges=56;//
        }
        else if(amt_lipa.amount>3500 && amt_lipa.amount<=5000){
            charg_lipa.charges=61;//
        }
        else if(amt_lipa.amount>5000 && amt_lipa.amount<=7500){
            charg_lipa.charges=77;//
        }
        else if(amt_lipa.amount>7500 && amt_lipa.amount<=10000){
            charg_lipa.charges=87;//
        }
        else if(amt_lipa.amount>10000 && amt_lipa.amount<=15000){
            charg_lipa.charges=97;//
        }
        else if(amt_lipa.amount>15000 && amt_lipa.amount<=20000){
            charg_lipa.charges=102;//
        }
        else if(amt_lipa.amount>20000 && amt_lipa.amount<=70000){
            charg_lipa.charges=105;//
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
        if (bal.balance>amt_lipa.amount){
            bal.balance=(bal.balance-(amt_lipa.amount+charg_lipa.charges));
            //deduct the amount plus the charges form the current balance
            printf("Enter PIN:");
            scanf("%d",&pin.user_pin);
        }
        if(pin.user_pin==get_pin){
            //display the amount payed
            printf("[%d]confirmed ksh%f send to [%d] for Account [%d]You were charged ksh %f\nNew Mpesa Blance is ksh%f\n",
                                                                                                            mpesa_random_code,
                                                                                                            amt_lipa.amount,
                                                                                                            Business_No,
                                                                                                            Account_No,
                                                                                                            charg_lipa.charges,
                                                                                                            bal.balance);
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
            bal.balance=bal.balance+(amt_lipa.amount+charg_lipa.charges);
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
        scanf("%f",&amt_lipa.amount);
        if (bal.balance>amt_lipa.amount){
            bal.balance=(bal.balance-(amt_lipa.amount+charg_lipa.charges));
            //deduct the amount plus the charges form the current balance
            printf("Enter PIN:");
            scanf("%d",&pin.user_pin);
        }
        else if(amt_lipa.amount>bal.amount){
            printf("insufficient Funds");
        }

        if(pin.user_pin==get_pin){
            //display the amount payed
            printf("[%d]confirmed ksh%f paid to [%d] You were charged ksh %f\nNew Mpesa Blance is ksh%f\n",
                                                                                        mpesa_random_code,
                                                                                        amt_lipa.amount,
                                                                                        Till_No,
                                                                                        charg_lipa.charges,
                                                                                        bal.balance);
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
            bal.balance=bal.balance+(amt_lipa.amount+charg_lipa.charges);
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
       /*
       the mini statement will keep track of any
       transactions done at any given time.
       The mini statement keeps track of any charges
       taken from the user;
                ->transaction cost
                ->charges while sending money
                ->charges while using Lipa na mpesa
                ->display the money sent
                ->display the money withdrawn
                ->this will also work later with Mshwari once mshwari capabilities are enabled
       */      
        printf("[%d]confirmed Current money sent ksh[%f] and the charge is ksh[%f]\n",account_random_code,amt_send.amount,charg_send.charges);
        printf("Current money withdrawned is ksh[%f] and transaction_cost is ksh[%f]\n",amt_tran.amount,tran.transaction_cost);
        printf("Current money paid with mpesa is ksh[%f] and the charge is ksh[%f]\n",amt_lipa.amount,charg_lipa.charges);

        printf("Press 0 to return to main menu:");
        scanf("%d",&option);
        if(option==0){
            system("cls");
            main_menu(option,lower_code,upper_code);
        }else{
            exit(0);
            //end the program
        }
       

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

void Loans_and_savings(int option,int lower_code,int upper_code){
    //get a random code
    int mshwari_random_code;//this is the value to display
    srand(time(0));
    mshwari_random_code=(rand()%(upper_code-lower_code+1)+lower_code);//this line will get random values from 1024 to RAND_MAX

    //this function will have mshwari capabilities 
    /*
    ->send to mashwari
        -once the amount is sent the balance will reduce dynamically
    ->withdraw from Mshwari
        -once the amount is withdrawn the balance will increase dynamically 
    */
   float prev_amount=amt_save.amount;//used to update the amount sent to mshwari
   printf("[1].M_shwari\n");
   printf("Your option:");
   scanf("%d",&option);
   if(option==1){
       //send money to mshwari
       //the account balnce will be updated once the usersends any amount to mshwari account 
       printf("[1].Send to M_shwari\n[2].Withdraw from M_shwari\n[3].check balance\n");
       printf("Your Option:");
       scanf("%d",&option);
       if (option==1){
           //make savings
           printf("Enter Amount:");
           scanf("%f",&amt_save.amount);
           if(bal.balance>amt_save.amount){
                //reduce the account balance
                bal.balance=(bal.balance-amt_save.amount);
                //allow the user to enter the PIN
                printf("Enter PIN:");
                scanf("%d",&pin.user_pin); 
            }else{
                //inform the user the he or she has insufficient funds
                printf("You have insufficient Funds!\n");
                printf("press 0 to return to main_menu");
                scanf("%d",&option);
                if(option==0){
                    system("cls");
                    printf("Your account balance is ksh %f",bal.balance);
                    main_menu(option,lower_code,upper_code);
                }else{
                    //end the program
                    exit(0);
                }
            }
            if(pin.user_pin==get_pin){
                //if the pin entered is correct allow the userto save money to mshwari
                //prev_amount updates the amount saved to mshwari incase the user sends money to mshwari more than once 
                prev_amount=(prev_amount+amt_save.amount);
                
                printf("[%d].confirmed ksh %f was transfered to mshwari\nYour Mshwari balance is ksh %f\nYour Mpesa balance is ksh %f\n",
                                                                                                                mshwari_random_code,
                                                                                                                amt_save.amount,
                                                                                                                prev_amount,
                                                                                                                bal.balance);
              // get the new amount incase  the user sends amount to mshwari more than once                                                                                                  
                amt_save.amount=prev_amount;//update the amount                                                                                                  
                printf("press 0 to return to main_menu");
                scanf("%d",&option);
                if(option==0){
                    //go to main menu
                    system("cls");
                    printf("Your account balance is ksh %f",bal.balance);
                    main_menu(option,lower_code,upper_code);
                }else{
                    //exit
                    exit(0);
                }                                                                                                                                                                                                    
            }else{
                //return the amount that was deducted form tha account balance
                bal.balance=(bal.balance+amt_save.amount);
                printf("press o to return to main menu");
                scanf("%d",&option);
                if(option==0){
                    //return to main menu
                    system("cls");
                    printf("Your Account balance is ksh %f",bal.balance);
                    main_menu(option,lower_code,upper_code);
                }else{
                    //end the program
                    exit(0);
                }
            }
        }//end of otption one

        else if(option==2){
            float amount_withdraw;//the amount the user will withdraw from
            //withdraw form mshwari
            //return the amount specified by the user and update the account balance globally 
            printf("Enter Amount:");
            scanf("%f",&amount_withdraw);
            printf("Enter PIN:");
            scanf("%d",&pin.user_pin);
            if((pin.user_pin==get_pin)&&(amt_save.amount>=amount_withdraw)){
                //the mshwari balance should be reduced 
                //the account balance should also be reduced 
                amt_save.amount=(amt_save.amount-amount_withdraw);//update the new mshwari balance
                bal.balance=(bal.balance+amount_withdraw);//update the account balance globally 
                printf("press 0 to return to main menu:");
                scanf("%d",&option);
                if (option==0){
                    system("cls");
                    printf("Your Account balance is ksh %f",bal.balance);
                    main_menu(option,lower_code,upper_code);
                }else{
                    //ens the program
                    exit(0);
                }

            }
            else if (amount_withdraw>amt_save.amount){
                //if the amount entered by the user is greater than the amount in mshwari
                printf("Amount entered is more than amount in Mshwari");
                printf("press 0 to return to main menu:");
                scanf("%d",&option);
                if (option==0){
                    system("cls");
                    printf("Your account balance is ksh %f",bal.balance);
                    main_menu(option,lower_code,upper_code);
                }else{
                    //end the program
                    exit(0);
                }
            }
        }//end of option  two

        else if(option==3){
            //display the mshwari balance to the user
            //get another random number
            mshwari_random_code=(rand()%(upper_code-lower_code+1)+lower_code);
            printf("[%d].confirmed Your M_shwari Balance is ksh %f /=\n",mshwari_random_code,prev_amount);
            printf("press 0 to return to main_menu:");
            scanf("%d",&option);
            if (option==0){
                //return to main
                system("cls");
                printf("Your account balance is ksh %f",bal.balance);
                main_menu(option,lower_code,upper_code);
            }else{
                //end the program
                exit(0);

            }
        }//end of option 3

    }//end of option one
    else{
       exit(0);
       //end the program
    }

}//end of function mshwari

void main_menu(int option,int lower_code,int upper_code){
    //this will display the main window
    //this is where the user will enter keyboard entries
    printf("Select: \n");
    printf("1.Send money\n2.withdraw cash\n3.Buy airtime\n4.loans and savings\n5.Lipa na m-pesa\n6.My account\n");
    printf("---|press  [0] to LOG_OUT or [9] to terminate the program|---\n");
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
    else if(option==4){
        Loans_and_savings(option,lower_code,upper_code);
        //saved money

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
        system("cls");
        Login_to_Account(option,lower_code,upper_code);
        //logout form the system
    }
    else if (option==9){
        exit(0);
        //end program
    }
}//end of main_finction

int main(){
    int option;
    int lower_code=1024;//this will be the lowest codethat can be generated
    int upper_code=RAND_MAX;//this is the maximum number that can be generated

    Login_to_Account(option,lower_code,upper_code);//call this function to login to the system
    return 0;
}//end of program
