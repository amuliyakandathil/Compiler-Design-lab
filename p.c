#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contain (char a[15],char b[20][20],int n)
{
    for (int i=0;i<n;i++)
    {
        if(strcmp(b[i],a)==0)
        {
            return -1;
        }
    }
    return 1;
}

void main() {
    char bfr[15], id[20][20], key[20][20], op[20][20],c1[20][20];
    char c;
    FILE *fp1,*fp2;
    int i = 0, id_count = 0, key_count = 0, op_count = 0,con_count=0;

    fp1 = fopen("input.txt", "r");
    if (fp1 == NULL) {
        printf("Unable to open file\n");
        return;
    }

    while ((c = fgetc(fp1)) != EOF) {

        start:
        if (c == '\n' || c == '\t' || c == '{' || c == ' '|| c == '('|| c == '}'|| c == ')'|| c == ';') {
            continue;
        }
        if(c>='0'&&c<='9')
        {
            i=0;
            bfr[i++]=c;
            while((c = fgetc(fp1))>='0'&&c<='9' && c!=';')
            {
                bfr[i++]=c;
            }
            bfr[i] = '\0';
            i = 0;
            if(contain(bfr,c1,con_count)==1)
            {
                strcpy(c1[con_count], bfr);
                con_count++;
            }
            goto start;

        } 
        else if (c == 'i') {
            bfr[i++] = c;
            c = fgetc(fp1);
            if (c == 'f') 
            {
                bfr[i++] = c;
                c = fgetc(fp1);
                if (c == ' ' || c == '(')
                {
                    bfr[i] = '\0';
                    i = 0;
                    if(contain(bfr,key,key_count)==1)
                    {
                        strcpy(key[key_count], bfr);
                        key_count++;
                    }
                } 
                else 
                {
                    goto identify;
                }
            } 
            else if (c == 'n') 
            {
                bfr[i++] = c;
                c = fgetc(fp1);
                if (c == 't') 
                {
                    bfr[i++] = c;
                    c = fgetc(fp1);
                    if (c == ' ' || c == '(' || c == '=') 
                    {
                        bfr[i] = '\0';
                        i = 0;
                        if(contain(bfr,key,key_count)==1)
                        {
                            strcpy(key[key_count], bfr);
                            key_count++;
                        }
                        if (c == '=') 
                        {
                            goto opertr;
                        }
                    }
                    else
                    {
                        goto identify;
                    }
                } 
                else 
                {
                    goto identify;
                }
            } 
            else 
            {
                goto identify;
            }
        } 
        else if (c == 'e') 
        {
            bfr[i++] = c;
            c = fgetc(fp1);
            if (c == 'l') 
            {
                bfr[i++] = c;
                c = fgetc(fp1);
                if (c == 's') 
                {
                    bfr[i++] = c;
                    c = fgetc(fp1);
                    if (c == 'e') 
                    {
                        bfr[i++] = c;
                        c = fgetc(fp1);
                        if (c == ' ' || c == '(' || c == '='|| c == '\n') 
                        {
                            bfr[i] = '\0';
                            i = 0;
                            if(contain(bfr,key,key_count)==1)
                            {
                                strcpy(key[key_count], bfr);
                                key_count++;
                            }
                            if (c == '=') 
                            {
                                goto opertr;
                            }
                        } 
                        else 
                        {
                            goto identify;
                        }
                    } 
                    else 
                    {
                        goto identify;
                    }
                } 
                else 
                {
                    goto identify;
                }
            } 
            else 
            {
                goto identify;
            }
        } 
        else if (c == 'v') 
        {
            bfr[i++] = c;
            c = fgetc(fp1);
            if (c == 'o') 
            {
                bfr[i++] = c;
                c = fgetc(fp1);
                if (c == 'i') 
                {
                    bfr[i++] = c;
                    c = fgetc(fp1);
                    if (c == 'd') 
                    {
                        bfr[i++] = c;
                        c = fgetc(fp1);
                        if (c == ' ' || c == '(' || c == '=') 
                        {
                            bfr[i] = '\0';
                            i = 0;
                            if(contain(bfr,key,key_count)==1)
                            {
                                strcpy(key[key_count], bfr);
                                key_count++;
                            }
                            if (c == '=') 
                            {
                                goto opertr;
                            }
                        } 
                        else 
                        {
                            goto identify;
                        }
                    } 
                    else 
                    {
                        goto identify;
                    }
                } 
                else 
                {
                    goto identify;
                }
            } 
            else 
            {
                goto identify;
            }
        } 
        else if (c == '=') 
        {
            opertr:bfr[i++] = c;
            c = fgetc(fp1);
            if (c == '=' || c == '+' || c == '-') 
            {
                bfr[i++] = c;
                bfr[i] = '\0';
                i = 0;
                if(contain(bfr,op,op_count)==1)
                { 
                    strcpy(op[op_count], bfr);
                    op_count++;
                }
               
            } 
            else 
            {
                bfr[i] = '\0';
                i = 0;
                if(contain(bfr,op,op_count)==1)
                { 
                    strcpy(op[op_count], bfr);
                    op_count++;
                }
                goto start;
            }
        } 
        else 
        {
            identify: bfr[i++] = c;

            while ((c = fgetc(fp1)) != ' ' && c != '\n' && c != '(' && c != ')' && c != ';' && c != ',' && c != '\t' && c != '{' && c != '}'&& c!=EOF && c!='=') 
            {
                bfr[i++] = c;
            }
            bfr[i] = '\0';
            i = 0;
            if(contain(bfr,id,id_count)==1)
            { 
                strcpy(id[id_count], bfr);
                id_count++;
            }
            
            if (c=='=')
            {
                goto opertr;
            }
        }
    }

    fclose(fp1);
    printf("\nKeywords are : ");
    for (int j = 0; j <key_count ; j++) 
    {
        printf("%s\n",key[j]);
    }

    printf("\nIdentifiers are: ");
    fp2=fopen("SymbolTable.txt","w");
    for (int j = 0; j <id_count ; j++) 
    {
        printf("%s\n",id[j]);
        fprintf(fp2,"%s\n",id[j]);
    }
    fclose(fp2);

    printf("\nconstants are : ");
    for (int j = 0; j <con_count ; j++) 
    {
        printf("%s\n",c1[j]);
    }

    printf("\nOperators  are: ");
    for (int j = 0; j <op_count ; j++) 
    {
        printf("%s\n",op[j]);
    }
    


}
/*Keywords
----------------------------
int
float
char
if
else
return

Identifiers are : 

main
radius
area
letter

constants are: 

5
3.14
'A'

Operators are:

=
*
>
*/