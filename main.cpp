#include <iostream>
#include <string.h>
#include <dirent.h>
#include "linked_list.h"
#include "lexi.h"

using namespace std;

struct tokenType{
    char type[16];
    int frequency = 0;
};

int main() {
    FILE *fp;
    DIR* dir;
    strNode *head, headNode;
    head = &headNode;
    char nameBuffer[16] = "\\", directory[64], dirBuffer[64], fileBuffer[1048576], c, tokenBuffer[16], *bufferP;
    bufferP = &tokenBuffer[0];
    struct dirent* entity;
    struct tokenType key, op, spc, id, st, co, arr;
    int i;

    strcpy(key.type, "KEYWORD");
    strcpy(op.type, "OPERATOR");
    strcpy(spc.type, "SP CHAR");
    strcpy(id.type, "IDENTIFIER");
    strcpy(st.type, "STRING");
    strcpy(co.type, "CONSTANT");
    strcpy(arr.type, "ARRAY");

    cout << "Enter fileDir >> ";
    gets(directory);
    strcpy(dirBuffer, directory);
    dir = opendir(directory);

    if(dir == NULL){
        cout << "Directory does not exist!!!";
        exit(0);
    }

    entity = readdir(dir);
    while(entity != NULL){
        strcat(nameBuffer, entity->d_name);
        strcat(dirBuffer, nameBuffer);

        fp = fopen(dirBuffer,"r");
        if(fp){
            cout << endl << dirBuffer << "   **********" << endl;
            i=0;
            while ((c = getc(fp)) != EOF) {
                fileBuffer[i] = c;
                i++;
            }

            bufferP = strtok(fileBuffer, " \t\n");
            while(bufferP != NULL){
                appendStr(&head, bufferP);
                bufferP = strtok(NULL, " \t\n");
            }

            while(head->next != NULL){
                cout << head->next->str << endl;
                if(isKeyword(head->next->str)){
                    key.frequency++;
                }
                else if(isOperator(head->next->str)){
                    op.frequency++;
                }
                else if(isSpChar(head->next->str)){
                    spc.frequency++;
                }
                else if(!strcmp(head->next->str, "[")){
                    arr.frequency++;
                }
                else if(isString(head->next->str)){
                    st.frequency++;
                }
                else{
                    id.frequency++;
                }


                head = head->next;
            }

            cout << "TOKEN COUNT FOR FILE >>" << endl;
            cout << key.type << "\t\t>>" << key.frequency << endl;
            cout << op.type << "\t>>" << op.frequency << endl;
            cout << spc.type << "\t\t>>" << spc.frequency << endl;
            cout << arr.type << "\t\t>>" << arr.frequency << endl;
            cout << st.type << "\t\t>>" << st.frequency << endl;
            cout << id.type << "\t>>" << id.frequency << endl;

        }
        strcpy(dirBuffer, directory);
        strcpy(nameBuffer, "\\");
        entity = readdir(dir);
    }

    exit(0);
}
