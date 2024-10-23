#include <iostream>
#include <vector>
#include <memory>

// Базовый класс для логических вентилей
class Item {
public:
    // Поля для входов и выходов
    Item() : input1(nullptr), input2(nullptr), output(false) {}

    // Установка входов
    void setInputs(Item* in1, Item* in2) {
        input1 = in1;
        input2 = in2;
    }

    // Метод для получения выходного значения
    bool getOutput() {
        return output;
    }

protected:
    Item* input1; // Первый вход
    Item* input2; // Второй вход
    bool output;  // Выходное значение
};

// Класс для передачи выходного сигнала другим вентилям
class Output {
public:
    // Добавление вентиля, который будет получать сигнал
    void addTarget(Item* target) {
        targets.push_back(target);
    }

    // Передача сигнала на все подключенные вентили
    void sendSignal() {
        for (auto target : targets) {
            target->calculate();
        }
    }
// Класс для логического вентиля AND
class AndGate : public Item {
public:
    // Метод для выполнения логики AND
    void calculate() {
        if (input1 && input2) {
            output = input1->getOutput() && input2->getOutput();
        }
    }
};

private:
    std::vector<Item*> targets; // Список вентилей для передачи сигнала
};


// Класс для логического вентиля OR
class OrGate : public Item {
public:
    // Метод для выполнения логики OR
    void calculate() {
        if (input1 && input2) {
            output = input1->getOutput() || input2->getOutput();
        }
    }
};

int main() {
    // Создание вентилей
    AndGate andGate;
    OrGate orGate;

    // Установка входов для вентиля AND
    andGate.setInputs(&orGate, &orGate); // Для примера, используем OR вентиль дважды

    // Создание выходного сигнала
    Output output;
    output.addTarget(&andGate);

    // Вычисляем выходное значение вентиля AND
    andGate.calculate();

    // Вывод результата
    std::cout << "Output of AND gate: " << andGate.getOutput() << std::endl;

    return 0;
}
