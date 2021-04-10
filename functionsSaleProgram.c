#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"saleProgram.h"
#include<stdbool.h>
#include<math.h>
#include<locale.h>

//product fucts 
void insertProduct(ProductPtr *pPtr, int p_ID, char* p_name, int p_type, double p_price)
{
	ProductPtr newPtr; // pointer to new node
	ProductPtr previousPtr; // pointer to previous node in list
	ProductPtr currentPtr; // pointer to current node in list
	
	newPtr = malloc( sizeof( Product ) ); // create node

	if ( newPtr != NULL ) { // is space available
		newPtr->ID = p_ID; // place value in node
        strcpy(newPtr->name,p_name);
        newPtr->type = p_type;
        newPtr->price = p_price;
		newPtr->nextProPtr = NULL; // node does not link to another node

		previousPtr = NULL;
		currentPtr = *pPtr;

		// loop to find the correct location in the list
		while ( currentPtr != NULL) {
			previousPtr = currentPtr; // walk to ...
			currentPtr = currentPtr->nextProPtr; // ... next node
		} // end while
		// insert new node at beginning of list
		if ( previousPtr == NULL ) {
			newPtr->nextProPtr = *pPtr;
			*pPtr = newPtr;
		} // end if
		else { // insert new node between previousPtr and currentPtr
			previousPtr->nextProPtr = newPtr;
			newPtr->nextProPtr = currentPtr;
		} // end else
	} // end if
	else {
		printf( "%d not inserted. No memory available.\n", p_ID );
	} // end else
} // end function insert

int deleteProduct(ProductPtr *pPtr, int p_ID)
{
	ProductPtr previousPtr; // pointer to previous node in list
	ProductPtr currentPtr; // pointer to current node in list
	ProductPtr tempPtr; // temporary node pointer

	// delete first node
	if ( p_ID == ( *pPtr )->ID ) {
		tempPtr = *pPtr; // hold onto node being removed
		*pPtr = ( *pPtr )->nextProPtr; // de-thread the node
		free( tempPtr ); // free the de-threaded node
		return p_ID;
	} // end if
	else {
		previousPtr = *pPtr;
		currentPtr = ( *pPtr )->nextProPtr;

		// loop to find the correct location in the list
		while ( currentPtr != NULL && currentPtr->ID != p_ID ) {
			previousPtr = currentPtr; // walk to ...
			currentPtr = currentPtr->nextProPtr; // ... next node
		} // end while
		
		// delete node at currentPtr
		if ( currentPtr != NULL ) {
			tempPtr = currentPtr;
			previousPtr->nextProPtr = currentPtr->nextProPtr;
			free( tempPtr );
			return p_ID;
		} // end if
	 } // end else
	 return '\0';
} // end function delete

int isEmptyProduct(ProductPtr pPtr)
{
    return pPtr == NULL;
}

void printProduct(ProductPtr currentPtr)
{ 
	int counter=0;
	// if list is empty
	if ( isEmptyProduct(currentPtr) ) {
		puts( "List is empty.\n" );
	} // end if
	else {
		puts( "The product list is:" );

		// while not the end of the list
		while ( currentPtr != NULL ) {
			printf("ID: %d\nName: %s\nType: %d\nPrice: %f"
            ,currentPtr->ID,currentPtr->name,currentPtr->type,currentPtr->price);
            printf("\n\t|\n\t|\n\t|\n\tV\n");
			currentPtr = currentPtr->nextProPtr;
			counter++;
		} // end while

		puts( "\tNULL\n" );
		printf( "%d\n", counter );
	} // end else
} // end function printCustomer

void findProductID(ProductPtr pPtr,char* name)
{
	ProductPtr previousPtr; // pointer to previous node in list
	ProductPtr currentPtr; // pointer to current node in list
	previousPtr = NULL;
	currentPtr = pPtr;
	
	if (isEmptyProduct(pPtr)) // conrol puchadesed list
		printf("The list is empty\n");
	else
	{
		while (currentPtr != NULL ) {
			if(strcmp(name,(currentPtr->name)) == 0) //compare name
			{
				printf("%s ID is: %d\n",name,(currentPtr->ID));
				break;
			}
			else
			{
				previousPtr = currentPtr; // walk to ...
				currentPtr = currentPtr->nextProPtr; // ... next node
			}
			
		} // end while
		if (currentPtr == NULL)
		{
			printf("No one %s",name);

		}
		
	}//end  else

}

