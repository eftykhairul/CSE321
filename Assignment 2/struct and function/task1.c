#include <stdio.h>

struct object {
    int quantity;
    float unit_price;
};

int main() {
    struct object para,veg,water;
    int numberOf_people;
    float total_bill,per_person;
    //Paratha
    printf("Quantity Of Paratha: ");
    scanf("%d", &para.quantity);
    printf("Unit Price: ");
    scanf("%f", &para.unit_price);
    //Vegetable
    printf("Quantity Of Vegetable: ");
    scanf("%d", &veg.quantity);
    printf("Unit Price: ");
    scanf("%f", &veg.unit_price);
    //Mineral Water
    printf("Quantity Of Mineral Water: ");
    scanf("%d", &water.quantity);
    printf("Unit Price: ");
    scanf("%f", &water.unit_price);
    //total bill
    total_bill=(para.quantity*para.unit_price)+(veg.quantity*veg.unit_price)+(water.quantity*water.unit_price);
    //number of people
    printf("Number of People: ");
    scanf("%d",&numberOf_people);
    // bill per person
    per_person=total_bill/numberOf_people;
    // Print result
    printf("Individual people will pay: %.2f tk\n",per_person);
    
    return 0;
}