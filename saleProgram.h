#ifndef SALEPROGRAM_H_
#define SALEPROGRAM_H_


struct product {
    int ID;
    char name[50];
    unsigned int type : 4;
    double price;
    struct Product *nextProPtr;
};
typedef struct product Product;
typedef Product *ProductPtr;

struct customer {
    int ID;
    char name[50];
    unsigned int type: 1;
    double x_coord;
    double y_coord;
    struct Customer *nextCusPtr;
};
typedef struct customer Customer;
typedef Customer *CustomerPtr;

struct purchased {
    int ID;
    int invoice_ID;
    int customer_ID;
    int product_ID;
    double cost;
    struct Purchased *nextPurchasedPtr;
};
typedef struct purchased Purchased;
typedef Purchased *PurchasedPtr;



int instruction(void);

//product fucts prototypes
void insertProduct(ProductPtr *pPtr, int p_ID, char* p_name, int p_type, double p_price);
int deleteProduct(ProductPtr *pPtr, int p_ID);
int isEmptyProduct(ProductPtr pPtr);
void printProduct(ProductPtr pPtr);
void findProductID(ProductPtr pPtr,char* name);
void printProductType(ProductPtr pPtr,int type);
void findProduct(ProductPtr pPtr,char* name);
void printProductV2(ProductPtr pPtr,int p_ID);
float productTotalPurchase(PurchasedPtr purPtr, int p_ID);
// float findProductCost(ProductPtr pPtr,int p_ID);

//customer fucts prototypes
void insertCustomer( CustomerPtr *cPtr, int c_ID, char* c_name, int c_type, double c_x, double c_y);
int deleteCustomer( CustomerPtr *cPtr, int c_ID);
int isEmptyCustomer( CustomerPtr cPtr );
void printCustomer(CustomerPtr cPtr);
void findCustomerID(CustomerPtr cPtr,char* name);
void printCustomerType(CustomerPtr currentPtr, int type);
void findCustomer(CustomerPtr cPtr,char* name);
void printCustomerPurchasedProduct(PurchasedPtr pur_ptr,ProductPtr p_ptr,int c_ID);
float customerTotalPurchase(PurchasedPtr pur_Ptr,int c_ID);
float allCustomerTotalPurchase(PurchasedPtr pur_Ptr);
void insertCustomerv2(CustomerPtr *cPtr);

//purchased fucts prototypes
void insertPurchased(PurchasedPtr *purPtr, int pur_ID, int i_ID, int c_ID, int p_ID, double pur_cost);
int deletePurchased(PurchasedPtr *purPtr, int pur_ID);
int isEmptyPurchased(PurchasedPtr purPtr);
void printPurchased(PurchasedPtr purPtr);
int lastPurchasedID(PurchasedPtr purPtr);
float findHowMuchSaled(PurchasedPtr purPtr, ProductPtr pPtr, int p_ID);
float findHowMuchSaledType(PurchasedPtr purPtr, ProductPtr pPtr, int type);
void insertPurchasedV2(PurchasedPtr *purPtr);


// other funct
void instructions();
void otomat(ProductPtr p_root,PurchasedPtr pur_root,CustomerPtr c_root);
char* getString(char *a);
int getInt(char *b);
float sam(CustomerPtr cPtr,int c_ID);
float samAll(CustomerPtr cPtr);
float getFloat(char *a);
float getDouble(char *a);

#endif