void printProductType(ProductPtr currentPtr,int type)
{ 
	int counter=0;
	// if list is empty
	if ( isEmptyProduct(currentPtr) ) {
		puts( "List is empty.\n" );
	} // end if
	else {
		puts( "The product list is:" );

		// while not the end of the list
		while ( currentPtr != NULL )
		{
			if (currentPtr->type == type)
			{
				printf("ID: %d\nName: %s\nType: %d\nPrice: %f"
            	,currentPtr->ID,currentPtr->name,currentPtr->type,currentPtr->price);
            	printf("\n\t|\n\t|\n\t|\n\tV\n");
			}
			currentPtr = currentPtr->nextProPtr;
			counter++;
		} // end while

		puts( "\tNULL\n" );
		printf( "%d\n", counter );
	} // end else
} // end function printCustomer

void findProduct(ProductPtr pPtr,char* name)
{
	ProductPtr previousPtr; // pointer to previous node in list
	ProductPtr currentPtr; // pointer to current node in list
	previousPtr = NULL;
	currentPtr = pPtr;
	
	if (isEmptyProduct(pPtr)) // conrol puchadesed list
		printf("The list is empty\n");
	else
	{
		while (currentPtr != NULL ) {
			if(strcmp(name,(currentPtr->name)) == 0) //compare name
			{
				printf("ID: %d\nName: %s\nType: %d\nPrice: %f"
            	,currentPtr->ID,currentPtr->name,currentPtr->type,currentPtr->price);
            	printf("\n\t|\n\t|\n\t|\n\tV\n");
				break;
			}
			else
			{
				previousPtr = currentPtr; // walk to ...
				currentPtr = currentPtr->nextProPtr; // ... next node
			}
			
		} // end while
		if (currentPtr == NULL)
		{
			printf("No one %s",name);

		}
		
	}//end  else

}

void printProductV2(ProductPtr currentPtr,int p_ID) // print product name use product ID
{ 
	int counter=0;
	// if list is empty
	if ( isEmptyProduct(currentPtr) ) {
		puts( "List is empty.\n" );
	} // end if
	else
	{
		// while not the end of the list
		while ( currentPtr != NULL )
		{
			if (currentPtr->ID == p_ID)
			{
				printf("Product Name: %s\n",currentPtr->name);
			}
			
			
			currentPtr = currentPtr->nextProPtr;
			counter++;
		} // end while

	} // end else
} // end function printCustomer

void insertProductV2(ProductPtr *pPtr)
{
	int ID = getInt("ID giriniz: ");
	char *name = getString("İsim giriniz: ");
	int type = getInt("Müşteri tipi giriniz: ");
	float price =  getFloat("Fiyat giriniz: ");
	insertProduct(pPtr,ID,name,type,price);
}

/*float findProductCost(ProductPtr pPtr,int p_ID)
{
	ProductPtr previousPtr; // pointer to previous node in list
	ProductPtr currentPtr; // pointer to current node in list
	previousPtr = NULL;
	currentPtr = pPtr;
	
	if (isEmptyProduct(pPtr)) // conrol puchadesed list
	{
		printf("The list is empty\n");
		return 0;
	}
	else
	{
		while (currentPtr != NULL )
		{
			if(currentPtr->ID == p_ID) //compare name
			{
				return (currentPtr->price);
				break;
			}
			
			previousPtr = currentPtr; // walk to ...
			currentPtr = currentPtr->nextProPtr; // ... next node
		
			
		} // end while
		if (currentPtr == NULL)
		{
			printf("No one %d",p_ID);
			return 0;

		}
		
	}//end  else

}*/

