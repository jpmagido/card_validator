#include <iostream>

std::string get_digits();

int double_second_digit(const std::string &card_number, const int &size);

int add_odd_numbers(const std::string &card_number, const int &size);

int main() {
    std::string card_number = get_digits();
    int size = card_number.size();

    int total = double_second_digit(card_number, size) + add_odd_numbers(card_number, size);

    if (total % 10 == 0) {
        std::cout << "Congratulations, your card numbers are valid\n";
    } else {
        std::cout << "Oups, your card numbers are not valid\n";
    }

    return 0;
}

std::string get_digits() {
    std::string card_numbers;

    std::cout << "Hello, please give us the card numbers you want to validate: \n";
    std::cout << "> ";
    std::cin >> card_numbers;

    return card_numbers;
}

int add_odd_numbers(const std::string &card_number, const int &size) {
    int result = 0;

    for (int i = size - 1; i >= 0; --i) {
        if (i % 2 == 1) {
            result += card_number[i] - 48;
        }
    }

    return result;
}

int double_second_digit(const std::string &card_number, const int &size) {
    int numbers[size / 2];
    int number_index = 0;
    int result = 0;

    for (int i = size - 1; i >= 0; --i) {
        if (i % 2 == 0) {
            if ((card_number[i] - 'O') * 2 > 10) {
                numbers[number_index] = 1;
                numbers[number_index + 1] = (card_number[i] - 48) * 2 % 10;
                number_index += 2;
            } else {
                numbers[number_index] = (card_number[i] - 48) * 2;
                number_index++;
            }
        }
    }

    for (int number: numbers) {
        if (number > 9) {
            result += 1;
            result += number % 10;
        } else {
            result += number;
        }
    }

    return result;
}
