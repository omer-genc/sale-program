#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"saleProgram.h"
#include <stdbool.h>
#include<math.h>
#include<locale.h>


int main()
{
    setlocale(LC_ALL, "Turkish");
    CustomerPtr c_root = NULL;
    ProductPtr p_root = NULL;
    PurchasedPtr pur_root = NULL;

    // customoers
    insertCustomer(&c_root,1,"Ali_Karaman",1,16.8,10);
    insertCustomer(&c_root,2,"Zehra_Cilek",0,12.4,6.9);
    insertCustomer(&c_root,3,"Mehmet_Derin",0,10.55,15.4);
    insertCustomer(&c_root,4,"Veli_Ortanca",1,5.1,1.2);
    insertCustomer(&c_root,5,"Menekse_Serin",1,2,7.9);

    // product
    insertProduct(&p_root,1,"portakal",1,3.95);
    insertProduct(&p_root,2,"bisküvi",2,1.25);
    insertProduct(&p_root,3,"tavuk",3,10.95);
    insertProduct(&p_root,4,"bebek bezi",4,3.95);
    insertProduct(&p_root,5,"çikolata",1,1.95);
    insertProduct(&p_root,6,"ekmek",2,1.5);
    insertProduct(&p_root,7,"muz",1,11.95);

    // PurchasedP
    insertPurchased(&pur_root,1,1,1,1,3.95);
    insertPurchased(&pur_root,2,1,1,1,1.25);
    insertPurchased(&pur_root,4,1,1,5,12.95);
    insertPurchased(&pur_root,5,1,2,7,12);
    insertPurchased(&pur_root,6,2,2,3,20);

    instructions();
    otomat(p_root,pur_root,c_root);

    return 0;
}