// customer funtions
void insertCustomer( CustomerPtr *cPtr, int c_ID, char* c_name, int c_type, double c_x, double c_y)
{
	CustomerPtr newPtr; // pointer to new node
	CustomerPtr previousPtr; // pointer to previous node in list
	CustomerPtr currentPtr; // pointer to current node in list
	
	newPtr = malloc( sizeof( Customer ) ); // create node

	if ( newPtr != NULL ) { // is space available
		newPtr->ID = c_ID; // place value in node
        strcpy(newPtr->name,c_name);
        newPtr->type = c_type;
        newPtr->x_coord = c_x;
        newPtr->y_coord = c_y;
		newPtr->nextCusPtr = NULL; // node does not link to another node

		previousPtr = NULL;
		currentPtr = *cPtr;

		// loop to find the correct location in the list
		while ( currentPtr != NULL ) {
			previousPtr = currentPtr; // walk to ...
			currentPtr = currentPtr->nextCusPtr; // ... next node
		} // end while
		// insert new node at beginning of list
		if ( previousPtr == NULL ) {
			newPtr->nextCusPtr = *cPtr;
			*cPtr = newPtr;
		} // end if
		else { // insert new node between previousPtr and currentPtr
			previousPtr->nextCusPtr = newPtr;
			newPtr->nextCusPtr = currentPtr;
		} // end else
	} // end if
	else {
		printf( "%d not inserted. No memory available.\n", c_ID );
	} // end else
} // end function insert

int deleteCustomer( CustomerPtr *cPtr, int c_ID)
{
	CustomerPtr previousPtr; // pointer to previous node in list
	CustomerPtr currentPtr; // pointer to current node in list
	CustomerPtr tempPtr; // temporary node pointer

	// delete first node
	if ( c_ID == ( *cPtr )->ID ) {
		tempPtr = *cPtr; // hold onto node being removed
		*cPtr = ( *cPtr )->nextCusPtr; // de-thread the node
		free( tempPtr ); // free the de-threaded node
		return c_ID;
	} // end if
	else {
		previousPtr = *cPtr;
		currentPtr = ( *cPtr )->nextCusPtr;

		// loop to find the correct location in the list
		while ( currentPtr != NULL && currentPtr->ID != c_ID ) {
			previousPtr = currentPtr; // walk to ...
			currentPtr = currentPtr->nextCusPtr; // ... next node
		} // end while
		
		// delete node at currentPtr
		if ( currentPtr != NULL ) {
			tempPtr = currentPtr;
			previousPtr->nextCusPtr = currentPtr->nextCusPtr;
			free( tempPtr );
			return c_ID;
		} // end if
	 } // end else
	 return '\0';
} // end function delete

int isEmptyCustomer( CustomerPtr cPtr )
{
    return cPtr == NULL;
}

void printCustomer(CustomerPtr currentPtr)
{ int counter=0;
// if list is empty
	if ( isEmptyCustomer(currentPtr) ) {
		puts( "List is empty.\n" );
	} // end if
	else {
		puts( "The list is:" );

		// while not the end of the list
		while ( currentPtr != NULL ) {
			printf("ID: %d\nName: %s\nType: %d\nx_coord: %f\ny_coord: %f"
            ,currentPtr->ID,currentPtr->name,currentPtr->type,currentPtr->x_coord,currentPtr->y_coord);
            printf("\n\t|\n\t|\n\t|\n\tV\n");
			currentPtr = currentPtr->nextCusPtr;
			counter++;
		} // end while

		puts( "\tNULL\n" );
		printf( "%d\n", counter );
	} // end else
} // end function printCustomer

void printCustomerType(CustomerPtr currentPtr, int type)
{ int counter=0;
// if list is empty
	if ( isEmptyCustomer(currentPtr) ) {
		puts( "List is empty.\n" );
	} // end if
	else {
		puts( "The list is:" );

		// while not the end of the list
		while ( currentPtr != NULL ) 
		{
			if (currentPtr->type == type)
			{
				printf("ID: %d\nName: %s\nType: %d\nx_coord: %f\ny_coord: %f"
            	,currentPtr->ID,currentPtr->name,currentPtr->type,currentPtr->x_coord,currentPtr->y_coord);
           	 	printf("\n\t|\n\t|\n\t|\n\tV\n");
			}
			currentPtr = currentPtr->nextCusPtr;
			counter++;
		} // end while

		puts( "\tNULL\n" );
		printf( "%d\n", counter );
	} // end else
} // end function printCustomer

