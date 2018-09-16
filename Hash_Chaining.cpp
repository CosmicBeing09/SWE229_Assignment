///Hash with Chaining


#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define SIZE 20

using namespace std;


struct DataItem2{
    char *department;
};

struct DataItem
{
    int data;
    int key;
    char *name;
    struct DataItem2 info;
    ///Keep reference of the next data set
    struct DataItem *next = NULL;
};

struct DataItem* dataList[SIZE];
struct DataItem* singleItem;
struct DataItem* item = NULL;

int getHashCode(int key)
{
    ///get the hash
    return key % SIZE;

}

struct DataItem* search(int key)
{
    struct DataItem* temp;
    int hashIndex = getHashCode(key);

    ///Search through the chain if the data is not the first element of the chain
    if(dataList[hashIndex]!=NULL && dataList[hashIndex]->key != key)
    {
        temp = dataList[hashIndex];
        while(temp!=NULL)
        {

            if(temp->key == key)
                return temp;
            else
                temp=temp->next;
        }
    }
    ///Check if the element is on the first of the chain
    else if(dataList[hashIndex]!=NULL && dataList[hashIndex]->key == key)
        return dataList[hashIndex];
    return NULL;

}

void insert(int key,int data,char *name,char *department)
{

    struct DataItem *temp;
    struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;
    item->name = name;
    item->info.department = department;
    item->next = NULL;

    ///get the hash
    int hashIndex = getHashCode(key);

    if(dataList[hashIndex]!=NULL)
    {
        ///If it is the first collision then allocate it right after the first element
        if(dataList[hashIndex]->next == NULL)
        {
            dataList[hashIndex]->next = item;

        }
        ///If the collision isn't first then allocate new data at proper position
        else
        {
            temp = dataList[hashIndex] -> next;
            ///Traverse through the chain for proper position
            while(temp->next!=NULL)
            {
                temp = temp->next;

            }
            temp->next = item;
        }

    }
    ///If no collision then simply allocate at the first position of a chain
    else
    {
        dataList[hashIndex] = item;
        dataList[hashIndex]->next = NULL;
    }
}

struct DataItem* del(struct DataItem* item)
{
    struct DataItem* current;
    struct DataItem* previous;
    if(item == NULL)
        return NULL;
    int key = item->key;

    int hashIndex = getHashCode(key);

    ///If item is on the first of the chain then simply over-write its position by
    ///the second element of the chain
    if(dataList[hashIndex]!=NULL && dataList[hashIndex]->key == key)
    {
        current = dataList[hashIndex]->next;
        dataList[hashIndex] = current;
    }
    ///If item is not the first element of the chain then allocate it properly
    ///and then bypass its location
    else if(dataList[hashIndex]!=NULL && dataList[hashIndex]->key != key)
    {
        current = dataList[hashIndex];
        while(current->key != key)
        {
            ///if it is the last node
            if(current ->next == NULL)
                return NULL;
            else
            {
                ///store reference to current link
                previous = current;
                ///move to next link
                current = current ->next;
            }
        }
        ///bypass the element what we want to delete
        previous -> next = current -> next;
    }
    return NULL;
}

void display()
{
    struct DataItem *temp;
    int i=0;
    for(i=0; i<SIZE; i++)
    {
        if(dataList[i]!= NULL)
        {
            printf("(%d, %d, %s, %s ) ",dataList[i]->key,dataList[i]->data,dataList[i]->name,dataList[i]->info.department);
            ///If there is a chain the proceed
            if(dataList[i]->next != NULL)
            {
                temp=dataList[i]->next;
                while(temp!=NULL)
                {
                    printf("(%d, %d, %s, %s ) ",temp->key,temp->data,temp->name,temp->info.department);
                    temp = temp->next;
                }
            }
        }
        else
            printf(" -- ");
        printf("\n");
    }
    printf("\n");
}
int main()
{
    singleItem = (struct DataItem*)malloc(sizeof(struct DataItem));
    singleItem->data = -1;
    singleItem->key = -1;

    insert(1,20,"Tom","CHE");
    insert(2,70,"Hopper","SWE");
    insert(42,80,"Raihan","CEE");
    insert(4,25,"Nishat","CSE");
    insert(12,44,"Munif","EEE");
    insert(14,32,"Maruf","SOC");
    insert(17,11,"Maruf","PAD");
    insert(13,78,"Partha","BNG");
    insert(37,97,"Imtiaz","ENG");
    insert(47,31,"Arafat","CEP");
    insert(62,77,"Sazzad","ECO");
    insert(77,97,"Ishan","FET");
    //insert(82,77,"Himu","FES");
    insert(97,57,"Shamim","ARC");
    insert(107,66,"Anik","PHY");
    //insert(102,88,"Rupa","MEE");
    insert(122,99,"Prothik","IPE");
    insert(142,93,"Nayeem","SOC");
    display();
    item = search(97);
    if(item != NULL)
        printf("Found: (%d, %d, %s )\n",item->key,item->data,item->name);
    else
        printf("Not Found\n");
    printf("\nAfter deletion: \n");


    ///Deleting last element of a chain
    del(item);
    display();



    item = search(37);
    ///Deleting any element of a chain
    printf("\nAfter deletion: \n");
    del(item);
    display();

    item = search(2);

    ///Deleting first element of a chain
    printf("\nAfter deletion: \n");
    del(item);
    display();
    return 0;
}



