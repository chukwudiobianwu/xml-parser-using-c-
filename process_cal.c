#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LEN 200
#define MAX_EVENTS 1000

/*
    Function: main
    Description: represents the entry point of the program.
    Inputs: 
        - argc: indicates the number of arguments to be passed to the program.
        - argv: an array of strings containing the arguments passed to the program.
    Output: an integer describing the result of the execution of the program:
        - 0: Successful execution.
        - 1: Erroneous execution.
*/ 
struct Order{
char description[MAX_EVENTS];
char timezone[MAX_EVENTS];
int day[MAX_EVENTS];
char location[MAX_EVENTS];
int month[MAX_EVENTS];
int year[MAX_EVENTS];
char dweek[MAX_EVENTS];
int starta[MAX_EVENTS];
char startb[MAX_EVENTS];
int enda[MAX_EVENTS];
char endb[MAX_EVENTS];
};
struct Order ord[MAX_EVENTS];

char *twelvehrclo(int da,int su,char *bru,char *cru){
    int hre=da;
    int br=su;
    char slom[MAX_EVENTS];
    char slik[MAX_EVENTS];
    char *slo;
    char *slj;
    if(da > 12){
        hre -=12;
        sprintf(slom,"%d:%spm",hre,bru);
        slo=slom;
    }else if(da <= 12){
        sprintf(slom,"%d:%sam",da,bru);
        slo=slom;
    }
    if(su > 12){
        br -=12;
        sprintf(slik,"%d:%spm",br,cru);
        slj=slik;
    }else if(su <= 12){
        sprintf(slik,"%d:%sam",su,cru);
        slj=slik;
    }
 sprintf(slo,"%s : %s",slo,slj);
return slo;
}
char* getMonth(int mon)
{
    char* month;
  
    switch (mon) {
    case 1:
        month = "January";
        break;
    case 2:
        month = "February";
        break;
    case 3:
        month = "March";
        break;
    case 4:
        month = "April";
        break;
    case 5:
        month = "May";
        break;
    case 6:
        month = "June";
        break;
    case 7:
        month = "July";
        break;
    case 8:
        month = "August";
        break;
    case 9:
        month = "September";
        break;
    case 10:
        month = "October";
        break;
    case 11:
        month = "November";
        break;
    case 12:
        month = "December";
        break;
    }
    return month;
}
void filled(char *nameoffile, int month[], int day[]){
char *description[MAX_EVENTS];
FILE *fpointer;
fpointer = fopen(nameoffile, "r");
char line[MAX_LINE_LEN];
int ai=-1;
char *simp;
char *slop;
char *slo;
while(fgets(line,MAX_LINE_LEN,fpointer) != NULL){
simp =  strtok_r(line," >", &slop);
if(strcmp(simp,"<event") == 0){
ai++;
}
if(strcmp(simp,"<description") == 0){
 strcpy(ord[ai].description,strtok(slop, "<"));
}
if(strcmp(simp,"<timezone") == 0){
 strcpy(ord[ai].timezone,strtok(slop, "<"));
}
if(strcmp(simp,"<location") == 0){
 strcpy(ord[ai].location,strtok(slop, "<"));
}
if(strcmp(simp,"<day") == 0){
 sscanf(slop, "%d</day>",ord[ai].day);
}
if(strcmp(simp,"<month") == 0){
 sscanf(slop, "%d</month>",ord[ai].month);
}
if(strcmp(simp,"<year") == 0){
 sscanf(slop, "%d</year>",ord[ai].year);
}
if(strcmp(simp,"<dweek") == 0){
 strcpy(ord[ai].dweek,strtok(slop, "<"));
}
if(strcmp(simp,"<start") == 0){
 sscanf(slop, "%d:%2s</start>",ord[ai].starta,ord[ai].startb);
}
if(strcmp(simp,"<end") == 0){
 sscanf(slop, "%d:%2s</end>",ord[ai].enda,ord[ai].endb);
}
}
int m;
int v[MAX_EVENTS];
int s[MAX_EVENTS];
int d[MAX_EVENTS];
int p=0;
 for(m=0;m<ai+1;m++){
if(*ord[m].month >= month[0] & month[1] >= *ord[m].month){
  
v[p] = *ord[m].month;
d[p]=m;
p++;

}
}

int i;
int j;
int tems;
int tek;
int sem;
    for (i = 0; i < p-1; i++)
    {
        for (j = i+1; j < p; j++){
          if (v[j] < v[i]){
            tems = d[j];
            d[j]=d[i];
            d[i]=tems;
            tek= v[j];
            v[j]=v[i];
            v[i]=tek;
    }
    }
    } 
int gh;
int gb;
for (i = 0; i < p-1; i++)
    {
        for (j = i+1; j < p; j++){
          if (*ord[d[j]].day < *ord[d[i]].day & v[i] == v[j]){
                gb= v[j];
            v[j]=v[i];
            v[i]=gb;
            gh = d[j];
            d[j]=d[i];
            d[i]=gh;
    }
    }
    }
    int yu;
    int uh;
    for (i = 0; i < p-1; i++)
    {
        for (j = i+1; j < p; j++){
          if (*ord[d[j]].starta < *ord[d[i]].starta & v[i] == v[j] & *ord[d[j]].day == *ord[d[i]].day ){
                yu= v[j];
            v[j]=v[i];
            v[i]=yu;
            uh = d[j];
            d[j]=d[i];
            d[i]=uh;
    }
    }
    }
    int sp;
    int amoun;
    char name[1500];
    int spz;
    
    sprintf(name,"%s %d, %d (%s)",getMonth(*ord[d[0]].month), *ord[d[0]].day,*ord[d[0]].year,ord[d[0]].dweek);
    sp = strlen(name);
    printf("%s %d, %d (%s)\n",getMonth(*ord[d[0]].month), *ord[d[0]].day,*ord[d[0]].year,ord[d[0]].dweek);
    for(spz=0; spz<sp ; spz++){
        printf("-");
    }
    printf("\n%s %s {{%s}} | %s\n",twelvehrclo(*ord[d[0]].starta,*ord[d[0]].enda,ord[d[0]].startb,ord[d[0]].endb),ord[d[0]].description,ord[d[0]].location,ord[d[0]].timezone);
    int spec;
    int so;
if(p>1){
for(spec=1; spec<p ; spec++){
if(*ord[d[spec]].day == *ord[d[spec-1]].day & v[spec] == v[spec-1]){
    printf("%s %s {{%s}} | %s",twelvehrclo(*ord[d[spec]].starta,*ord[d[spec]].enda,ord[d[spec]].startb,ord[d[spec]].endb),ord[d[spec]].description,ord[d[spec]].location,ord[d[spec]].timezone);
    }
else if(v[spec] != v[spec-1]){
    sprintf(name,"%s %d, %d (%s)",getMonth(*ord[d[spec]].month), *ord[d[spec]].day,*ord[d[spec]].year,ord[d[spec]].dweek);
    sp = strlen(name);
    printf("\n\n%s %d, %d (%s)\n",getMonth(*ord[d[spec]].month), *ord[d[spec]].day,*ord[d[spec]].year,ord[d[spec]].dweek);
    for(spz=0; spz<sp ; spz++){
        printf("-");
    }
    printf("\n%s %s {{%s}} | %s\n",twelvehrclo(*ord[d[spec]].starta,*ord[d[spec]].enda,ord[d[spec]].startb,ord[d[spec]].endb),ord[d[spec]].description,ord[d[spec]].location,ord[d[spec]].timezone);
}
else if(v[spec] == v[spec-1] & *ord[d[spec]].day != *ord[d[spec-1]].day){
    sprintf(name,"%s %d, %d (%s)",getMonth(*ord[d[spec]].month), *ord[d[spec]].day,*ord[d[spec]].year,ord[d[spec]].dweek);
    sp = strlen(name);
    printf("\n\n%s %d, %d (%s)\n",getMonth(*ord[d[spec]].month), *ord[d[spec]].day,*ord[d[spec]].year,ord[d[spec]].dweek);
    for(spz=0; spz<sp ; spz++){
        printf("-");
    }
    printf("\n%s %s {{%s}} | %s\n",twelvehrclo(*ord[d[spec]].starta,*ord[d[spec]].enda,ord[d[spec]].startb,ord[d[spec]].endb),ord[d[spec]].description,ord[d[spec]].location,ord[d[spec]].timezone);
}
    }
}
    
}
void processlin(char *nameoffile,char *line[]){
        int day[2];
        int month[2];
        int year;
        char str[] = "‐‐start=";
        char end[] = "‐‐end=";
        char fim[] = "‐‐file=";
        
       if(strncmp(str, line[1],8) == 0){
           sscanf(line[1],"‐‐start=%d/%d/%d",&year,&month[0],&day[0]);
       }
    if(strncmp(end, line[2],6) == 0){
           sscanf(line[2],"‐‐end=%d/%d/%d",&year,&month[1],&day[1]);
       }
    if(strncmp(fim,line[3],7) == 0){
           sscanf(line[3],"‐‐file=%s",nameoffile);
       }
       filled(nameoffile,month,day);
    }
int main(int argc, char *argv[])
{
    if(argc > 1){
        
        char *line[3];
        char nameoffile[100];
        for(int i=1; i <= 3 ; i++){
        line[i]=argv[i];
        
        }
        processlin(nameoffile,line);
    }
    exit(0);
       }
   
    /* Starting calling your own code from this point. */
    // Ideally, please try to decompose your solution into multiple functions that are called from a concise main() function.\\


