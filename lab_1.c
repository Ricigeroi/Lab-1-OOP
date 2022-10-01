#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_pos();
void searchElement();
void sortList();
void writeLinkedList();
void readLinkedList();
void insert();
void reverse();


struct node* head = NULL;
struct node
{
	int data;
	struct node* next;
};
int main()
{
	int choice;
	while(1)
	{
	    printf("\n*****\n");
	    printf("0. Reverse the list\n");
	    printf("1. display\n");
	    printf("2. Insert Node at beginning\n");
	    printf("3. Insert Node in specific position\n");
	    printf("4. Insert Node at end of LinkedList\n");
	    printf("5. Search an element\n");
	    printf("6. Sort the list\n");
	    printf("7. Delete Node at position\n");
	    printf("8. Save list to file\n");
			printf("9. Load list from a file\n");


		printf("\n Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0: reverse();
					break;
			case 1: display();
					break;
			case 2: insert_begin();
					break;
			case 3: insert_pos();
					break;
			case 4: insert_end();
					break;
			case 5: searchElement();
					break;
			case 6: sortList();
					break;
			case 7: delete_pos();
					break;
			case 8: writeLinkedList();
					break;
			case 9: readLinkedList();
					break;

			default:printf("\n Wrong Choice");
                    break;
		}
	}
}

void reverse()
{
    struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; // Make first node as last node

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; // Make last node as head

        printf("Successfuly reversed list\n");
    }
}

//creates a node
void create()
{
	struct node* temp;
        //creating new node
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->next = NULL;
	if(head==NULL)	{
		head = temp;
	}
	else{
		struct node* ptr = head;
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp; //inserting at end of List
	}
}

void readLinkedList()
{
	FILE *file = fopen("input.txt", "r");
	int info;
	while (fscanf(file, "%d", &info) != EOF) {
			insert(info);
	}
	fclose(file);
}


// prints the entire LinkedList
void display()
{
	if(head==NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
        printf("LinkedList: ");
	struct node* ptr = head;
	while(ptr!=NULL) // start from first node
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
    printf("\n");
}

// function to write linked list to a file
void writeLinkedList()
{
    struct node* ptr = head;
    FILE* file;
    file = fopen ("output.txt", "w");
    if (file == NULL)
    {
        fprintf(stderr, "\nCouldn't Open File'\n");
        exit (1);
    }
    // writing all the nodes of the linked list to the file
    while(ptr!=NULL)
    {
        fprintf(file, "%d ", ptr->data);
        ptr = ptr->next;
    }
    fclose(file);
}

void searchElement()
{
    struct node* ptr = head;  // Initialize current
    int index = 0;
    // traverse till then end of the linked list
    int item;
    printf("Enter element to search: ");
    scanf("%d", &item);
    while (ptr != NULL)
    {
        if (ptr->data == item){
            printf("Item found at position: %d\n", index);
            break;
        }
        ptr = ptr->next;
        index++;
    }
    if((ptr == NULL) && (index!=0)){
        printf("Item not found\n");
    }
}

void sortList() {
       //Node current will point to head
       struct node *ptr = head, *index = NULL;
       int temp;

       if(head == NULL) {
           return;
       }
       else {
           while(ptr != NULL) {
               //Node index will point to node next to current
               index = ptr->next;

               while(index != NULL) {
                   //If current node's data is greater than index's node data, swap the data between them
                   if(ptr->data > index->data) {
                       temp = ptr->data;
                       ptr->data = index->data;
                       index->data = temp;
                   }
                   index = index->next;
               }
               ptr = ptr->next;
           }
       }
   }

// to insert node at start of LinkedList
void insert_begin()
{
	struct node* temp;
        // creating a new node
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->next = NULL;
	if(head==NULL)
	{
		head = temp;
		return;
	}
	else
	{
		temp->next = head; //point it to old head node
		head = temp; //point head to new first node
	}
}
// to insert node at given position
void insert_pos()
{
	struct node* temp;
        // creating a new node
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->next = NULL;
	if(head==NULL) // if list empty we return
	{
		head = temp;
	        return;
	}
	else
	{
		struct node* prev_ptr;
		struct node* ptr = head;
		int pos;
		printf("Enter position: ");
		scanf("%d",&pos);
		for(int i=0;i<pos;i++)
		{
			prev_ptr = ptr;
			ptr = ptr->next;
		}
                //new node pointing to node in that pos
		temp->next = ptr;
                //prevptr pointing to new node
		prev_ptr->next = temp;
	}
}
// to insert node at end of LinkedList
void insert_end()
{
	struct node* temp;
        //creating new node
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->next = NULL;
	if(head==NULL)
	{
		head = temp; //if list is empty, we return
	        return;
	}
	else{
		struct node* ptr = head;
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
               // tail node pointing to new node
		ptr->next = temp;
	}
}

// to delete node at given position
void delete_pos()
{
	int pos;
	printf("Enter node position to delete: ");
	scanf("%d",&pos);
	struct node* ptr=head;
	if(head==NULL) //we return if List is empty
	{
		printf("Linked List is empty \n");
		return;
	}
	else if(pos == 0)
	{
		ptr = head;
		head=ptr->next; // head pointing to second node
		free(ptr); // deleting old first node
	}
	else
	{
		struct node* prev_ptr;
		for(int i=0;i<pos;i++)
		{
			prev_ptr = ptr;
			ptr = ptr->next;
		}
		prev_ptr->next = ptr->next; //prev node pointing to pos+1 node
		free(ptr); //deleting node at pos
	}
}



void insert(int data)
{
	struct node* temp;
        //creating new node
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	if(head==NULL)
	{
		head = temp; //if list is empty, we return
	        return;
	}
	else{
		struct node* ptr = head;
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
               // tail node pointing to new node
		ptr->next = temp;
	}
}
