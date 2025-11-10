#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <set>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::map<std::string, std::set<std::string>> departmentInfo;
    std::map<std::string, std::string> memberInfo;

    for (int i = 0; i < N; i++)
    {
        std::string name, department;
        std::cin >> name >> department;
        departmentInfo[department].insert(name);
        memberInfo[name] = department;
    }

    for (int i = 0; i < M; i++)
    {
        int command;
        std::cin >> command;
        if (command == 1)
        {
            std::string name, department;
            std::cin >> name >> department;
            if (department != memberInfo[name])
            {
                departmentInfo[department].insert(name);
                departmentInfo[memberInfo[name]].erase(name);
                memberInfo.erase(name);
                memberInfo[name] = department;
            }
        } else {
            std::string department_1, department_2;
            std::cin >> department_1 >> department_2;

            for (auto x : departmentInfo[department_1])
            {
                departmentInfo[department_2].insert(x);
                memberInfo[x] = department_2;
            }

            departmentInfo.erase(department_1);
        }
    }

    for (auto x : departmentInfo)
    {
        std::cout << x.first << ": ";
        
        for (auto y : x.second)
        {
            std::cout << y << " ";
        }
        
        std::cout << "\n";
    }
}