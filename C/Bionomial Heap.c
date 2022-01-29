//code used for reference: https://www.sanfoundry.com/c-program-implement-binomial-heap/

#include<stdio.h>
#include<malloc.h>
 
struct node
{
    int n;
    int degree;
    struct node *parent;
    struct node *child;
    struct node *sibling;
};
 
int count=1;
 
struct node *makeHeap()
{
    struct node *np;
    np=NULL;
    return np;
}
 
struct node *h=NULL;
struct node *hdash=NULL;
 
int binomialLink(struct node *y, struct node *z)
{
    y->parent=z;
    y->sibling=z->child;
    z->child=y;
    z->degree=z->degree+1;
}
 
struct node *createNode(int k)
{
    struct node *p;//new node;
    p=(struct node*)malloc(sizeof(struct node));
    p->n=k;
    return p;
}

struct node *heapMerge(struct node *h1, struct node *h2)
{
    struct node *h=makeHeap();
    struct node *y;
    struct node *z;
    struct node *a;
    struct node *b;
    y=h1;
    z=h2;
    if (y!=NULL)
    {
        if(z!=NULL && y->degree<=z->degree)
            h=y;
        else if(z!=NULL && y->degree>z->degree)
            h=z;
        else
            h=y;
    }
    else
        h=z;
    while (y!=NULL && z!=NULL)
        if(y->degree<z->degree)
            y=y->sibling;
        else if(y->degree==z->degree)
        {
            a=y->sibling;
            y->sibling=z;
            y=a;
        }
        else
        {
            b=z->sibling;
            z->sibling=y;
            z=b;
        }
    return h;
}

struct node *heapUnion(struct node *h1, struct node *h2)
{
    struct node *previous;
    struct node *next;
    struct node *x;
    struct node *h=makeHeap();
    h=heapMerge(h1, h2);
    if (h==NULL)
        return h;
    previous=NULL;
    x=h;
    next=x->sibling;
    while(next!=NULL)
    {
        if((x->degree!=next->degree) || ((next->sibling!=NULL)&&(next->sibling)->degree==x->degree))
        {
            previous=x;
            x=next;
        }
        else 
            if(x->n<=next->n)
            {
                x->sibling=next->sibling;
                binomialLink(next, x);
            }
            else
            {
                if(previous==NULL)
                    h=next;
                else
                    previous->sibling=next;
                binomialLink(x, next);
                x=next;
            }
        next=x->sibling;
    }
    return h;
}
 
struct node *heapInsert(struct node *h, struct node *x)
{
    struct node *h1=makeHeap();
    x->parent=NULL;
    x->child=NULL;
    x->sibling=NULL;
    x->degree=0;
    h1=x;
    h=heapUnion(h, h1);
    return h;
}
 

int display(struct node *h)
{
    struct node *p;
    if(h==NULL)
    {
        printf("\nHeap is empty.");
        return 0;
    }
    printf("\nThe root nodes of the binomial heap are: \n");
    p=h;
    while(p!=NULL)
    {
        printf("%d", p->n);
        if (p->sibling!=NULL)
            printf("-->");
        p=p->sibling;
    }
}

int revertList(struct node *y)
{
    if(y->sibling!=NULL)
    {
        revertList(y->sibling);
        (y->sibling)->sibling=y;
    }
    else
        hdash=y;
}

struct node *extractMinimim(struct node *h1)
{
    int min;
    struct node *t=NULL;
    struct node *x=h1;
    struct node *hdash;
    struct node *p;
    hdash=NULL;
    if(x==NULL)
    {
        printf("\nHeap is empty, nothing to extract.");
        return x;
    }
    p=x;
    while(p->sibling!=NULL)
    {
        if((p->sibling)->n<min)
        {
            min=(p->sibling)->n;
            t=p;
            x=p->sibling;
        }
        p=p->sibling;
    }
    if(t==NULL && x->sibling==NULL)
        h1=NULL;
    else if (t==NULL)
        h1=x->sibling;
    else if (t->sibling==NULL)
        t=NULL;
    else
        t->sibling=x->sibling;
    if(x->child!=NULL)
    {
        revertList(x->child);
        (x->child)->sibling=NULL;
    }
    h=heapUnion(h1, hdash);
    return x;
}
 
