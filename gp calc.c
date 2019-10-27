/*  Author: Uchegbu Damianson-Wisdom Onyekachi with snippets from Sir Bhatt; C Programming Beast
*	Description: Calculates total GPA for a semester */

#include <stdio.h>
#include <string.h>

#define MAX_COURSE 10 //total number of courses

enum grades {
	A,B,C,D,E,F
} grade_t;

/*
	name: name of the course (Course code) limit 10 Characters
	credits: credit load of the course
	grade: grade allocated to the course... if you know what i mean..lol
*/

struct course {
	char name[10];
	int credits;
	float grade;
};

/* Display courses...
	c'mon this thing has to look fine abi?
	courses: courses entered
	size: number of courses */
	
void displayCourses(struct course courses[], int size){
	int i;
	puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++"); // 54
	puts("+          Courses          |         Grades         +");
	puts("+----------------------------------------------------+");
	for (i = 0; i < size; i++){
		//puts("+                                                    +");
		printf("%d). %s\t\tCredits: %d\t Grade: %.3f\n",i+1,courses[i].name, courses[i].credits, courses[i].grade);
		//puts("+                                                    +");
		puts("+----------------------------------------------------+");
	}
}

/* This is the real deal.... where all the calculation is done */

void calculateGPA(const struct course courses[], int size, float grade_points, int units, float *tgpa, float *sgpa){
	float points = grade_points;
	int cred = units;
	int i;
	for (i = 0; i < size; i++){
		points += courses[i].credits * courses[i].grade; // add to the total points
		cred += courses[i].credits; // add to the total credits
	}
	// GPA = Grade Points / Number of Credits
	*tgpa = points/cred; // total GPA
	*sgpa = (points - grade_points)/(cred - units); // Semester GPA
}

/* Here comes the part where we assign values to the grades, eh hen.... i heard that E has been added to our grading system now so */

float getGradeValue(int grade){
	switch (grade){
		case A :
			return 5;
		case B :
			return 4;
		case C :
			return 3;
		case D :
			return 2;
		case E :
			return 1.;
		case F :
			return 0.;
	}
	return -1;
}

/* Yeah i added a grade menu.... for those people that dont know the points associated to the grades.. */

void displayGradeMenu() {
	puts("\t\t(0) A\t(5)\n\t\t(1) B\t(4)\n\t\t(2) C\t(3)\n\t\t(3) D\t(2)\n\t\t(4) E\t(1)\n\t\t(5) F\t(0)\n");
	return;
}

// Where we enter our couses.. finally!

void getCourses(struct course courses[], int *size){
	struct course c; // temporary struct to store current entered course
	int grade;
	int credit;
	char stop = 'y'; // if not y then stop
	int i = 0;
	int result; //temp variable for detecting success of user input
	char temp[50]; // temp variable to get user input from stdin

	while((stop == 'y') && (i < MAX_COURSE)){ // if user did not press y or if MAX_COURSE courses have been added, break
		// Get course name
		printf("\n");
		printf("\tDetails for Course %d\n\n", i+1);
		puts("\t[A]\tEnter course name:");
		printf("\t\t");
		fgets(c.name, 50, stdin);
		// Get number of credits
		printf("\n");
		puts("\t[B]\tEnter number of credits:");
		printf("\t\t");
		fgets(temp, 50, stdin);
		result = sscanf(temp, "%2d", &credit); // format user input
		while (result != 1){ //Prompt user if invalid
			puts("\t\tRead failed. Please enter a valid number:");
			printf("\t\t");
			fgets(temp, 50, stdin);
			result = sscanf(temp, "%2d", &credit);
		}
		c.credits = credit; // store credit into temp variable
		// Get estimated grade
		printf("\n");
		puts("\t[C]\tSelect grade (type the number shown at the right hand side of the grade):");
		displayGradeMenu(); // display options
		printf("\t\t");
		fgets(temp, 50, stdin);
		result = sscanf(temp,"%1d", &grade); // format user input
		while (result != 1){ // Prompt user if invalid
			puts("\t\tRead failed. Please enter a valid number:");
			printf("\t\t");
			fgets(temp, 50, stdin);
			result = sscanf(temp,"%1d", &grade);
		}
		c.grade = getGradeValue(grade);// store grade into temp variable
		// Store temp struct course into courses array
		strcpy(courses[i].name, c.name);
		courses[i].credits = c.credits;
		courses[i].grade = c.grade;
		i++; // Add 1 to the number of courses added
		//Prompt user to enter another course if MAX_COURSE courses have not been added
		if (i >= MAX_COURSE){
			puts("\n\tCourses stored!\n\n\tMaximum number of courses have been entered.\n\tPress enter to get results.\n\n");
			getchar();
		}else{
			printf("\n\tCourse Added!\n\n[%d]\tTo add another course press (y).\n\tOtherwise press enter to exit course addition.\n", i+1);
			printf("\t");
			stop = getchar(); // get user input

			if (stop == 'y'){
				getchar(); //clear buffer of Enter

			}
		}
	}
	*size = i; // store number of courses for return
}
/*
 * main
 *
 * Carries out the main flow for user.  Prompts user to input data to calculate GPA
 */
int main (int argc, char ** argv){
	float grade_points; // total number of grade points
	int result; // temp variable for detecting success of user input
	int units; // number of credits taken
	int numCourses = 0; // number of courses
	struct course courses[MAX_COURSE]; // list of courses
	float gpa; //total GPA
	float semester_gpa; // semester GPA
	char c; // used to detect whether courses are needed to be entered
	char temp[50]; // temp variable to get user input from stdin


	puts("[1]\tPress 'y' to enter courses to calculate your estimated GPA.\n\tOtherwise press enter.\n");
	printf("\t");
	c = getchar();
	if( c == 'y') { // if yes (c='y') then add courses
		getchar(); // clear input
		getCourses(courses, &numCourses); // get courses
		displayCourses(courses, numCourses); // display entered courses
		calculateGPA(courses, numCourses, grade_points, units, &gpa, &semester_gpa); // calculate new gpa
		printf("\nYour estimated semester GPA:\t%.3f\n\n", semester_gpa); // echo estimated semester gpa round to 3 decimal places
		printf("Your estimated total GPA:\t%.3f\n\n\n", gpa); // echo estimated gpa round to 3 decimal places
	}
	puts("Press Enter to Exit..."); // Prompt user to press enter before exiting so they can view results
	getchar();

	return 0;
}
