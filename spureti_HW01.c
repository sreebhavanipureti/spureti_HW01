#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>

typedef struct studentDatasetCsv {
char firstName[100];
char lastName[100];
char major[100];
char degree[100];
char gpa[100];
char creditHours[100];
char ta[100];
char advisor[100];
} student;

typedef struct department_Advisor {
	char department[100];
	char advisor[100];
	int count[100];
} da;


void getAllDifferentDegree(int rows);
void convertToFloat(int rows);
void averageGpaForComputerScience(int rows);
void getDepartmentsAndAdvisor(int rows);
void averageCreditHours(int rows); 

student values[999];

int main() {

	// please make sure, file is saved as CSV 
	FILE *filePointer=fopen("students_dataset.csv","r");

if(filePointer!=NULL){
    //get length of file
        char  characterBuffer[1024];
        int row_count=0;
        int column_count=0;
       
        int i=0;
        while(fgets(characterBuffer,1024,filePointer))
        {
        	column_count =0;
        	row_count++;
        	if(row_count ==1)
        		continue;
        	char *record = strtok(characterBuffer, ",");
        	while(record)
        	{
        		if(column_count==0)
        		{
						strcpy(values[i].firstName, record);
				}
				if(column_count==1)
        			strcpy(values[i].lastName, record);
        		if(column_count==2)
        			strcpy(values[i].major, record);
        		if(column_count==3)
        			strcpy(values[i].degree, record);
        		if(column_count==4){
        			strcpy(values[i].gpa, record);
        		}
				if(column_count==5)
        			strcpy(values[i].creditHours, record);
        		if(column_count==6)
        			strcpy(values[i].ta, record);
        		if(column_count==7)
        			strcpy(values[i].advisor, record);
        			
        		record =  strtok(NULL, ",");
        		column_count++;
			}
			i++;
		}
		fclose(filePointer);
		
printf("\n ----------------------Question1------------------------------------\n");
getAllDifferentDegree(i);

printf("\n ----------------------Question2------------------------------------\n");
convertToFloat(i);

printf("\n ----------------------Question3------------------------------------\n");
averageCreditHours(i);

printf("\n ----------------------Question4------------------------------------\n");
averageGpaForComputerScience(i);

printf("\n ----------------------Question5------------------------------------\n");
getDepartmentsAndAdvisor(i);


}
}

