/*
* Author: Thomas Wilson
* Program: The Corner Store Simulator
* Purpose: This program lets the user add a variety of foods with different prices and amounts to there shopping cart. Then
           it calculates the total amount of money the user spent when they exit.
* Reflection: The hardest part for me was trying to account for all the edge cases like what happens if the user
               enters a number below zero for a quantity of goods or picks a number that isn't an option.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>


float prices[4] = {2.50, 1.20, 3.00, 2.00};
char productName[20] = {};


void displayPrices()
{
   printf("Welcome to the Simple Shopping System! \n");
   printf("1.Apples - %.2f$ each  2.Bananas - %.2f$ each \n",prices[0],prices[1]);
   printf("3. Carrots - %.2f$ each 4. Oranges - %.2f$ each 5. Exit \n",prices[2],prices[3]);
   printf("\n");
}

void getProductName(int option)
{
   switch(option)
   {
      case 1:
      strcpy(productName,"Apples");
      break;

      case 2:
      strcpy(productName, "Bananas");
      break;

      case 3:
      strcpy(productName, "Carrots");
      break;

      case 4:
      strcpy(productName, "Oranges");
      break;

      default:
      strcpy(productName, "Invalid product");
      break;
   }

 

     
}

void main()
{
   float userOption = 0;
   int exitOption = 5;
   float numPurchased = 0;
   double total = 0;
   
   displayPrices();

   printf("Enter the number of the product you want to buy (1-5): ");
   
  
 
   
   while((scanf(" %f", &userOption) == 0) || (userOption > 5 || userOption < 1) || userOption != (int)userOption)
   {
      printf("invalid option please keep numbers (1-5) \n");
      printf("Enter the number of product you want to buy (1-5): ");
      
      while (getchar() != '\n'); 
      
   }

   
   while(userOption != exitOption)
   {
     printf("enter the quanity: ");
    
     

     while((scanf(" %f", &numPurchased) == 0) || numPurchased < 1 || numPurchased != (int)numPurchased)
     {
      printf("not valid amount try again \n");
      printf("enter the quantity: ");
      
      while (getchar() != '\n'); 
     }

     total += (numPurchased * prices[(int)userOption - 1]);
     getProductName(userOption);
     printf("Added %d %s to your cart. Total so far: $%.2lf \n", (int)numPurchased, productName, total);
     printf("\n");
     
     printf("Enter the number of product you want to buy (1-5) 2: ");
      
   
     
     
     while((scanf(" %f", &userOption) == 0) || (userOption > 5 || userOption < 1) || userOption != (int)userOption)
     {
      printf("invalid option please keep numbers (1-5) \n");
      printf("Enter the number of product you want to buy (1-5): ");
      
      while (getchar() != '\n'); 
      
     }
     

     if(userOption == exitOption)
     {
      printf("Thank you for shopping with us \n");

      if(total > 100)
      {
         total = total - (total * (0.1));
         printf("A 10%% discount has been applied! \n");
         
      }
      printf("Your final total is %.2lf$", total);
      printf("\n");
     }
     
    
   }
  
}


