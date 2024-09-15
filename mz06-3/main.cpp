#include <iostream>
#include <map>
#include <set>
#include <string.h>

class Date
{
private:
    unsigned year, month, day;
public:
    Date(std::string date)
    {
        sscanf(date.c_str(), "%u/%u/%u", &year, &month, &day);
    }

    std::string get_date() const
    {
        char date[20];
        sprintf(date, "%u/%02u/%02u", year, month, day);
        return std::string(date);
    }

    bool operator<(const Date &other) const
    {
        return (strcmp(this->get_date().c_str(), other.get_date().c_str()) < 0);
    }
};

int main()
{
    std::string name, date;
    double mark;

    std::map<std::string, std::map<Date, double> > dict;
    std::set<Date> dates;
    std::set<std::string> names;

    while (std::cin >> name) {
        std::cin >> date >> mark;
        dates.insert(date);
        names.insert(name);
        dict[name][date] = mark;
    }

    std::cout << ". ";
    for (auto date : dates) {
        std::cout << date.get_date() << ' ';
    }
    std::cout << std::endl;

    for (auto student : names) {
        std::cout << student << ' ';
        for (auto date : dates) {
            if (dict[student].find(date) == dict[student].end()) {
                std::cout << ". ";
            } else {
                std::cout << dict[student][date] << ' ';
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
