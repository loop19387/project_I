#include<stdio.h>
#include<time.h>
struct info
{
    int g_id ,rate ,hrs ;
    char nm[10];
    time_t strt_t;
    time_t end_t;
    float time_diff;
    int total_amt;
    
    float add_amt, add_time ;
    char payment_mode [10];
};

int main (){
    char w='Y';
    struct info i;
    i.rate = 2000;
    int choice;
    char confirm;
     char ground_name[] = "Kathmandu Futsal Arena";
    char contact[] = "9812345678";
    char opening_hours[] = "5:00 AM - 5:00 PM";
    while (w!='N' &&  w!= 'n'){
        printf("enter 'Y' to see the schedule and post record , and press 'N' to skip  \n");
        scanf("%c",&w);
         if (w == 'y' || w== 'y')
        { 
       printf("\n");
        printf("     %s\n", ground_name);
        printf("\n");
        printf("------------------------------------------------\n");
        printf("Rate per hour      : Rs %d\n", i.rate);
        printf("Opening Hours      : %s\n", opening_hours);
        printf("Contact Number     : %s\n", contact);
        printf("\n");
       printf("-------------------------------------------------\n");
       printf("\n");
        }
      while (1) {
        printf("\n--- What action do you want to do? ---\n");
        printf("1. Book Participants\n");
        printf("2. Log Time\n");
        printf("3. Exit\n");
        printf("Enter Choice (1-3): ");
        scanf("%d", &choice);

        if (choice == 3) break;

        switch (choice) {
            case 1: // SECTION A: BOOK PARTICIPANTS
                printf("\n--- Booking Function ---\n");
                printf("Enter Booker Name: \n ");
                getchar();
                fgets(i.nm,sizeof(i.nm),stdin);
                printf("Enter Booking Time ( 5am to  5 PM): ");
                scanf("%d", &i.g_id);   // Using g_id to store the time slot for now
                printf("Enter Hours: ");
                scanf("%d", &i.hrs);

                i.total_amt = i.hrs * i.rate;
                
                printf("\n--- Booking Receipt ---\n");
                printf("Booking ID: %d\n", i.g_id);
                printf("Name: %s\n", i.nm);
                printf("Schedule: %d PM - %d PM\n", i.g_id, i.g_id + i.hrs);
                printf("Total Amount: Rs %d\n", i.total_amt);
                break;

            case 2: // SECTION B: LOG TIME
                printf("\n--- Log Time ---\n");
                printf("Enter Booking ID to start: ");
                scanf("%d", &i.g_id);
                
                printf("Do you want to start the game? (y/n): ");
                scanf(" %c", &confirm);

                if (confirm == 'y' || confirm == 'Y') {
                    time(&i.strt_t);
                    printf("Game Started at: %s", ctime(&i.strt_t));
                    
                    printf("\nPress Enter to END the game...");
                    getchar(); // Catch newline
                    getchar(); // Wait for actual press
                    
                    time(&i.end_t);
                    i.time_diff = difftime(i.end_t, i.strt_t);
                    
                    printf("Game Ended. Total Duration: %.2f seconds.\n", i.time_diff);
                    printf(" Match Completed Successfully!\n");
                }
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    printf("Exiting... Thank you!\n");
    return 0;
}
}
   