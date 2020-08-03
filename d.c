#include <stdio.h>
#include <stdlib.h>

int main()
{
   
   pid_t pid=fork();

   if(pid==0)
     {	
         

       
         
             
        
             pid=fork();
             if(pid==0)
             {
                 printf("%s","3-");
              }
          else{ printf("%s","2-");}
 
         
     }
     else
      {

         printf("%s","1-");
 

      }
   
}
