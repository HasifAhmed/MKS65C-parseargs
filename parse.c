 #include <string.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>

char ** parse_args( char * line ){

  char **args = malloc( sizeof(char *) * 6);
  char * s1 = line;
  args[0] = strsep(&s1, " ");
  args[1] = s1;
  return args;
}
 int main(int argc, char * argv[]){
   char line[100];
   if(argc > 1){
     strcpy(line,*argv);
   }
   else{
     strcpy(line,"ls");
   }
   char ** args = parse_args(line);
   printf("%s",args[0]);
   execvp(args[0],args);
   return 0;
 }
