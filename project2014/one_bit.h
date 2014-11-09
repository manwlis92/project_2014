#include<stdio.h>




void one_bid(double *hits,char a_hex[],char b_hex[],int counterA, int counterB, int inner_enable, FILE *p)
{    int x=0; int i=0;  int z = 0; int sum=0;
     int out_state=1; int inner_state=1; //reset 

  
	if (inner_enable == 1)
			       	       {   
			       	       	   for (x=1; x < counterA;x++)
			       	       	   {
			       	       	   	  for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]); 
			       	       	   	  fprintf(p," |  T |");  if (out_state == 1) {  fprintf(p,"  T |\n"); (*hits)++;}
										                  else 
														    {	fprintf(p," NT |\n");	out_state = 1;  }
			       	       	   	  
			       	       	   	 
			       	       	   	        for (i = 1; i < counterB/(counterA-1);i++)
			       	       	   	            {   
											     fprintf(p," "); for (z=0;z<=7;z++)   fprintf(p,"%c",b_hex[z]); 	
											 fprintf(p,"|  T |");  if (inner_state == 1) {  fprintf(p,"  T |\n");  (*hits)++;}
											                              else 
																		  {	fprintf(p," NT |\n");	inner_state = 1;  }	      
											 }
									 fprintf(p," ");	for (z=0;z<=7;z++)   fprintf(p,"%c",b_hex[z]); 	 
									 
			       	       	   	  fprintf(p,"| NT |");   if (inner_state == 1) {  fprintf(p,"  T |\n"); inner_state = 0;} else {	fprintf(p," NT |\n");	 (*hits)++;  }	
			       	       	   	      
			       	       	   }
			       	       	      
			       	       }
			       	      else
			       	          { 
								 for (x=1; x < counterA; x++)
			       	       	   {
			       	       	   	   for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]); 
			       	       	   	  fprintf(p," |  T |");  if (out_state == 1) {  fprintf(p,"  T |\n"); (*hits)++; } else {	fprintf(p," NT |\n");	out_state = 1 ; }
			       	       	   	 
			       	           } 
			       	            
			       	          }
			       	    for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]);			
			       	   fprintf(p," | NT |"); if (out_state == 1) {  fprintf(p,"  T |\n"); out_state = 0;} else {	fprintf(p," NT |\n");	 (*hits)++;  }	
			               	
		  
}

