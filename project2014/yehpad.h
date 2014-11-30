#include<stdio.h>


void yehpad(double *hits,char a_hex[],char b_hex[],int counterA, int counterB, int inner_enable, FILE *p,int pred[],int *yeh)
{    int x=0; int i=0;  int z = 0; 
     int out_state=1; int inner_state=1; //reset  
     int array[32] = {00000,00001,00010,00011,00100,00101,00110,00111,01000,01001,01010,01011,01100,01101,01110,01111,10000,10001,10010,10011,10100,10101,10110,10111,11000,11001,11010,11011,11100,11101,11110,11111};              
int w=0; int h=0; int u = 0;

for (w=0;w<32;w++) {
	                  for (h=0;h<32;h++)
	                  {
	                  	if (array[w] == pred[h]);
	                  	u = w;
	                  }
	
                   }
  
	if (inner_enable == 1)
			       	       {   
			       	       	   for (x=1; x < counterA;x++)
			       	       	   {
			       	       	   	  for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]); 
			       	       	   	  fprintf(p," |  T |");  if (pred[u] == 1) {  fprintf(p,"  T |\n"); (*hits)++;} 
										                   else 
			       	       	   	                         if (pred[u] == 2) {  fprintf(p,"  T |\n"); (*hits)++; pred[u] =1;} 
			       	       	   	                            else
			       	       	   	                          if (pred[u] == 3) {  fprintf(p," NT |\n"); pred[u]=4;} 
			       	       	   	                             else
			       	       	   	                          if (pred[u] == 4) {  fprintf(p," NT |\n"); pred[u]=1;} 
			       	       	   	 
			       	       	   	       for (i = 1; i < counterB/(counterA -1 );i++)
			       	       	   	            {   
											     fprintf(p," "); for (z=0;z<=7;z++)   fprintf(p,"%c",b_hex[z]); 	
											     fprintf(p,"|  T |");  
											 
											       if (inner_state == 1) {  fprintf(p,"  T |\n");  (*hits)++;} 
												       else 
													if (inner_state == 2) {  fprintf(p,"  T |\n");  (*hits)++; inner_state=1;}   
													  else
			       	       	   	                     if (inner_state == 3) {  fprintf(p," NT |\n"); inner_state=4;} 
			       	       	   	                      else
			       	       	   	                     if (inner_state == 4) {  fprintf(p," NT |\n");inner_state=1;}       
											 }
									  fprintf(p," ");	for (z=0;z<=7;z++)   fprintf(p,"%c",b_hex[z]); 	 
			       	       	   	      fprintf(p,"| NT |");   if (inner_state == 1) {  fprintf(p,"  T |\n"); inner_state = 2;} 
											                   else 	
			       	       	   	                              if (inner_state == 2) {  fprintf(p,"  T |\n"); inner_state = 3;} 
			       	       	   	                                else
											                   if (inner_state == 3) {  fprintf(p," NT |\n");(*hits)++;} 
											                     else
											                    if (inner_state == 4) {  fprintf(p," NT |\n"); (*hits)++; inner_state=3;} 
											                
			       	       	   }
			       	       	      
			       	       }
			       	      else
			       	          { 
								 for (x=1; x < counterA; x++)
			       	       	   {
			       	       	   	   for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]); 
			       	       	   	  fprintf(p," |  T |");  if (pred[u] == 1) {  fprintf(p,"  T |\n"); (*hits)++;} 
										                   else 
			       	       	   	                         if (pred[u] == 2) {  fprintf(p,"  T |\n"); (*hits)++; pred[u] =1;} 
			       	       	   	                            else
			       	       	   	                          if (pred[u] == 3) {  fprintf(p," NT |\n"); pred[u]=4;} 
			       	       	   	                             else
			       	       	   	                          if (pred[u] == 4) {  fprintf(p," NT |\n"); pred[u]=1;} 			       	       	   	 
			       	           } 
			       	            
			       	          }
			       	    for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]);			
			       	   fprintf(p," | NT |");                 if (pred[u] == 1) {  fprintf(p,"  T |\n"); pred[u] = 2;} 
											                   else 	
			       	       	   	                              if (pred[u] == 2) {  fprintf(p,"  T |\n"); pred[u] = 3;} 
			       	       	   	                                else
											                   if (pred[u] == 3) {  fprintf(p," NT |\n");(*hits)++;} 
											                     else
											                    if (pred[u] == 4) {  fprintf(p," NT |\n"); (*hits)++; pred[u]=3;} 	
			               	
			       
}
