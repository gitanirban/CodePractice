   //make sub array
    //pass the sub array chunk and group size to the  getLargest to get the dssired value.
    // how to make the sub array chunk ?                                                                                        5 + 2 = 6 + 1                                                                                                                        //  5 + 2  =
     /*
                        [ 3, 6, 8, 4, 2, 9] = size 6,
        group 2, data : [ {3, 6}, {6, 8}, {8, 4}, {4, 2}, {2, 9} ]     size = 10 [ (sz * grp) - grp ] || grp count 5 || (grp_cnt + grp_sz = sz + 1);
                           0  1    1  2    2  3    3  4    4  5                                                         => grp_cnt =  (sz - grp_sz + 1)

        group 3, data : [ {3, 6, 8}, {6, 8, 4}, {8, 4, 2}, {4, 2, 9}]  size = 12 [ () ]               || grp count 4
                           0  1  2    1  2  3    2  3  4    3  4  5

        group 4, data : [ {3, 6, 8, 4}, {6, 8, 4, 2}, {8, 4, 2, 9} ]   size = 12                      || grp count 3
                           0  1  2  3    1  2  3  4    2  3  4  5

           //  for(int i2 = 0; i2< storage.size(); i2++ ){
           //     cout << storage.at(i2);
           // }
        }
        */
// boat sz =2, size =10

//        group 2, data : [ {3, 6}, {6, 8}, {8, 4}, {4, 2}, {2, 9} ]     size = 10
//                           0  1    1  2    2  3    3  4    4  5
//#1 Boat_Sz=2               <-->
//   Boat_start = 0
//   Boat_End   = 1



// boat sz =2, size =10

//        group 2, data :   [ 3, 6, 8, 4, 2, 9]      size = 10
//                            0  1  2  3  4  5
//#1 Boat_Sz=2                <-->

//        group 2, data :   [ 3, 6, 8, 4, 2, 9]      size = 10
//                            0  1  2  3  4  5
//#1 Boat_Sz=2                   <-->





//   Boat_start = 0
//   Boat_End   = 1





//        group 2, data : [ {3, 6}, {6, 8}, {8, 4}, {4, 2}, {2, 9} ]     size = 10
//                           0  1    1  2    2  3    3  4    4  5
//#2 Boat_Sz=2                       <-->
//   Boat_start = 1
//   Boat_End   = 2


//        group 2, data : [ {3, 6}, {6, 8}, {8, 4}, {4, 2}, {2, 9} ]     size = 10
//                           0  1    1  2    2  3    3  4    4  5
//#3 Boat_Sz=2                               <-->
//   Boat_start = 2
//   Boat_End   = 3

//        group 2, data : [ {3, 6}, {6, 8}, {8, 4}, {4, 2}, {2, 9} ]     size = 10
//                           0  1    1  2    2  3    3  4    4  5
//#4 Boat_Sz=2                                       <-->
//   Boat_start = 3
//   Boat_End   = 4


//        group 2, data : [ {3, 6}, {6, 8}, {8, 4}, {4, 2}, {2, 9} ]     size = 10
//                           0  1    1  2    2  3    3  4    4  5
//#5 Boat_Sz=2                                               <-->
//   Boat_start = 4
//   Boat_End   = 5
//end



//**********************************************************************************************
// boat sz =3, size =10

//        group 3, data : [ {3, 6, 8}, {6, 8, 4}, {8, 4, 2}, {4, 2, 9}]  size = 12
//                           0  1  2    1  2  3    2  3  4    3  4  5
//#1 Boat_Sz=3               <----->
//   Boat_start = 0
//   Boat_End   = 2

//        group 3, data : [ {3, 6, 8}, {6, 8, 4}, {8, 4, 2}, {4, 2, 9}]  size = 12
//                           0  1  2    1  2  3    2  3  4    3  4
//#2 Boat_Sz=3                          <----->
//   Boat_start = 1
//   Boat_End   = 2


//        group 3, data : [ {3, 6, 8}, {6, 8, 4}, {8, 4, 2}, {4, 2, 9}]  size = 12
//                           0  1  2    1  2  3    2  3  4    3  4  5
//#3 Boat_Sz=2                               <-->
//   Boat_start = 2
//   Boat_End   = 3

//        group 3, data : [ {3, 6, 8}, {6, 8, 4}, {8, 4, 2}, {4, 2, 9}]  size = 12
//                           0  1  2    1  2  3    2  3  4    3  4  5

//#4 Boat_Sz=2                                       <-->
//   Boat_start = 3
//   Boat_End   = 4


//        group , data : [ {3, 6, 8}, {6, 8, 4}, {8, 4, 2}, {4, 2, 9}]  size = 12
//                           0  1  2    1  2  3    2  3  4    3  4  5
//#5 Boat_Sz=3                                               <-->
//   Boat_start = 4
//   Boat_End   = 5






 /*  //make a copy in the Deque!
     for(int i2 = 0; i2< storage.size(); i2++ ){
         storage.at(i2) = arr[i2];
    }*/

#include <iostream>
#include <deque>
#include <stdio.h>
using namespace std;
void getLargest(int arr[], int n, int start_p, int end_p);
//void swap(int *xp, int *yp);


void slide(int arr[], int arr_sz, int grp_sz){
uint32_t start_p = 0u;
uint32_t end_p = 0u;
uint32_t const loop_count = arr_sz - grp_sz;
uint32_t i=0;
     for(i=0; i<=loop_count; i++){
         getLargest(arr,arr_sz,i,(grp_sz+i-1));
    }
    cout << endl;
}

// A function to implement bubble sort
void getLargest(int arr[], int n, int start_p, int end_p)
{
    uint8_t j;

    uint32_t bigger_temp = 0u;
     for (j = start_p; j < end_p ; j++){
        //bigger_temp = arr[start_p];
            if (arr[j] < arr[j+1]){
                    if( bigger_temp < arr[j+1])
                        bigger_temp = arr[j+1];
            }
            else{
                if( bigger_temp < arr[j])
                        bigger_temp = arr[j];
                if( bigger_temp < arr[j+1])
                        bigger_temp = arr[j+1];
            }
    }
    cout << bigger_temp << " ";
}

int main(){

int t;
cin >> t;
while(t) {
int n,k;
    cin >> n >> k;
    int i;
    int arr[n];
    for(i=0;i<n;i++)
      cin >> arr[i];
    slide(arr, n, k);
    t--;
  }
  return 0;
}