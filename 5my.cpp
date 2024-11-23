#include <iostream>
#include <fstream>
#include <string>

int main(){
    int players = 0;
    int tele = 0;
    int N = 1; // сектор
    int sector[13];// массив для проверки, был ли в игре этот вопрос

    while((players < 6) && (tele < 6))
    {
        int n = 0;

        std::cout << "Крутите волчок:";
        std::cin >> n;

        N += n;
        // проверка смещения
        while (N > 13){
            N -= 13;
        }
        // 
        while(sector[((N > 13) ? N -= 13 : N ) - 1] == 1){
            N++;
        }
        // когда выпадает вопрос, соответсвующая ячейка массива принимает значение 1
        sector[N - 1] = 1;

        std::string pathQuestion = "question_" + std::to_string(N) + ".txt";
        std::string pathAnswer = "answer_" + std::to_string(N) + ".txt";

        std::string strQuestion;
        std::string strAnswer;
        std::string youAnswer;
 
        std::ifstream question(pathQuestion); // окрываем файл вопроса
        std::ifstream answer(pathAnswer); // окрываем файл ответа

        if (question.is_open() && answer.is_open()){
            while (std::getline(question, strQuestion))
            {
                std::cout << "номер вопроса: " << N << std::endl;
                std::cout << strQuestion << std::endl;
            }

            std::cout << "Ваш ответ: ";
            std::cin >> youAnswer;

            std::getline(answer, strAnswer);

            std::cout << "Правильный ответ: " << strAnswer << std::endl;

            if (youAnswer.compare(strAnswer) == 0){
                std::cout << "+1 очко игрокам" << std::endl;
                players++;
            } 
            else {
                std::cout << "+1 очко зрителям" << std::endl;
                tele++;
            }
        }
        question.close();
        answer.close();
    }

    if (players == 6) {
        std::cout << "Знатоки побеждают!" << std::endl;
    } else {
        std::cout << "Телезрители побеждают!" << std::endl;
    }

    return 0;
}