#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define filename "data.txt"

//structure to store hotel details
struct hotel{
	char name[100];
	char location[100];
	int number;
	int available_acroom;
	int available_non_acroom;
	float price_perday_acroom;
	float price_perday_non_acroom;
	char facilities[500];
	int total_booked;

};
//structure to get inputs for the customer details
struct customer{
	char name[100];
	int age;
	char phone_number[11];
	char email[50];
	char hotel_name[100];
	int adults;
	int children;
	int room_type;
	int room_count;
	float total;
};

//function prototypes
void billing(float l);
void display_hotels(struct hotel h[], int size);
void customer_details(struct hotel *h,struct customer *c,int *total_days);
void book_room(struct hotel *h, struct customer *c, int total_days);
void payment_method(struct customer c);
void exit();
void error();
void open();
void read_terms_file();
//main function
int main()
{

    struct hotel kandy[]={
		{"Lavendish Hills Kandy","No 12, Vidyartha Mawatha, 20000 Kandy",242222122,2,5,15678.00,11200.00,"The accommodation features a 24-hour front desk, room service and currency exchange for guests.At the hotel, all rooms are fitted with a wardrobe. Complete with a private bathroom, all guest rooms at Lavendish Hills Kandy come with air conditioning, and some rooms also offer a seating area. All rooms will provide guests with a desk and a kettle.Continental and à la carte breakfast options are available every morning at the accommodation.Kandy railway station is 2.7 km from Lavendish Hills Kandy, while Ceylon Tea Museum is 6.5 km from the property. The nearest airport is Katugastota Polgolla Reservoir Seaplane Base, 3 km from the hotel, and the property offers a paid airport shuttle service.",0},
		{"Sky Gate kandy","352/S, Pattiyakale Watta, Dharmaraja Mawatha, Kandy, 20000 Kandy, Sri Lanka",242222324,2,8,13000.00,6400.00,"The accommodation features room service, a 24-hour front desk and currency exchange for guests.At the hotel, each room has a wardrobe, a flat-screen TV, a private bathroom, bed linen and towels. The rooms come with a kettle, while selected rooms are fitted with a balcony and others also offer mountain views.Breakfast is available daily, and includes continental, Full English/Irish and Italian options. At Sky Gate kandy you will find a restaurant serving Chinese, local and Asian cuisine. Vegetarian, dairy-free and halal options can also be requested.",0},
		{"Hotel Kandyan View","No. 03, Paradise Park, Hanthana, Kandy, 20000 Kandy, Sri Lanka",242222224,1,3,9500.00,7300.00,"Free WiFi access is available in the public areas of the property.The accommodation will offer you mountain and city view from the balcony. Private bathrooms come with a shower.At Hotel Kandyan View ''Free pickup from Kandy city'' you will find a garden and terrace. Other facilities like a shared lounge and an ironing service are offered. Activities in the surrounding area include hiking. The property offers free parking.The Kandy Railway Station is 1.4 km while the Bandaranaike International Airport is located 83 km away.",0},
		{"Eagle's Residence","No.105, Rajapihilla Mawatha, 20000 Kandy, Sri Lanka",762324234,1,3,9600.00,7400.00,"With free WiFi and a terrace, guests can stay connected and enjoy the beautiful surroundings. The hotel's on-site restaurant serves a delicious breakfast, and free private parking is available for those traveling by car.The rooms are equipped with flat-screen TVs and private bathrooms with free toiletries. Some rooms offer views of the garden or city, making it a perfect place to relax after a day of exploring.There are plenty of amenities to keep guests entertained during their stay, including a shared lounge, dry cleaning services, gift shop, and shops nearby. For those who enjoy outdoor activities, the hotel is located near popular hiking trails, and guests can even play billiards on-site.",0}
	};
	struct hotel nuwara[]={
		{"Royal Lake Hotel","No1, Badulla Road, 22200 Nuwara Eliya",742606450,1,2,23000.00,20000.00,"Conveniently situated in the Nuwara Eliya City Center part of Nuwara Eliya, this property puts you close to attractions and interesting dining options.Parking,Launtry,Room service,24 hour front desk",0},
		{"Manudi Glenfallsedge Rest B&B","60, 23 Glenfall Rd, Nuwara Eliya 22200",726385606,2,2,20000.00,18000.00,"The car parking and the Wi-Fi are always free, so you can stay in touch and come and go as you please. Conveniently situated in the Nuwara Eliya City Center part of Nuwara Eliya, this property puts you close to attractions and interesting dining options. Don't leave before paying a visit to the famous Race course. As an added bonus, restaurant is provided on-site to conveniently serve your needs.",0},
		{"La Cottage Boutique Hotel & Restaurant","Ranasinghe Mawatha, Nuwara Eliya",773501100,4,1,12500.00,17500.00,"a 24-hour front desk for the convenience of the guests. Free WiFi access is available.Each room here will provide you with a flat-screen cable TV, seating area with sofa and work desk. Complete with a microwave, the dining area also has an electric kettle and a dining table. Featuring a shower, private bathroom comes with a hairdryer. You can enjoy mountain and city view from the room.",0},
		{"Tea Bush Hotel","No 29, Haddon Hill Road, 22200 Nuwara Eliya, Sri Lanka",242222345,1,2,16000.00,14000.00,"It offers a restaurant, free parking on site and free WiFi in public areas.Guest rooms are fitted with cable television and an en suite bathroom with toiletries and hot/cold showers.The hotel can assist guests with arranging excursions to the Tea Estate and the Tea Factory. Laundry and ironing services are offered.The on site restaurant serves international dishes.Hotel Tea Bush is 8 km from the Nanu Oya Railway Station. Bandaranaike International Airport is a 6-hour drive away. The Nuwara Eliya Town is a 10-minute ride.",0}
	};
	struct hotel badulla[]={
		{"Ella Moon Rock","Ella moon rock No 66/5, Ella",773060478,1,1,13000.00,10000.00,"Conveniently situated in the Ella City part of Ella, this property puts you close to attractions and interesting dining options.24 Hour Front Desk,Airport Shuttle,Laundry",0},{"Awesome Place","no 26/1 ella waththa, 90090 Ella, Sri Lanka",766667244,2,1,22000.00,18000.00,"Located in Ella, 7.9 km from Demodara Nine Arch Bridge, Awesome Place provides accommodation with a restaurant, free private parking, an outdoor swimming pool and a bar. 2.1 km from Little Adam's Peak and 3.8 km from Ella Spice Garden, the property features a garden and a terrace. The accommodation offers a 24-hour front desk and room service for guests.",0},
		{"Villa Perpetua","Mahaulpatha Road, Kinigama, Bandarawela, 90100 Bandarawela, Sri Lanka",722215445,4,4,24705.00,19764.00,"Boasting a 24-hour front desk, this property also provides guests. Both free WiFi and private parking are accessible at this property.All guest rooms in the resort are fitted with a flat-screen TV. Villa Perpetua provides certain units with mountain views, and the rooms are fitted with a terrace. All units will provide guests with a private bathroom with a bath.A range of activities are offered in the area, such as cycling and hikin",0},
		{"360 City View","25 Eladaluwa Road, 90000 Badulla, Sri Lanka",718311333,3,1,7204.00,4717.00,"At the guest house, each room is fitted with a desk, bed linen and a balcony with a mountain view. With a private bathroom equipped with a bidet and free toiletries, rooms at 360 City View also offer a city view. Guest rooms will provide guests with a wardrobe and a kettle.",0},
		{"Kithal Ella Station Resort","Station Road, Kithal, Ella 90090",778808410,2,2,17000.00,12000.00,"Kithal Ella Station Resort provides accommodation with a garden, free private parking, a terrace and a restaurant. Located around 46 km from Hakgala Botanical Garden, the hotel with free WiFi is also 47 km away from Horton Plains National Park. The accommodation offers room service and a 24-hour front desk for guests.The hotel offers a continental or Asian breakfast.",0}
	};

	//declare the variables
	int choice,next,hotel_choice,total_days=0;
	struct customer c;
    int x,y,i,z,w,v,u,ip,placei,t,select,confirm;
    float l;
    char b[4];
    int ss,cnumber;

    //starting functions for terms and conditions
    read_terms_file();
    open();

    //starting loop for select the purpose
     for(i=1; i>=1; i++)
        {
MAIN:
    printf("\t\tVisit The Heaven...\n");
    printf("1. Travelling booking system\n");
    printf("2. Hotel booking system\n");
    printf("Select your purpose(1 or 2): ");
    scanf("%d",&select);

    if(select == 1) goto TRAVEL;
	else if(select == 2) goto FOOD;
	else{
	printf("Invalid selection... Please type a valid number(1 or 2)...\n\n");
	goto MAIN;
	}

	//travelling booking system
TRAVEL:
	printf("\n\tWelcome to the \"Visit The Heaven\" Travelling booking system\n");
	printf("Select your type of travel...\n");
    printf("\t 1.Travel plan in between the Districts.\n");
    printf("\t 2.Travel plan inside a district\n");
    printf("\t 3.exit\n");
    printf("Type the Number of your selection...\n");
    printf("Type Your input here:");
    scanf("%d",&x);

    //travel plan between the districts
    if(x==1)
    {
        for(i=1; i>=1; i++)
        {
        printf("Welcome to our Travel Plan Between the Districts...\n");
        printf("\t1.Kandy\n");
        printf("\t2.Nuwara Eliya\n");
        printf("\t3.Badulla\n");
        printf("Type your starting place( 1-3 ): ");
        scanf("%d",&y);
        printf("Type your Destination: ");
        scanf("%d",&z);

        //bus scheduled times of each district
       if(y==1 && z==2)
       {
            printf("Kandy-Nuwara Eliya\n");
            printf("Bus scheduled times...\n");
            printf("1.Departure time: 5.00 am  to time of Arrival: 3.00 pm\n");
            printf("2.Departure time: 7.00 am  to time of Arrival: 5.15 pm\n");
            printf("3.Departure time: 9.00 am  to time of Arrival: 6.30 pm\n");
            printf("4.Departure time: 5.00 pm  to time of Arrival: 3.30 am\n");
            printf("5.Departure time: 8.00 pm  to time of Arrival: 6.15 am\n");
            printf("Select Your time( 1-5 ):");
            scanf("%d",&t);
            goto ef;
       }
       else if(y==1 && z==3)
       {
            printf("Kandy - Badulla\n");
            printf("Bus scheduled times...\n");
            printf("1.Departure time:  5.00 am to time of Arrival: 11.00 am\n");
            printf("2.Departure time: 10.00 am to time of Arrival:  3.30 pm\n");
            printf("3.Departure time:  1.00 pm to time of Arrival:  6.30 pm\n");
            printf("4.Departure time:  8.00 pm to time of Arrival: 12.15 pm\n");
            printf("Select Your time( 1-5 ):");
            scanf("%d",&t);
            goto ef;
       }
        else if(y==2 && z==3)
       {
            printf("Nuwara Eliya - Badulla\n");
            printf("Bus scheduled times...\n");
            printf("1.Departure time:  5.00 am  to time of Arrival:  4.00 pm\n");
            printf("2.Departure time:  7.00 am  to time of Arrival:  6.15 pm\n");
            printf("3.Departure time: 12.00 am  to time of Arrival: 10.30 pm\n");
            printf("4.Departure time:  5.00 pm  to time of Arrival:  4.30 am\n");
            printf("5.Departure time:  8.00 pm  to time of Arrival:  7.15 am\n");
            printf("Select Your time( 1-5 ):");
            scanf("%d",&t);
            goto ef;
       }
        else if(y==2 && z==1)
       {
            printf("Nuwara Eliya - Kandy\n");
            printf("Bus scheduled times...\n");
            printf("1.Departure time:  5.00 am  to time of Arrival: 3.00 pm\n");
            printf("2.Departure time:  7.30 am  to time of Arrival: 5.15 pm\n");
            printf("4.Departure time:  5.00 pm  to time of Arrival: 3.30 am\n");
            printf("5.Departure time: 10.00 pm  to time of Arrival: 7.15 am\n");
            printf("Select Your time( 1-5 ):");
            scanf("%d",&t);
            goto ef;
       }
        else if(y==3 && z==1)
       {
            printf("Badulla - Kandy\n");
            printf("Bus scheduled times...\n");
            printf("1.Departure time:  5.00 am  to time of Arrival: 11.00 am\n");
            printf("2.Departure time: 10.30 am  to time of Arrival:  5.15 pm\n");
            printf("3.Departure time:  4.00 pm  to time of Arrival:  8.30 pm\n");
            printf("4.Departure time:  8.00 pm  to time of Arrival:  6.15 am\n");
            printf("Select Your time( 1-5 ):");
            scanf("%d",&t);
            goto ef;
       }
        else if(y==3 && z==2)
       {
            printf("Badulla - Nuwara Eliya\n");
            printf("Bus scheduled times...\n");
            printf("1.Departure time: 5.00 am  to time of Arrival: 3.00 pm\n");
            printf("2.Departure time: 7.00 am  to time of Arrival: 5.15 pm\n");
            printf("3.Departure time: 9.00 am  to time of Arrival: 6.30 pm\n");
            printf("4.Departure time: 5.00 pm  to time of Arrival: 3.30 am\n");
            printf("5.Departure time: 8.00 am  to time of Arrival: 6.15 am\n");
            printf("Select Your time( 1-5 ):");
            scanf("%d",&t);
            goto ef;
       }
       else{
         printf("Error occured...\nPlease check the code.");

        }
       }
    }

    //travel plan inside the districts
    else if(x==2)
    {
 for(i=1; i>=1; i++)
        {
        printf("Welcome to our Travel Plan Inside the Districts...\n");
        printf("\t1.Kandy\n");
        printf("\t2.Nuwara Eliya\n");
        printf("\t3.Badulla\n");
        printf("Select the District( 1-3 ): ");
        scanf("%d",&w);

        //tourist places in each district
       for(i=1; i>=1; i++)
        {
        if(w==1){
                printf("Kandy District\n");
                printf("Select the tourist place:\n ");
                printf(" 1.Ambuluwawa Tower\n ");
                printf(" 2.Temple of the tooth\n ");
                printf(" 3.Royal Botanic Garden\n ");
                printf("Type the selected number( 1-3 ):");
                scanf("%d",&v);
                goto cd;
                }
        else if(w==2){
                printf("Nuwara Eliya District\n");
                printf("Select the tourist place:\n ");
                printf(" 1.Moon Plains\n ");
                printf(" 2.Victoria Park\n ");
                printf(" 3.Haggala Botanical Garden\n ");
                printf("Type the selected number( 1-3 ):");
                scanf("%d",&v);
                goto cd;
                }
        else if(w==3){
                printf("Badulla District\n");
                printf("Select the tourist place:\n ");
                printf(" 1.Narangala\n ");
                printf(" 2.Ella Rock Trailhead\n ");
                printf(" 3.Little Adam's Peak'\n ");
                printf("Type the selected number( 1-3 ):");
                scanf("%d",&v);
                goto cd;
                }
        else{
                 printf("Error occured...Please check the code.\n");
                break;
                }
        }
        }

        //bus scheduled time for inside travelling
        cd:
        for(i=1; i>=1; i++)
        {
                    if(w==1 && v==1)
                    {
                       printf("Bus scheduled times...\n");
                       printf("1.Departure time:  5.00 am  to time of Arrival: 5.00 am\n");
                       printf("2.Departure time: 12.30 am  to time of Arrival: 1.15 pm\n");
                       printf("3.Departure time:  4.00 pm  to time of Arrival: 4.40 pm\n");
                       printf("Select Your time( 1-3 ):");
            scanf("%d",&t);
            goto ef;
                    }
                    else if(w==1 && v==2)
                    {
                       printf("Bus scheduled times...\n");
                       printf("1.Departure time:  8.00 am  to time of Arrival: 9.00 am\n");
                       printf("2.Departure time: 12.30 am  to time of Arrival: 1.45 pm\n");
                       printf("3.Departure time:  4.00 pm  to time of Arrival: 6.45 pm\n");
                       printf("Select Your time( 1-3 ):");
            scanf("%d",&t);
            goto ef;
                    }
                    else if(w==1 && v==3)
                    {
                       printf("Bus scheduled times...\n");
                       printf("1.Departure time:  5.00 am  to time of Arrival:  5.00 am\n");
                       printf("2.Departure time: 11.30 am  to time of Arrival: 12.15 am\n");
                       printf("3.Departure time:  4.00 pm  to time of Arrival:  4.40 pm\n");
                       printf("Select Your time( 1-3 ):");
            scanf("%d",&t);
            goto ef;
                    }
                    else if(w==2 && v==1)
                    {
                       printf("Bus scheduled times...\n");
                       printf("1.Departure time:  5.00 am  to time of Arrival: 5.00 am\n");
                       printf("2.Departure time: 12.30 am  to time of Arrival: 1.15 pm\n");
                       printf("3.Departure time:  4.00 pm  to time of Arrival: 4.40 pm\n");
                       printf("Select Your time( 1-3 ):");
            scanf("%d",&t);
            goto ef;
                    }
                    else if(w==2 && v==2)
                    {
                       printf("Bus scheduled times...\n");
                       printf("1.Departure time:  5.00 am  to time of Arrival: 5.00 am\n");
                       printf("2.Departure time: 12.30 am  to time of Arrival: 1.15 pm\n");
                       printf("3.Departure time:  4.00 pm  to time of Arrival: 4.40 pm\n");
                       printf("Select Your time( 1-3 ):");
            scanf("%d",&t);
            goto ef;
                    }
                    else if(w==2 && v==3)
                    {
                       printf("Bus scheduled times...\n");
                       printf("1.Departure time:  5.00 am  to time of Arrival: 5.00 am\n");
                       printf("2.Departure time: 12.30 am  to time of Arrival: 1.15 pm\n");
                       printf("3.Departure time:  4.00 pm  to time of Arrival: 4.40 pm\n");
                       printf("Select Your time( 1-3 ):");
            scanf("%d",&t);
            goto ef;
                    }
                    else if(w==3 && v==1)
                    {
                       printf("Bus scheduled times...\n");
                       printf("1.Departure time:  5.00 am  to time of Arrival: 5.00 am\n");
                       printf("2.Departure time: 12.30 am  to time of Arrival: 1.15 pm\n");
                       printf("3.Departure time:  4.00 pm  to time of Arrival: 4.40 pm\n");
                       printf("Select Your time( 1-3 ):");
            scanf("%d",&t);
            goto ef;
                    }
                    else if(w==3 && v==2)
                    {
                       printf("Bus scheduled times...\n");
                       printf("1.Departure time:  5.00 am  to time of Arrival: 5.00 am\n");
                       printf("2.Departure time: 12.30 am  to time of Arrival: 1.15 pm\n");
                       printf("3.Departure time:  4.00 pm  to time of Arrival: 4.40 pm\n");
                       printf("Select Your time( 1-3 ):");
            scanf("%d",&t);
            goto ef;
                    }
                    else if(w==3 && v==3)
                    {
                       printf("Bus scheduled times...\n");
                       printf("1.Departure time:  5.00 am  to time of Arrival: 5.00 am\n");
                       printf("2.Departure time: 12.30 am  to time of Arrival: 1.15 pm\n");
                       printf("3.Departure time:  4.00 pm  to time of Arrival: 4.40 pm\n");
                       printf("Select Your time( 1-3 ):");

            scanf("%d",&t);
            goto ef;
                    }
                    else{
                         printf("Error occured...Please check the code.\n");
                        break;
                    }
        }
    }
    else if(x==3)
    {

//exit loop, when you want to exit our page
EXIT:
	  for(i=1; i>=1; i++)
        {
        printf("do you really want to exit?\n");
        printf("Type your input(if type yes \"yes\" else type \"no\".): ");
            scanf("%s",b);
             printf("\n\n");
            if(strcmp(b,"yes")==0)
            {
                printf("Thank you for selecting us...\n\n");
                exit(0);
            }
            else if(strcmp(b,"no")==0)
            {
               goto MAIN;
               break;
            }
             else
            {
                printf("\n\n");

             printf("Some thing went wrong.please check your input and try again.\n");
            }
              }

    }
    else{
        error();
        break;
    }
        }

//billing system of travelling
ef:
	printf("\nThankyou for your kind information.Booking Confirmed...!\n\n");
    printf("Welcome to our billing system.\n");
    printf("If you want to exit please press 0.\n");//no need to book press 0 and exit

    printf("No of Seats:");
    scanf("%d",&ss);
    if(ss==0)
    {
        goto EXIT;
    }
    else{
        if(x==1 && y==1 && z==2){  l=ss*2100; printf("You have to pay:Rs.%.2f\n",l);}
   else if(x==1 && y==1 && z==3){  l=ss*580; printf("You have to pay:Rs.%.2f\n",l);}
   else if(x==1 && y==2 && z==3){  l=ss*1350; printf("You have to pay:Rs.%.2f\n",l);}
   else if(x==1 && y==2 && z==1){  l=ss*2100; printf("You have to pay:Rs.%.2f\n",l);}
   else if(x==1 && y==3 && z==1){  l=ss*580; printf("You have to pay:Rs.%.2f\n",l);}
   else if(x==1 && y==3 && z==2){  l=ss*1350; printf("You have to pay:Rs.%.2f\n",l);}
   else if(x==2 && w==1 && v==1){  l=ss*59; printf("You have to pay:Rs.%.2f\n",l);}
   else if(x==2 && w==1 && v==2){  l=ss*103; printf("You have to pay:Rs.%.2f\n",l);}
   else if(x==2 && w==1 && v==3){  l=ss*70; printf("You have to pay:Rs.%.2f\n",l);}
   else if(x==2 && w==2 && v==1){  l=ss*29; printf("You have to pay:Rs.%.2f\n",l);}
   else if(x==2 && w==2 && v==2){  l=ss*78; printf("You have to pay:Rs.%.2f\n",l);}
   else if(x==2 && w==2 && v==3){  l=ss*80; printf("You have to pay:Rs.%.2f\n",l);}
   else if(x==2 && w==3 && v==1){  l=ss*25; printf("You have to pay:Rs.%.2f\n",l);}
   else if(x==2 && w==3 && v==2){  l=ss*110; printf("You have to pay:Rs.%.2f\n",l);}
   else if(x==2 && w==3 && v==3){  l=ss*67; printf("You have to pay:Rs.%.2f\n",l);}
else{
        printf("Some thing went wrong.please check your input and try again.\n");

}
}

    billing(l);//function call for billing
    goto NEXT;

//starting of hotel booking system
FOOD:
	printf("\n\tWelcome to the \"Visit The Heaven\" Hotel booking system\n");

PROMPT:
	printf("\nWhere would you like to go...?\n1.Kandy\n2.Nuwaraeliya\n3.Badulla\n4.Exit\nSelect the place(1-4): ");
	scanf("%d",&choice);

	//display the available hotels in each district
	switch(choice){
		case 1:
			printf("\nAvailable hotels in Kandy:\n");
			display_hotels(kandy,4);
			break;
		case 2:
			printf("\nAvailable hotels in Nuwaraeliya:\n");
			display_hotels(nuwara,4);
			break;
		case 3:
			printf("\nAvailable hotels in Badulla:\n");
			display_hotels(badulla,4);
			break;
		case 4:
			goto EXIT;
		default:
			printf("Invalid choice. Please select a valid option( 1-4 ).\n");
			goto FOOD;
	}



//input the hotel needs
HOTEL:
	printf("Enter the hotel number to book(1-4): ");
	scanf("%d",&hotel_choice);

	if(hotel_choice<1 || hotel_choice>4){
		printf("Invalid hotel choice!\n");
		goto HOTEL;
	}

	struct hotel *selected_hotel;
	if(choice == 1){
		selected_hotel = &kandy[hotel_choice - 1];
	}
	else if(choice == 2){
		selected_hotel = &nuwara[hotel_choice - 1];
	}
	else if(choice == 3){
		selected_hotel = &badulla[hotel_choice - 1];
	}

	customer_details(selected_hotel,&c,&total_days);//print the customer details using function call

    book_room(selected_hotel,&c,total_days);//booking details using the function call

	printf("\nThankyou for your kind information.Booking Confirmed...!\n\n");
	payment_method(c);

//end the program asking next need
     int s;

NEXT:
     for(s=1; s>=1; s++){
	printf("Do you want to book another one?( 1 for Yes, 2 for No): ");
	scanf("%d",&confirm);

	if(confirm==1){
	   goto MAIN;
	}
	else if(confirm==2){
       printf("Thankyou for your booking!\nHave a nice day...\n\n");
break;
	}
	else{
		printf("Invalid input...\n\n");

	}

     }
    return 0;
}
//function for error management
void error(){
	printf("An error occurred. Please try again.\n");
	exit(1);
}
//file handling function
void read_terms_file(){
	FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open '%s'. Make sure the file exists.\n", filename);
        exit(0);
    }

    char data[200];
    while (fgets(data, sizeof(data), file) != NULL) {
        printf("%s", data);
    }

    fclose(file);
}
//opening function
void open()
{
    int x,i;
    char a[10];
    char b[4];
    char c[9];
    for(x=1; x>=1; x=x+1)
    {
    printf("Welcome to our Manage your tour.\nIf you like to continue please type\"continue\" otherwise please type exit.\n");
    printf("Enter your input hear:");
    scanf("%s",a);

    if(strcmp(a,"continue")==0)
    {
       break;
    }
    else if(strcmp(a,"exit")==0)
    {
         for(x=1; x>=1; x=x+1)
    {
        printf("\n");
    printf("\n");
        printf("do you really want to exit?\n");
        printf("(if type yes \"yes\" else type \"no\".) ");
        printf("Type your input: ");
            scanf("%s",b);
             printf("\n");
             printf("\n");
            if(strcmp(b,"yes")==0)
            {
                goto ab;
            }
            else if(strcmp(b,"no")==0)
            {
               break;
            }
             else
            {
                printf("\n");
    printf("\n");
             printf("Some thing went wrong.please check your input and try again.\n");
            }
    }

    }
    else
    {
        printf("\n");
    printf("\n");
        printf("Some thing went wrong\n");
    }
    }

      for(x=1; x>=1; x=x+1)
       {
         printf("If you agree to our terms and conditions type\"agree\" in the input field\n");
         printf("otherwise type\"disagree\"\n");
         scanf("%s",c);
         if(strcmp(c,"agree")==0)
         {
             break;
         }
         else if(strcmp(c,"disagree")==0)
         {
             goto ab;
         }
         else
         {
             printf("Input error.please check your input and try again.");
         }

       }
goto bc;




ab:
    printf("Thank you for selecting us...");
    printf("\n");
    exit(0);
bc:
	printf("\n");
}