void findCustomerID(CustomerPtr cPtr,char* name)
{
	CustomerPtr previousPtr; // pointer to previous node in list
	CustomerPtr currentPtr; // pointer to current node in list
	previousPtr = NULL;
	currentPtr = cPtr;
	

	if (isEmptyCustomer(cPtr)) // conrol puchadesed list
		printf("The list is empty\n");
	else
	{
		while (currentPtr != NULL ) {
			if(strcmp(name,(currentPtr->name)) == 0) //compare name
			{
				printf("%s ID is: %d\n",name,(currentPtr->ID));
				break;
			}
			else
			{
				previousPtr = currentPtr; // walk to ...
				currentPtr = currentPtr->nextCusPtr; // ... next node
			}
			
		} // end while
		if (currentPtr == NULL)
		{
			printf("No one %s",name);

		}
		
	}
}

void findCustomer(CustomerPtr cPtr,char* name)
{
	CustomerPtr previousPtr; // pointer to previous node in list
	CustomerPtr currentPtr; // pointer to current node in list
	previousPtr = NULL;
	currentPtr = cPtr;
	

	if (isEmptyCustomer(cPtr)) // conrol puchadesed list
		printf("The list is empty\n");
	else
	{
		while (currentPtr != NULL ) {
			if(strcmp(name,(currentPtr->name)) == 0) //compare name
			{
				printf("ID: %d\nName: %s\nType: %d\nx_coord: %f\ny_coord: %f"
            	,currentPtr->ID,currentPtr->name,currentPtr->type,currentPtr->x_coord,currentPtr->y_coord);
				break;
			}
			else
			{
				previousPtr = currentPtr; // walk to ...
				currentPtr = currentPtr->nextCusPtr; // ... next node
			}
			
		} // end while
		if (currentPtr == NULL)
		{
			printf("No one %s",name);

		}
		
	}
}

void printCustomerPurchasedProduct(PurchasedPtr currentPtr,ProductPtr p_ptr,int c_ID)
{ 
	int counter=0;
	// if list is empty
	if ( isEmptyPurchased(currentPtr))
	{
		puts( "List is empty.\n" );
	} // end if
	else
	{
		puts( "The list is:" );

		// while not the end of the list
		while ( currentPtr != NULL )
		{
			if (currentPtr->customer_ID == c_ID) // find custmer ID  in puchased
			{
				printProductV2(p_ptr,currentPtr->product_ID);
			}
			
			
			currentPtr = currentPtr->nextPurchasedPtr;
			counter++;
		} // end while
	} // end else
} // end function printCustomer

float customerTotalPurchase(PurchasedPtr currentPtr,int c_ID)
{ 
	float sum = 0;
	// if list is empty
	if ( isEmptyPurchased(currentPtr) ) {
		puts( "List is empty.\n" );
	} // end if
	else {
		// while not the end of the list
		while ( currentPtr != NULL )
		{
			if (currentPtr->customer_ID == c_ID)
			{
				sum += (currentPtr->cost);
			}
			currentPtr = currentPtr->nextPurchasedPtr;

		} // end while
		return sum;
	} // end else
} // end function customerTotalPurchase

float allCustomerTotalPurchase(PurchasedPtr currentPtr)
{ 
	float sum=0;
	// if list is empty
	if ( isEmptyPurchased(currentPtr) ) {
		puts( "List is empty.\n" );
		return 0;
	} // end if
	else {
		// while not the end of the list
		while ( currentPtr != NULL )
		{	
			sum += (currentPtr->cost);
			currentPtr = currentPtr->nextPurchasedPtr;
		} // end while

	} // end else
	return sum;
} // end function allCustomerTotalPurchase

void insertCustomerv2(CustomerPtr *cPtr)
{
	int ID = getInt("ID giriniz: ");
	char *name = getString("İsim giriniz: ");
	int type = getInt("Müşteri tipi giriniz: ");
	float x =  getFloat("X oordinatını giriniz: ");
	float y = getFloat("Y kooardinatlarını giriniz");
	insertCustomer(cPtr,ID,name,type,x,y);
}

