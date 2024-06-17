#include <stdio.h>
#include <math.h>
#include <string.h>
#include "FMS.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


void Generate_Time_Table(FMS * pFMS){
    
  
   printf("   Airline|Flight No.|from|  to|Departure| Arrival|Airplane\n"); //printing table header
   printf("----------|----------|----|----|---------|--------|--------\n");
    
    for(int i=0; i< pFMS->cntAirline;++i){ //passes through all the airlines 
        
        for(int k=0; k< pFMS->airlines[i]->pairplane->cntFlightPaths;++k){ //passes through all the flightpaths
            
            //using strncpy to shorten the pahts by copying it in variable
            char pairlinename[MAX_STR];
            strncpy(pairlinename, pFMS->airlines[i]->airlineName, MAX_STR - 1);
            char flightno[MAX_STR];
            strncpy(flightno, pFMS->airlines[i]->pairplane->flightPaths[k]->flightPathName, MAX_STR - 1);
            char depatureAp[MAX_STR];
            strncpy(depatureAp,pFMS->airlines[i]->pairplane->flightPaths[k]->pDepatureAirport->iata, MAX_STR - 1);
            char arrivalAp[MAX_STR];
            strncpy(arrivalAp,pFMS->airlines[i]->pairplane->flightPaths[k]->pArrivalAirport->iata, MAX_STR - 1);
            char plane[MAX_STR];
            strncpy(plane,pFMS->airlines[i]->pairplane->airVehicleRegistration, MAX_STR - 1);
           
            //copying paths into a variable
            int deptimehour= pFMS->airlines[i]->pairplane->flightPaths[k]->pdepature->hour;
            int deptimemin = pFMS->airlines[i]->pairplane->flightPaths[k]->pdepature->min;
            int arrtimehour = pFMS->airlines[i]->pairplane->flightPaths[k]->parrival->hour;
            int arrtimemin = pFMS->airlines[i]->pairplane->flightPaths[k]->parrival->min;
            
            //printing the content of the table
            printf("%10s|%10s|%4s|%4s|    %02i:%02i|   %02i:%02i|%8s\n",
            pairlinename,flightno,depatureAp,arrivalAp,deptimehour,deptimemin,arrtimehour,arrtimemin,plane);
        }

    }

}

//print duration Table

void Generate_Duration_Table(FMS * pFMS){
    
    for(int i=0;i<pFMS->cntAirline;++i){ //passes through all the airlines 
        printf("   Airline|Flight No.|from|  to|Duration\n");  //printing table header (inside the loop due to multiple tables)
        printf("----------|----------|----|----|--------\n");
       
        //declaring variables that are needed for the caption of the table 
        char pairlinename[MAX_STR];
        strncpy(pairlinename, pFMS->airlines[i]->airlineName, MAX_STR - 1);
        char planetype[MAX_STR];
        strncpy(planetype,pFMS->airlines[i]->pairplane->airplanename, MAX_STR - 1);
        int totaldurationinminutes =0;         //setting the totalduration back to zero after each airline and is used to store the total duration in minutes
        int totaldurationmin=0;                //stores the minutes o the total duration 
        int totaldurationhour=0;               //stores the hours of the total duration 
        for(int k=0;k<pFMS->airlines[i]->pairplane->cntFlightPaths;++k){ //passes through all the flightpaths
            
            //using strncpy to shorten the pahts by copying it in variable
            char flightno[MAX_STR];
            strncpy(flightno, pFMS->airlines[i]->pairplane->flightPaths[k]->flightPathName, MAX_STR - 1);
            char depatureAp[MAX_STR];
            strncpy(depatureAp,pFMS->airlines[i]->pairplane->flightPaths[k]->pDepatureAirport->iata, MAX_STR - 1);
            char arrivalAp[MAX_STR];
            strncpy(arrivalAp,pFMS->airlines[i]->pairplane->flightPaths[k]->pArrivalAirport->iata, MAX_STR - 1);
            
            //copying paths into a variable
            int deptimehour= pFMS->airlines[i]->pairplane->flightPaths[k]->pdepature->hour;
            int deptimemin = pFMS->airlines[i]->pairplane->flightPaths[k]->pdepature->min;
            int arrtimehour = pFMS->airlines[i]->pairplane->flightPaths[k]->parrival->hour;
            int arrtimemin = pFMS->airlines[i]->pairplane->flightPaths[k]->parrival->min;
            

            //Calculating Duration
            int min=0;                  //min is used to store the duration between arrival and depature in minutes
            int durationhour=0;         //stores the hours of the flight duration
            int durationmin=0;
            min = ((arrtimehour-deptimehour)*60 )+(arrtimemin-deptimemin);  
            durationmin=min%60;                                             //caclculating the leftover minutes after filling all the hours
            durationhour=(min-durationmin)/60;                              //calculating the hours 


            //printing the content of the table
            printf("%10s|%10s|%4s|%4s|  %02i:%02i\n",
            pairlinename,flightno,depatureAp,arrivalAp,durationhour,durationmin);
            
            //adding all durations in minutes to get the total duration in minutes
            totaldurationinminutes= totaldurationinminutes + min ;


        }

    
        totaldurationmin=totaldurationinminutes%60;  //caclculating the leftover minutes after filling all the hours
        totaldurationhour=(totaldurationinminutes-totaldurationmin)/60;  //calculating the hours
        //printing the caption of the table
        printf("Total flight Time for %s %s is %02i:%02i\n",
        pairlinename,planetype,totaldurationhour,totaldurationmin);

    }
}

