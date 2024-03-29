#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node   //node of Binary tree storing character, its frequency and adress of children nodes
{
        char ch;
        int freq;
        struct node *left;
        struct node *right;
}node;

node * heap[100];
int heapSize = 0;
void insert(node * t)
{
        heapSize++;
        heap[heapSize] = t;
        int n = heapSize;
        while(heap[n/2] -> freq > t -> freq)
        {
                heap[n] = heap[n/2];
                n = n/2;
        }
        heap[n] = t;
}
node * DeleteMin()    
{
        node * minElement,*lastElement;
        int child,n;
        minElement = heap[1];
        lastElement = heap[heapSize--];
        for(n = 1; n*2 <= heapSize ; n = child)
        {
             child = n*2;
                 if(child != heapSize && heap[child+1]->freq < heap[child] -> freq )
                {
                        child++;
                }
                if(lastElement -> freq > heap[child] -> freq)
                {
                        heap[n] = heap[child];
                }
                else
                {
                        break;
                }
        }
        heap[n] = lastElement;
        return minElement;
}
void print(node *temp,char *c)  //function to print huffman compression codes
{
        if(temp->left == NULL && temp->right == NULL)
        {
                printf("char %c code %s\n",temp->ch,c);
                return;
        }
        int length = strlen(c);
        char leftcode[10],rightcode[10];
        strcpy(leftcode,c);
        strcpy(rightcode,c);
        leftcode[length] = '0';
        leftcode[length+1] = '\0';
        rightcode[length] = '1';
        rightcode[length+1] = '\0';
        print(temp->left,leftcode);
        print(temp->right,rightcode);
}
int main()   //main function to implement above functions
{

       heap[0] = (node *)malloc(sizeof(node));
        heap[0]->freq = 0;
        int n;
        printf("Enter the no of characters: ");
        scanf("%d",&n);
        printf("Enter the characters and their frequencies: ");
        char ch;
        int freq,i;

        for(i = 0; i < n; i++)
        {
                scanf(" %c",&ch);
                scanf("%d",&freq);
                if(freq < 0)
                {   printf("Frequency of %c cannot be negative, hence taking its absolute value\n",ch);
                    freq = abs(freq);
                }
                node * temp = (node *) malloc(sizeof(node));
                temp -> ch = ch;
                temp -> freq = freq;
                temp -> left = temp -> right = NULL;
                insert(temp);
        }
        if(n == 1)
        {
                printf("char %c code 0\n",ch);
                return 0;
        }
        for(i = 0; i < n-1 ; i++)
        {
                node * left = DeleteMin();
                node * right = DeleteMin();
                node * temp = (node *) malloc(sizeof(node));
                temp -> ch = 0;
                temp -> left = left;
                temp -> right = right;
                temp -> freq = left->freq + right -> freq;
                insert(temp);
        }
        node *tree = DeleteMin();
        char code[10];
        code[0] = '\0';
        print(tree,code);



}