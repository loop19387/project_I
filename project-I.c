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
     char ground_name[] = "Kathmandu Futsal Arena";
    char contact[] = "9812345678";
    char opening_hours[] = "6:00 AM - 10:00 PM";
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
        printf("Press 'Y' to Book Ground\n");
        printf("Press 'N' to Exit\n");
        printf("Enter choice: ");
        scanf(" %c",&w);

        printf("enter the name of booker :");
        fgets(i.nm,sizeof(i.nm),stdin);
        printf(" %s \n ",i.nm);
        printf("enter the no of hrs that you wnat to play : \n");
        scanf("%d",&i.hrs);
        i.rate = 2000;
        i.total_amt = i.hrs * i.rate;
        printf("the total amount will be  %d hrs * Rs %d= Rs %d \n",i.hrs,i.rate,i.total_amt);
         time(&i.strt_t);
         printf("press any key to stop :\n");
         getchar();
         getchar();
         time(&i.end_t);
         i.time_diff=i.end_t - i.strt_t;
         if (i.time_diff<=60)
         {
            printf("in seconds \n");
            printf("the total time is %f sec  \n",i.time_diff);
             printf("The final total amount will be Rs %d \n",i.total_amt);
         }else if (i.time_diff >= 60 && i.time_diff <=60*60){
            printf("in min \n");
            printf("the total time is %f min \n",i.time_diff/(60));
            printf("The final total amount will be Rs %d \n",i.total_amt);
         }else{
            printf("in hrs \n");
            printf("the total time is %f \n",i.time_diff/(60*60));
            if (i.time_diff > i.hrs){
            i.add_time=i.time_diff-i.hrs;
            i.add_amt= i.add_time * 2050;
            printf("The final total amount will be Rs %f+%d \n",i.add_amt+i.total_amt);
        } else{
             printf("The final total amount will be Rs %d \n",i.total_amt);
        }
        printf("enter  payment method (online / offline ) \n");
        printf("press yes  if payment is completed  via any medium \n ");

         }

        }else if ( w =='N' || w == 'n' ){
            printf("press 'y'or exit \n"); 
        }
    
    } 
    return 0;
    /*

    // using if -else statement
    #include<stdio.h>
#include<time.h>

struct booking
{
    int booking_id;
    char name[20];
    int hrs;
    time_t start_time;
    time_t end_time;
    double total_time;
};

int main()
{
    struct booking b;
    int choice;
    char start;

    printf("Kathmandu Futsal Arena\n");
    printf("-----------------------\n");

    while(1)
    {
        printf("\nWhat action do you want to do?\n");
        printf("1. Book Pitch\n");
        printf("2. Log Time\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("\n--- Pitch Booking ---\n");

            printf("Enter Name: ");
            scanf("%s",b.name);

            printf("Enter number of hours: ");
            scanf("%d",&b.hrs);

            b.booking_id = 1001;

            printf("\nBooking Time: 5pm - 6pm\n");
            printf("Booking ID: %d\n",b.booking_id);
            printf("Booking Successful!\n");
        }

        else if(choice==2)
        {
            int id;

            printf("\n--- Log Time ---\n");

            printf("Enter Booking ID: ");
            scanf("%d",&id);

            if(id==b.booking_id)
            {
                printf("Do you want to start the game? (Y/N): ");
                scanf(" %c",&start);

                if(start=='Y' || start=='y')
                {
                    time(&b.start_time);
                    printf("Game Started...\n");

                    printf("Press any key to end game\n");
                    getchar();
                    getchar();

                    time(&b.end_time);

                    b.total_time = difftime(b.end_time,b.start_time);

                    printf("Time Ended\n");
                    printf("Total Time Played: %.2f seconds\n",b.total_time);
                    printf("Thank you for playing!\n");
                }
            }
            else
            {
                printf("Invalid Booking ID\n");
            }
        }

        else if(choice==3)
        {
            printf("Exiting Program...\n");
            break;
        }

        else
        {
            printf("Invalid Choice\n");
        }
    }

    return 0;
}

// using switch case 

    #include <stdio.h>
#include <time.h>
#include <string.h>

struct info {
    int g_id, rate, hrs;
    char nm[20];
    time_t strt_t;
    time_t end_t;
    double time_diff;
    int total_amt;
};
int main() {
    struct info i;
    int choice;
    char confirm;
    i.rate = 2000; // Standard rate

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
                printf("Enter Booker Name: ");
                scanf(" %s", i.nm); // Simplified string input
                printf("Enter Booking Time (e.g., 5 for 5 PM): ");
                scanf("%d", &i.g_id); // Using g_id to store the time slot for now
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
                    printf("Display Message: Match Completed Successfully!\n");
                }
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    printf("Exiting... Thank you!\n");
    return 0;
}
    */
}