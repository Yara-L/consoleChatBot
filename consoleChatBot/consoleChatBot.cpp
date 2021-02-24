#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <regex>

std::map<std::string, std::string> knowledge = { //База вопросов и ответов
    {"hello", "Oh, hello hooman!"}, //{"вопрос", "ответ"}
    {"how are you", "Not too bad for a machine"},
    {"what is your name", "My creator gave me name ChatBot3000"},
    {"what are you up to", "Answering stupid question"},
};

std::string exitPhrases[] = { "exit", "bye", "have a good day" };

//Принимает на вход строку и возвращает такую же строку, 
//только в нижнем регистре
std::string to_lower(std::string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

void botSay(std::string text) {
    std::cout << "[BOT]: " << text << "\n";
}

//Получить вопрос от пользователя
std::string userQuestion() {
    std::string question;
    std::cout << "[USER]: ";
    std::getline(std::cin, question);
    question = to_lower(question);
    return question;
}

bool isExit(std::string text) {
    for (auto phrase : exitPhrases) {
        std::regex expression = std::regex(".*" + phrase + ".*");
        if (regex_match(text, expression)) {
            botSay("Ok, byeeee!!!");
            return true; //Да, этот текст содержит фразу для выхода
        }
    }
    return false; //Нет, не содержит
}

//Выводит на экран ответ на вопрос question
void botAnswer(std::string question) {
    bool foundAnswer = false; //Найден ли ответ
    for (auto entry : knowledge) {// Для каждой записи в базе:
        //entry.first - вопрос
        //entry.second - ответ
        std::regex expression = std::regex(".*" + entry.first + ".*");
        if (regex_match(question, expression)) {
            //Дать ответ!
            botSay(entry.second);
            foundAnswer = true;
        }
    }
    if (!foundAnswer) { //Если не найден ответ
        botSay("Do not comprende");
    }
}

int main() {
    std::cout << "Hello, Welcome to ChatBot3000\n";

    std::string question; //Объявление переменной, тип+имя

    while (!isExit(question)) { //Выполняем код, пока вопрос не содержит фразы для выхода
        question = userQuestion();
        botAnswer(question);
    }
    //Getline -- прочитать строчку
    //Из ввода программы (cin) в переменную question
}