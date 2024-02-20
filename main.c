#include <stdio.h>
#include <string.h>
#include "strList.h"

void splitWords(char *str, StrList *list);
void cleanInputBuffer();
char* getWord(char *str);


int main() {

    int action = -1;
    scanf("%d",&action);
    char *line = NULL;
    size_t len = 0;
    size_t wordsNumber = 0;
    size_t lineSize = 0;
    StrList *list = StrList_alloc();

    while (action != 0) {
        if (action == 1) { // insert multiple words at end
            scanf("%zd",&wordsNumber);
            cleanInputBuffer();
            lineSize = getline(&line, &len, stdin);
            if (lineSize != -1) {
                splitWords(line, list);
            }
        } else if (action == 2) { // insert single word at given index
            int index = -1;
            scanf("%d",&index);
            cleanInputBuffer();
            lineSize = getline(&line, &len, stdin);
            if (lineSize != -1) {
                char* token = getWord(line);
                StrList_insertAt(list, token, index);
            }
        } else if (action == 3) {   //print list
            StrList_print(list);
        } else if (action == 4) { // print size
            printf("%zu\n", StrList_size(list));
        } else if (action == 5) { // print word at given index
            int index = -1;
            scanf("%d",&index);
            StrList_printAt(list,index);
        } else if (action == 6) { // print total character count
            printf("%d\n", StrList_printLen(list));
        } else if (action == 7) {  //print number of appearances of a word in the list
            cleanInputBuffer();
            lineSize = getline(&line, &len, stdin);
            if (lineSize != -1) {
                char* token = getWord(line);
                printf("%d\n", StrList_count(list,token));
            }
        } else if (action == 8) { // remove all appearances of given word in list
            cleanInputBuffer();
            lineSize = getline(&line, &len, stdin);
            if (lineSize != -1) {
                char* token = getWord(line);
                StrList_remove(list,token);
            }
        } else if (action == 9) { // removes a word at given index
            int index = -1;
            scanf("%d",&index);
            StrList_removeAt(list,index);
        } else if (action == 10) { // reverse the list
            StrList_reverse(list);
        } else if (action == 11) { // clear list
            while (StrList_size(list)) {
                StrList_removeAt(list,0);
            }
        } else if (action == 12) { // sort
            StrList_sort(list);
        } else if (action == 13) { // is sorted
            if (StrList_isSorted(list)) printf("true\n");
            else printf("false\n");
        }
        scanf("%d",&action);
    }
    StrList_free(list);
    free(line);

    return 0;
}

void splitWords(char *str, StrList *list) {
    char *token = strtok(str, " ");
    while (token != NULL) {
        //printf("%s\n", token);
        int last = strlen(token)-1;
        if (token[last] == 10) { token[last] = '\0'; }
        StrList_insertLast(list, token);
        token = strtok(NULL, " ");
    }
}
void cleanInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Discard characters until newline or end-of-file
    }
}
char* getWord(char *str) {
    char *token = strtok(str, " ");
    unsigned last = strlen(token)-1;
    if (token[last] == 10) { token[last] = '\0'; }
    return token;
}

