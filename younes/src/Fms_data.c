#include <stdio.h>
#include "FMS.h"



// initialising coordinates

Coordinate HAMla={53,37,49};

Coordinate HAMlo={9,59,18};

Coordinate FRAla={50,1,59};

Coordinate FRAlo={8,34,14};

Coordinate MUCla={48,21,14};

Coordinate MUClo={11,47,10};

Coordinate DUSla={51,16,51};

Coordinate DUSlo={6,45,26};

Coordinate CGNla={50,51,57};

Coordinate CGNlo={7,8,34};

Coordinate BERla={52,21,44};

Coordinate BERlo={13,30,2};

Coordinate STRla={48,41,24};

Coordinate STRlo={9,13,19};

//initialising times(counting upwards) so they can have multiple uses

Time T0300={3,00};

Time T0415={4,15};

Time T0800={8,00};

Time T1000={10,00};

Time T1012={10,12};

Time T1015={10,15};

Time T1130={11,30};

Time T1300={13,00};

Time T1310={13,10};

Time T1315={13,15};

Time T1430={14,30};

Time T1500={15,00};

Time T1512={15,12};

Time T1530={15,30};

Time T1630={16,30};

Time T1700={17,00};

Time T1800={18,00};

Time T1830={18,30};

Time T2030={20,30};

Time T2045={20,45};

Time T2145={21,45};

Time T2200={22,00};

Time T2230={22,30};

Time T2330={23,30};

Time T2400={24,00};

//initialising Airports

Airport HAM={"EDDH","HAM",&HAMla,&HAMlo,16};

Airport MUC={"EDDM","MUC",&MUCla,&MUClo,453};

Airport FRA={"EDDF","FRA",&FRAla,&FRAlo,111};

Airport DUS={"EDDL","DUS",&DUSla,&DUSlo,45};

Airport CGN={"EDDK","CGN",&CGNla,&CGNlo,92};

Airport STR={"EDDS","STR",&STRla,&STRlo,389};

Airport BER={"EDDB","BER",&BERla,&BERlo,47};
//initialising flightpaths in order of the Time Table

//flightpaths Lufthansa

FlightPath LHPath1={"LH 2147",&MUC,&HAM,&T1130,&T1430};

FlightPath LHPath2={"LH 2147",&HAM,&FRA,&T1530,&T1630};

FlightPath LHPath3={"LH 2147",&FRA,&MUC,&T1830,&T2030};

FlightPath LHPath4={"LH 2147",&MUC,&HAM,&T2045,&T2200};

FlightPath LHPath5={"LH 2147",&HAM,&MUC,&T2230,&T2330};

//flightpaths EuroWings

FlightPath EWPath1={"EW 5953",&MUC,&DUS,&T0300,&T0415};

FlightPath EWPath2={"EW 5953",&DUS,&BER,&T0800,&T1000};

FlightPath EWPath3={"EW 5953",&BER,&CGN,&T1012,&T1315};

FlightPath EWPath4={"EW 5953",&CGN,&MUC,&T1800,&T2030};

FlightPath EWPath5={"EW 5953",&MUC,&DUS,&T2145,&T2330};

//flightpaths TUIFly

FlightPath X3Path1={"X3 2174",&HAM,&STR,&T0800,&T1000};

FlightPath X3Path2={"X3 2174",&STR,&BER,&T1015,&T1300};

FlightPath X3Path3={"X3 2174",&BER,&FRA,&T1310,&T1500};

FlightPath X3Path4={"X3 2174",&FRA,&HAM,&T1512,&T1700};

FlightPath X3Path5={"X3 2174",&HAM,&FRA,&T2200,&T2400};

//initialising the 3 airplanes 
Airplane LH2147={"A380","D-AIMA",.flightPaths={&LHPath1,&LHPath2,&LHPath3,&LHPath4,&LHPath5},5};

Airplane EW5953={"A320","D-AIAB",.flightPaths={&EWPath1,&EWPath2,&EWPath3,&EWPath4,&EWPath5},5};

Airplane X32174={"B747","D-ABCD",.flightPaths={&X3Path1,&X3Path2,&X3Path3,&X3Path4,&X3Path5},5};

//iniatialising the airlines
Airline LH={"Lufthansa",&LH2147,1};

Airline EW={"EuroWings",&EW5953,1};

Airline X3={"TUIFly",&X32174,1};

//iniatialising the FMS
FMS FMS1={.airlines={&LH,&EW,&X3},3};