void getAllDifferentDegree(int rows)
{
	student listofDegree[rows];
	student newList[rows];
	int index = 0;
	int i=0, j=0;
	int f = 0;
	
	for(i=0;i<rows;i++)
	{
		for(j=0;j<rows;j++){
			
		if(strcmp(listofDegree[j].degree, values[i].degree)==0)	{
			f=1;
			break;
		
		}
	}
	if(f==0)
	{
		listofDegree[index] = values[i];
		index++;
		f=0;
	}
	else
	{ f=0;
	}
	}
	printf("\n Total Number of degree's :%d \n",index);
	printf(" [ ");
	for(i=0;i<index;i++)
	printf(" %d: %s  ", i+1, listofDegree[i].degree);
	printf(" ]");
}
void convertToFloat(int rows) {
	/*Converting GPA to Float (We have Stored Every Column as character datatype...)*/
	float gpa[rows];
	float f;
	int i=0,lindex=0;

	for(i=0;i<rows;i++)
	{
		gpa[i] = (float)atof(values[i].gpa);
	}
	
	int gpaIndexArray[rows];
	
	//getting top three GPA
	 float gpa1, gpa2, gpa3;
    for (i = 0; i < rows; i++) {
       
        if (gpa[i] > gpa1) {
            gpa3 = gpa2;
            gpa2 = gpa1;
            gpa1 = gpa[i];
        }
 
       
        else if (gpa[i] > gpa2 && gpa[i] < gpa1) {
            gpa3 = gpa2;
            gpa2 = gpa[i];
        }
 
        else if (gpa[i] > gpa3 && gpa[i] < gpa2)
            gpa3 = gpa[i];
    }
    printf("GPA 1: %f\n", gpa1);
	// get the index of the three elements..
    int index = 0;
    for(i=0;i<rows;i++)
    {
    	if(gpa1 == gpa[i])
    		{
    		gpaIndexArray[index++]=i;
			}
    		
	}
    for( i=0;i<index;i++)
	{
		printf("\n %s %s  \n",values[gpaIndexArray[i]].firstName, values[gpaIndexArray[i]].lastName);
		lindex = i;
	}
	printf("\n");
    printf("GPA 2: %f\n", gpa2);

	 for(i=0;i<rows;i++)
    {
    	if(gpa2 == gpa[i])
    		{
    		gpaIndexArray[index++]=i;
			}
	}
for( i=lindex+1;i<index;i++)
	{
		printf("\n %s %s  \n",values[gpaIndexArray[i]].firstName, values[gpaIndexArray[i]].lastName);
		lindex = i;
	}
	printf("\n");

printf("GPA 3: %f\n", gpa3);

	 for(i=0;i<rows;i++)

    {
    	if(gpa3 == gpa[i])
    		{
    		gpaIndexArray[index++]=i;
			}
}
	for( i=lindex+1;i<index;i++)
	{
		printf("\n %s %s  \n",values[gpaIndexArray[i]].firstName, values[gpaIndexArray[i]].lastName);
	}
  
}
void averageGpaForComputerScience(int rows){
	
		float gpa[rows];
	float f;
	int i=0;

	for(i=0;i<rows;i++)
	{
		gpa[i] = (float)atof(values[i].gpa);
	}
	float arrayToCalculateAverageGpa[rows];
	int index=0;
	float sum =0;
	for(i=0;i<rows;i++)
	{
		if(strcmp(values[i].major,"Computer Science")==0)
		{
			sum = sum + gpa[i];
			index ++;
		}
	}

double avg = sum/(float)index;
	printf("\n Average GPA for  computer Science: %.5f",avg);
}
void getDepartmentsAndAdvisor(int rows) {
	student listofDepartments[rows];
	da departmentAdvisor[rows];
	int index = 0;
	int i=0, j=0;
	int f = 0;
	
	for(i=0;i<rows;i++)
	{
		for(j=0;j<rows;j++){
			
		if(strcmp(listofDepartments[j].major, values[i].major)==0)	{
			f=1;
			break;
		
		}
	}
	if(f==0)
	{
			if(strcmp(values[i].major,"Undeclared")==0)
			f=0;
			else{
			
			listofDepartments[index] = values[i];
			index++;
			f=0;
		}
	}
	else
	{ f=0;
	}
	}

	//collecting all advisors for a department;
	int newIndex = 0;
	for(i=0;i<index;i++)
	{
		for(j=0;j<rows;j++){
		if(strcmp(values[j].major,listofDepartments[i].major)==0)
		{
			strcpy(departmentAdvisor[newIndex].advisor, values[j].advisor);
			strcpy(departmentAdvisor[newIndex].department, listofDepartments[i].major);
			newIndex++;
		}
	}
	}
	// removing duplicates from departmentAdvisor for Advisors;
	da newList[100];
	int index2 =0;
	f = 0;
	for(i=0;i<newIndex;i++)
	{
		for(j=0;j<newIndex;j++){
		char *strfound = strchr(departmentAdvisor[i].advisor,'\r');
		    if(strfound !=NULL)
		    {
		        int len = strlen(departmentAdvisor[i].advisor) - strlen(strfound);
		        for(int a = len; a < strlen(departmentAdvisor[i].advisor); a++ )
		        {
		            departmentAdvisor[i].advisor[a] = departmentAdvisor[i].advisor[a+1];
		        }
		    }
		    strfound = strchr(newList[j].advisor,'\r');
		    if(strfound !=NULL)
		    {
		        int len = strlen(newList[j].advisor) - strlen(strfound);
		        for(int a = len; a < strlen(newList[j].advisor); a++ )
		        {
		            newList[j].advisor[a] = newList[j].advisor[a+1]; 
		        }
		    }	
		if(strcmp(departmentAdvisor[i].advisor, newList[j].advisor)==0 && strcmp(departmentAdvisor[i].department, newList[j].department)==0)	{
			f=1;
			break;
		
		}
	}
	if(f==0)
	{		
			newList[index2] = departmentAdvisor[i];
			index2++;
			f=0;
	}
	else
	{ f=0;
	}
	}
	// new List of departments and their advisors...
	// printing count of advisors for a department...

		int c = 0;	
	for(i=0;i<index;i++)
	{
		for(j=0;j<index2;j++)
		{
		    if(strcmp(listofDepartments[i].major, newList[j].department)==0)
			{
				c++;
			}
		}
		printf("\n");
		printf("%s - %d\n",listofDepartments[i].major,c);
		c=0;
	}
	
}
void averageCreditHours(int rows) {
	
	int creditHours[rows];
	int i=0;
	int sum =0;
	for(i=0;i<rows;i++)
	{
		creditHours[i] = (int)atoi(values[i].creditHours);
		sum = sum + creditHours[i];
	}
	float average = (float)sum / (float)rows ;
	printf(" Average Credit Hours: %.2f ",average);
}
