// shaimaa dar taha
// 1222440
//section 1


// include the  libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
// difine constant
#define TABLE_SIZE 100   // size of the table
#define  size 50   // the length of  each words
#define   bigSize  500  // the size of each line string from the file

typedef struct AVLnode *AVLNode; // difine the struct to AVL tree

struct AVLnode
{
    char words[size];  // the node word
    AVLNode Left; // the left pointer
    AVLNode Right; // the right pointer
    int Height; //Balance information
    int frequancy; // to catch how many time the word repeated
};
typedef struct HashNode {  // define the hash node
    char words[size];
    int frequency;
    struct HashNode* next;
} HashNode;

HashNode* hashTable[TABLE_SIZE] = {NULL};  // Initialize hash table with NULL

/////////////////////////////////////////////////////
// the functions
void readFromFile(); // read the file
void displayMenu();
// AVL functions

AVLNode MakeEmpty( AVLNode T );// this function to make the AVL empty

void cleanString(char str [bigSize]);// this function to remove the not  alphabetical characters

void removeSpace(char *str ); // this function to remove the UN necessary  spaces

AVLNode Insert( char X[size], AVLNode T );//Insert a word to the AVL tree: insert a new word or update the frequency of existing word.

void PrintInOrder( AVLNode t);// print the AVL in order

AVLNode Find( char *s, AVLNode T );// find the word in  AVL

int Max(int a, int b);// find the max between two number

int height(AVLNode N);// function to find the height of the node

AVLNode deleteAVL(char x[size], AVLNode T) ;//Delete word from the AVL Tree: Search for a word in the AVL tree and delete it. If the word
//does not exist, then show a clear message about this.




// function of hash table
void traverseAndInsert(AVLNode root); // After building the AVL tree, traverse the tree and insert each word and
//its frequency into a hash table.The hash table will allow for fast retrieval of word frequency by
//direct access through the hash of the word

int hash(char* word);// find the hash function

void insertHashTable(char* word, int frequency); // inser to hash table from any places

void deleteFromHashTable(char* word);// delete word from hash table

void printHashTable(); // to print the hash table

void insertOrUpdateHashTable(char* word, int frequency);// to insert word and its frequency

void search(char* word) ; // to search fr a word in the hash table

void printWordStatistices();//Provide statistics such as total number of unique words, most frequent
//word, and words repeated more than specific threshold in the tree from the hash table.

