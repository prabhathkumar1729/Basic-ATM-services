                                                      /*VJIT ATM SERVICES
                                                          PIN-4321
                                            initial money in savings account=25000/- 
                                            initial money in current account=50000/-*/
#include <stdio.h>
int pin_(int pin)
{
    int b, i = 1;
    printf ("Enter the 4 digit pin:  ");
    scanf("%d",&b);
    while(b!=pin&&i<=4)
        {   
            if(i<3)
                {
                    printf("ENTERED WRONG PIN,PLEASE ENTER CORRECT PIN:  ");
                    scanf("%d",&b);
                }
            i++;
        }
    return i;
}
int displayy (int sav, int cur)
{
                printf("\nAMOUNT AVAILABLE IN SAVINGS ACCOUNT=%d\nAMOUNT AVAILABLE IN CURRENT ACCOUNT=%d\nBALANCE AMOUNT=%d",sav, cur, sav + cur);
}
int main ()
{
    int a,amnt,j,account,c,pin=4321,confirm;
    static int sav = 25000, cur = 50000;
                printf("Hello\nWelcome to VJIT ATM services\nPLEASE INSERT YOUR CARD\n1)Deposit\n2)Money Transfer\n3)PIN change\n4)Cash Withdrawal\n5)Balance Enquiry\n6)Mini statement\nPLEASE ENTER THE SERVICE NUMBER YOU ARE SEARCHING FOR:   ");
                scanf ("%d", &a);
    switch (a)
    {
    case 1:
    //Deposit
        j = pin_ (pin);
        if (j ==5)      printf("YOUR CARD IS BLOCKED DUE TO ENTERING WRONG PIN\nPLEASE CONTACT OUR CUSTOMER CARE TOLL-FREE NUMBER OR VISIT OUR NEAR BRANCH FOR ANY FURTHER HELP");
        else
            {
                confirm=0;
                while(confirm!=1)
                        {
	                        printf("Please deposit money in multiples of 100,500\nEnter how much amount you want to deposit:   ");
	                        scanf ("%d", &amnt);
	                        if(amnt%100==0||amnt%500==0)
	                        {
	                        printf("To confirm enter 1 & if not confirm enter 2:   ");
                            scanf("%d",&confirm);
	                        }
	                        else printf("PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100,500\n");
                        }
	            sav = sav + amnt;
	            printf("Deposited RUPEES %d Successfully",amnt);
                displayy (sav, cur);
            }    
    break;
    case 2:
    //Transfer
        j=pin_(pin);
        if (j == 5)          printf("YOUR CARD IS BLOCKED DUE TO ENTERING WRONG PIN\nPLEASE CONTACT OUR CUSTOMER CARE TOLL-FREE NUMBER OR VISIT OUR NEAR BRANCH FOR ANY FURTHER HELP");
        else
            {   
                confirm=0;
                while(confirm!=1)
                    {
                        printf("Enter the ACCOUNT NUMBER to which you want to transfer money:   ");
                        scanf("%d",&account);
                        printf("To confirm enter 1 & if not confirm enter 2:   ");
                        scanf("%d",&confirm);
                    } 
                printf("Transfer money from\n1)SAVINGS ACCOUNT\n2)CURRENT ACCOUNT\nFrom:   ");
                scanf("%d",&c);
                confirm=0;
                while(confirm!=1)
                    {
                        printf("Enter how much amount you want to Transfer:   ");
                        scanf("%d",&amnt);
                        printf("To confirm enter 1 & if not confirm enter 2:   ");
                        scanf("%d",&confirm);
                    }
                if(c==1)
                    {
                        if(amnt>sav)    
                        {
                            printf("you don't have sufficient funds in your acoount to transfer money");
                        }
                        else    
                            {
                                sav=sav-amnt;
                                printf("Successfully transfered %d RUPEES to %d\n",amnt,account);
	  	                    }    
                    }
                else
                    {
                        if(amnt>cur)    
                        {
                            printf("you don't have sufficient funds in your acoount to transfer money");
                        }
                        else
                            {
                                cur=cur-amnt;
                                
                            printf("Successfully transfered %d RUPEES to %d\n",amnt,account);
		                     }    
                    }    
            
        displayy(sav,cur);
            }    
    break;
    case 3:
    //pin change
       j=pin_(pin);
       if(j==5 )    printf("YOUR CARD IS BLOCKED DUE TO ENTERING WRONG PIN\nPLEASE CONTACT OUR CUSTOMER CARE TOLL-FREE NUMBER OR VISIT OUR NEAR BRANCH FOR ANY FURTHER HELP");
        else 
        {
            c=pin;
            confirm=0;
            while(confirm!=1)
                {
                    printf("Enter New 4 digit PIN:   ");
                    scanf("%d",&pin);
                    if(c==pin)
                        {
                            printf("Entered last PIN,please enter a new PIN:   ");
                            scanf("%d",&pin);
                        }
                    printf("To confirm enter 1 & if not confirm enter 2:   ");
                    scanf("%d",&confirm);
                }
            printf("Successfully changed your PIN ");
        }
    break;
    case 4:
    //cash Withdrawal
        j=pin_(pin);
        if(j==5)    printf("YOUR CARD IS BLOCKED DUE TO ENTERING WRONG PIN\nPLEASE CONTACT OUR CUSTOMER CARE TOLL-FREE NUMBER OR VISIT OUR NEAR BRANCH FOR ANY FURTHER HELP");
        else
            {   
                printf("Withdraw money from your\n1)SAVINGS ACCOUNT\n2)CURRENT ACCOUNT\nFrom:   ");
                scanf("%d",&c);
                confirm=0;
                while(confirm!=1)
                    {
                        printf("Enter how much amount you want to withdraw in multiples of 100,500:   ");
                        scanf("%d",&amnt);
                        if(amnt%100==0||amnt%500==0)
	                        {
                             printf("To confirm enter 1 & if not confirm enter 2:   ");
                             scanf("%d",&confirm);
	                        }
	                        else printf("PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100,500\n");
                    }
                if(c==1)
                    {
                        if(amnt>sav)
                        {
                            printf("you don't have sufficient funds in your account to withdraw money");
                        }
                        else
                            {
                                sav=sav-amnt;
		                        printf("Transaction is Successfull, Please collect %d RUPEES\n",amnt);
                            }    
                    }
                else 
                    {
                        if(amnt>cur)   
                        {
                            printf("you don't have sufficient funds in your acoount to transfer money");
                        }
                        else
                            {
                                cur=cur-amnt;
    	                        printf("Transaction is Successfull, Please collect %d RUPEES\n",amnt);
                            }
                    }
            
        displayy(sav,cur);
            }
    break; 
    case 5:
    //balance check
        j=pin_(pin);
        if(j==5)    
        {
            printf("YOUR CARD IS BLOCKED DUE TO ENTERING WRONG PIN\nPLEASE CONTACT OUR CUSTOMER CARE TOLL-FREE NUMBER OR VISIT OUR NEAR BRANCH FOR ANY FURTHER HELP");
        }
        else
            {
                displayy(sav,cur);  
            }
    break;
    case 6:
    //ministatement
        j = pin_ (pin);
        if(j ==5)    
        {
            printf("\nYOUR CARD IS BLOCKED DUE TO ENTERING WRONG PIN\nPLEASE CONTACT OUR CUSTOMER CARE TOLL-FREE NUMBER OR VISIT OUR NEAR BRANCH FOR ANY FURTHER HELP");
        }
	    else
		    {
                printf ("10/12  Rs-3500  Withdraw\n");
		        printf ("11/12  Rs-3453  Transfer\n");
		        printf ("11/12  Rs-453  paytm\n");
		        printf ("12/12  Rs-53  paytm\n");
		        printf ("12/12  Rs-64453  Transfer\n");
		        printf ("AVAILABLE BALANCE=%d\n", sav + cur);
		    }
    break;
    }
    printf ("\nTHANQ FOR VISITING");
}
