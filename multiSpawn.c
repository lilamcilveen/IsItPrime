#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>   
#include <unistd.h>

//Function prototypes
int fileExists(char *fileName);
int morph(char *number);

/*
 fileExists
Input: pointer to the fileName

Output:
    - Error if file DNE
    - 
 */
int fileExists(char *fileName)
{
    FILE *f = NULL;
    f = fopen(fileName, "rb");

    if(f == NULL) {
        printf("file %s does not exist\n", fileName);
        return 3;
    }

   fclose(f);
  return 0; 


}



/*
 morph
Input: pointer to char array of numbers

Output:
    - return -1 if morph failed
 */
int morph(char *number)
{
    char *param[3];
    param[0] = "isPrime";
    param[1] = number;
    param[2] = NULL;

    if(execvp("./isPrime", param) < 0)
        return -1;
    else
        return execvp("./isPrime", param);


}

int main(int arc, char *argv[])
{
    char s[10][11];
    int r = 0;
    int morphR = 0;
    unsigned int buffer;

    int status;
    int statusR;

    FILE *f;

    int i = 0;
    int childPID[10];

    if(argv[1] != NULL) {
        r = fileExists(argv[1]);

        if(r == 0) {
            f = fopen(argv[1], "rb");

            while(i < 10) {
                fread(&buffer, sizeof(unsigned int), 1, f);
                sprintf(s[i], "%u", buffer);
                childPID[i] = fork();

                if(childPID[i] != 0) {
                    waitpid(-1, &status, 0);
                    if(WIFEXITED(status)) {
                        statusR = WEXITSTATUS(status);
                        if(statusR == -1)
                            printf("Error, failed\n");
                        else if(statusR == 0) {
                            i++;
                            continue;
                        }
                        else if(statusR == 1)
                            printf("%s is a prime number\n", s[i]);
                        else if(statusR == 2)
                            printf("Number not found!\n");
                        i++;
                    }
                }
                else {
                     morphR = morph(s[i]);
                 }
             }

         fclose(f);
        }
    }
    else {
        printf("Usage: singlePrime fileName\n"); //fileName not provied
        return 2;
    }
}
