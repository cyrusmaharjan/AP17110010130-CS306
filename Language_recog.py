state=0
ip=input("Enter a string:")
for i in ip:
    if (state==0):
        if(i=='a'):
            state=1
        elif(i=='b'):
            state=3
        else:
            print("invalid input")
            state=4
            
            
    elif (state==1):
        if(i=='a'):
            state=0
        elif(i=='b'):
            state=2
        else:
            print("invalid input")
            state=4
            
           
    elif (state==2):
        if(i=='a'):
            state=3
        elif(i=='b'):
            state=1
        else:
            print("invalid input")
            state=4
            

    elif(state==3): 
        if(i=='a'):
            state=2
        elif(i=='b'):
            state=0
        else:
            print("invalid input")
            state=4
        
        
if(state==0):
    print("Accepted")
else:
    print("Not Accepted")
        
                        
            
            