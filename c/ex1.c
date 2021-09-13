#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
   FILE *fp;
   char line[100][100];
   char *type,*var;
   int i=0,j,depth=0;
   fp=fopen("symbolfile.c","r");
   while(!feof(fp))
   {
     fgets(line[i],200,fp);
     i++;
   }
   printf("TYPE\tIDENTIFIER\tADDRESS\tDEPTH\n");
   for(j=0;j<i-1;j++)
   {
      type=strtok(line[j]," ");
      if(strncmp(type,"{",1)==0)
      {
          depth++;
      }
      else if(strncmp(type,"}",1)==0)
      {
          depth--;
      } 
      if(strcmp(type,"int")==0||strcmp(type,"float")==0||strcmp(type,"double")==0||  strcmp(type,"char")==0)
      {
        while((var=strtok(NULL,",;\n"))!=NULL)
        {
           printf("%s\t%s\t%p\t%d\n",type,var,var,depth);
        }
      }
   }
}
