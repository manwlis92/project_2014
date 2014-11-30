#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "hex.h"
#include "one_bit.h"
#include "two_bit.h"
#include "correlating.h"
#include "tournament.h"
#include "yehpad.h"

int main()
{  

   
   FILE *input_file; FILE *outp1; FILE *outp2; FILE *outp3; FILE *outp4; FILE *outp5; FILE *outp6; FILE *outp7;
   
   char filename[20]; double h;  int ch = 0; char address[9]; int row=0; double line_counter = 0; int out = 0; int x = 0;  int int_address = 0; int prevadd=0;
   int A = 0; int B = 0;  int inner_enable = 0; int counterA =1;  int counterB=1; int enableA = 1; int enableB = 1; int last =0;
    int i=0;  int ready=0; char A_hex[9]; char B_hex[9]; double hits1B = 0;   double hits2B = 0; double hitsCB = 0; double hitsT = 0; double hitsY = 0; long int branch=0; int counter = 0;
    int pred[32]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; //yeahpad 1 =  T´ 2 =T 3 = NT´ 4 = NT
    int yeh = 00000;
   printf("Dose to onoma tou arxeiou gia eisodo: ");  
   scanf( "%s" ,filename); 
 
   input_file = fopen(filename,"r");  	if (!input_file) { printf("File name does not exists "); return 0; }
   
                                      outp1 = fopen("1_BIT_PRED_TABLE.txt","w");  
                                      outp2 = fopen("PRED_RESULTS.txt","w");  
                                      outp3 = fopen("2_BIT_PRED_TABLE.txt","w"); 
									  outp4 = fopen("branch_counter.txt","w"); 
									  outp5 = fopen("CORR_PRED_TABLE.txt","w");
									  outp6 = fopen("Tournament_TABLE.txt","w");
									  outp7 = fopen("YeahPad_TABLE.txt","w");
									  
    fprintf(outp1,"1-bit branch predictor table\n\n"); 
	fprintf(outp1,"          Act |Pred \n");                                 
   
   fprintf(outp3,"2-bit branch predictor table\n\n"); 
	fprintf(outp3,"          Act |Pred \n");  
	
	fprintf(outp5,"correlating branch predictor table\n\n"); 
	fprintf(outp5,"          Act |Pred \n");  

	fprintf(outp6,"Tourmanent table\n\n"); 
	fprintf(outp6,"          Act |Pred SELECT\n"); 
		
	fprintf(outp7,"YeahPad branch predictor table\n\n"); 
	fprintf(outp7,"          Act |Pred \n");   
	
	printf("\n\nPLEASE WAIT..\n");

	while (( ch = fgetc(input_file)) != EOF) /*eisagogi lekseon ston disdiastato pinaka */
   {  
              address[row] = ch;   
			  row++;                         
              if (row > 9) { printf("\nERROR!! CHECK YOUR INPUT FILE IN LINE: %0.f !!\n\n", ++line_counter); printf("write something and prees Enter to exit: "); scanf( "%i",out);exit(-1);}
     
      
        if (ch == '\n' ) //etimi i dieu8insi
               {              
			    line_counter++;    
			                                   
	            if (row < 8 ) { printf("\nERROR!! CHECK YOUR INPUT FILE IN LINE: %0.f !!\n\n", line_counter);printf("write something and prees Enter to exit: "); scanf( "%i" ,out); exit(-1);}
			             row=0;     
			                                                               
			                   			     
                               int_address = hex_decimal(address);   
				
              if(int_address == -1) {printf("\nERROR!! CHECK YOUR INPUT FILE IN LINE: %0.f !!\n\n", line_counter);printf("write something and prees Enter to exit: "); scanf( "%i" ,out);exit(-1);} //an den iparxi lan8asmeni dieu8insi
			      
		       
			   
			       	
			                if ( enableA == 1)  { A = int_address;  for (x=0;x<=7;x++)  A_hex[x] = address[x];  enableA = 0; }
			             else
			                 if ( enableB == 1 && int_address != A)   { B = int_address; for (x=0;x<=7;x++)  B_hex[x] = address[x]; enableB =0; inner_enable=1;}
			             else 
			                 if ( A == int_address)  { ++counterA; enableB = 0;  }
			             else
			                 if ( B == int_address)  { ++counterB;  }
			             else 
						     if (int_address > A )   {	ready = 1;   one_bid(&hits1B,A_hex,B_hex,counterA, counterB, inner_enable, outp1);
						                                             two_bid(&hits2B,A_hex,B_hex,counterA, counterB, inner_enable, outp3);
						                                             corr(&hitsCB,A_hex,B_hex,counterA, counterB, inner_enable, outp5);
						                                             tournament(&hitsT,A_hex,B_hex,counterA, counterB, inner_enable, outp6, &counter);
						                                             yehpad(&hitsY,A_hex,B_hex,counterA, counterB, inner_enable, outp7, pred, &yeh);
			                  		                       branch++;
			                  		                       if (inner_enable ==1)
			                  		                       {
			                  		                       	  for (x=0;x<=7;x++)   fprintf(outp4,"%c",A_hex[x]); 	fprintf(outp4," BRANCH %i : %i times\n",branch,counterA); branch++;
			                  		                       	 for (x=0;x<=7;x++)   fprintf(outp4,"%c",B_hex[x]); fprintf(outp4," BRANCH %i : %i times\n",branch,counterB); 
			                  		                       }
			                  		                    else
			                  		                       {
			                  		                       	 for (x=0;x<=7;x++)   fprintf(outp4,"%c",A_hex[x]); fprintf(outp4," BRANCH %i : %i times\n",branch,counterA);
			                  		                       }
			                  		                       
									                     A = int_address; enableB=1; inner_enable=0; counterA=1; counterB=1; ready=0;
									                     for (x=0;x<=7;x++)  A_hex[x] = address[x]; 
									                           
												     }
			     
		 }
                
   } 

             for (x=0;x<=7;x++)  A_hex[x] = address[x]; 
			 one_bid(&hits1B,A_hex,B_hex,counterA, counterB, inner_enable, outp1);  
			 two_bid(&hits2B,A_hex,B_hex,counterA, counterB, inner_enable, outp3);  
			 corr(&hitsCB,A_hex,B_hex,counterA, counterB, inner_enable, outp5);
			 tournament(&hitsT,A_hex,B_hex,counterA, counterB, inner_enable, outp6, &counter);
			 yehpad(&hitsY,A_hex,B_hex,counterA, counterB, inner_enable, outp7, pred, &yeh);
			                                     branch++;
			                                      if (inner_enable ==1)
			                  		                       {
			                  		                       	    for (x=0;x<=7;x++)   fprintf(outp4,"%c",A_hex[x]); 	
															    fprintf(outp4," BRANCH %i : %i times\n",branch,counterA); branch++;
															    
			                  		                       	    for (x=0;x<=7;x++)   fprintf(outp4,"%c",B_hex[x]);
															    fprintf(outp4," BRANCH %i : %i times\n",branch,counterB); 
			                  		                       }
			                  		                    else
			                  		                       {
			                  		                       	    for (x=0;x<=7;x++)   fprintf(outp4,"%c",A_hex[x]);
															    fprintf(outp4," BRANCH %i : %i times\n",branch,counterA);
			                  		                       }
			                  		                       
									                     A = int_address; enableB=1; inner_enable=0; counterA=1; counterB=1; ready=0;
									                     for (x=0;x<=7;x++)  A_hex[x] = address[x]; 
									                     
			 
fprintf(outp2,"1-b_predictor:\n"); 			  			       
fprintf(outp2,"              SUCCESS: %.0f/%.0f = %.2f %%\n",hits1B,line_counter,100*hits1B/line_counter); 
fprintf(outp2,"                 FAIL: %.0f/%.0f = %.2f %%\n\n",(line_counter-hits1B),line_counter,100-100*hits1B/line_counter);

fprintf(outp2,"2-b_predictor:\n"); 			  			       
fprintf(outp2,"              SUCCESS: %.0f/%.0f = %.2f %%\n",hits2B,line_counter,100*hits2B/line_counter);
fprintf(outp2,"                 FAIL: %.0f/%.0f = %.2f %%\n\n",(line_counter-hits2B),line_counter,100-100*hits2B/line_counter);

fprintf(outp2,"CORR-b_predictor:\n"); 			  			       
fprintf(outp2,"              SUCCESS: %.0f/%.0f = %.2f %%\n",hitsCB,line_counter,100*hitsCB/line_counter);
fprintf(outp2,"                 FAIL: %.0f/%.0f = %.2f %%\n",(line_counter-hitsCB),line_counter,100-100*hitsCB/line_counter);

fprintf(outp2,"Tourn_predictor:\n"); 			         
fprintf(outp2,"              SUCCESS: %.0f/%.0f = %.2f %%\n",hitsT,line_counter,100*hitsT/line_counter);
fprintf(outp2,"                 FAIL: %.0f/%.0f = %.2f %%\n",(line_counter-hitsT),line_counter,100-100*hitsT/line_counter); 

fprintf(outp2,"YeahPad_predictor:\n"); 			         
fprintf(outp2,"              SUCCESS: %.0f/%.0f = %.2f %%\n",hitsY,line_counter,100*hitsY/line_counter);
fprintf(outp2,"                 FAIL: %.0f/%.0f = %.2f %%\n",(line_counter-hitsY),line_counter,100-100*hitsY/line_counter); 

fclose(input_file); fclose(outp1); fclose(outp2); fclose(outp3); fclose(outp4); fclose(outp5); fclose(outp6);fclose(outp7);
printf("process finished!\n\n");
system("PAUSE");
   
}
  
 