void Generate_Distance_Table(FMS * pFMS){
    for(int i = 0; i < pFMS->cntAirline; i++){  //passes through all the airlines 
        
        printf("   Airline|Flight No.|from|  to|Distance\n");  //printing table header (inside the loop due to multiple tables)
        printf("----------|----------|----|----|--------\n");
       
        //declaring variables that are needed for the caption of the table  
        char pairlinename[MAX_STR];
        strncpy(pairlinename, pFMS->airlines[i]->airlineName, MAX_STR - 1);
        char planetype[MAX_STR];
        strncpy(planetype,pFMS->airlines[i]->pairplane->airplanename, MAX_STR - 1);
    	double totalflightdistance=0;
        
        
        for(int k=0; k<pFMS->airlines[i]->pairplane->cntFlightPaths;++k){ //passes through all the flightpaths
            
            //using strncpy to shorten the pahts by copying it in variable
            char flightno[MAX_STR];
            strncpy(flightno, pFMS->airlines[i]->pairplane->flightPaths[k]->flightPathName, MAX_STR - 1);
            char depatureAp[MAX_STR];
            strncpy(depatureAp,pFMS->airlines[i]->pairplane->flightPaths[k]->pDepatureAirport->iata, MAX_STR - 1);
            char arrivalAp[MAX_STR];
            strncpy(arrivalAp,pFMS->airlines[i]->pairplane->flightPaths[k]->pArrivalAirport->iata, MAX_STR - 1);
           
            // shorting paths for all the coordinates(arr is short for arrival,dep is short for depature)
            double arrlatdeg =pFMS->airlines[i]->pairplane->flightPaths[k]->pArrivalAirport->Latitude->degree ;
            double arrlatmin=pFMS->airlines[i]->pairplane->flightPaths[k]->pArrivalAirport->Latitude->minute ;
            double arrlatsec =pFMS->airlines[i]->pairplane->flightPaths[k]->pArrivalAirport->Latitude->second ;
            double arrlongdeg =pFMS->airlines[i]->pairplane->flightPaths[k]->pArrivalAirport->Longitude->degree;
            double arrlongmin =pFMS->airlines[i]->pairplane->flightPaths[k]->pArrivalAirport->Longitude->minute ;  
            double arrlongsec=pFMS->airlines[i]->pairplane->flightPaths[k]->pArrivalAirport->Longitude->second ;
            double deplatdeg=pFMS->airlines[i]->pairplane->flightPaths[k]->pDepatureAirport->Latitude->degree ;
            double deplatmin =pFMS->airlines[i]->pairplane->flightPaths[k]->pDepatureAirport->Latitude->minute ;
            double deplatsec =pFMS->airlines[i]->pairplane->flightPaths[k]->pDepatureAirport->Latitude->second ;
            double deplongdeg =pFMS->airlines[i]->pairplane->flightPaths[k]->pDepatureAirport->Longitude->degree;
            double deplongmin =pFMS->airlines[i]->pairplane->flightPaths[k]->pDepatureAirport->Longitude->minute ;
            double deplongsec =pFMS->airlines[i]->pairplane->flightPaths[k]->pDepatureAirport->Longitude->second ;

            //combining the degrees,minutes and seconds to another and converting them from  degree to radian
            
            double arrlat= (arrlatdeg+(arrlatmin/60)+(arrlatsec/3600))*M_PI/180;
            double arrlong= (arrlongdeg+(arrlongmin/60)+(arrlongsec/3600))*M_PI/180;
            double deplat= (deplatdeg+(deplatmin/60)+(deplatsec/3600))*M_PI/180;
            double deplong= (deplongdeg+(deplongmin/60)+(deplongsec/3600))*M_PI/180;
           
           //calculating distance
           double distance;
           const double r=6378.388;
           distance = r * (acos((sin(arrlat)*sin(deplat))+(cos(deplat)*cos(arrlat)*cos(arrlong - deplong))));
           
            printf("%10s|%10s|%4s|%4s| %3.2f\n",
            pairlinename,flightno,depatureAp,arrivalAp,distance);
            
            //adding the distances of each loop to another
            totalflightdistance = distance+totalflightdistance;





        }
        //printing the caption of the table
        printf("Total flight distance for %s %s is %3.2f\n",
        pairlinename,planetype,totalflightdistance);



    }
    
}



