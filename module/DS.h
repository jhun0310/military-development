//data sturcture module

/*
void push(NODE **ptr, char data) //ptr(head)의 stack에 data를 push함
{
    NODE *tmp;

    if((*ptr) == NULL)
    {
        (*ptr) = (NODE *)malloc(sizeof(NODE));
        (*ptr)->data = data;
        (*ptr)->next_ptr = NULL;
    }
    else
    {
        tmp = (NODE *)malloc(sizeof(NODE));
        tmp->data = data;
        tmp->next_ptr = (*ptr);
        (*ptr) = tmp;
    }

    return;
}

char pop(NODE **ptr) //ptr(head)의 stack에서 데이터 하나를 pop하여 리턴
{
    char data;
    NODE *tmp;

    if((*ptr) == NULL)
    {
        return 0;
    }
    else
    {
        data = (*ptr)->data;
        tmp = (*ptr);
        (*ptr) = (*ptr)->next_ptr;
        free(tmp);
        return data;
    }
}
*/