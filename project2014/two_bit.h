#include<stdio.h>


void two_bid(double *hits,char a_hex[],char b_hex[],int counterA, int counterB, int inner_enable, FILE *p)
{    int x=0; int i=0;  int z = 0; 
     int out_state=1; int inner_state=1; //reset 

  
	if (inner_enable == 1)
			       	       {   
			       	       	   for (x=1; x < counterA;x++)
			       	       	   {
			       	       	   	  for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]); 
			       	       	   	  fprintf(p," |  T |");  if (out_state == 1) {  fprintf(p,"  T |\n"); (*hits)++;} 
										                   else 
			       	       	   	                         if (out_state == 2) {  fprintf(p,"  T |\n"); (*hits)++; out_state =1;} 
			       	       	   	                            else
			       	       	   	                          if (out_state == 3) {  fprintf(p," NT |\n"); out_state=4;} 
			       	       	   	                             else
			       	       	   	                          if (out_state == 4) {  fprintf(p," NT |\n"); out_state=1;} 
			       	       	   	 
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
			       	       	   	  fprintf(p," |  T |");  if (out_state == 1) {  fprintf(p,"  T |\n"); (*hits)++;} 
										                   else 
			       	       	   	                         if (out_state == 2) {  fprintf(p,"  T |\n"); (*hits)++; out_state =1;} 
			       	       	   	                            else
			       	       	   	                          if (out_state == 3) {  fprintf(p," NT |\n"); out_state=4;} 
			       	       	   	                             else
			       	       	   	                          if (out_state == 4) {  fprintf(p," NT |\n"); out_state=1;} 			       	       	   	 
			       	           } 
			       	            
			       	          }
			       	    for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]);			
			       	   fprintf(p," | NT |");                 if (out_state == 1) {  fprintf(p,"  T |\n"); out_state = 2;} 
											                   else 	
			       	       	   	                              if (out_state == 2) {  fprintf(p,"  T |\n"); out_state = 3;} 
			       	       	   	                                else
											                   if (out_state == 3) {  fprintf(p," NT |\n");(*hits)++;} 
											                     else
											                    if (out_state == 4) {  fprintf(p," NT |\n"); (*hits)++; out_state=3;} 	
			               	
			       
}

