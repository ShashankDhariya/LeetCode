class Solution {
public:
    int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeap(int year){
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }

    int daysfrom1971(string date){
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8));

        int days = 0;
        for(int i=1971;i<year;i++)
            days += isLeap(i)? 366: 365;
        
        for(int i=0;i<month-1;i++)   
            days += d[i];
        days += (month > 2 && isLeap(year));

        days += day;
        return days;
    }

    int daysBetweenDates(string date1, string date2) {
        return abs(daysfrom1971(date1) - daysfrom1971(date2));
    }
};
