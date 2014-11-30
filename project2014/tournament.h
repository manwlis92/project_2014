#include<stdio.h>




void tournament(double *hits,char a_hex[],char b_hex[],int counterA, int counterB, int inner_enable, FILE *p, int *counter)
{    int x=0; int i=0;  int z = 0; int sum=0;
     int out_state=1; int inner_state=1; //reset 
     
     
     //printf("   %d" ,*counter);
     
     int pred1i = 1; int pred2i =1 ; int pred1o = 1; int pred2o = 1; int real =1;

  if (*counter == 0 || *counter == 1 )  // 1 - bit
  {
	if (inner_enable == 1)
			       	       {   
			       	       	   for (x=1; x < counterA;x++)
			       	       	   {                                                             
			       	       	   	  for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]); 
			       	       	   	  fprintf(p," |  T |");  if (out_state == 1) {  fprintf(p," 1-bit\n");  *counter = 0; (*hits)++;}
										                  else 
														    {	fprintf(p," 1-bit\n");	out_state = 1; (*counter)++; }
			       	       	   	  
			       	       	   	 
			       	       	   	        for (i = 1; i < counterB/(counterA-1);i++)
			       	       	   	            {   
											     fprintf(p," "); for (z=0;z<=7;z++)   fprintf(p,"%c",b_hex[z]); 	
											 fprintf(p,"|  T |");  if (inner_state == 1) {  fprintf(p," 1-bit\n");(*hits)++;    *counter = 0;}
											                              else 
																		  {	fprintf(p," 1-bit\n"); (*counter)++;	inner_state = 1;  }	      
											 }
									 fprintf(p," ");	for (z=0;z<=7;z++)   fprintf(p,"%c",b_hex[z]); 	 
									 
			       	       	   	  fprintf(p,"| NT |");   if (inner_state == 1) {  fprintf(p," 1-bit\n"); inner_state = 0;} else {	fprintf(p," 1-bit\n"); *counter = 0;	(*counter)++; (*hits)++;  }	
			       	       	   	      
			       	       	   }
			       	       	      
			       	       }
			       	      else
			       	          { 
								 for (x=1; x < counterA; x++)
			       	       	   {
			       	       	   	   for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]); 
			       	       	   	  fprintf(p," |  T |");  if (out_state == 1) {  fprintf(p," 1-bit\n"); *counter = 0; (*hits)++; } else {	fprintf(p," 1-bit\n");(*counter)++;	out_state = 1 ; }
			       	       	   	 
			       	           } 
			       	            
			       	          }
			       	    for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]);			
			       	   fprintf(p," | NT |"); if (out_state == 1) {  fprintf(p," 1-bit\n"); (*counter)++;out_state = 0;} else {	fprintf(p," 1-bit\n"); *counter = 0;	 (*hits)++;  
						  }	
			               	
		  

}
else if (*counter == 2 || *counter == 3)  // correlating
{  	
   	if (inner_enable == 1)
			       	       {   
			       	       	   for (x=1; x < counterA;x++)
			       	       	   {
			       	       	   	  for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]); 
			       	       	   	  
			       	       	   	  fprintf(p," |  T |");   if (pred1o == 1) { (*hits)++; fprintf(p," correlating\n"); *counter = 2;  }
			       	       	   	                         else
			       	       	   	                           if (pred1o == 0) { fprintf(p," correlating\n"); pred1o = 1; (*counter)++;  }
			       	       	   	 
			       	       	   	        for (i = 1; i < counterB/(counterA-1);i++)
			       	       	   	            {   
											     fprintf(p," "); for (z=0;z<=7;z++)   fprintf(p,"%c",b_hex[z]); 	
											     
											 fprintf(p,"|  T |");  
											                          if (pred1i == 1) { (*hits)++; fprintf(p," correlating\n"); *counter = 2;  }
			       	       	   	                                    else
			       	       	   	                                       if (pred1i == 0) { fprintf(p," correlating\n"); (*counter)++;pred1i = 1;   }
											 
											       
											 }
									 fprintf(p," ");	for (z=0;z<=7;z++)   fprintf(p,"%c",b_hex[z]); 	 
									 
			       	       	   	  fprintf(p,"| NT |");  
			       	       	   	                                       if (pred1i == 0) { (*hits)++; fprintf(p," correlating\n"); *counter = 2;   }
			       	       	   	                                        else
			       	       	   	                                       if (pred1i == 1) { fprintf(p," correlating\n");(*counter)++; pred1i = 0;   }
			       	       	   	      
			       	       	   }
			       	       	   for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]);			
			       	                fprintf(p," | NT |"); 
			       	                                                    if (pred2o == 0) { (*hits)++; fprintf(p," correlating\n"); *counter = 2;   }
			       	       	   	                                        else
			       	       	   	                                       if (pred2o == 1) { fprintf(p," correlating\n"); (*counter)++;pred2o = 0;   }
			       	       	      
			       	       }
			       	      else
			       	          { 
								 for (x=1; x < counterA; x++)
			       	       	   {
			       	       	   	   
			       	       	   	   if (out_state == 1) {   (*hits)++; } else {		out_state = 1 ; }
			       	       	   	 
			       	           } 
			       	            
			       	          }
			       	     
			               	
		  if (*counter >3) *counter = 0;

}

}