AVLNode tree; // to store the word from the file
int count =0;
int main()
{
displayMenu();  // display the menue
int op =0; // to catch the number of operation
int load=0,fre=0,check=0;
// load to check if the file loaded
// fre to catch the frequency
// check to check if the hash table created
char user [size];// to catch the word from user
scanf("%d",&op);// scan the operation
while(op!=11){ // exit if the number is 11
    switch(op){
case 1://Load data from the file.
    readFromFile(); // call the function
    printf("the information load successfully \n");
    load =1;
    break;
    ///////////////////////////////////////////////

    case 2://Create the AVL tree.

         if (load)
    printf("the AVL tree is Created  \n");
    else
    printf ("please enter 1 to loaded the word to AVL\n");
    break;
    //////////////////////////////////////////////

    case 3://Insert a word to the AVL tree.
         if (load){
    printf("please enter the word you want to add  \n");
    scanf ("%s",user); //save the word in user array
    cleanString(user); // to clear any non alphabetical characters.
          for (int j = 0; user[j]; j++) {
    user[j] = tolower(user[j]);// make all characters in the  word
}
    AVLNode match = Find(user, tree); // Search for the word in the AVL tree
    if (match != NULL) {
        match->frequancy = match->frequancy + 1; // Update frequency of the matched word
    } else {
        tree = Insert(user, tree); // Insert the word into the AVL tree if not found
    printf("\n the word add successfully\n");
    }

         } else {
          printf ("please enter 1 to loaded the word to AVL\n");// error massage
         }
    break;

    //////////////////////////////////////
    case 4://Delete a word from the AVL tree
        if (load){// to check if loaded
        printf ("please enter the word you want delete from AVL tree \n");
         scanf ("%s",user);
         cleanString(user);
          for (int j = 0; user[j]; j++) {
    user[j] = tolower(user[j]);
}
         deleteAVL(user,tree); // call the function to delete the word from AVL
        // printf("the word %s delete successfully",user);
        }else
         printf ("please enter 1 to loaded the word to AVL\n");
    break;
    //////////////////////////////////////////////////
    case 5://Print the words as sorted in the AVL tree.
        if (load)
        PrintInOrder(tree);    //print the AVL tree in order
        else
            printf ("please enter 1 to loaded the word to AVL\n");
    break;
    ////////////////////////////////////////////////////
    case 6:
    if (load ){//. Create the Hash Table
 traverseAndInsert(tree);
 printf("the hash table created please click 1 if you want to see the contents \n");
 scanf("%d",&fre);// if i want to print the hash table
 check=1;
 if (fre){
 printHashTable();// print the hash table
 }
 else
    printf("please enter number ");
    }else
    printf ("please enter 1 to loaded the word to AVL\n");

    break;
    //////////////////////////////////////////

    case 7://Insert a word to the Hash table
        if (load){
                if (check){
        printf("please enter the word to add in the hash table \n");
        scanf("%s",user); //store the word
        printf("please enter the word frequency ");
        scanf("%d",&fre);// store the frequency
        cleanString(user);
            for (int j = 0; user[j]; j++) {
    user[j] = tolower(user[j]);
}
          for (int j = 0; user[j]; j++) {
    user[j] = tolower(user[j]);
          }
        insertOrUpdateHashTable(user,fre);// to store it in the hash table
        printHashTable();
        }
        else
            printf("please chick 6 to create hash table\n");
        }else
         printf ("please enter 1 to loaded the word to AVL\n");
    break;
    /////////////////////////////////////////////////////

    case 8://Delete a word from the hash table
        if (load){
                if (check){
         printf("please enter the word to delete in the hash table \n");
        scanf("%s",user);
        cleanString(user);
            for (int j = 0; user[j]; j++) {
    user[j] = tolower(user[j]);
}
        deleteFromHashTable(user);// delete the word

         printf(" please click 1 if you want to see the contents \n");
 scanf("%d",&fre);// if i want to print the hash table

 if (fre){
 printHashTable();// print the hash table
 }else
 printf("please enter number ");
        }else
        printf ("please enter 6 to loaded the word to hash table\n");
        }else
        printf ("please enter 1 to loaded the word to AVL\n");
    break;
    /////////////////////////////////////////////////////
    case 9://Search for a word in the hash table and print its frequency.
        if (load){
            if (check){
                    printf ("please enter the word you want to know it frequency \n");
            scanf("%s",user);
            cleanString(user);
             for (int j = 0; user[j]; j++) {
    user[j] = tolower(user[j]);
}
              search(user);
            }else
             printf ("please enter 6 to loaded the word to hash table\n");
        }else
         printf ("please enter 1 to loaded the word to AVL\n");
    break;
    /////////////////////////////////////////////
    case 10://Print words statistics.
        if (load){
                if (check){
                        printWordStatistices();

                }else{
                printf ("please enter 6 to loaded the word to hash table\n");
                }

        }else{
             printf ("please enter 1 to loaded the word to AVL\n");
        }
    break;
    ////////////////////////////////////
default:// if the user enter any number with no operation
printf("no such operation in %d ! please enter number ",op);
 }
 printf ("\n\n");
 printf("please enter number ");
 scanf("%d",&op);


}
printf("thank you for using my program \n good bye\n ");


}

void readFromFile(){
    char temp[bigSize]; // string store line from the file

// AVLNode T=NULL;
    FILE*input; // pointer to the file

    input=fopen("input.txt","r"); // open the file
    if (input==NULL){
          printf("error !This File does not exist.\n"); // error massage
    }

    while(fgets(temp,sizeof(temp),input)){ //reading line by line and store each string in words
             cleanString(temp); // clean the string from non alphabetical characters

char *token=strtok(temp," ");// to divide the string word by word
               while (token != NULL) {
                    removeSpace(token); // remove UN necessary
            for (int j = 0; token[j]; j++) {
    token[j] = tolower(token[j]); // convert to lower cases
}

    AVLNode match = Find(token, tree); // Search for the word in the AVL tree
    if (match != NULL) {
        match->frequancy = match->frequancy + 1; // Update frequency of the matched word
    } else {
        tree = Insert(token, tree); // Insert the word into the AVL tree if not found
    }
    token = strtok(NULL, " ");
}

        }
        // PrintInOrder(tree);


//("\n%d\n",count);
fclose(input);

}
////////----------------------------------------------------->
AVLNode MakeEmpty( AVLNode T ) // make the AVL empty
{
    if( T != NULL )
    {
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free( T );
    }
    return NULL;
}
////////--------------------------------------------->
void cleanString(char str [bigSize]){// clean the string
    int i=0,j=0;
    for (i=0;str[i]!='\0';i++){
        if (isalpha(str[i]) ||  str[i]==' ') {
            str[j++]=str[i];
        }
    }
    str[j]='\0';
}
////////-------------------------------------->
void removeSpace(char *str ){
    // this function is useful when I compare between the string I use from file
    // and from user to make the opp true and acurate
int i,j;
for (i=0,j=0;str[i];i++){
    if (str[i]!=' '){ // spaces remove
        str[j++]=str[i];
    }
}
str[j]='\0';
}
////////-------------------------------------->

