/***********************************************************************
 * nurse.c
 * A program to enter patient details to be saved and read later
 * Simon Sorensen
 * 21/11/19
 * Version a
 * ********************************************************************/

/* Structures */
struct nurse {
    char name[50];
    char id[9];
    char password[9];
};

struct patient {
    char first_name[50];
    char last_name[50];
    char birthday[12];
    int height;
    int waist;
    int weight;
    char comment[2000];
};

/* Main functions */
void loadAuth(char *dest);
int validateCredentials(char *id, char *password, struct nurse nurses[]);
void savePatient(struct patient);

/* Encryption */
char* encrypt(char *input);
char* decrypt(char *output);

/* Data input */
char *input(char *validation);
char *getBirthday(void);
int getNumber(int min, int max);

int main(void)
{
    /* Load nurse details from file */
    /* Prompt for login */
    /* Authenticate and greet nurse */
    /* Prompt for new patient details */
    /* Confirm whether details are correct and allow for editing */
    /* Save to file */
    /* Ask whether to add new patient or exit */

    return 0;
}