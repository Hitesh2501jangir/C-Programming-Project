#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// Functions
void cycle();
void show_Detail();
void bus();
void car();
void bike();
void rickshaw();
void delete();
char menu();
void amount();
void file();
void SMenu();
void LMenu();
void algoritm();
void reverse();
// Variables
char day[15];
char date[15];
char fil[18];
char st[6];
int Bus=0,Bike=0,Car=0,Rickshaw=0,Cycle=0;
int Total_amount=0,Total_vechile=0;
int Bus_amount=0,Bike_amount=0,Car_amount=0,Cycle_amount=0,Rickshaw_amount=0;
// Main Function
void main(){
    SMenu();
    LMenu();
    algoritm();
     while(1<2){
            
        switch(menu()){
            case '1':
                    bike();
                    file();
                    break;
            case '2':
                    car();
                    file();
                    break;
            case '3':
                    rickshaw();
                    file();
                    break;
            case '4':
                    cycle();
                    file();
                    break;
            case '5':
                    bus();
                    file();
                    break;
            case '6':
                    show_Detail();
                    break;
            case '7':
                    amount();
                    break;
            case '8':
                    delete();
                    break;
            case '9':
                    exit(0);        
            default :
                    printf("\nInvalid Input\n\n");
                        
        } 
                  
    }

}




// Start Screen of console
void SMenu(){
    char ch;
    printf("*****WELCOME*****");
    printf("\n\n\n\n");
    printf("   Press ENTER\n");
    scanf("%c",&ch);
}



// Second Display function
void LMenu(){
    printf("------Enter the Details------\n");
    printf("\t\tDate Format : (25/05/2004)\n\n\n");
    printf("Enter the day : ");
    gets(day);
    printf("Enter the date : ");
    gets(date);
}



// This Function hold Basic input option to execute or perform task
char menu(){
    char ch;
    printf("\nPress 1. For add Bike\n");
    printf("Press 2. For add Car\n");
    printf("Press 3. For add Rickshaw\n");
    printf("Press 4. For add Cycle\n");
    printf("Press 5. For add Bus\n");
    printf("Press 6. For Parking Detail\n");
    printf("Press 7. For Amount Detail\n");
    printf("Press 8. For Delete Record\n");
    printf("Press 9. For EXIT\n");
    printf("Enter Your Choice : ");
    scanf("%c",&ch);
    return ch;
}





//Parking vechile detail show on screen
void show_Detail(){
    char ch,c;
    printf("\n\nNumber of BIKE parked       : %d\n",Car);
    printf("Number of CAR parked        : %d\n",Bike);
    printf("Number of RICKSHAW parked   : %d\n",Rickshaw);
    printf("Number of CYCLE parked      : %d\n",Cycle);
    printf("Number of BUS parked        : %d\n",Bus);
    printf("  Total Vechile parked   =   %d\n\n\n",Total_vechile);
    scanf("%c",&ch);
    scanf("%c",&c);
}





// Amount detail show in screen
void amount(){
    printf("\n\nBike Amount        :    %d\n",Bike_amount);
    printf("Car Amount         :    %d\n",Car_amount);
    printf("Rickshaw Amount    :    %d\n",Rickshaw_amount);
    printf("Cycle Amount       :    %d\n",Cycle_amount);
    printf("Bus Amount         :    %d\n",Bus_amount);
    printf("  Total amount   =   %d\n\n\n",Total_amount);
    char ch,c;
    scanf("%c",&ch);
    scanf("%c",&c);
}




// Reverse Function
void reverse(){
    int length = 0;
    int i=0;
    while(st[i]!='\0'){
        length++;
        i++;
    }
    for(int i=0,j=length-1;i<=j;i++,j--){
        char temp = st[i];
        st[i] = st[j];
        st[j] = temp;
    }
}




// File name conversion function
/*
    This function convert a file name according to the given data--> Day & Date
    eg:- Day = Tuesday
         Date = 01/01/2024

         File name is --> 01Tuesday01
*/
void algoritm(){
    strncpy(st,date,5);
    st[5] = '\0';
    reverse();
    char rev[3];
    strncpy(rev,st,2);
    rev[2] = '\0';
    strcpy(st,rev);
    reverse();
    //Make a file name
    strncpy(fil,date,2);
    fil[2] = '\0';
    strcat(fil,day);
    strcat(fil,st);
    strcat(fil,".txt");
}





// This function print record in the file
void file(){
    FILE *fp;
    fp = fopen(fil,"w");
    fprintf(fp,"Day : %s\nDate : %s\n\n\n",day,date);
    //VECHILE DETAILS
    fprintf(fp,"Vechile Detail ---->\n");
    fprintf(fp,"Number of Car parked         :   %d\n",Car);
    fprintf(fp,"Number of Bike parked        :   %d\n",Bike);
    fprintf(fp,"Number of Rickshaw parked    :   %d\n",Rickshaw);
    fprintf(fp,"Number of Cycle parked       :   %d\n",Cycle);
    fprintf(fp,"Number of Bus parked         :   %d\n",Bus);
    fprintf(fp,"Total Vechile parked   =   %d\n\n\n",Total_vechile);
    //AMOUNT DEATAILS
    fprintf(fp,"Amount Detail ---->\n");
    fprintf(fp,"Bike Amount        :   %d\n",Bike_amount);
    fprintf(fp,"Car Amount         :   %d\n",Car_amount);
    fprintf(fp,"Rickshaw Amount    :   %d\n",Rickshaw_amount);
    fprintf(fp,"Cycle Amount       :   %d\n",Cycle_amount);
    fprintf(fp,"Bus Amount         :   %d\n",Bus_amount);
    fprintf(fp,"Total amount   =   %d",Total_amount);
    fclose(fp);
}




// This Function delete all record
void delete(){
    Bus=0;
    Bike=0;
    Car=0;
    Rickshaw=0;
    Cycle=0;
    Bus_amount=0;
    Bike_amount=0;
    Car_amount=0;
    Cycle_amount=0;
    Rickshaw_amount=0;
    Total_amount=0;
    Total_vechile=0;
    int x;
    printf("\n\nYou Want to Delete data from Record then--\n\n");
    printf("Press 1. To Delete Data From File\n");
    printf("Press 2. To continue\n");
    printf("Enter Your Choice : ");
    scanf("%d",&x);
    if(x==1){
        file();
    }
    char ch;
    scanf("%c",&ch);
}




void bus(){
    Bus++;
    Total_vechile++;
    Total_amount+=100;
    Bus_amount+=100;
    char ch;
    scanf("%c",&ch);

}



void car(){
    Car++;
    Total_vechile++;
    Total_amount+=80;
    Car_amount+=80;
    char ch;
    scanf("%c",&ch);
}



void bike(){
    Bike++;
    Total_vechile++;
    Total_amount+=30;
    Bike_amount+=30;
    char ch;
    scanf("%c",&ch);
}



void rickshaw(){
    Rickshaw++;
    Total_vechile++;
    Total_amount+=50;
    Rickshaw_amount+=50;
    char ch;
    scanf("%c",&ch);
}



void cycle(){
    Cycle++;
    Total_vechile++;
    Total_amount+=10;
    Cycle_amount+=10;
    char ch;
    scanf("%c",&ch);
}