//function for display hotel details
void display_hotels(struct hotel h[], int size){
	int i;

	for(i=0;i<size;i++){
		printf("%d.%s\nLocation: %s\nContact: %d\n",i+1,h[i].name,h[i].location,h[i].number);
		printf("\tPrice per day for AC room:%.2f\n\tPrice per day for non AC room:%.2f\n",h[i].price_perday_acroom,h[i].price_perday_non_acroom);
		printf("\tAvailable rooms:\n\tAC rooms: %d\tNon AC room: %d\n\tFacilities: %s\n\n",h[i].available_acroom,h[i].available_non_acroom,h[i].facilities);
	}
}
//function for get customer details as inputs
void customer_details(struct hotel *h,struct customer *c,int *total_days){
	int check_in_day,check_in_month,check_in_year,check_out_day,check_out_month,check_out_year,check_in_total,check_out_total;

	printf("Enter your name: ");
	scanf("%s",&c->name);
	printf("Enter your age: ");
	scanf("%d",&c->age);
PHONE:
	printf("Enter your phone number: ");
	scanf("%s",&c->phone_number);

	if(strlen(c->phone_number)!= 10){
		printf("Invalid phone number.Please enter a valid 10 digit number...\n");
		goto PHONE;
	}
	printf("Enter your email: ");
	scanf("%s",&c->email);
	printf("Enter number of adults: ");
	scanf("%d",&c->adults);
	printf("Enter number of children: ");
	scanf("%d",&c->children);

	int p;

gh:
	//check-in and check-out dates calculation
	printf("Enter the check-in date(dd mm yy): ");
	scanf("%d %d %d", &check_in_day, &check_in_month, &check_in_year);
	printf("Enter the check-out date(dd mm yy): ");
	scanf("%d %d %d", &check_out_day, &check_out_month, &check_out_year);
	check_in_total = check_in_year*365 + check_in_month*30 + check_in_day;
	check_out_total = check_out_year*365 + check_out_month*30 + check_out_day;
	*total_days = check_out_total-check_in_total;

	if(*total_days >0){
		printf("Total staying days: %d\n",*total_days);
		goto ROOM_TYPE;
	}
	else{
		printf("Error: Check-out date must be after Check-in date.\n");
        goto gh;
	}


ROOM_TYPE:
	printf("Select room type( 1 for AC, 2 for Non AC): ");
	scanf("%d",&c->room_type);

	if(c->room_type<1 || c->room_type>2){
		printf("Invalid room type.Please select 1 or 2...\n");
		goto ROOM_TYPE;
	}

	printf("How many rooms do you want?: ");
	scanf("%d",&c->room_count);

	if(c->room_type == 1 && h->available_acroom < c->room_count || c->room_type == 2 && h->available_non_acroom < c->room_count){
		printf("Oops...This much rooms are not available now...\n");
		goto ROOM_TYPE;
	}

	strcpy(c->hotel_name, h->name);
	printf("\nCustomer details:-\n");
    printf("Customer name: %s\nHotel name: %s\nRoom type: %s\nNumber of rooms: %d\nNumber of adults: %d\nNumber of children: %d\nTotal days to stay: %d\n",c->name,c->hotel_name,c->room_type==1?"AC room":"Non AC room",c->room_count,c->adults,c->children,*total_days);
}
//function for book the room and calculate the price
void book_room(struct hotel *h, struct customer *c, int total_days){
	if(c->room_type==1){
		if(h->available_acroom>0){
			c->total = h->price_perday_acroom * total_days * c->room_count;
			h->available_acroom--;
		}
		else{
			printf("\nSorry, no AC rooms available.\n");
			return;
		}
	}
	else if(c->room_type==2){
		if(h->available_non_acroom>0){
			c->total = h->price_perday_non_acroom * total_days * c->room_count;
			h->available_non_acroom--;
		}
		else{
			printf("\nSorry, no Non-AC rooms available.\n");
			return;
		}
	}
	h->total_booked++;
	printf("Total Price: LKR%.2f\n",c->total);
}
//function for payment method in hotel booking system
void payment_method(struct customer c){
	int OTP;
	char card_number[17],expiry_date[6],cvv[4];

PAYMENT:
	printf("Enter card number(16 digits): ");
	scanf("%s",card_number);
	printf("Enter expiry date(MM/YY): ");
	scanf("%s",expiry_date);
	printf("Enter CVV(3 digits): ");
	scanf("%s",cvv);

	if(strlen(card_number)== 16 && strlen(expiry_date)== 5 && strlen(cvv)== 3){
		printf("Amount to pay(Half payment - 50%): LKR%.2f\n\n",(c.total)/2.0);
		if((c.total)/2.0>0) {
        printf("Your payment is progressing...\nEnter your OTP number: ");
		scanf("%d",&OTP);
		printf("\tPayment successful!\n\tThank you for your booking.\n\tThe receipt will be sent to your Email.\n");
		}
	}
	else{
		printf("Invalid card details...Please check and try again.\n");
		goto PAYMENT;
	}
}
//function for billing in travelling system
void billing(float l){
	int OTP;
	char card_number[17],expiry_date[6],cvv[4];

PAY:
	printf("Enter card number(16 digits): ");
	scanf("%s",card_number);
	printf("Enter expiry date(MM/YY): ");
	scanf("%s",expiry_date);
	printf("Enter CVV(3 digits): ");
	scanf("%s",cvv);

	if(strlen(card_number)== 16 && strlen(expiry_date)== 5 && strlen(cvv)== 3){
		printf("Amount to pay: LKR%.2f\n\n",l);
		if(l>0) {
        printf("Your payment is progressing...\nEnter your OTP number: ");
		scanf("%d",&OTP);
		printf("\tPayment successful!\n\tThank you for your booking.\n\tThe receipt will be sent to your Email.\n");
		}
	}
	else{
		printf("Invalid card details...Please check and try again.\n");
		goto PAY;
	}
}