struct node *findNode(struct node *h, int k)
{
    struct node *x=h;
    struct node *p=NULL;
    if(x->n==k)
    {
        p=x;
        return p;
    }
    if(x->child!=NULL && p==NULL)
        p=findNode(x->child, k);
    if(x->sibling!=NULL && p==NULL)
        p=findNode(x->sibling, k);
    return p;
}
 
int decreaseKey(struct node *h, int i, int k)
{
    int temp;
    struct node *p;
    struct node *y;
    struct node *z;
    p=findNode(h, i);
    if(p==NULL)
    {
        printf("\nERROR! Key not found in the heap.");
        return 0;
    }
    if(k>p->n)
    {
        printf("\nERROR! New key is greater than current one.");
        return 0;
    }
    p->n=k;
    y=p;
    z=p->parent;
    while(z!=NULL&&y->n<z->n)
    {
        temp=y->n;
        y->n=z->n;
        z->n=temp;
        y=z;
        z=z->parent;
    }
    printf("\nKey reduced successfully.");
}
 
int delete(struct node *h, int k)
{
    struct node *np;
    if(h==NULL)
    {
        printf("\nHeap is empty.");
        return 0;
    }
    decreaseKey(h, k, -1000);
    np=extractMinimim(h);
    if(np!=NULL)
        printf("\nNode deleted successfully.");
}
 
int main()
{
    int i, n, m, l;
    struct node *p;
    struct node *np;
    char ch;
    printf("----------------------------\n");
    printf("Binomial Heap Implementation\n");
    printf("----------------------------\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter values:\n");
    for(i=1; i<=n; i++)
    {
        scanf("%d", &m);
        np=createNode(m);
        h=heapInsert(h, np);
    }
    display(h);
    do
    {
        printf("\n\n-------------MENU--------------");
        printf("\n1. Insert an element");
        printf("\n2. Extract the minimum key node");
        printf("\n3. Decrease a node value");
        printf("\n4. Delete a node");
        printf("\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &l);
        switch(l)
        {
            case 1:
                do
                {
                    printf("\nEnter element to be inserted: ");
                    scanf("%d", &m);
                    p = createNode(m);
                    h = heapInsert(h, p);
                    printf("\nCurrent state of heap: \n");
                    display(h);
                    printf("\nDo you want to insert more? (Y|y): ");
                    fflush(stdin);
                    scanf("%c", &ch);
                }while (ch=='Y' || ch=='y');
                break;
            case 2:
                do
                {
                    printf("\nExtracting minimum key node...");
                    p=extractMinimim(h);
                    if (p!=NULL)
                        printf("\nNode extracted: %d", p->n);
                    printf("\nCurrent state of heap:\n");
                    display(h);
                    printf("\nDo you want to extract more? (Y|y): ");
                    fflush(stdin);
                    scanf("%c", &ch);
                }while(ch=='Y' || ch=='y');
                break;
            case 3:
                do
                {
                    printf("\nEnter the key of the node to be decreased: ");
                    scanf("%d", &m);
                    printf("\nEnter the new key: ");
                    scanf("%d", &l);
                    decreaseKey(h, m, l);
                    printf("\nCurrent state of heap: \n");
                    display(h);
                    printf("\nDo you want to decrease more? (Y|y): ");
                    fflush(stdin);
                    scanf("%c", &ch);
                } while (ch=='Y' || ch=='y');
                break;
            case 4:
                do
                {
                    printf("\nEnter the key to be deleted: ");
                    scanf("%d", &m);
                    delete(h, m);
                    printf("\nWould you like to delete more? (Y|y): ");
                    fflush(stdin);
                    scanf("%c", &ch);
                }while (ch=='y' || ch=='Y');
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
            printf("\nInvalid entry! Try again.\n");
        }
    }while(l!=5);
}