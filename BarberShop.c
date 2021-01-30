#include <stdio.h>

int main()
{
    /*
        wrc: Waiting Room Chairs
        bs: Barber Status
        nc: Number of Chairs Occupied
        cs: New Customer Status
    */
    
    int wrc, bs, nc, cs;
    
    printf("Enter number of chairs in waiting room: ");
    scanf("%d", &wrc);
    
    printf("Enter number of chairs occupied: ");
    scanf("%d", &nc);
    
    if(nc == 0){
        bs = 0;                     //sleeping
        printf("-> Barber is sleeping.\n");
    }
    else{
        bs = 1;                     //awake or busy
        printf("-> Barber is busy (say awake).\n");
    }
    
    printf("Enter 1 (if new customer enters) or 0 (if no new customer enters): ");
    scanf("%d", &cs);
    
    if(cs == 1){
        printf("-> New customer entered.\n");
        
        if(nc < wrc && nc > 0){
            nc += cs;               //customer will sit on the chair
            printf("-> Customer will wait in waiting room.\n");
        }
        else if(nc == 0){
            if(bs == 0){
                bs = 1;             //customer will wakeup the Barber
                printf("-> Barber is sleeping and the new customer wakes up the barber.\n");
            }
        }
        else{
            cs = 0;                 //customer leaves the shop
            
            printf("-> There is no free space customer leaves the shop.\n");
        }
    }
    else{
        printf("-> No new customer entered.\n");
    }
    
    printf("-> Number of customers in the shop is: %d", (nc+1));
}
