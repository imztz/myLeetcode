class Solution {
public:
    bool isLeapYear (int yy) {
        if (yy % 4 == 0 && yy % 100 != 0 || yy % 400 == 0)
            return true;
        return false;
    }

    vector<int> months{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    unordered_map<int, string> r = 
    {
        {0, "Sunday"},
        {1, "Monday"},
        {2, "Tuesday"},
        {3, "Wednesday"},
        {4, "Thursday"},
        {5, "Friday"},
        {6, "Saturday"}
    };


    string dayOfTheWeek(int day, int month, int year) {
        int sum = 0;
        for (int i = 1971; i < year; ++i) {
            if (isLeapYear(i))
                sum += 366;
            else
                sum += 365;
        }
        for (int i = 1; i < month; ++i) {
                sum += months[i];
        }
        if (isLeapYear(year) && month > 2)
            ++sum;
        sum += day;
        --sum;
        sum %= 7;
        sum = (sum + 5) % 7;
        return r[sum];
    }
};