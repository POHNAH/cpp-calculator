using Number = double;

#include <vector>
#include <string>


// Возвращает true, если удалось прочитать число
// и сохранить его в Number.
bool ReadNumber(Number& result);

// Возвращает true, если удалось прочитать число из строки str
// и сохранить его в Number.
bool ReadNumber(Number& result, std::string str);

// Возвращает true, если работа завершилась штатно 
// командой q. Если из-за ошибки, возвращает false.
bool RunCalculatorCycle();