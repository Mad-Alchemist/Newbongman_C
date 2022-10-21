#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {

    // terms (약관 유효기간), privacies (가입날짜 약관종류)
    // 각 달은 28일까지 존재 즉, 1년은 12*28, 336

    class num {
    public:
        int year;
        int month;
        int day;

        num(string input) {
            year = stoi(input.substr(0, 4));
            month = stoi(input.substr(5, 2));
            day = stoi(input.substr(8, 2));
        }


    };

    vector<int> answer;    //오늘 파기해야하는 정보

    num today_temp = num(today);
    for (int i = 0; i < privacies.size(); i++)
    {
        num privacies_temp = num(privacies[i]);
        int t_month = 0;
        for (int j = 0; j < terms.size(); j++) {
            if (!(terms[j].substr(0, 1).compare(privacies[i].substr(privacies[i].length() - 1))))
            {
                t_month = stoi(terms[j].substr(2, terms[j].length() - 2));
            }
        }
        cout << t_month << endl;

        num expire = num(privacies[i]);
        expire.month += t_month;
        while (1)
        {
            if (expire.month > 12)
            {
                expire.month -= 12;
                expire.year += 1;
                continue;
                if (expire.day - 1 == 0)
                {
                    expire.month -= 1;
                    expire.day = 28;
                }
                else
                {
                    expire.day -= 1;
                }
            }
            else
                break;
        }

        if (expire.year < today_temp.year)
        {
            answer.push_back(i + 1);
        }
        else if (expire.year == today_temp.year)
        {
            if (expire.month <= today_temp.month)
            {
                if (expire.day <= today_temp.day)
                    answer.push_back(i + 1);
            }
        }
        cout << expire.year << " " << expire.month << " " << expire.day << endl;

    }




    return answer;
}

int main(void)
{
    vector<string> terms;
    vector<string> privacies;

    terms.push_back("A 6");
    terms.push_back("B 12");
    terms.push_back("C 3");

    privacies.push_back("2021.05.02 A");
    privacies.push_back("2021.07.01 B");
    privacies.push_back("2022.02.19 C");
    privacies.push_back("2022.02.20 C");

    string today = "2022.05.19";

    vector<int> a = solution(today, terms, privacies);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i]<<endl;
    }


    return 0;
}