AVLNode Find( char *s, AVLNode T ) // find the word in AVL
{
    if( T == NULL )// if empty
        return NULL;

    if( strcmp(s,T->words)==-1 ) // the word less than so go to the left
        return Find( s, T->Left );// call the function again but the lef side
    else if( strcmp(s,T->words)==1 )// greater than so go to the right
        return Find( s, T->Right );
    else
        return T;
}
////////-------------------------------------->
AVLNode FindMin( AVLNode T ) // find the min node
{
    if( T == NULL )
        return NULL;
    else if( T->Left == NULL )// if there is no left child so the root is the min
        return T;
    else
        return FindMin( T->Left ); // recall the function
}
////////-------------------------------------->
AVLNode FindMax( AVLNode T ) // find the max node
{
    if( T != NULL )
        while( T->Right != NULL )
            T = T->Right;

    return T; // return the maximum node
}
////////-------------------------------------->
int Height( AVLNode P ) // the height function
{
    if( P == NULL )
        return -1; // if its empty
    else
        return P->Height; // return the height
}
////////-------------------------------------->
int Max( int Lhs, int Rhs ) //find the  max between two number
{
    if (Lhs > Rhs)
     return   Lhs;
    else
     return    Rhs;

}
////////-------------------------------------->

AVLNode SingleRotateWithLeft( AVLNode K2 )// single rotate left
{
    AVLNode  K1;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max( Height( K2->Left ), Height( K2->Right ) ) + 1;
    K1->Height = Max( Height( K1->Left ), K2->Height ) + 1;// Corrected height calculation

    return K1;  /* New root */
}
////////-------------------------------------->
AVLNode SingleRotateWithRight( AVLNode K1 )// single rotate right
{
    AVLNode K2;

    K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;

    K1->Height = Max( Height( K1->Left ), Height( K1->Right ) ) + 1;
    K2->Height = Max( Height( K2->Right ), K1->Height ) + 1;

    return K2;  /* New root */
}
////////-------------------------------------->
AVLNode DoubleRotateWithLeft( AVLNode K3 ) // double rotate left
{
    /* Rotate between K1 and K2 */
    K3->Left = SingleRotateWithRight( K3->Left );

    /* Rotate between K3 and K2 */
    return SingleRotateWithLeft( K3 );
}
////////-------------------------------------->
AVLNode DoubleRotateWithRight( AVLNode K1 ) //double rotate right
{
    /* Rotate between K3 and K2 */
    K1->Right = SingleRotateWithLeft( K1->Right );

    /* Rotate between K1 and K2 */
    return SingleRotateWithRight( K1 );
}
////////-------------------------------------->
AVLNode Insert( char X[size], AVLNode T ) // insert to AVL
{

    if( T == NULL )
    {
        /* Create and return a one-node tree */
        T = malloc( sizeof( struct AVLnode ) );
        if( T == NULL )
            printf( "Out of space!!!" );
        else
        {// if the AVL not empty
            strcpy(T->words,X);
            T->Height = 0;
            T->Left = T->Right = NULL;
            T->frequancy=1;
            count++;
        }
    }
// if the AVL not empty
    else if( strcmp(X , T->words)<0 ) // go to left
    {
        T->Left = Insert( X, T->Left );
        if( Height( T->Left ) - Height( T->Right ) == 2 ){
                if( strcasecmp(X , T->words)==0 ){
                    T->frequancy++;
                }
          else  if( strcmp(X , T->words)<0 ){
                T = SingleRotateWithLeft( T );

            }
            else{
                T = DoubleRotateWithLeft( T );

            }
        }
    }
    else if( strcmp(X ,T->words )>0) // go to right
    {
        T->Right = Insert( X, T->Right );
        if( Height( T->Right ) - Height( T->Left ) == 2 ){
            if( strcmp(X ,T->words )>0 ){
                T = SingleRotateWithRight( T );

            }
            else
            {
                T = DoubleRotateWithRight( T );

            }

        }

    }
    /* Else X is in the tree already; we'll do nothing */
//printf("%d",count);

    T->Height = Max( Height( T->Left ), Height( T->Right ) ) + 1;
    return T;
}
////////-------------------------------------->
/* END */
void PrintInOrder( AVLNode t) // print in order (ascending order )
{
    if( t != NULL)
    {
        PrintInOrder( t->Left ); // recall the function
        printf("%s\t", t->words);// print the  word
        printf("%d\n",t->frequancy);// print the frequency
        PrintInOrder( t->Right ); // recall the function
    }
}
////////-------------------------------------->

