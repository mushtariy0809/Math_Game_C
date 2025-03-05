#include <stdio.h>
#include <stdlib.h>

void displ_questions(char** questions, int* user_ptr, int user);
int calc_score(int user, int* user_ptr, int* answers);
void displ_results(char** questions, int* answers, int* user_ptr, int user);


int main () {
	printf("Welcome to the game of Math >_< \n");

	int gameStatus = 1;

	while(gameStatus == 1) {

		int user = 5;
		int answers[5] = {2, 4, 6, 8, 7};

		char* questions[] = {
       		 "1. Question: 1 + 1? ",
        	 "2. Question: 6 - 2? ",
       		 "3. Question: 8 - 2? ",
        	 "4. Question: 4 + 4? ",
        	 "5. Question: 5 + 2? ",
		};


		int* user_ptr;
		user_ptr = (int*) malloc(user * sizeof(int));

		if(user_ptr == NULL){
			printf("Memory allocation failed\n");
			return 0;
		}
		
	 	displ_questions(questions, user_ptr,user);

		
		 printf("Wished to continue? 1(yes) 2(display results) 3(no): \n");
	 	 scanf("%d",&gameStatus);

	 	 if( gameStatus == 2){
		 	int score = calc_score(user, user_ptr, answers);
		 	printf("You got %d / %d\n",score, user);
			displ_results(questions, answers,user_ptr,user);
		 }
		 	printf("Wished to continue? 1-(yes) 3-(no): \n");
                 	scanf("%d",&gameStatus);
		 
		        free(user_ptr); 
	}
	return 0;


			 printf("Thank You for Playing, (exiting the game . . . )\n");
			 return 0;
		 
	
	}
void displ_questions(char** questions, int* user_ptr, int user){
	 for(int i =0; i<user; i++){
                  printf("%s", questions[i]);
                  scanf("%d", user_ptr +i);
	 }
}

int calc_score(int user, int* user_ptr, int* answers){
	 int score = 0;
         for (int i =0; i<user;i++){
               if(user_ptr[i] == answers[i]){
                        score++;
	       }
	 }
                 return score;
}
void displ_results(char** questions, int* answers, int* user_ptr, int user){
	 printf("Results:\n");
         for(int i =0; i< user; i++){
                printf("%s | Your answer: %d | Correct answer: %d | %s\n", questions[i], user_ptr[i],answers[i], user_ptr[i] == answers[i] ? "Correct" : "Incorrect");
        }
}
