#include <stdio.h>
#include "strList.h"

char* inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n' && ch != ' '){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';
    return realloc(str, sizeof(*str)*len);
}

int main() {

    int action = -1;
    scanf("%d",&action);
    StrList *list = NULL;

    while (action != 0) {
        if (action == 1) {
            while (StrList_size(list)) {
                StrList_removeAt(list,0);
            }
            // input
        } else if (action == 2) {
            int index = -1;
            scanf("%d",&index);
            // input data
            //StrList_insertAt(list,data,index);
        } else if (action == 3) {
            StrList_print(list);
        } else if (action == 4) {
            printf("%zu", StrList_size(list));
        } else if (action == 5) {
            int index = -1;
            scanf("%d",&index);
            StrList_printAt(list,index);
        } else if (action == 6) {
            printf("%d", StrList_printLen(list));
        } else if (action == 7) {
            // input data
            // printf("%d", StrList_count(list,data));
        } else if (action == 8) {
            // input data
            // StrList_remove(list,data);
        } else if (action == 9) {
            int index = -1;
            scanf("%d",&index);
            StrList_removeAt(list,index);
        } else if (action == 10) {
            StrList_reverse(list);
        } else if (action == 11) {
            while (StrList_size(list)) {
                StrList_removeAt(list,0);
            }
        } else if (action == 12) {
            StrList_sort(list);
        } else if (action == 13) {
            printf("%d", StrList_isSorted(list)); // TODO what to print
        }
        scanf("%d",&action);
    }
    StrList_free(list);

    return 0;
}
