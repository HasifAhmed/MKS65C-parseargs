 #include <string.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>

char ** parse_args( char * line ){

  char **args = calloc(1, sizeof(char **) );
  char * s1 = line;
  args[0] = calloc(1,sizeof(char*));
  line = strsep(&s1," ");
  args[0] = line;
  int i = 1;
  while(s1!=NULL){
    args[i] = calloc(1,sizeof(char*));
    line = strsep(&s1," ");
    args[i] = line;
    i++;
  }
  args[i] = NULL;
  return args;
  }
int main(){
  char line[100] = "ls -a -l";
  char ** args = parse_args(line);
   //printf("%s\n",args[0]);
   //printf("%s\n",args[1]);
  execvp(args[0],args);
   /*char * ok[3];
   ok[0] = "ls";
   ok[1] = "-al";
   ok[2] = NULL;m
   execvp(ok[0],ok); */
  return 0;
}
