#include <bits/stdc++.h>

using namespace std;

int leapYear(int year){
     if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)){
        return 2;
     }else{
        return 1;
     }
}

int main(){
    vector<pair<int, int> > arr;
    fstream fin("input.txt");
    for(int i=0; i<11; i++){
        int month;
        int day;
        fin>>month>>day;
        arr.push_back(pair<int, int>(month, day));
    }

    int year;
    int months[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin>>year;
    int decade[100];
    for(int i=0; i<100; i++){
        decade[i]=0;
    }

    for(int a=0; a<10; a++){
        int weekday=1;
        for(int h=1601; h<year+a; h++){
            weekday+=leapYear(h);
        }
        int m=weekday;

        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<arr[i].first-1; j++){
                weekday+=months[j];
            }
            weekday+=arr[i].second-1;
            weekday%=7;

            if(weekday<6){
                decade[a]++;
            }

            weekday=m;
        }
        cout<<year+a<<": "<<decade[a]<<endl;
    }

    return 0;
}