//purchased fucts
void insertPurchased(PurchasedPtr *purPtr, int pur_ID, int i_ID, int c_ID, int p_ID, double pur_cost)
{
	PurchasedPtr newPtr; // pointer to new node
	PurchasedPtr previousPtr; // pointer to previous node in list
	PurchasedPtr currentPtr; // pointer to current node in list
	
	newPtr = malloc( sizeof( Purchased ) ); // create node

	if ( newPtr != NULL ) { // is space available
		newPtr->ID = pur_ID; // place value in node
		newPtr->invoice_ID =i_ID;
        newPtr->customer_ID = c_ID;
        newPtr->product_ID = p_ID;
		newPtr->cost =pur_cost;
		newPtr->nextPurchasedPtr = NULL; // node does not link to another node

		previousPtr = NULL;
		currentPtr = *purPtr;

		// loop to find the correct location in the list
		while ( currentPtr != NULL) {
			previousPtr = currentPtr; // walk to ...
			currentPtr = currentPtr->nextPurchasedPtr; // ... next node
		} // end while
		// insert new node at beginning of list
		if ( previousPtr == NULL ) {
			newPtr->nextPurchasedPtr = *purPtr;
			*purPtr = newPtr;
		} // end if
		else { // insert new node between previousPtr and currentPtr
			previousPtr->nextPurchasedPtr = newPtr;
			newPtr->nextPurchasedPtr = currentPtr;
		} // end else
	} // end if
	else {
		printf( "%d not inserted. No memory available.\n", pur_ID );
	} // end else
} // end function insert

int deletePurchased(PurchasedPtr *purPtr, int pur_ID)
{
	PurchasedPtr previousPtr; // pointer to previous node in list
	PurchasedPtr currentPtr; // pointer to current node in list
	PurchasedPtr tempPtr; // temporary node pointer

	// delete first node
	if ( pur_ID == ( *purPtr )->ID ) {
		tempPtr = *purPtr; // hold onto node being removed
		*purPtr = ( *purPtr )->nextPurchasedPtr; // de-thread the node
		free( tempPtr ); // free the de-threaded node
		return pur_ID;
	} // end if
	else {
		previousPtr = *purPtr;
		currentPtr = ( *purPtr )->nextPurchasedPtr;

		// loop to find the correct location in the list
		while ( currentPtr != NULL && currentPtr->ID != pur_ID ) {
			previousPtr = currentPtr; // walk to ...
			currentPtr = currentPtr->nextPurchasedPtr; // ... next node
		} // end while
		
		// delete node at currentPtr
		if ( currentPtr != NULL ) {
			tempPtr = currentPtr;
			previousPtr->nextPurchasedPtr = currentPtr->nextPurchasedPtr;
			free( tempPtr );
			return pur_ID;
		} // end if
	 } // end else
	 return '\0';
} // end function delete

int isEmptyPurchased(PurchasedPtr purPtr)
{
	return purPtr == NULL;
}

void printPurchased(PurchasedPtr currentPtr)
{ 
	int counter=0;
	// if list is empty
	if ( isEmptyPurchased(currentPtr))
	{
		puts( "List is empty.\n" );
	} // end if
	else
	{
		puts( "The list is:" );

		// while not the end of the list
		while ( currentPtr != NULL )
		{
			printf("ID: %d\nInvoice ID: %d\nCustomer ID: %d\nProduct ID: %d\nCost: %f"
            ,currentPtr->ID,currentPtr->invoice_ID,currentPtr->customer_ID,currentPtr->product_ID,currentPtr->cost);
            printf("\n\t|\n\t|\n\t|\n\tV\n");
			currentPtr = currentPtr->nextPurchasedPtr;
			counter++;
		} // end while

		puts( "\tNULL\n" );
		printf( "%d\n", counter );
	} // end else
} // end function printPurchased

