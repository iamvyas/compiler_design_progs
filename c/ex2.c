#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
   FILE *fp;
   char line[100][100];
   char *type,*var,*check,*check_p,*check_f;
   char pre[10];
   int i=0,j;
   fp=fopen("symf.c","r");
   
   while(!feof(fp))
   {
     fgets(line[i],200,fp);
     i++;
   }
   printf("LINE NUMBER\tPREPROCESSORS\tFUNCTIONS\tKEYWORDS \tIDENTIFIERS\n");
   for(j=0;j<i-1;j++)
   {
      type=strtok(line[j]," ");
      check_p=strchr(type,'#');
      if(check_p!=NULL)
        printf("%d\t\t%s\n",j+1,type);
      check_f=strchr(type,'(');
      if(check_f!=NULL)
        printf("%d\t\t\t\t%s",j+1,type);
      if(strcmp(type,"int")==0||strcmp(type,"float")==0||strcmp(type,"double")==0|| strcmp(type,"char")==0)
      {
        while((var=strtok(NULL,";\n"))!=NULL)
        {
           printf("%d\t\t\t\t\t\t%s\t\t%s\n",j+1,type,var,var);
        }
      }
   }
}
