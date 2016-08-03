#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>
#include<ctype.h>
int listpscurrent()
{
  const char* directory = "/proc/";
  
  struct dirent *dirstruct;
  DIR *dirptr = opendir(directory);
  //int counter=0;
  if (dirptr == NULL) 
  {
    printf("\nThis Directory does not exist");
    return 1;
  }
  closedir(dirptr);
  recurse_dir(directory);


return(0);

}

recurse_dir(const char* dirname)
{
  
	
  struct dirent *dirstruct,*dirsubstruct;
  DIR *dirptr = opendir(dirname);
  DIR *dirsubptr = NULL;
  FILE *fileptr1,*fileptr2;
  int counter=0;
  char  buffer[512] = {0};
   

    /*while ((dirstruct = readdir(dirptr)) != NULL) 
    {
    	 if ( !strcmp(dirstruct->d_name, ".") || !strcmp(dirstruct->d_name, "..") )
        {
           
        } 
        else {
            
        
        sprintf(buffer, "%s/%s", dirname, dirstruct->d_name);
        printf("%s\n", dirstruct->d_name);
        if (path_is_directory(buffer))
            recurse_dir(buffer);
        
            
    }
    }*/
    
      int i,dirnum=22;
      char *filename;
      char *start="/";
      char *proc="proc";
      char *fd="fd";
      char *status="status";
      while ((dirstruct = readdir(dirptr)) != NULL)
         {   
            dirnum=atoi(dirstruct->d_name);
            //printf("%i\t", dirnum);
            if(dirnum>0)
            {
           	if(dirnum==getpid() || dirnum==getppid())
           	{
           	filename=malloc(strlen(dirstruct->d_name)+3*(strlen(start))+strlen(status)+strlen(proc)+1);
           	strcpy(filename, start);
           	strcat(filename, proc);
           	strcat(filename, start);
    		strcat(filename,dirstruct->d_name);
    		strcat(filename, start);
    		//strcat(filename, fd);
    		//strcat(filename, start);
    		strcat(filename,status);
    		printf("%s\n",filename);
           	fileptr1=fopen(filename,"r");
			if (fileptr1 == NULL) {
			fputs("File does not exist", stderr);
        	//exit(1);
    		}
    		char buffer[5000];
    		char *ret=NULL,*p,hold[5000];
    		while(fgets(buffer, 100, fileptr1)) 
   			{
        	if(strncmp(buffer, "Name:", 5) != 0)
            continue;
        	p = buffer+6;
        	while(isspace(*p)) ++p;
        	if((i = readlink(filename,hold,sizeof(hold)-1))!=-1)
    		{	
    		hold[i] = '\0';
			ret = strchr(hold, '/');
			ret++;
			ret = strchr(ret, '/');
			ret++;
			if(strcmp(ret,"null")==0)
				ret=NULL;
			}
    
			free(filename);
			}
			}
		
		}
    closedir(dirptr);
    
}
}



int path_is_directory (const char* path) {
    struct stat s_buf;

    if (stat(path, &s_buf))
        return 0;

    return S_ISDIR(s_buf.st_mode);
}

int main(int argc, char *argv[])
{

int argcount=argc;

if(argcount==1)
{
printf("\nProccess list for Current User\n");
listpscurrent();
}
else
if(argcount==2 && strcmp(argv[1],"-a")==0)
{
printf("\nProccess list for All User\n");
//listpsall();
}
else{
printf("\nIllegal Arguements, Please Check");
exit(0);
}


return(0);

}
