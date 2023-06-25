#include <iostream>
#include <exception>
#include <string>
using namespace std;

/*string AskTimeServer() {
 throw system_error(error_code());
}*/

class TimeServer {
public:
    string GetCurrentTime() {
         string tmp;
        try
        {
           tmp=AskTimeServer();
        }catch(const system_error&e)
        {
                return last_fetched_time;

        }catch(exception *e)
        {
            throw e;
        }
        last_fetched_time=tmp;
        return last_fetched_time;
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля last_fetched_time
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
