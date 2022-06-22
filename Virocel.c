#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// FOR DECLARATION

void ClearSc() {
	system("cls");
}

void OpeningScreen(){
	printf("Welcome!");
	printf("  \nClick any button to continue >");
	scanf("%*c");
}

void DisplayStats(float Money, int CarHealth, int Carcount){
	
	printf("\nYou currently have:\n");
	printf("Your Money: %.2f\n", Money);
	printf("CarHealth: %d\n", CarHealth);
	printf("Carcount: %d\n", Carcount);
	
}

void RepairParts(float Money, int CarHealth, int Carcount) {
	int Choice;
	
	
	printf("----------------------------------------------------------------\n");
	printf("                       REPAIR SHOP                            \n");
	printf("----------------------------------------------------------------\n");
	printf("           WHICH ITEM DO YOU WANT TO REPAIR?                   \n");
	printf("-----------------------------------------------------------------\n");
	Items(); // CALL OF FUCNTION DISPLAYING ITEMS
	scanf("%d", &Choice);

	while (Choice >= 4 || Choice <= 0) { //VALIDATION OF ITEM
		printf("Invalid item! Pick another item: ");
		scanf("%d", &Choice);
	}
	
	switch(Choice){
		case 1: 
		        ClearSc(); 
		        Money = Money - 40000;
		        CarHealth = CarHealth + 15;
		        DisplayStats(Money, CarHealth, Carcount);
		        break;
		        
		case 2: ClearSc();
				Money = Money - 10000;
		        CarHealth = CarHealth + 10;
		        DisplayStats(Money, CarHealth, Carcount);
		        break;
		        
	    case 3: ClearSc();
	    		Money = Money - 5000;
		        CarHealth = CarHealth + 5;
		        DisplayStats(Money, CarHealth, Carcount);
		        break;
	}
	
	
}

void Items() {
	
	printf("  ITEMS                      PRICE                    ADDED HEALTH TO CAR\n");
	printf("[1] Engine                   40,000                          15% \n");
	printf("[2] Wheels                   10,000                          10% \n");
	printf("[3] Bumper                   5,000                            5% \n");

	
}

char HomeMenu(float Money, int CarHealth, int Carcount){
	
	char Choice;
	printf("----------------------------------------------------------------\n");
	printf("                         HOME MENU\n");
	printf("----------------------------------------------------------------\n");
	printf("ITEM     WARES AND GOODS     SELLING/BUYING PRICE        STORAGE\n");
	printf("----------------------------------------------------------------\n");
	printf("\n[R]epair Parts [S]ell Car [G]o to Bank [Q]uit\n");
	
	printf("  \nClick any button to continue >");
	scanf(" %c", &Choice);
	Choice = tolower(Choice);
	
	switch(Choice){
		case 'r': ClearSc(); RepairParts(Money, CarHealth, Carcount); 
	}
	
}


int CarDealer(int Carcount, float Money, int CarHealth){
	int Choice;
	
	printf("I'm assuming you don't have a car to restore yet! Here's a capital of 250,000 to get you started\n");

	printf("Welcome to the Car Dealer, here you can choose from 3 different cars to buy,");
	printf("\n\nCAR       PRICE    HEALTH\n"); 
	printf("\n[1]Car 1  180,000      60%\n"); 
	printf("\n[2]Car 2  160,000      65%\n");
	printf("\n[3]Car 3  200,000      80%\n"); 
	printf("BUY >");
	scanf("%d", &Choice);
	Carcount = 1;
	ClearSc(); 

	switch(Choice){
		case 1: 
	
			Money = Money - 180000; 
			CarHealth = 60;
			ClearSc(); 
			DisplayStats(Money, CarHealth, Carcount);
			do{
				HomeMenu(Money, CarHealth, Carcount);
			}while(Money > 0);
		    break;
			
	
		case 2:

			Money = Money - 160000; 
			CarHealth = 65;
			ClearSc(); 
			DisplayStats(Money, CarHealth, Carcount);
			HomeMenu(Money, CarHealth, Carcount);	
 			break;
		
		case 3: 
	
			Money = Money - 200000; 
			CarHealth = 80;
			ClearSc(); 
			DisplayStats(Money, CarHealth, Carcount);  
			HomeMenu(Money, CarHealth, Carcount);	
		    break;
		
		default: printf("mwa");
	}


}



int main(){
	
	// FOR DELCARATION
	float Money = 250000;
	int CarHealth = 100;
	int Carcount = 0;
	int Days = 1;
	
	OpeningScreen();
	ClearSc();
	
	if(Carcount == 0){
				CarDealer(Carcount, Money, CarHealth);	
				
 			}   

	
}
