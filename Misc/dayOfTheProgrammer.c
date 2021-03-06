#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * Time: O(log tensPower)
 * Space: O(c)
 * The pow function could be O(n) but I'm assuming its optimized
 * enough for this to be regarded as constant
 */
int getDecimal(int value, int tensPower) {
    return value % (int) pow(10, tensPower);
}

/**
 * Time: O(log tensPower)
 * Space: O(c)
 * For getDecimal and removeDecimal I added a tensPower variable
 * incase I wanted to used these as helper functions for other functions
 * where I may not always be operating on the least significant digit (10^1 in the case of how this function works instead of 10^0)
 */
int removeDecimal(int value, int tensPower) {
    int power = (int) pow(10, tensPower);
    int difference = value - (value % power);
    return difference / power;
}

/**
 * Time: O(n * log decimalsPlace)
 * Space: O(c)
 * n = Number of digits long a value is
 */
int getDecimalsPlaceToLeft(int value) {
    int decimalsPlace = 0;

    while (value != 0) {
        value = value - getDecimal(value, ++decimalsPlace);
    }

    return decimalsPlace;
}

/**
 * Time: O(n * log n)
 * Space: O(n)
 * n = Number of digits long a value is
 * 
 * Returns number of characters added to the string.
 */
int intToString(int value, char* s) {
    int decimalsToLeft = getDecimalsPlaceToLeft(value);
    char arr[decimalsToLeft];

    for (int i = decimalsToLeft - 1; i >= 0; --i) {
        arr[i] = getDecimal(value, 1) + '0';
        value = removeDecimal(value, 1);
    }

    strncat(s, arr, decimalsToLeft);

    return sizeof(arr) / sizeof(char);
}

/**
 * Time: O(c)
 * Space: O(c)
 * 
 * Since each value in the array must always be in dd/mm/yyy format
 * the time for this function to run will always be the same. Input will
 * not change this functions run time.
 */
char* buildDateString(int dd, int mm, int yyyy, char* s) {
    int arr[] = {dd, mm, yyyy};

    for (int i = 0; i < 3; ++i) {
        if (arr[i] < 10) {
            char ch = '0';
            strncat(s, &ch, 1);
        }

        intToString(arr[i], s);

        if (i < 2) {
            char ch = '.';
            strncat(s, &ch, 1);
        }
    }
    
    return s;
}

/**
 * Time: O(c)
 * Space: O(c)
 */
int isLeapYearJulianCalendar(int year) {
    return year % 4 == 0;
}

/**
 * Time: O(c)
 * Space: O(c)
 */
int isLeapYearGregorianCalendar(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

/**
 * Time: O(c)
 * Space: O(c)
 * Factored out Julian and Gregorian calendars in case more calendars needed to be compared
 */
int isLeapYear(int year) {
    return (year < 1918) ?
        isLeapYearJulianCalendar(year) : 
        isLeapYearGregorianCalendar(year);
}

/**
 * Time: O(c)
 * Space: O(c)
 * This function is a constant of 12 months
 * Input does not change the runtime
 */
void daysIntoYear(int daysAfter, int* dd, int* mm, int yyyy) {
    int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (yyyy == 1918) {
        months[1] = 15;
    }

    int days = 0;
    for (int month = 0; month < 12; ++month) {
        if ((days + months[month]) < daysAfter) {
            days += months[month];
        } else {
            *dd = daysAfter - days - isLeapYear(yyyy);
            *mm = month + 1;
            break;
        }
    }
}

/**
 * Time: O(c)
 * Space: O(c)
 * 
 * Because this charcter array is fixed at 10 the input cant change the runtime.
 */
char* dayOfProgrammer(int year) {
    static char s[10];
    int dd;
    int mm;

    daysIntoYear(256, &dd, &mm, year);
    buildDateString(dd, mm, year, s);

    return s;
}

/**
 * Marie invented a Time Machine and wants to test it by time-traveling to visit Russia on the Day of the Programmer (the 256th day of the year) during a year in the inclusive range from 1700 to 2700.
 * From 1700 to 1917, Russia's official calendar was the Julian calendar; since 1919 they used the Gregorian calendar system. The transition from the Julian to Gregorian calendar system occurred in 1918, when the next day after January 31st was February 14th. This means that in 1918, February 14th was the 32nd day of the year in Russia.
 * In both calendar systems, February is the only month with a variable amount of days; it has 29 days during a leap year, and 28 days during all other years. In the Julian calendar, leap years are divisible by 4; in the Gregorian calendar, leap years are either of the following:
 * Divisible by 400. Divisible by 4 and not divisible by 100.
 */
int main(void) {
    printf("%s", dayOfProgrammer(1918));
    return 0;
}
