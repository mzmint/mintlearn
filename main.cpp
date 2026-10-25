#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <string>

using json = nlohmann::json;

int main() {
    std::string lesson;
    std::cout << "Lesson?\n";
    std::cin >> lesson;
    std::ifstream file(lesson + ".json");
    json data = json::parse(file);
    std::cout << data["title"].get<std::string>();
    for (int i = 0; i < data["question_count"].get<int>(); i++) {
        int answered = 0;
        std::cout << "\n" << data["lessons"][i]["question"].get<std::string>() << "\n";
        for (int j = 0; j < data["lessons"][i]["options"].size(); j++) {
            std::cout << " " << j + 1 << ". " << data["lessons"][i]["options"][j].get<std::string>();
        }
        std::cout << "\nAnswer?\n";
        std::cin >> answered;
        if (answered == data["lessons"][i]["correct"].get<int>()) {
            std::cout << "Correct!";
        } else {
            std::cout << "Wrong!";
        }
    }
    return 0;
}