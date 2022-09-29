/*
* Author: Lee Jhun Hyeok <wnsx0000@gmail.com>
* This program is stack (abstract data type) created for practice using linked list, and text file.
* Stack saves English words.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 10                //maximum word length
#define COMMAND_HEAD_SIZE 10        //maximum head command length


typedef struct node
{
    struct node *next_node_ptr;
    char data[WORD_SIZE];
}DATA_WORD_NODE;


/*
* Function for downloading data as a linked list.
*/
static void stack_download(DATA_WORD_NODE **head_ptr)
{
    char buf[WORD_SIZE] = { 0 };
    DATA_WORD_NODE *tmp_node_ptr = NULL;

    FILE *data_file_ptr;
    if((data_file_ptr = fopen("word_data", "r")) == NULL) //no existing file
    {
        printf("Can't find data file, creating new file...\n"); //when uploading stack
    }
    else
    {
        printf("Data file detected.\n");

        while(fscanf(data_file_ptr, "%s", buf) != (-1))
        {
            if((*head_ptr) == NULL)   // in case of first ptr
            {
                (*head_ptr) = (DATA_WORD_NODE *)malloc(sizeof(DATA_WORD_NODE));

                (*head_ptr)->next_node_ptr = NULL;
                strcpy((*head_ptr)->data, buf);
            }
            else
            {
                tmp_node_ptr = (DATA_WORD_NODE *)malloc(sizeof(DATA_WORD_NODE));
                tmp_node_ptr->next_node_ptr = (*head_ptr);
                strcpy(tmp_node_ptr->data, buf);

                (*head_ptr) = tmp_node_ptr;
            }
        }

        fclose(data_file_ptr);
    }

    return;
}


/*
* Function for executing command.
*/
static void stack_command(DATA_WORD_NODE **head_ptr)
{
    char head_command[COMMAND_HEAD_SIZE] = { 0 };
    char input_data[WORD_SIZE] = { 0 };
    DATA_WORD_NODE *tmp_node_ptr = NULL;
    char buff;
    int oversize = 0; //0: don't have to flush input buffer, 1: need to flush input buffer

    while(1)
    {
        printf("Enter command -> ");
        oversize = 0;

        for(int i = 0; i <= COMMAND_HEAD_SIZE; i++) //getting command
        {
            buff = getchar();

            if((buff == ' ') || (buff == '\n') || (buff == '\r'))
            {
                if(i == COMMAND_HEAD_SIZE)
                {
                    ;
                }
                else
                {
                    head_command[i] = 0;
                }

                break;
            }
            else
            {
                if(i == COMMAND_HEAD_SIZE)
                {
                    oversize = 1;
                    break;
                }
                else
                {
                    head_command[i] = buff;
                }
            }
        }

        if(!strcmp("push", head_command))
        {
            for(int i = 0; i <= WORD_SIZE; i++) //getting command
            {
                buff = getchar();

                if((buff == ' ') || (buff == '\n') || (buff == '\r'))
                {
                    if(i == WORD_SIZE)
                    {
                        ;
                    }
                    else
                    {
                        input_data[i] = 0;
                    }

                    break;
                }
                else
                {
                    if(i == WORD_SIZE)
                    {
                        oversize = 1;
                        printf("Too long word. Input word should be between 1~%d characters. Word was saved only up to %d characters.\n", WORD_SIZE, WORD_SIZE);
                        break;
                    }
                    else
                    {
                        input_data[i] = buff;
                    }
                }
            }

            printf("New data \"%s\" was added to the stack.\n", input_data);

            tmp_node_ptr = (DATA_WORD_NODE *)malloc(sizeof(DATA_WORD_NODE));
            tmp_node_ptr->next_node_ptr = (*head_ptr);
            strcpy(tmp_node_ptr->data, input_data);
            (*head_ptr) = tmp_node_ptr;
        }
        else if(!strcmp("pop", head_command))
        {
            if((*head_ptr) == NULL)
            {
                printf("Stack is empty.\n");
            }
            else
            {
                printf("Top data \"%s\" was deleted.\n", (*head_ptr)->data);

                tmp_node_ptr = (*head_ptr);
                (*head_ptr) = (*head_ptr)->next_node_ptr;
                free(tmp_node_ptr);   
            }
        }
        else if(!strcmp("top", head_command))
        {
            if((*head_ptr) == NULL)
            {
                printf("Stack is empty.\n");
            }
            else
            {
                printf("Top data is \"%s\"\n", (*head_ptr)->data);
            }
        }
        else if(!strcmp("empty", head_command))
        {
            if((*head_ptr) == NULL)
            {
                printf("Stack is empty.\n");
            }
            else
            {
                printf("Stack is NOT empty.\n");
            }
        }
        else if(!strcmp("reset", head_command))
        {
            if((*head_ptr) == NULL)
            {
                printf("Stack is empty.\n");
            }
            else
            {
                printf("Resetting stack...\n");

                while((*head_ptr)->next_node_ptr != NULL)
                {
                    tmp_node_ptr = (*head_ptr);
                    (*head_ptr) = (*head_ptr)->next_node_ptr;
                    free(tmp_node_ptr);
                }

                free((*head_ptr));
                (*head_ptr) = NULL;
            }
        }
        else if(!strcmp("total", head_command))
        {
            if((*head_ptr) == NULL)
            {
                printf("Stack is empty.\n");
            }
            else
            {
                printf("Printing all data...\n<top>\n");

                tmp_node_ptr = (*head_ptr);

                do
                {
                    printf("%s\n", tmp_node_ptr->data);
                    tmp_node_ptr = tmp_node_ptr->next_node_ptr;
                } while(tmp_node_ptr != NULL);

                printf("<bottom>\n");
            }
        }
        else if(!strcmp("end", head_command))
        {
            break;
        }
        else
        {
            printf("Wrong Command.\n");
        }

        if(oversize == 1) //flushing input buffer
        {
            while(getchar() != '\n')
            {
                ;
            }
        }
    }

    return;
}