AVLNode deleteAVL(char x[size], AVLNode T) {// delete the AVLnode
    if (T == NULL) {
          printf("Word '%s' not found in the AVL tree.\n", x);
        return T;
    }

    if (strcmp(x, T->words) < 0) {// go to left
        T->Left = deleteAVL(x, T->Left);
    } else if (strcmp(x, T->words) > 0) { //go to right
        T->Right = deleteAVL(x, T->Right);
    } else {
        if (T->Left == NULL || T->Right == NULL) { // if theres no child or one child
            AVLNode temp ;
            if (T->Left )// if it have left child
               temp= T->Left ;
                else // if have right side
           temp= T->Right;
            if (temp == NULL) { // no child
                temp = T;
                T=NULL;
            } else {
               T=temp;
            }
            free(temp);
        } else {
            AVLNode temp = FindMin(T->Right);
            strcpy(T->words, temp->words);
            T->frequancy = temp->frequancy;
            T->Right = deleteAVL(temp->words, T->Right);
        }
        if  (T==NULL){
                return T;
        }

        T->Height = Max(height(T->Left), height(T->Right)) + 1;
        int balance = height(T->Left) - height(T->Right);

        if (balance > 1 && height(T->Left->Left) >= height(T->Left->Right)) { // rotate
            return SingleRotateWithLeft(T); // rotate left
        }

        if (balance > 1 && height(T->Left->Left) < height(T->Left->Right)) {// rotate
                T->Left = SingleRotateWithRight(T->Left);
            return SingleRotateWithRight(T); //rotate right
        }

        if (balance < -1 && height(T->Right->Right) >= height(T->Right->Left)) {// rotate
            return SingleRotateWithRight(T); // rotate right
        }

        if (balance < -1 && height(T->Right->Right) < height(T->Right->Left)) {// rotate
            T->Right = SingleRotateWithLeft(T->Right); // rotate left
            return SingleRotateWithRight(T); // rotate right
        }
    }

    return T;
}
////////-------------------------------------->
int height(AVLNode N) { // find the height
    if (N==NULL)
        return 0;
    else
        return N->Height;

}
////////-------------------------------------->
void displayMenu(){ // display menu
printf("welcome to my program \n");
printf("please choose one operation  \n");
printf("1. Load data from the file\n");
printf("2. Create the AVL tree.\n");
printf("3. Insert a word to the AVL tree\n");
printf("4. Delete a word from the AVL tree.\n");
printf("5. Print the words as sorted in the AVL tree.\n");
printf("6. Create the Hash Table.\n");
printf("7. Insert a word to the Hash table.\n");
printf("8. Delete a word from the hash table\n");
printf("9. Search for a word in the hash table and print its frequency.\n");
printf("10. Print words statistics.\n");
printf("11. Exit the application.\n");
printf("********************************************\n");
printf("********************************************\n");

}
////////-------------------------------------->

int hash(char* word) { // hash function  to convert string to integer
    //solve collision problem I use the separate chaining
    unsigned int hashValue = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hashValue = (hashValue << 5) + word[i];// shift
    }
    return hashValue % TABLE_SIZE; // convert the string to number
}

