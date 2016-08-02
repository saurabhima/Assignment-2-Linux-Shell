#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>

int listpscurrent()
{
  const char* directory = "/";
  
  struct dirent *dirstruct;
  DIR *dirptr = opendir(directory);
  //int counter=0;
  if (dirptr == NULL) 
  {
    printf("\nThis Directory does not exist");
    return 1;
  }
 
  
  
  closedir(dirptr);


return(0);

}



int main(int argc, char *argv[])
{

int argcount=argc;

if(argcount==1)
{
printf("\nProccess list for Current User");
listpscurrent();
}
else
if(argcount==2 && strcmp(argv[1],"-a")==0)
{
printf("\nProccess list for All User");
//listpsall();
}
else{
printf("\nIllegal Arguements, Please Check");
exit(0);
}


return(0);

}
