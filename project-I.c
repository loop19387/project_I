#include<stdio.h>
#include<time.h>

void book (FILE *fp ,int *k , int *p, int *q,int *r,char n []);
void log_time (FILE *fp,int m,int *c,int *l,float *t,char b );
struct info
{
    int g_id ,rate ,hrs ;
    char nm[10];
    time_t strt_t;
    time_t end_t;
    float time_diff;
    int total_amt;
    
    float add_amt, add_time ;
};

int main (){
   FILE *fp;
   fp = fopen("proj.txt","a");
    char w='Y';
    int a=0;
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
         if (w == 'Y' || w== 'y')
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
         
        printf("\n   What action do you want to do?  \n");
        printf("1. Book Participants\n");
        printf("2. Log Time\n");
        printf("3. Exit\n");
        printf("Enter Choice (1-3): ");
        scanf("%d", &choice);

         if (choice == 3){
            break;
         }
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
                  
                book (fp,&i.rate ,&i.g_id,&i.hrs,&i.total_amt,i.nm );

                i.total_amt = i.hrs * i.rate;
                 a = i.g_id;
                
               /* printf("\n--- Booking Receipt ---\n");
                printf("Booking ID: %d\n", i.g_id);
                printf("Name: %s\n", i.nm);
                printf("Schedule: %d PM - %d PM\n", i.g_id, i.g_id + i.hrs);
            
                printf("Total Amount: Rs %d\n", i.total_amt);
                fprintf(fp, "Name: %s \n", i.nm);
                fprintf(fp, "Booking ID: %d\n", i.g_id);
                fprintf(fp, "Schedule: %d PM - %d PM\n", i.g_id, i.g_id + i.hrs);
                fprintf(fp, "Total Amount: Rs %d\n", i.total_amt);   
                */
                break;

             case 2: // SECTION B: LOG TIME
                printf("\n--- Log Time ---\n");
                printf("Enter Booking ID to start: ");
                scanf("%d", &i.g_id);
                if (a==i.g_id){
                printf("Do you want to start the game? (y/n): ");
                scanf(" %c", &confirm);

                log_time (fp, a ,&i.strt_t,&i.end_t,&i.time_diff , confirm ); // should not state '&' FP rather we should state only FP even though pointer FP is given as an argument
               /* if (confirm == 'y' || confirm == 'Y') {
                    time(&i.strt_t);
                    printf("Game Started at: %s", ctime(&i.strt_t));
                    
                    printf("\nPress Enter to END the game...");
                    getchar(); // Catch newline
                    getchar(); // Wait for actual press
                    
                    time(&i.end_t);
                    i.time_diff = difftime(i.end_t, i.strt_t);
                    
                    printf("Game Ended. Total Duration: %f seconds.\n", i.time_diff);
                    fprintf(fp,"time duration: %f \n",i.time_diff);
                    printf(" Match Completed Successfully!\n");
                 }
                    */
                }
                else{
                  printf("try again");
                }
             break;

             default:
                printf("Invalid choice!\n");
        }
    }
   }
   
    printf("Exiting !!!!!! Thank you!!!!!!!!!!\n");
    fclose (fp);
    return 0;
   
}

void book (FILE *fp ,int *k , int *p, int *q,int *r,char n[]){

                *r=*k * *q ;
                printf("\n--- Booking Receipt ---\n");
                printf("Booking ID: %d\n", *p);
                printf("Name: %s\n", n);
                printf("Schedule: %d PM - %d PM\n", *p, *p + *q);
            
                printf("Total Amount: Rs %d\n", *r);
                fprintf(fp, "Name: %s \n", n);
                fprintf(fp, "Booking ID: %d\n", *p);
                fprintf(fp, "Schedule: %d PM - %d PM\n", *p, *p + *q);
                fprintf(fp, "Total Amount: Rs %d\n", *r); 
}
void log_time (FILE *fp,int m,int *c,int *l,float *t,char b ) {
if (b == 'y' || b == 'Y') {
                    time(c);                              // time needs address not value
                    printf("Game Started at: %s", ctime(c));
                    
                    printf("\nPress Enter to END the game...");
                    getchar(); // Catch newline
                    getchar(); // Wait for actual press
                    
                    time(l);
                    *t = difftime(*l, *c);
                    
                    printf("Game Ended. Total Duration: %f seconds.\n", *t);
                    fprintf(fp,"time duration: %f \n",*t);
                    printf(" Match Completed Successfully!\n");
}
}
  //	If you use a (append mode), all bookings are saved, and new bookings are added at the end. 
  // 	If you use w (write mode) every time someone makes a booking, all previous bookings will be lost.