////////-------------------------------------->
void traverseAndInsert(AVLNode root) { // function to traverse the data and move to hash table
    if (root != NULL) {
        traverseAndInsert(root->Left); // recall the function with left
        insertHashTable(root->words, root->frequancy); //  call the insert function
        traverseAndInsert(root->Right);// recall the function with right
    }
}
////////-------------------------------------->

void insertHashTable(char* word, int frequency) { // insert into hash table from user
    unsigned int index = hash(word);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode)); // create hash node
    strcpy(newNode->words, word); // copy the word to the new hash node
    newNode->frequency = frequency;// assign the frequency
    newNode->next = hashTable[index];// add to hash
    hashTable[index] = newNode;
}
////////-------------------------------------->
void printHashTable() { // function to print hash table
    for (int i = 0; i < TABLE_SIZE; i++) { // for loop to visit all element
        HashNode* node = hashTable[i]; // create hash node
        if (node != NULL) {
            printf("Index %d: ", i); // the index of hashing table
            while (node != NULL) {
                printf("(%s, %d) ", node->words, node->frequency);// print all node in this index
                node = node->next;
            }
            printf("\n");
        }
    }
}
////////-------------------------------------->
// Delete from hash table
//Traverses the linked list at the hashed index to find the node with the word to be deleted, adjusts pointers to remove the node, and frees its memory.
void deleteFromHashTable(char* word) {
    unsigned int index = hash(word);
    HashNode* current = hashTable[index];
    HashNode* prev = NULL;

    // Traverse the linked list at the computed index
    while (current != NULL && strcmp(current->words, word) != 0) {
        prev = current;
        current = current->next;
    }

    // If the word was not found
    if (current == NULL) {
        printf("Word '%s' not found in the hash table.\n", word);
        return;
    }

    // Remove the node from the linked list
    if (prev == NULL) {
        // The node to delete is the first node
        hashTable[index] = current->next;
    } else {
        prev->next = current->next;
    }

    // Free the memory allocated for the node
    free(current);
    printf("Word '%s' deleted from the hash table.\n", word);
}
////////-------------------------------------->
void insertOrUpdateHashTable(char* word, int frequency) { // insert from user
    unsigned int index = hash(word);
    HashNode* current = hashTable[index];

    // Traverse the linked list at the computed index to check if the word already exists
    while (current != NULL) {
        if (strcmp(current->words, word) == 0) {
            // Word found, update its frequency
            current->frequency+= frequency;
            return;
        }
        current = current->next;
    }

    // Word not found, insert new node
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    // assign the node data
    strcpy(newNode->words, word);
    newNode->frequency = frequency;
    newNode->next = hashTable[index];
    hashTable[index] = newNode; // add to hash table
}
////////-------------------------------------->
void search(char* word) {//Traverses the linked list at the hashed index to find the word and prints its frequency if found.
    unsigned int index = hash(word); // I used unsigned integer
    HashNode* current = hashTable[index];

    // Traverse the linked list at the computed index to check if the word  exists
    while (current != NULL) {
        if (strcmp(current->words, word) == 0) {
                printf("the frequency of the word %s is %d \n",current->words,current->frequency);
              return;
        }
        current=current->next;
    }
    printf("the word %s not in the hash to know its frequency \n",word);

    }
    ////-------------------------------------->
void printWordStatistices() {//Collects and prints statistics such as the total number of unique words, the most frequent word, and words with a frequency above a given threshold.

    int max=0,threshold=0,index=0,count =0,countI=0; // variables to carry the result
    char maxWord [size];
     printf("please enter the threshold \n");
    scanf("%d",&threshold); // the threshold


    while (index<TABLE_SIZE){ // for all index in hash table
    HashNode* current = hashTable[index];

    // Traverse the linked list at the computed index to check if the word  exists
    while (current != NULL) {
            if (current->frequency==1){
                count++;
            }// calculate the number of unique word
            if (current->frequency>max){
                max=current->frequency;
               strcpy( maxWord,current->words);
            }// find witch word with the max frequency

            if (current->frequency>threshold){
                printf("\n the word %s with %d\n",current->words,current->frequency);
                countI++; // catch the number of them
            }// find the word who more than the threshold
            current=current->next;
    }
    index++;
}
printf("\n Total unique words with frequency 1: %d\n", count);
printf("Total  words more than threshold %d is  %d\n",threshold, countI);
printf("Most frequent word: '%s' with frequency %d\n", maxWord, max);
}// print statement
////////-------------------------------------->

