#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>

int rem_file(int arg,char *argv[])
{
   system("clear");
   int filenum=arg;
   int return_val=-1;
   int count;
   char *filename=NULL;
   FILE *fileptr;
   for(count=1;count<filenum;count++)
   {
   return_val=-1;
   filename=argv[count];
   fileptr = fopen(filename, "r");
   if(fileptr==NULL)
   {
   printf("Error: File does not exist");
   return(-1);
   }
   fclose(fileptr);
   return_val = remove(filename);
   
   }
   
   return(return_val);
   
}

/*int check_empty_dir(char *directory) {
  struct dirent *dirstruct;
  DIR *dirptr = opendir(directory);
  int counter=0;
  if (dirptr == NULL) 
  {
    printf("\nThis Directory does not exist");
    return 1;
  }
  while ((dirstruct = readdir(directory)) != NULL) {
    if(++counter > 2)
      break;
  }
  closedir(directory);
  if (counter <= 2) //Directory Empty
    return 2;
  else
    return 0;
}*/

int rem_empty_dir(int arg,char *argv[])
{
char *dirname=NULL;
dirname=argv[2];
printf("\n%s",dirname);
//int check=check_empty_dir(dirname);
//printf("\nCheck-->%i",check);
//if(check==2)
//{
 int check = rmdir(dirname);
 if (!check)
      printf("\nDirectory Succesfully Deleted\n");
   else
   {   
            printf("Unable to remove directory\n");
          
            exit(1);
   }

//}

return(0);
}

rem_nonempty_dir(const char* dirname)
{
  
	
  struct dirent *dirstruct;
  DIR *dirptr = opendir(dirname);
  
  int counter=0;
  char  buffer[512] = {0};
   

    while ((dirstruct = readdir(dirptr)) != NULL) 
    {
    	 if ( !strcmp(dirstruct->d_name, ".") || !strcmp(dirstruct->d_name, "..") )
        {
           
        } 
        else {
            
        
        sprintf(buffer, "%s/%s", dirname, dirstruct->d_name);
        printf("%s\n", dirstruct->d_name);
        if (path_is_directory(buffer))
            rem_nonempty_dir(buffer);
        else
            unlink(buffer);
    }
    }

    closedir(dirptr);
    rmdir(dirname);
}

int path_is_directory (const char* path) {
    struct stat s_buf;

    if (stat(path, &s_buf))
        return 0;

    return S_ISDIR(s_buf.st_mode);
}

int main(int argc, char *argv[])
{

system("clear");
char arg1[10],arg2[10];
char *arg=argv[1];
if(argc<2)
{
printf("\n Error:Inadequate number of arguements");
exit(2);

}


strcpy(arg1,"-l");
strcpy(arg2,"-d");
if((strcmp(arg1,argv[1])!=0)&&(strcmp(arg2,argv[1])!=0))
{

printf("\nThis is file deletion");
int returnval=rem_file(argc,argv);
if(returnval == 0) 
   {
      printf("\nDelete Successful");
   }
   else 
   {
      printf("\nError");
   }
  return(0); 
}

if((strcmp(arg1,argv[1])==0)&&argc>2)
{

rem_empty_dir(argc,argv);
return(0);

}

if((strcmp(arg2,argv[1])==0)&&argc>2)
{

printf("\nRemoving non Empty Directory\n");
rem_nonempty_dir(argv[2]);
return(0);
}

return(0);
}