/*
* Function for uploading data as a linked list.
*/
static void stack_upload(DATA_WORD_NODE **head_ptr)
{
    DATA_WORD_NODE *tmp_node_ptr = NULL;
    DATA_WORD_NODE *tmp_node_ptr_2 = NULL;
    FILE *data_file_ptr;

    data_file_ptr = fopen("word_data", "w");

    if((*head_ptr) == NULL)
    {
        ;
    }
    else
    {
        while(1) //printing on text file
        {
            tmp_node_ptr = (*head_ptr);
            tmp_node_ptr_2 = NULL;

            while(tmp_node_ptr->next_node_ptr != NULL)
            {
                tmp_node_ptr_2 = tmp_node_ptr;
                tmp_node_ptr = tmp_node_ptr->next_node_ptr;
            }

            fprintf(data_file_ptr, "%s ", tmp_node_ptr->data);
            free(tmp_node_ptr);

            if(tmp_node_ptr_2 != NULL)
            {
                tmp_node_ptr_2->next_node_ptr = NULL;
            }
            else
            {
                break;
            }
        }
    }

    fclose(data_file_ptr);

    return;
}


int main(void)
{
    DATA_WORD_NODE *head_ptr = NULL; //head pointer for linked list

    /*
    * stack download
    * Because this program saves data as a text file, this part downloads the file as a linked list.
    */
    stack_download(&head_ptr);
    

    /*
    * stack management commands
    */
    char head_command[COMMAND_HEAD_SIZE] = { 0 };

    printf("<Stack Management Program>\n");

    stack_command(&head_ptr);


    /* 
    * stack upload
    * Saving data in the linked list as a text file.
    */
    stack_upload(&head_ptr);
    

    return 0;
}