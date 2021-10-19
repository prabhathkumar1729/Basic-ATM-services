print("Welcome to VJIT ATM services")
restart=('y')
chances=3
pin=1234
savings=5000
current=5000
balance=savings+current
confirm='n'
trace=[]
while chances>=0:
    temp=int(input("please enter 4 digit pin: "))
    if pin==temp:
        while restart!='n':
            print("1.Balance enquiry\n2.Withdrawal\n3.Deposit\n4.Mini statement\n5.PIN change\n6.Transfer\n7.Exit")
            option=int(input("What would you like to choose?: "))
            if option==1:
                print("Savings account:",savings,"\nCurrent account:",current,"\nYour total balance is: ",balance)
                restart=input("Do you want to restart (y/n): ")
                if restart=='n':
                    print("Thank you\nHave a nice day")
                    exit()
            elif option==2:
                while confirm=='n':
                    amount=int(input("Please enter the amount you want to withdraw in multiples of 100: "))
                    if amount%100!=0:
                        print("Entered amount is not in multiples of 100 ")
                    else:
                        confirm=input("Confirm to withdraw: "+str(amount)+" (y/n):")
                confirm='n'
                t=int(input("Choose\n1.savings account\n2.Current account\n"))
                temp=savings if t==1 else current
                if amount<=temp:
                    temp-=amount
                    if t==1:
                        savings=temp
                    else:
                        current=temp
                    balance=savings+current
                    print("Successfully withdrawn {} from  {}   Remaining balance:{}".format(amount,"savings account"  if t==1 else "current account",balance))
                    trace.append("{} Amount withdrawn from {}  Avl bal {}".format(amount,"savings account"if t==1 else "current account",balance))
                else:
                    print("Insufficient balance")
                    trace.append("{} Amount failed to withdraw from {}  Avl bal {}".format(amount,"savings account"if t==1 else "current account",balance))
                restart=input("Do you want to restart (y/n): ")
                if restart=='n':
                    print("Thank you\nHave a nice day")
                    exit()
            elif option==3:
                while confirm=="n":
                    amount=int(input("Please enter the amount you want to deposit in multiples of 100: "))
                    if amount%100!=0:
                        print("Entered amount is not in multiples of 100 ")
                    else:
                        confirm=input("Confirm to deposit: "+str(amount)+" (y/n):")
                confirm='n'
                t=int(input("Choose\n1.savings account\n2.Current account\n"))
                temp=savings if t==1 else current
                temp+=amount
                if t==1:
                    savings=temp
                else:
                    current=temp
                balance=savings+current
                print("Successfully deposited {} into  {}   Available balance:{}".format(amount,"savings account"  if t==1 else "current account",balance))
                trace.append("{} Amount deposited into {}  Avl bal {}".format(amount,"savings account"if t==1 else "current account",balance))
                restart=input("Do you want to restart (y/n): ")
                if restart=='n':
                    print("Thank you\nHave a nice day")
                    exit()  
            elif option==4:
                for i in trace:
                    print(i)
                restart=input("Do you want to restart (y/n): ")
                if restart=='n':
                    print("Thank you\nHave a nice day")
                    exit()
            elif option==5:
                chances_=3
                while chances_>=0:
                    temp=int(input("Enter your current 4 digit PIN: "))
                    if(temp==pin):
                        break
                    else:
                        if chances_!=1:
                            chances_-=1
                            print("Entered wrong PIN\nYou have ",chances_,"chances")
                        else:
                            print("Your card is blocked")
                            exit()
                while confirm=='n':
                    newpin=int(input("Enter new 4 digit pin: "))
                    if newpin==pin:
                        print("You entered current PIN, please enter another PIN: ")
                    else:
                        confirm=input("confirm (y/n): ")
                confirm='n'
                pin=newpin
                print("PIN successfully changed")
                trace.append("PIN changed")
                restart=input("Do you want to restart (y/n): ")
                if restart=='n':
                    print("Thank you\nHave a nice day")
                    exit()
            elif option==6:
                while confirm=='n':
                    account=int(input("Transfer money to account number: "))
                    amount=int(input("Amount to transfer: "))
                    confirm=input("confirm to tranfer "+str(amount)+" to "+str(account)+" (y/n): ")
                confirm='n'
                t=int(input("Choose\n1.savings account\n2.Current account\n"))
                temp=savings if t==1 else current
                if amount<=temp:
                    temp-=amount
                    if t==1:
                        savings=temp
                    else:
                        current=temp
                    balance=savings+current
                    print("Succesfully transfered {} from {} to {}    Remaining balance:{}".format(amount,"savings account"if t==1 else "current account",account,balance))
                    trace.append("{} Amount successfully transfered from {} to {}    Avl balance:{}".format(amount,"savings account"if t==1 else "current account",account,balance))
                else:
                    print("Insufficient balance")
                    trace.append("{} Amount unsuccessfully transfered from {} to {}    Avl balance:{}".format(amount,"savings account"if t==1 else "current account",account,balance))
                restart=input("Do you want to restart (y/n): ")
                if restart=='n':
                    print("Thank you\nHave a nice day")
                    exit()
            elif option==7:
                print("Thank you\nHave a nice day")
                exit()
    else:
        if chances!=1:
            chances-=1
            print("Entered wrong PIN\nYou have ",chances,"chances")
        else:
            print("Your card is blocked")
            exit()
