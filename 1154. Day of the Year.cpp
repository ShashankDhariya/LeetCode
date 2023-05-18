class Solution {
public:
    vector<int> months = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    vector<int> leap = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

    bool leapF(int year){
        if(year % 400 == 0)
            return true;

        else if(year % 100 == 0)
            return false;

        else if(year % 4 == 0)
            return true;

        else 
            return false;
    }

    int dayOfYear(string date) {
        int month = (date[5] - '0')*10 + date[6] - '0';
        int day = (date[8] - '0')*10 + date[9] - '0';

        int year = ((date[0] - '0') * 1000) + ((date[1] - '0') * 100) + ((date[2] - '0') * 10) + (date[3] - '0');
        if(leapF(year))
            return leap[month - 1] + day;
        return months[month - 1] + day;
    }
};
