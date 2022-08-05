//tell the user when and how many times it was sad..
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<ctype.h>

struct account{
    char name[30], mood[10];
    int days;
    bool mood_predicted_already;
}acc;

int satisfied_with_result();
int mood_predictor_again();

int mood_predictor(){  
	int Happy = 0, Sad = 0, Excited = 0, Worried = 0;       //Happy, sad, excited and worried are the 4 moods
	char ans;
	
	if (acc.mood_predicted_already == true)
	        printf("Mood already predicted for the day.\nMeet you tommorow.");
	else{
        	printf("\nTo know your mood please answer the following questions.\n");
        	printf("(The questions below should be answered in Y/N format only.)\n");
        	printf("(In order to skip a question, press 's'.)\n\n");
        	
        	do{
            	printf("1. Are you feeling grateful today?\n\t-->");
              	scanf(" %c",&ans);
             	if(ans == 'Y' || ans == 'y')
             	    Happy++;
             	else if(ans == 'N' || ans == 'n')
             	    Sad++;
             	else  if (ans == 'S' || ans == 's')
             	    break;
             	else{
             	    printf("\n[Press Y or y for 'Yes' and N or n for 'No']");
             	    printf("\n[Press S or s to skip this question]\n\n");
             	}
        	}while(ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');
         	    
         	do{
             	printf("2. Do you feel motivated and satisfied?\n\t-->");
             	scanf(" %c",&ans);
             	if(ans == 'Y' || ans == 'y')
             	    Happy++;
             	else if(ans == 'N' || ans == 'n')
             	    Worried++;
             	else  if (ans == 'S' || ans == 's')
             	    break;
             	else{
             	    printf("\n[Press Y or y for 'Yes' and N or n for 'No']");
             	    printf("\n[Press S or s to skip this question]\n\n");
             	}
         	}while(ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');
         	
         	do{    
             	printf("3. Is your day going according to you?\n\t-->");
             	scanf(" %c",&ans);
             	if(ans == 'Y' || ans == 'y')
             	    Happy++;
             	else if(ans == 'N' || ans == 'n')
             	    Sad++;
             	else  if (ans == 'S' || ans == 's')
             	    break;
             	else{
             	    printf("\n[Press Y or y for 'Yes' and N or n for 'No']");
             	    printf("\n[Press S or s to skip this question]\n\n");
             	}
         	}while(ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');
         	
         	do{    
             	printf("4. Are you looking forward for your day?\n\t-->");
             	scanf(" %c",&ans);
             	if(ans == 'Y' || ans == 'y')
             	    Excited++;
             	else if(ans == 'N' || ans == 'n')
             	    Worried++;
             	else  if (ans == 'S' || ans == 's')
             	    break;
             	else{
             	    printf("\n[Press Y or y for 'Yes' and N or n for 'No']");
             	    printf("\n[Press S or s to skip this question]\n\n");
             	}
         	}while(ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');
         	    
         	do{
            	printf("5. Are your manifestations coming close?\n\t-->");
             	scanf(" %c",&ans);
             	if(ans == 'Y' || ans == 'y')
             	    Excited++;
             	else if(ans == 'N' || ans == 'n')
              	    Sad++;
              	else  if (ans == 'S' || ans == 's')
             	    break;
             	else{
             	    printf("\n[Press Y or y for 'Yes' and N or n for 'No']");
             	    printf("\n[Press S or s to skip this question]\n\n");
             	}
         	}while(ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');
          	    
          	if((Happy>Sad)&&(Happy>Excited)&&(Happy>Worried)){           
                strcpy(acc.mood,"Happy");                             
                printf("\nRESULT : \nGreat!!\nYour mood is happy!!\n\n");
                printf("\nWe hope you are satisfied with the result.");
                satisfied_with_result();
          	}
            else{
                if ((Sad>Excited) && (Sad>Worried)){
                    strcpy(acc.mood,"Sad");                         
                    printf("\nRESULT : \nAlas!!\nYour mood is sad.\n\n");
                    printf("\nWe hope you are satisfied with the result.");
                    satisfied_with_result();
                }
                else{
                    if (Excited>Worried){
                        strcpy(acc.mood,"Excited");                 
                        printf("\nRESULT : \nWhoopee!!\nYou are excited!!\n\n");
                        printf("\nWe hope you are satisfied with the result.");
                        satisfied_with_result();
                    }
                    else if(Worried>Excited){
                        strcpy(acc.mood,"Worried");                 
                        printf("\nRESULT : \nSeems, you are worried.\nRemember, you cannot run away from problems but worrying is not the solution.");
                        printf("\n\nWe hope you are satisfied with the result.");
                        satisfied_with_result();
                    }
                    else{
                        printf("\nAs you have skipped all the questions we cannot predict your mood.\nTry answering these questions.\n\n");
                        printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
                        mood_predictor_again();
                    }
                }
            }
            
            acc.mood_predicted_already = true;
	    }
}

int mood_predictor_again()                                    //Predict  the mood of the user as the user is not satisfied with the result
{  
	int Happy = 0, Sad = 0, Excited = 0, Worried = 0;         
	char ans;
	
	printf("\nTo know your mood please answer the following questions.\n");
	printf("(The questions below should be answered in Y/N format only.)\n");
	printf("(In order to skip a question, press 's'.)\n\n");
	
	do
	{
    	printf("1. Are you craving for sweets and chocolates?\n\t-->");
      	scanf(" %c",&ans);
     	if(ans == 'Y' || ans == 'y')
     	    Sad++;
     	else  if (ans == 'S' || ans == 's'|| ans == 'N' || ans == 'n')
     	    break;
     	else
     	{
     	    printf("\n[Press Y or y for 'Yes' and N or n for 'No']");
     	    printf("\n[Press S or s to skip this question]\n\n");
     	}
	}while(ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');
 	    
 	do
 	{
     	printf("2. Are you satisfied with how your life now is?\n\t-->");
     	scanf(" %c",&ans);
     	if(ans == 'Y' || ans == 'y')
     	    Happy++;
     	else  if (ans == 'S' || ans == 's'|| ans == 'N' || ans == 'n')
     	    break;
     	else
     	{
     	    printf("\n[Press Y or y for 'Yes' and N or n for 'No']");
     	    printf("\n[Press S or s to skip this question]\n\n");
     	}
 	}while(ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');
 	
 	do
 	{    
     	printf("3. Are you thinking about anything bad that might happen?\n\t-->");
     	scanf(" %c",&ans);
     	if(ans == 'Y' || ans == 'y')
     	    Worried++;
     	else  if (ans == 'S' || ans == 's'|| ans == 'N' || ans == 'n')
     	    break;
     	else
     	{
     	    printf("\n[Press Y or y for 'Yes' and N or n for 'No']");
     	    printf("\n[Press S or s to skip this question]\n\n");
     	}
 	}while(ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');
 	
 	do
 	{    
     	printf("4. Do feel like being over the moon?\n\t-->");
     	scanf(" %c",&ans);
     	if(ans == 'Y' || ans == 'y')
     	    Excited++;
     	else  if (ans == 'S' || ans == 's' || ans == 'N' || ans == 'n')
     	    break;
     	else
     	{
     	    printf("\n[Press Y or y for 'Yes' and N or n for 'No']");
     	    printf("\n[Press S or s to skip this question]\n\n");
     	}
 	}while(ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');
  	    
  	if((Happy>Sad)&&(Happy>Excited)&&(Happy>Worried))         
  	{           
        strcpy(acc.mood,"Happy");                             
        printf("\nRESULT : \nGreat!!\nYour mood is happy!!\n");
  	}
    else{
        if ((Sad>Excited) && (Sad>Worried))                  
        {
            strcpy(acc.mood,"Sad");                          
            printf("\nRESULT : \nAlas!!\nYour mood is sad.\n");
        }
        else
        {
            if (Excited>Worried)                            
            {
                strcpy(acc.mood,"Excited");                 
                printf("\nRESULT : \nWhoopee!!\nYou are excited!!");
            }
            else if (Worried > Excited)
            {
                strcpy(acc.mood,"Worried");                 
                printf("\nRESULT : \nSeems, you are worried.\nRemember, you cannot run away from problems but worrying is not the solution.");
            }
            else
                printf("\nSorry, can't predict your mood,as all the questions are skipped");
        }
    }
    printf("\nWe hope you are satisfied with the result.");
    
    satisfied_with_result();
}

 
int satisfied_with_result()
{
    char ans;
    
    FILE *ptr;
    ptr = fopen("Mood.txt", "a");

    do
    {
    printf("\n\nAre you are unsure about your mood, do you want to again take the quiz?\n(Please, answer in Y/N format)\n\t=>");
    scanf(" %c",&ans);

        if (ans == 'Y' || ans == 'y')
        {
            mood_predictor_again();
        }
        else if(ans == 'N' || ans == 'n')
        {
            fprintf(ptr, "\n%s", acc.mood);                        
            fclose(ptr);
            acc.days++;                 //Increment days as there is new mood stored in the file, this update will be visible in the menu and when history is printed
        }
        else
            printf("\n[Enter 'Y', if you want to retake the quiz or 'N', if you are satified the result.]");
    }while(ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');
}

int mood_enhancer()                                        //Give suggestions to the user in order to improve the mood
{
    char mood;
    
    printf("\nChoose your mood : {h} Happy\t\t{s} Sad\t\t{e} Excited\t\t{w} Worried\t\t: ");
    scanf(" %c", &mood);
    
    switch(mood)
    {
        case 'h':                                        
        case 'H':
            printf("\nTry spreading your happiness around you with your vibrant smile.");
            break;
            
        case 's':                                         
        case 'S':                
            printf("\nHere are some of our suggestions to uplift your mood :\n\tListening songs can help you get in better mood. ♫\n\tWrite in a journal your feeling.  \n\tWatch comic sketches.  \n\tTalk to your loved ones.");    
            break;
            
        case 'e':                                         
        case 'E':
            printf("\nHope your day goes the way you claimed.");
            break;
            
        case 'w':                                        
        case 'W':
            printf("\nTry doing these :\n   Practice deep breathing.\n   Discuss your problem with someone whom you trust.\n   Be patient.\n   Take a deep breath.....");
            printf("\n");
            int iterations = 0;
            int msec = 0, trigger = 1000; // 10ms 
            clock_t before = clock();
            do{
                for (int i = 0; i < 100; i++);
                clock_t difference = clock () - before;
                msec = difference * 100 / CLOCKS_PER_SEC;
                iterations++;
            } while (msec < trigger/2);
            printf("\n   Now, exhale.");
	        break;

        default :
            printf("\nPlease enter the initial of your mood.\nFor example : Press 'H' or 'h' if you are happy.");
            mood_enhancer();
            break;
    }
}

int number_of_days()                                 //Count the number of days for which the user detected the mood 
{
    FILE *ptr;
    ptr = fopen("Mood.txt", "r");
    
    char i;
    
    if (ptr == NULL){
        printf("\nDay : 1");
        return 0;
    }
    
    while ((i = fgetc(ptr)) != EOF){
        if (i == '\n')                             
            acc.days++;                            //Increment days   (since, number of lines = number of days)
    }
    fclose(ptr);

    printf("\nDay : %d", acc.days+1);             
}

int mood_history()                                //Print the mood of the user in a file
{  
    int day =  1;
    
    FILE *ptr;
    ptr = fopen("Mood.txt", "r");
    if (ptr == NULL){
        printf("After you predict your mood, we will show you the history of your moods.");
        return 0;
    }
    else{
        printf("\nYour mood for the past %d day(s) are as follows : \n", acc.days);  
        
        while(!feof(ptr)){
            fscanf(ptr, "%s", acc.mood);           
            printf("Day %02d => %s\n",day,acc.mood);
            day++;
        }
    }
    
    fclose(ptr);
}

int more_about_us()
{
    printf("Hi, %s!!",acc.name);
    printf("\nThis mood predicting system will help you in detecting your mood, we can suggest you some tips to enhance your mood and track your mood if you want to check it in the future.");
    printf("\n\nHere, we have four moods, which are 'Happy', 'Sad', 'Worried' and 'Excited'");
    printf("\n\nIf you want to know your mood, press '1'. \nYou will be put through some questions.\nKindly answer them in Y/N format only\n[Press Y or y for 'Yes' and N or n for 'No']\nBased on your answers, we will detect your mood.");
    printf("\n\nIf in case, you are unsure about your mood. You can retake the quiz by pressing 'Y', you'll be taken to the questionnaire,again. \nElse, press 'N' as you are ssatisfied with the result.");
    printf("\n\nNow, that you know your mood but are confused what to do next, then press '2'. \nThen enter the initial of your mood.\nFor example : Press 'H' or 'h' if you are happy.\nAnd, you will get suggestions which will help you get in better mood.");
    printf("\n\nDo feel like you experience a lot of mood swings and unfortunately are not sure about it.\nDo not worry!!\nJust press '3'. \nNow, you have the history of the past days since day 1, so you can be sure about your mood swings.");
}

int main()
{   
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ Mood Detecting System +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
    
    printf("Enter your name : ");
    scanf(" %s",acc.name);
    
    printf("\nWelcome %s, to our mood detecting system!!\n",acc.name);
    printf("Here, our aim is to detect your mood and help you in tracking the same.\n");
    
    number_of_days();
    int choice;
    
    do
    {
        printf("\n______________________________________________________________________________________________________________________________________________________\n");
        printf("\n{1} Check your mood\n{2} Enhance your mood\n{3} Check your mood for the past %d day(s)\n{4} Help\n{5} Exit\n\nEnter your choice : ", acc.days);
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            system("clear");
            printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ Mood Detecting System +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
            mood_predictor();
            break;
            
            case 2:
            system("clear");
            printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ Mood Detecting System +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
            mood_enhancer();
            break;
            
            case 3: 
            system("clear");
            printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ Mood Detecting System +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
            mood_history();
            break;
            
            case 4:
            system("clear");
            printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ Mood Detecting System +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
            more_about_us();
            break;
            
            case 5:
            system("clear");
            printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ Mood Detecting System +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
            printf("\nThankyou!!!\nHave a great day ahead!!");
            break;
            
            default:
            printf("\nPlease enter a number between 1 and 5\n");
            
        }
    }while (choice != 5);
}





