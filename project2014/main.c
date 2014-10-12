#include<stdio.h>
#include"string.h"
#include"math.h"
#include <stdlib.h>

 int hex_decimal(char hex[])   /* Metatropi hex se decimal */
 {               
     int x, sum=0; int i=7;
     
    for (x=0;x<=7;x++)
      {
     	   if (sum!=-1)
     	   {
     	       if (hex[x] == '0') sum= sum+0*pow(16,i);
     	         else
        	   if (hex[x] =='4') sum= sum+4*pow(16,i);
     	         else    
     	       if (hex[x] == 'A') sum= sum+10*pow(16,i);
     	         else 
     	       if (hex[x] == 'B') sum= sum+11*pow(16,i);
     	         else
     	       if (hex[x] =='C') sum= sum+12*pow(16,i);
     	  	     else     	    
     	       if (hex[x] =='D') sum= sum+13*pow(16,i);
     	         else
     	       if (hex[x] =='E') sum= sum+14*pow(16,i);
     	         else
     	       if (hex[x] =='F') sum= sum+15*pow(16,i);
     	         else     	    
     	       if (hex[x] =='1') sum= sum+1*pow(16,i);
     	         else
     	       if (hex[x] =='2') sum= sum+2*pow(16,i);
     	         else
     	       if (hex[x] =='3') sum= sum+3*pow(16,i);
     	         else     	    
     	       if (hex[x] =='5') sum= sum+5*pow(16,i);
     	         else
     	       if (hex[x] =='6') sum= sum+6*pow(16,i);
     	         else
     	       if (hex[x] =='7') sum= sum+7*pow(16,i);
     	         else
     	       if (hex[x] =='8') sum= sum+8*pow(16,i);
     	         else
     	       if (hex[x] =='9') sum= sum+9*pow(16,i);
     	         else
     	          sum = -1;
     	   }
	          i--; 
     }
    return sum;
 }
 

 
  int bp_1bit(FILE *input_file)
  {   
         FILE *outp1;   FILE *outp2; FILE *outp3; 
	     
	      int ch; int c = 0;
          int r=0; 
	      int k0 = 0; int k1=0; int k2=0; int k3=0; int k4=0;  
	      char address0[9]; char address1[9]; char address2[9]; char address3[9];
		  long int m=1; int pr=0; int y=0;
	 
	      long int sumbranches=0;   int wrongaddress=0; int tr=3; int cc=0;	
	     
          int loopinbr1=0;  int loopinbr2=0; int loopinbr3=0;  
          int success =0; int x=0; 
          int inner_enable =0; 
          int wrongadd=0;  int add1[9];int add2[9];int add3[9];
          int add[9]; // giana tiponno adrees dipla apo tin provle4i kai drasi
          int current_state = 1; int inner_state = 1; double sum=0;  
	      double hits= 0;
	      double q ; double line_counter=0; int sum_loop = 0; int out=0;
             
		           
	   outp1 = fopen("branches_loops_result.txt","w");   outp2 = fopen("1_bit_pred_table.txt","w"); outp3 = fopen("predictors_results.txt","w"); 
       
      
      fprintf(outp2,"1-bit branch predictor table\n\n");
      fprintf(outp2,"         Act|Pred \n");
      
      printf("1-bit branch predictor in progress..\n"); 
  	while (( ch = fgetc(input_file)) !=EOF) /*eisagogi lekseon ston  pinaka*/
  	
   {                              
              address0[r] = ch;   
			                    r++;   if (r > 9) { printf("\nERROR!! CHECK YOUR INPUT FILE IN LINE: %i !!\n\n", ++line_counter); printf("write something and prees Enter to exit: "); scanf( "%i",out);exit(-1);}
      
      if (ch == '\n' )
              {                line_counter++;   
			                                   if (r < 8 ) { printf("\nERROR!! CHECK YOUR INPUT FILE IN LINE: %i !!\n\n", line_counter);printf("write something and prees Enter to exit: "); scanf( "%i" ,out); exit(-1);}
			                    r=0;  
			                                                               
			                    for (x=0;x<=7;x++)   add[x]=address0[x];   for (x=0;x<=7;x++) address1[x]=address0[x]; 
				     
                                k1= hex_decimal(address0);    
				
              if(k1 == -1) {printf("\nERROR!! CHECK YOUR INPUT FILE IN LINE: %i !!\n\n", line_counter);printf("write something and prees Enter to exit: "); scanf( "%i" ,out);exit(-1);} //an den iparxi lan8asmeni dieu8insi
			      
		            if (k1 > k2 && k1>k3 &&k1 >k4) //eisodos neas dieu8insis
		             {      
		            	if (c==0) { k2 =k1; for (x=0;x<=7;x++)   add1[x]=address0[x]; }
		        	     else
		        	    if (c==1) {k3 =k1; for (x=0;x<=7;x++)   add2[x]=address0[x];}
		        	     else
		        	    if (c==2) {k4 =k1; for (x=0;x<=7;x++)   add3[x]=address0[x];}
		        	    
		             	c++; sumbranches++;  pr++;	             	 
		            			   
			         }
			     else if (k1==k2)  loopinbr1++;  // sinolo loops ka8e neou branch(neas address an i dieu8insi iparxi pio pano
			     else if (k1==k3 ) loopinbr2++; 
			     else if (k1==k4 ) loopinbr3++;
			  
			      
			  
			       if (pr==tr)
				   {                   
			            	if (c==1){	 
			         	               for (x=0;x<=7;x++)   fprintf(outp1,"%c", add2[x]);  
					                  fprintf(outp1," %io branch: %i loops\n",m,loopinbr2); loopinbr2=0; m++;pr=0;tr=1;current_state=1;	
								  				            
							         }
							     
				       else if (c==2){	 
				                         for (x=0;x<=7;x++)   fprintf(outp1,"%c", add3[x]);  
					                   fprintf(outp1," %io branch: %i loops\n",m,loopinbr3); loopinbr3=0;m++;pr=0;tr=1;current_state=1;
					             
							         }
							     
			   	       else if (c==3){
			   	   	                        for (x=0;x<=7;x++)   fprintf(outp1,"%c", add1[x]);  
					        	       fprintf(outp1," %io branch: %i loops\n",m,loopinbr1); loopinbr1=0;m++;pr=0;tr=1;current_state=1;
					        	 
							         }
			      } 
			       
			        if(k0!=0)  //den 8a ektelestei tin proti fora gt mono mia dieuthinsi tha exo tin proti fora, sto k1
				    {
				    	
			            if (k1-k0==8||k1-k0==4)  // inner loop
				        {
			       	        fprintf(outp2,"| T ");  sum_loop++;
							    
				        	        if (current_state == 1)  { 
									                           fprintf(outp2," | T |" );  hits++;
															 }
				                 	else{
				         		            fprintf(outp2," | T |"); current_state= 1;  hits++;
				         	            }
				         	            
				         	             fprintf(outp2,"\n        ----------\n");   fprintf(outp2,"         in_LOOP \n"); inner_enable =1; 
				         	                                                                 
				       }
					    else 
				         if(k0==k1)  //epomeni proigoueni idies
						 {
				         	fprintf(outp2,"| T "); sum_loop++;
							 if (inner_state ==0 && inner_enable ==1)  { fprintf(outp2," | NT |\n"); inner_state=1;	  
							 
							                                              if (k1==k2)         loopinbr1--;  
			                                                              else if (k1==k3 )   loopinbr2--;  
			                                                              else if (k1==k4 )   loopinbr3--;  			                                                                                                 
															           }
							 
							  else if (inner_state ==1 && inner_enable ==1){fprintf(outp2," | T |\n"); hits++; }
							  else
				         	      if (current_state == 1) {fprintf(outp2," | T |\n"); hits++; }
				         	   else{
				         		     fprintf(outp2," | NT |\n"); current_state= 1; 
				         	       }
				         }
				         else if  (k1-k0== -8||k1-k0== -4) //inner ends
				         {
				             fprintf(outp2,"| NT");
							 if (inner_state ==0 && inner_enable == 1)  {
							                                             fprintf(outp2," | NT |\n");	 	hits++;						                                                                                 
												                        }
							 else if (inner_state == 0) {fprintf(outp2," | NT |\n");  hits++; }
				         	  else  { 
				         	  
				         		      fprintf(outp2," | T |\n");   inner_state = 0; 		         		 
				         		   
				         	        }
				         	 fprintf(outp2,"\n        ----------\n");  fprintf(outp2,"         inner end \n"); inner_enable = 0; 
				         	                                                           
				         	                                                                     
						  }
				          else
				          {   
						      
						     fprintf(outp2,"| NT");  
				           	if (current_state == 0) {fprintf(outp2," | NT |\n"); hits++;}
				            else
						     	{
						     		 
						     		   
								     
						     		
				         		    fprintf(outp2," | T |\n"); current_state= 1;
									 fprintf(outp2,"        ----------\n");	fprintf(outp2,"        >>>>>>>>>\n"); //gt neo branch :)
				         	        inner_enable=0; inner_state=1;     
				         	                                                                   
								 }
						  }   
			      }
			      fprintf(outp2,"        ----------\n");     
			        k0=k1;  if (pr == 0) cc=c; if (c==3) c=0;  
			        
			       
		      for (x=0;x<=7;x++)   fprintf(outp2,"%c", add[x]); 
			   
		    }
                
   }                                             																
   
                    if (cc==0)
                    
					    {	for (x=0;x<=7;x++)   fprintf(outp1,"%c", add2[x]); 
						     fprintf(outp1," %io branch: %i loops\n",m,loopinbr2); m++;
						     for (x=0;x<=7;x++)   fprintf(outp1,"%c", add3[x]); 
					         fprintf(outp1," %io branch: %i loops\n",m,loopinbr3); 
					    }
					else
					 if (cc==1)
					    {	  for (x=0;x<=7;x++)   fprintf(outp1,"%c", add3[x]); 
						      fprintf(outp1," %io branch: %i loops\n",m,loopinbr3);m++;
						      for (x=0;x<=7;x++)   fprintf(outp1,"%c", add1[x]); 
					         fprintf(outp1," %io branch: %i loops\n",m,loopinbr1); 
					   }
					   else
					 if (cc==2){
					              for (x=0;x<=7;x++)   fprintf(outp1,"%c", add1[x]); 	
					              fprintf(outp1," %io branch: %i loops\n",m,loopinbr1); m++;
					              for (x=0;x<=7;x++)   fprintf(outp1,"%c", add2[x]); 
								  fprintf(outp1," %io branch: %i loops\n",m,loopinbr2); 
								}
					else			
					 if (cc==3){        for (x=0;x<=7;x++)   fprintf(outp1,"%c", add2[x]); 
					            	 fprintf(outp1," %io branch: %i loops\n",m,loopinbr2);m++;
					            	 for (x=0;x<=7;x++)   fprintf(outp1,"%c", add3[x]); 
					                fprintf(outp1," %io branch: %i loops\n",m,loopinbr3); 
					           }
					           
					       
						               
     fprintf(outp2,"| NT");  fprintf(outp2," |  T|\n"); fprintf(outp2,"--------------------------------\n");
      q = sumbranches; 
      fprintf(outp3,"1-bit branch predictor:\n");
     fprintf(outp3,"\n  SUCCESS: %.0f/%.0f = %4.2f %%\n",hits,line_counter,100*hits/line_counter); 
    fprintf(outp3,"  FAIL: %.0f/%.0f = %4.2f %%\n",(line_counter-hits),line_counter,100 - 100*hits/line_counter);
  
     fprintf(outp1,"----------------------------------------------\n\n");
     fprintf(outp1,"sum of branches: %i\n",sumbranches);
     fprintf(outp1,"sum of loops: %i\n",sum_loop);
 
     

      fclose(input_file); fclose(outp1); fclose(outp2); fclose(outp3);
    printf("1-bit branch predictor done!\n"); 
  	return sumbranches;
  }
  
    void bp_2bit(FILE *input_file2, int h)
  {   
      FILE *outp1; FILE *outp2;
	
     int r=0;
	 int k1=0; int y=0; int k2=0; int k3=0; int k4=0; int k0 = 0; int e=0; int m=1; int pr=0;
	 int ch; int c = 0;
	   long int sumbranches=0;  int wrongaddress=0;  int tr=3; int cc=0;
	 char address0[9];
        int lathoi=0; int loopinbr1=0;  int loopinbr2=0; int loopinbr3=0; int current_state = 1;  int inner_enable =0;
      int success =0; int x=0; int add[9]; 
      int inner_state=1; int wrongadd=0;    double hits =0; double line_counter=0;
      
	   outp1 = fopen("2_bit_pred_table.txt","w"); outp2 = fopen("predictors_results.txt","a"); 
       

      fprintf(outp1,"2-bit branch predictor table\n\n");
      fprintf(outp1,"         Act|Pred \n");
     
      printf("\n2-bit branch predictor in progress..\n"); 
  	while (( ch = fgetc(input_file2)) !=EOF) /*eisagogi lekseon ston disdiastato pinaka */
   {  
              address0[r] = ch;   
			  r++;  
      
      if (ch == '\n' )
                    {  line_counter++; 
                    
				      for (x=0;x<=7;x++)   add[x]=address0[x];
				      
			           r=0;  
                     k1= hex_decimal(address0);   
				           
                    //printf("%i\n",k1-k0);
                
				if (k1!=-1)
				{    
		        if (k1 > k2 && k1>k3 &&k1 >k4)
		          {
		        	if (c==0) k2 =k1;
		        	else
		        	if (c==1) k3 =k1;
		        	else
		        	if (c==2) k4 =k1;
		             	 c++;   pr++;
		             	 
		            			   
			       }
			     			  
			      
			   // printf("dfs %i\n",loopinbr1);
			     if (pr==tr)
				{
			    	if (c==1){	 
					             pr=0;tr=1;current_state=1;
					            
							 }
				else if (c==2){	 
					             pr=0;tr=1;current_state=1;
							 }
				else if (c==3){
					        	 pr=0;tr=1;current_state=1;
							 }
			    } 
			       
			     if(k0!=0)
				  {
			       if (k1-k0==8||k1-k0==4)
				   {
			       	    fprintf(outp1,"| T");   
				        	if (current_state == 1 || current_state == 2 )  {fprintf(outp1," | T |");  if (current_state == 2) current_state= 1; hits++;}
				                 	else				         		           
										if(current_state= 4) { fprintf(outp1,"  | NT |");   current_state ==1;  }
							     	 else  
										if(current_state= 3) { fprintf(outp1,"  | NT |");   current_state ==4; }	 
				         	           fprintf(outp1,"\n        ---------\n");   fprintf(outp1,"         in_LOOP \n"); inner_enable = 1;
				   }
					  else 
				         if(k0==k1) 
						 {             //if (inner_enable == 1) inner_hits++; else out_hits++;
				         	fprintf(outp1,"| T");  
				         	    if (inner_state == 1 && inner_enable == 1)  {fprintf(outp1," |  T |\n"); inner_state=2; hits++;}					                 
							     else   
				            	if (inner_state == 2 && inner_enable ==1) {fprintf(outp1," |  T |\n");  inner_state=2; hits++;}
				            	else
				            	if (inner_state == 3 && inner_enable ==1) {fprintf(outp1," | NT |\n");  inner_state=3; }
				            	else
				            	if (inner_state == 4 && inner_enable ==1) {fprintf(outp1," | NT |\n");  inner_state=3;  }
				            	else
				        	    if (current_state == 1 || current_state == 2 )  {fprintf(outp1," | T |\n"); hits++; if (current_state == 2) current_state= 1;}
				                 	else				         		           
										if(current_state= 4) { fprintf(outp1,"  | NT | \n");   current_state ==1; }
							     	 else  
										if(current_state= 3) { fprintf(outp1,"  | NT |\n");   current_state ==4; }	 
				         }
				        else if  (k1-k0== -8||k1-k0== -4)
				         {
				         	fprintf(outp1,"|NT"); 
							  if (inner_state == 1 && inner_enable == 1)  {fprintf(outp1," | T |"); inner_state=2;	  }					                 
							     else   
				            	if (inner_state == 2 && inner_enable ==1) {fprintf(outp1," |  T |");  inner_state=2; }
				            	else
				            	if (inner_state == 3 && inner_enable ==1) {fprintf(outp1," | NT |");  inner_state=3;hits++;}
				            	else
				            	if (inner_state == 4 && inner_enable ==1) {fprintf(outp1," | NT |");  inner_state=3;hits++;}
				            		
				         	   fprintf(outp1,"\n        ---------\n");   fprintf(outp1,"        inner end\n");  inner_enable=0; 
				         }
				    else
				         {
				         	
						     
						 fprintf(outp1,"|NT");  
				          if (current_state == 1 || current_state == 2 )  {fprintf(outp1," | T |\n");  if (current_state == 2) current_state= 1;
						     		                                       
									                                         
																		}
				                 	else				         		           
										if(current_state= 4) { fprintf(outp1,"  | NT | \n");   current_state ==1; hits++;}
							     	 else  
										if(current_state= 3) { fprintf(outp1,"  | NT |\n");   current_state ==4; hits++;}
											 
									 fprintf(outp1,"        ---------\n");	fprintf(outp1,"        >>>>>>>>>\n"); 
									 inner_enable=0;
																							   
												                  	
				         }
				 }   
			      
			       fprintf(outp1,"        ---------\n");     
			        k0=k1;  cc=c; if (c==3) c=0;
			        
			         for (x=0;x<=7;x++)  fprintf(outp1,"%c", add[x]);
		      }
		      else wrongadd++;
		  }
		      
		     
                
   }  
                                   							 										
					       
 fprintf(outp1,"|NT");  fprintf(outp1," | T |\n");   fprintf(outp1,"-----------------------\n");

 
  fprintf(outp2,"\n2-bit branch predictor:\n");
     fprintf(outp2,"\n  SUCCESS: %.0f/%.0f = %4.2f %%\n",hits,line_counter,100*hits/line_counter); 
     fprintf(outp2,"  FAIL: %.0f/%.0f = %4.2f %%\n",(line_counter-hits),line_counter,100 - 100*hits/line_counter);

    fclose(input_file2); fclose(outp1); fclose(outp2); 
    printf("2-bit branch predictor done!\n"); 
  	
  }

int main()
{  

   
   FILE *input_file;
   
   char filename[20]; double h;
   
   printf("Dose to onoma tou arxeiou gia eisodo: ");  
   scanf( "%s" ,filename);
   //printf("%s",&filename);  
 
   input_file = fopen(filename,"r");
  
// printf("please wait..\n"); 
 h = bp_1bit(input_file); fclose(input_file); input_file = fopen(filename,"r");
bp_2bit(input_file,h);
//printf("finished! \n");
fclose(input_file);
system("PAUSE");
   
}
  
 