int lastPurchasedID(PurchasedPtr purPtr)
{
	PurchasedPtr previousPtr; // pointer to previous node in list
	PurchasedPtr currentPtr; // pointer to current node in list
	previousPtr = NULL;
	currentPtr = purPtr;

	if (isEmptyPurchased(purPtr)) // conrol puchadesed list
		return 0;
	else
	{
		// loop to find the last location in the list
		while ( currentPtr != NULL) {
			previousPtr = currentPtr; // walk to ...
			currentPtr = currentPtr->nextPurchasedPtr; // ... next node
		} // end while
		return previousPtr ->ID;
	}	
}

float findHowMuchSaled(PurchasedPtr purPtr, ProductPtr pPtr, int p_ID)
{
	PurchasedPtr previousPtr; // pointer to previous node in list
	PurchasedPtr currentPtr; // pointer to current node in list
	previousPtr = NULL;
	currentPtr = purPtr;
	float sum = 0;

	if (isEmptyPurchased(purPtr)) // conrol puchadesed list
		return 0;
	else
	{
		
		while ( currentPtr != NULL)
		{
			if (currentPtr->product_ID == p_ID)
			{
				sum += (currentPtr->cost);
			}
			
			previousPtr = currentPtr; // walk to ...
			currentPtr = currentPtr->nextPurchasedPtr; // ... next node
		} // end while
		
	}
	printf("Kazanılan para %f",sum);
	return sum;
}

void insertPurchasedV2(PurchasedPtr *purPtr)
{
	int pur_ID = getInt("anlamını tam olarak bilmediğim ID giriniz: ");
	int i_ID = getInt("Fatura ID sini giriniz");
	int c_ID = getInt("Müşteri ID sini giriniz: ");
	int p_ID = getInt("Ürün ID sini giriniz");
	double pur_cost = getDouble("Tutar giriniz: ");
	insertPurchased(purPtr,pur_ID,i_ID,c_ID,p_ID,pur_cost);
}

/*float findHowMuchSaledType(PurchasedPtr purPtr, ProductPtr pPtr, int type)
{
	
}*/

// other functs
void instructions()
{
	int c;
	printf("Satış otomasyon programına hoş geldiniz lütfen seçim yapınız:\n");
	
	FILE *file;
	file = fopen("metin.txt", "r");
	if (file) {
    while ((c = getc(file)) != EOF)
	{
        putchar(c);
	}
    fclose(file);
	}

}

char* getString(char *a)
{
	printf("%s",a);
    char *s = (char*) malloc( 100 );
    scanf("%s",s);
    return s;
}

float sam(CustomerPtr cPtr,int c_ID)
{
	CustomerPtr previousPtr; // pointer to previous node in list
	CustomerPtr currentPtr; // pointer to current node in list
	previousPtr = NULL;
	currentPtr = cPtr;

	float cost;
	

	if (isEmptyCustomer(cPtr)) // conrol puchadesed list
		printf("The list is empty\n");
	else
	{
		while (currentPtr != NULL ) {
			if(c_ID == cPtr->ID) //compare ID
			{
				cost = (cPtr->x_coord)*(cPtr->x_coord) + (cPtr->y_coord)*(cPtr->y_coord);
				cost = sqrtf(cost)*2;
				return (cost + 10);
				break;
			}
			else
			{
				previousPtr = currentPtr; // walk to ...
				currentPtr = currentPtr->nextCusPtr; // ... next node
			}
			
		} // end while
		if (currentPtr == NULL)
		{
			printf("No one %d",c_ID);
			return 0;

		}
		
	}
}

int getInt(char *b)
{
	printf("%s",b);
	int a;
	scanf("%d",&a);
	return a;
}

float samAll(CustomerPtr cPtr)
{
	CustomerPtr previousPtr; // pointer to previous node in list
	CustomerPtr currentPtr; // pointer to current node in list
	previousPtr = NULL;
	currentPtr = cPtr;

	float cost = 0;
	float sum = 0;

	if (isEmptyCustomer(cPtr)) // conrol puchadesed list
		printf("The list is empty\n");
	else
	{
		while (currentPtr != NULL )
		{
			
			
			cost = (cPtr->x_coord)*(cPtr->x_coord) + (cPtr->y_coord)*(cPtr->y_coord);
			cost = sqrtf(cost)*2;
			sum = cost + 10;
			previousPtr = currentPtr; // walk to ...
			currentPtr = currentPtr->nextCusPtr; // ... next node
			
			
		} // end while
		
	}
}

