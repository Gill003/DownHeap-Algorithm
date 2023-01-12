//Bhavjot Gill (1186643)
//Assignment 4-Q1
//C program which reads text from a f.dat file and stores it an array as objects, thep uing a downheap algorithm it 
//sorts the array and prints it out
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Create an oject that has SUM,key and content to store each row of the array
typedef struct Node{
    int SUM;
    int key[3];
    int content[7];
}Node;
//function which splits each row and stores it in an array
int *splitchar(char line[256]){
    char spp[] = " ";
    static int arr[10];
    int i=0;
    char *ptr = strtok(line,spp);
        while(ptr != NULL)
	{
        int ti=atoi(ptr);
        arr[i]=ti;
		ptr = strtok(NULL, spp);
        i++;
	}
    return arr;
}

//Sorts the array in decending order using downheap algorithm
void Heapsort(Node SARR[20]){
int done=0;
int count=0;
while(done==0){
     for (int i = 9; i>=0 ;i--)
 {  
    if(i==9){
        //checks if child is less than parent then swicthes
        if(SARR[(2*i)+1].SUM<SARR[i].SUM && ((2*i)+1)<20){
            Node temps=SARR[(2*i)+1];
            SARR[(2*i)+1]=SARR[i];
            SARR[i]=temps;
            count++;
        }
    }
    //checks which child is lower
    else if(SARR[(2*i)+1].SUM<SARR[(2*i)+2].SUM && i<9){
        //checks if child is less than parent then swicthes
        if(SARR[(2*i)+1].SUM<SARR[i].SUM && ((2*i)+1)<20){
            Node temps=SARR[(2*i)+1];
            SARR[(2*i)+1]=SARR[i];
            SARR[i]=temps;
            count++;
        }
    }
    //checks which child is lower
    else if(SARR[(2*i)+1].SUM>SARR[(2*i)+2].SUM && ((2*i)+2)<20 )
    {
        //checks if child is less than parent then swicthes
        if(SARR[(2*i)+2].SUM<SARR[i].SUM){
            Node temps=SARR[(2*i)+2];
            SARR[(2*i)+2]=SARR[i];
            SARR[i]=temps;
            count++;
        }
    }
}
//ends loop if no swicthes are made and the array is organzied
if(count==0){
done++;
}
count=0;
}
//prints the heap sorted array
   for(int i=0;i<20;i++){
        for(int k=0;k<10;k++){
            if(k<3){
            printf("%i ",SARR[i].key[k]);
            }
            else if(k>=3){
            printf("%i ",SARR[i].content[k-3]);
            }
        }
        printf("\n");
   }
}
int main(){
Node ARR[20];
int *n;
int numsarr[20][10];
//reads the f.dat file
FILE* file = fopen("f.dat", "r"); 
    char line[256];
    int j=0;
   while (fgets(line, sizeof(line), file)) {
        //runs function to split the row
        n=splitchar(line);
        for(int t=0;t<10;t++){
            numsarr[j][t]=n[t];
        }
        j++;
    }
    fclose(file);
;
int sum=0;
//stores each row as an object
    for(int i=0;i<20;i++){
        for(int k=0;k<10;k++){
            if(k<3){
            sum=numsarr[i][k]+sum;
            ARR[i].key[k]=numsarr[i][k];
            }
            else if(k>=3){
            ARR[i].content[k-3]=numsarr[i][k];
            }
        }
        ARR[i].SUM=sum;
        sum=0;
    }
    Heapsort(ARR);
    return 0;
}
