/*
 	tuition calculator that will calculate the base tuition for enrollment and then add on fees for the number of courses, for the book pack if purchasedfor parking fees and for out of state tuition. 	
	usage: tuition [-bs] [-c cnum] [-p pnum] base

	Jose Hichez
	PID:6186740 
	I affirm that I wrote this program myself without any help from any other people or sources from the internet 
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){ /*initializing vars*/

	extern char *optarg;
	extern int optind;
	int c; 
	int cflag=0, sflag=0, bflag=0, pflag=0;
	char *pnum,*cnum,*base; /*null pointer var*/
	int BaseofTuition,Courses,OutofStateCourses,ParkingFee;
	double Tuition; /*assings a base to 0*/ 
	static char usage[] = "usage: %s tuition [-bs] [-c cnum] [-p pnum] base\n";

	while ((c = getopt(argc, argv, "c:sbp:")) != -1) /*iterates through command line args until it ends*/
		switch (c) { /*starts switch*/
		case 'c':
			cflag = 1;
			cnum=optarg;	
			OutofStateCourses=atoi(cnum); 	
			break;
		case 's':
			sflag = 1;
			break;
		case 'b':
			bflag = 1;
			break;
		case 'p':
			pflag =1;
			pnum=optarg;
			ParkingFee=atoi(pnum);
			break;
		case ':':
			printf("Error:Provide value\n");/*breaks out of switch*/
			break;
		case '?':
			printf("Error:Invalid argument\n");	/*breaks out of switch*/
		}
	for(;optind<argc;optind++) {
		base=argv[optind];
		BaseofTuition=atoi(base);
	}
		Tuition+=BaseofTuition;
		Courses=3;
	/*main logic*/
	if(BaseofTuition<1000 || BaseofTuition>4000){	/*checks if the base is between 1000 & 4000*/ 
		fprintf(stderr,"%s:missing base\n",argv[0]);
	       	fprintf(stderr,usage,argv[0]);
		exit(1);
	}
	if(cflag==1){
		if(OutofStateCourses>=1&&OutofStateCourses<=4){
			Tuition+=OutofStateCourses*300;
			Courses+=OutofStateCourses;
		}
		else{
			fprintf(stderr,"result:value of the course is not inbound,has to be between 1&4\n",argv[0]);
		    	fprintf(stderr,usage,argv[0]);
			exit(1);
		}
	}
	if(OutofStateCourses<=1&&OutofStateCourses>=4){
		fprintf(stderr,"result:not a valid number of courses\n",argv[0]);  /*error message if extra courses are not between 1 & 4*/
		fprintf(stderr,usage,argv[0]);
		exit(1);
	}
	if(sflag==1){
		Tuition+=(Tuition*0.25);  /*adds 25% to the bace*/
	}
	if(bflag==1){
		Tuition+=(Courses*50);   /*adds a per course fee of 50 on top of the base for the book pack*/
	}
	if(pflag==1){
		if(ParkingFee>=25&&ParkingFee<=200){  /*parking fee*/ 
			Tuition+=ParkingFee;
		}
		else{
			fprintf(stderr,"result:the fee that was added is not valid\n",argv[0]);
		       	fprintf(stderr,usage,argv[0]);
			exit(1);
		}
}
	/*get output for tuition after adding up all extra fees*/
	printf("result:%.2f\n",Tuition);
	exit(0);

	}
