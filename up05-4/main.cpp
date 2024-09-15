#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

enum
{
    PERCENTAGE = 10,
    ACCURACY = 10
};

class Average
{
private:
    double sum;
    int cnt;
public:
    Average(double sum = 0.0, int cnt = 0): sum(sum), cnt(cnt) {}

    void operator()(double number)
    {
        sum += number;
        ++cnt;
    }

    double get_average() const
    {
        return sum / cnt;
    }
};

//cutting out first and last "percentage"-number of sample
void cutting_out(std::vector<double> &sample, int percentage)
{
    int percent = sample.size() / percentage;
    sample.erase(sample.begin(), sample.begin() + percent);
    sample.erase(sample.end() - percent, sample.end());
}

int main()
{
    double number;
    std::vector<double> sample;

    while (std::cin >> number) {
        sample.push_back(number);
    }

    cutting_out(sample, PERCENTAGE); // cutting out first and last 10 percent of sample

    std::sort(sample.begin(), sample.end()); //sorting sample

    cutting_out(sample, PERCENTAGE); //cutting out first and last 10 percent of maximums and minimums of sample

    Average answer = std::for_each(sample.begin(), sample.end(), Average()); //calculating average for normal sample

    std::cout << std::fixed << std::setprecision(ACCURACY) << answer.get_average() << std::endl;

    return 0;
}
