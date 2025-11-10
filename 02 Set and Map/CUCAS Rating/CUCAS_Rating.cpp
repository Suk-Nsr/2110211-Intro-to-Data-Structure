#include <iomanip>
#include <iostream>
#include <utility>
#include <map>

int main() {
    std::cout << std::fixed << std::setprecision(2);
    
    int N;
    std::cin >> N;
    std::map<std::string, std::pair<int, int>> subjectScore;
    std::map<std::string, std::pair<int, int>> teacherScore;

    for (int i = 0; i < N; i++)
    {
        std::string subject, teacher;
        int score;
        std::cin >> subject >> teacher >> score;

        auto it_1 = subjectScore.find(subject);
        if (it_1 == subjectScore.end())
        {
            subjectScore[subject] = {score, 1};
        } else {
            subjectScore[subject] = {subjectScore[subject].first + score, subjectScore[subject].second + 1};
        }

        auto it_2 = teacherScore.find(teacher);
        if (it_2 == teacherScore.end())
        {
            teacherScore[teacher] = {score, 1};
        } else {
            teacherScore[teacher] = {teacherScore[teacher].first + score, teacherScore[teacher].second + 1};
        }
    }

    for (auto x : subjectScore)
    {
        std::cout << x.first << " " << ((x.second.first + 0.0) / (x.second.second + 0.0)) << "\n";
    }

    for (auto x : teacherScore)
    {
        std::cout << x.first << " " << ((x.second.first + 0.0) / (x.second.second + 0.0)) << "\n";
    }
}