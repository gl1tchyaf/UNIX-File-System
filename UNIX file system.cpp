#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <dirent.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

void openCreateFile(){
	char name[50];
    printf("Enter File name: ");
    scanf("%s",name);
    FILE *fp;
    fp  = fopen (name, "w");
    printf("%s is opened/created",name);
   
}

void closeAFileDescriptor(){
    char name[50];
    printf("Enter File name: ");
    scanf("%s",name);
    FILE *fp;
    fp  = fopen (name, "w");
    fclose (fp);
    printf("%s is closed",name);
    
}

void readfile(){
	char num[100];
	char name[50];
    printf("Enter File name: ");
    scanf("%s",name);
   FILE *fptr;

   if ((fptr = fopen(name,"r")) == NULL){
       printf("Error! opening file");
       exit(1);
   }
    while (fgets(num, 100, fptr) != NULL)
        printf("%s", num);
   fclose(fptr);
   
}

void writefile(){
	char sentence[100];
    FILE *fptr;
    //char a[10];
    char name[50];
    printf("Enter File name: ");
    scanf("%s",name);
    fptr = fopen(name, "w");
    //not mendetory
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    
    printf("Enter a Text:\n");
    //scanf("%s",a);
    scanf("%s",sentence);

    //printf("%s",sentence);
    fputs(sentence,fptr);
    //fprintf(fptr, "%s", sentence);
    fclose(fptr);
    
}

void makedirectory(){
	char name[50];
    printf("Enter directory name: ");
    scanf("%s",name);
    char command[50]="mkdir ";

    strcat(command,name);
    system(command);
    
}

void deletedirectory(){
	char name[50];
    printf("Enter directory name: ");
    scanf("%s",name);
    char command[50]="rm -r ";

    strcat(command,name);
    system(command);
    
}

void renamefile(){
	char name[50];
	char name2[50];
	char space[50]={' '};
    printf("Enter File name: ");
    scanf("%s",name);
    printf("Enter new name: ");
    scanf("%s",name2);
    char command[50]="mv ";

    strcat(command,name);
    strcat(command,space);
    strcat(command,name2);
    system(command);
    
}

void deletefile(){
	char name[50];
    printf("Enter file name: ");
    scanf("%s",name);
    char command[50]="rm ";

    strcat(command,name);
    system(command);
    
}

void status(){
	char name[50];
    printf("Enter file/directory name: ");
    scanf("%s",name);
	//char fn[]=name;
  struct stat info;
  int file_descriptor;

  if ((file_descriptor = creat(name, S_IWUSR)) < 0){
    char command[20]="stat ";
    strcat(command,name);
    system(command);
    //perror("creat() error");
    }
  else {
    if (fstat(file_descriptor, &info) != 0)
      perror("fstat() error");
    else {
      puts("fstat() returned:");
      printf("  inode:   %d\n",   (int) info.st_ino);
      printf(" dev id:   %d\n",   (int) info.st_dev);
      printf("   mode:   %08x\n",       info.st_mode);
      printf("  links:   %ld\n",         info.st_nlink);
      printf("    uid:   %d\n",   (int) info.st_uid);
      printf("    gid:   %d\n",   (int) info.st_gid);
    }
    close(file_descriptor);
    //unlink(name);
    
  }
}
void listdirectory(){
     DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    
}

void changedir(){
	char s[100];
 	char name[50];
    printf("Enter directory name: ");
    scanf("%s",name);
    chdir(name);

    printf("%s\n", getcwd(s, 100));
    

}

void fileoffset(){
	int seek;
	FILE *fp;
	
	char name[50];
	char text[50];
    printf("Enter file name: ");
    scanf("%s",name);
    
     char num[100];
	
   FILE *fptr;

   if ((fptr = fopen(name,"r")) == NULL){
       printf("Error! opening file");
       exit(1);
   }
    while (fgets(num, 100, fptr) != NULL)
        //printf("%s", num);
   fclose(fptr);
    
    
   fp = fopen(name,"w");
   
   fputs(num,fp);
   printf("Enter seek position: ");
   scanf("%d",&seek);
   printf("Enter your text: ");
   scanf("%s",text);
   fseek( fp, seek*sizeof(char),SEEK_SET );
   fputs(text, fp);
   fclose(fp);
   
}



int main()
{

	while(true){
    int choice;
    printf("\nEnter Your choice\n");
    printf("-----------------\n");
    printf("1.Open or Create File\n");
    printf("2.Close a file descriptor\n");
    printf("3.Read a File\n");
    printf("4.Write a File\n");
    printf("5.Reposition read/write File offset\n");
    printf("6.Create Directory\n");
    printf("7.Delete Directory\n");
    printf("8.Change Current Directory\n");
    printf("9.Rename File\n");
    printf("10.Delete a file\n");
    printf("11.Get file/directory status\n");
    printf("12.List current directory content\n");
    printf("13.Exit\n");


    scanf("%d",&choice);

    switch(choice)
    {
        case 1: openCreateFile();
        break;

        case 2: closeAFileDescriptor();
        break;

        case 3: readfile();
        break;

        case 4: writefile();
        break;

        case 5: fileoffset();
        break;

        case 6: makedirectory();
        break;

        case 7: deletedirectory();
        break;

	case 8: changedir();
        break;

	case 9: renamefile();
        break;

	case 10: deletefile();
        break;

	case 11: status();
        break;

	case 12: listdirectory();
        break;
        
        case 13: return 0;
        break;

	default: printf("Wrong Input");
	break;
    }
  }
}

