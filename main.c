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
    StrList* list;

    while (action != 0) {
        switch (action) {
            case 1:
                list = StrList_alloc();
                break;
            case 2:
                int ind = -1;

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            case 10:

                break;
            case 11:

                break;
            case 12:

                break;
            case 13:

                break;
        }
        scanf("%d",&action);
    }
    StrList_free(list);

    return 0;
}