float getFloat(char *a)
{
	printf("%s",a);
	float x;
	scanf("%f",&x);
	return x;
}

float getDouble(char *a)
{
	printf("%s",a);
	double x;
	scanf("%le",&x);
	return x;
}

void otomat(ProductPtr p_root,PurchasedPtr pur_root,CustomerPtr c_root)
{
	bool loop = true;
    float amount = 1;
    int choosing;
    // for add purpuschade
    int a,b,c,d;
    float e;
    // end
    while (loop)
    {
        
        printf("\nSeçim: ");
        scanf("%d",&choosing);
        
        
        switch (choosing)
        {
        case 1:
            printf("The last puschade number is: %d",lastPurchasedID(pur_root));
            break;
        
        case 2:
            printf("Müşteri ismi giriniz: ");
            findCustomerID(c_root,getString(""));
            break;
        case 3:
            printf("Ürün ismi giriniz: ");
            findProductID(p_root,getString(""));
            break;
        case 4:
            scanf("Miktar bilgisi giriniz: %f",&amount);
            break;
        
        case 5:
            printf("Kargo ücreti: %f",sam(c_root,getInt("Kargo hesabı için müşteri ID si giriniz: ")));
            break;
        case 6:
            printf("Satın alım ID sini giriniz: ");
            scanf("%d",&a);
            printf("Fatura ID sini giriniz: ");
            scanf("%d",&b);
            printf("Müşteri ID sini gir: ");
            scanf("%d",&c);
            printf("Ürün ID sini giriniz");
            scanf("%d",&d);
            printf("Fiyat giriniz:");
            scanf("%f",&e);
            insertPurchased(&pur_root,a,b,c,d,e);
            printPurchased(pur_root);
            break;
        case 7:
            printCustomer(c_root);
            break;
        case 8:
            printCustomerType(c_root,getInt("Ticari müşteriler için 1 bireysel için 0\nSeçim: "));         
            break;
        case 9:
            printf("Müşteri ismi giriniz: ");
            findCustomer(c_root,getString(""));
            break;
        case 10:
            printProduct(p_root);
            break;
        case 11:
            printProductType(p_root,getInt("Ürün tipi giriniz: "));
            break;
        case 12:
            printf("Ürün ismi giriniz: ");
            findProduct(p_root,getString(""));
            break;    
        case 13:
            printCustomerPurchasedProduct(pur_root,p_root,getInt("Müşteri numarası giriniz: "));
            break;
        case 14:
            printf("Müşteriden kazanılan toplam para: %f",customerTotalPurchase(pur_root,getInt("müşteri ID si giriniz: ")));
            break;
        case 15:
            printf("Müşterilerden kazanılan toplam para: %f",allCustomerTotalPurchase(pur_root));
            break;
        case 16:
            printf("Tüm müşterilerin kargo ücreti: %f",samAll(c_root));
            break;
        case 17:
            findHowMuchSaled(pur_root,p_root,getInt("Üründen kazanılan parayı hesaplamak için ürün ID giriniz: "));
            break;
        case 18:
            break;
        case 19:
            break;
        case 20:
            insertCustomerv2(&c_root);
            break;
        case 21:
            deleteCustomer(&c_root,getInt("Silmek istediğiniz müşterinin ID sini giriniz"));
            break;
        case 22:
            insertProductV2(&p_root);
            break;
        case 23:
            deleteProduct(&p_root,getInt("Silmek istediğiniz ürünün ID sini giriniz"));
            break;
        case 24:
            insertPurchasedV2(&pur_root);
            break;
        case 25:
        deletePurchased(&pur_root,getInt("Silinmesini istediğiniz fatura ID sini giriniz: "));
            break;
        case 0:
            loop = false;
            break;
        default:
            printf("Geçersiz Seçim\nSeçim: ");
            break;
        }
    }
}