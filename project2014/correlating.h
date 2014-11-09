#include<stdio.h>




void corr(double *hits,char a_hex[],char b_hex[],int counterA, int counterB, int inner_enable, FILE *p)
{    int x=0; int i=0;  int z = 0; int sum=0;
     int out_state=1; int inner_state=1; //reset 
     int pred1i = 1; int pred2i =1 ; int pred1o = 1; int pred2o = 1; int real =1;
  
	if (inner_enable == 1)
			       	       {   
			       	       	   for (x=1; x < counterA;x++)
			       	       	   {
			       	       	   	  for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]); 
			       	       	   	  
			       	       	   	  fprintf(p," |  T |");   if (pred1o == 1) { (*hits)++; fprintf(p,"  T |"); fprintf(p," T / T\n");   }
			       	       	   	                         else
			       	       	   	                           if (pred1o == 0) { fprintf(p," NT |"); pred1o = 1;  fprintf(p," T / T\n"); }
			       	       	   	 
			       	       	   	        for (i = 1; i < counterB/(counterA-1);i++)
			       	       	   	            {   
											     fprintf(p," "); for (z=0;z<=7;z++)   fprintf(p,"%c",b_hex[z]); 	
											     
											 fprintf(p,"|  T |");  
											                          if (pred1i == 1) { (*hits)++; fprintf(p,"  T |");   fprintf(p,"   T / T\n"); }
			       	       	   	                                    else
			       	       	   	                                       if (pred1i == 0) { fprintf(p," NT |"); pred1i = 1;   fprintf(p,"   T / T\n"); }
											 
											       
											 }
									 fprintf(p," ");	for (z=0;z<=7;z++)   fprintf(p,"%c",b_hex[z]); 	 
									 
			       	       	   	  fprintf(p,"| NT |");  
			       	       	   	                                       if (pred1i == 0) { (*hits)++; fprintf(p," NT |");   fprintf(p,"   NT/ T\n");  }
			       	       	   	                                        else
			       	       	   	                                       if (pred1i == 1) { fprintf(p,"  T |"); pred1i = 0;    fprintf(p,"   NT/ T\n");}
			       	       	   	      
			       	       	   }
			       	       	   for (z=0;z<=7;z++)   fprintf(p,"%c",a_hex[z]);			
			       	   fprintf(p," | NT |"); 
			       	                                                    if (pred2o == 0) { (*hits)++; fprintf(p," NT |");   fprintf(p," T / NT\n"); }
			       	       	   	                                        else
			       	       	   	                                       if (pred2o == 1) { fprintf(p,"  T |"); pred2o = 0;  fprintf(p," T / NT\n"); }
			       	       	      
			       	       }
			       	      else
			       	          { 
								 for (x=1; x < counterA; x++)
			       	       	   {
			       	       	   	   
			       	       	   	   if (out_state == 1) {   (*hits)++; } else {		out_state = 1 ; }
			       	       	   	 
			       	           } 
			       	            
			       	          }
			       	     
			               	
		  
}

