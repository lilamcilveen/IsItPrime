#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
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
    char s[100];
    int r = 0;
    int morphR = 0;
    unsigned int buffer;

    FILE *f;

    int pid = 0;
    int cpid = 0;
    int status;

    if(argv[1] != NULL) {
        r = fileExists(argv[1]);
        if(r == 0) {
            f = fopen(argv[1], "rb");
            fread(&buffer, sizeof(unsigned int), 1, f);
            fclose(f);

            sprintf(s, "%u", buffer);
	    morphR = morph(s);
        }
    }

    else {
        printf("Usage: singlePrime fileName\n"); //fileName not provied
        return 2;
    }
}
