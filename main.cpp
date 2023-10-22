#include <iostream>
#include <string>
#include <vector>
#include <cpr/cpr.h>
#include <fstream>
#include <nlohmann/json.hpp>

int main(int argc, char** argv) {

    //Отчет по комнате


    //Сделать переменные на изм данные
        //Переменная на дату
        //Переменная на комнату
        //Переменная на токен
        //Переменная на запрос(jsonData)

    //проверка на массив
    //создавать Отчет по датам
    //Сделать рандоайзер
    //рефактинг кода
    //Переписать на ООП
    
    cpr::Response r = cpr::Get(cpr::Url{"https://ekbetagi.ktalk.ru/api/roomreport/lpjhwswo187f/statistics/report"},
                               cpr::Parameters{{"from", "2023-10-21T19:00:00.000Z"}},
                               cpr::Header{{"X-Auth-Token", "hy1br3aregjWf9ZpBudZsTyI64PMBEsz"}});
                            
    std::cout << "Status code: " << r.status_code << '\n';
    if(r.status_code == 200)
    {
        nlohmann::json jsonData = nlohmann::json::parse(r.text);
        nlohmann::json users = jsonData["participantTotalDurations"];
        for(const auto& user : users)
        {
            std::cout << user << '\n';
        }

        std::ofstream outfile("ОТЧЕТ.xlsx", std::ios::binary);
        outfile << r.text;
        outfile.close();
    }


    return 0;
}