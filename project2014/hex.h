
#include <math.h>


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
 
