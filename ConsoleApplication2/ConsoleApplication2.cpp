#include <iostream>  
#include <cstring>  
#include <cctype>  

using namespace std;

void FindSlove(const char* str, char ch) { // 1
    int count = 0;
    cout << "Индексики вхождений символа '" << ch << "': ";
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            cout << i << " ";
            count++;
        }
    }
    cout << "\nКоличество совпаденний: " << count << "\n";
}

void Countik(const char* str) { // 2
    int Glasnie = 0, Coglasnie = 0, Punktacia = 0, Chisla = 0, Drugieee = 0, Slova = 0;
    bool InWord = false;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (isalpha(ch)) {
            if (strchr("aeiou", ch)) {
                Glasnie++;
            }
            else {
                Coglasnie++;
            }
            if (!InWord) {
                InWord = true;
                Slova++;
            }
        }
        else {
            if (isspace(ch)) {
                InWord = false;
            }
            else if (ispunct(ch)) {
                Punktacia++;
            }
            else if (isdigit(ch)) {
                Chisla++;
            }
            else {
                Drugieee++;
            }
        }
    }

    cout << "Всего символов в строке текста – " << strlen(str) << ", из них:\n";
    cout << "Слов – " << Slova << "\nГласненьких буквочек - " << Glasnie
        << "\nСогласненьких буквочек - " << Coglasnie
        << "\nЗнаков пунктуации - " << Punktacia
        << "\nЦифрочек – " << Chisla
        << "\nДругих символов – " << Drugieee << "\n";
}

void SrediSlovecki(const char* str) { // 3
    int TotalLength = 0, Words = 0;
    char* Copy = strdup(str);
    char* Token = strtok(Copy, " ");

    while (Token != nullptr) {
        TotalLength += strlen(Token);
        Words++;
        Token = strtok(nullptr, " ");
    }

    if (Words > 0) {
        cout << "Средняя длина словечка: " << static_cast<double>(TotalLength) / Words << "\n";
    }
    else {
        cout << "Словечок не найдено(" << "\n";
    }

    free(Copy);
}

void CountikDerr(const char* str, const char* word) { // 4
    int Count = 0;
    char* copy = strdup(str);
    char* token = strtok(copy, " ");

    while (token != nullptr) {
        if (strcasecmp(token, word) == 0) {
            Count++;
        }
        token = strtok(nullptr, " ");
    }

    cout << "Словечко \"" << word << "\" встречается " << Count << " раз(а)." << "\n";
    free(copy);
}

void CkeckSPam(const char* str, const char* badWords[], int size) { // 5
    for (int i = 0; i < size; i++) {
        if (Constan(str, badWords[i]) != nullptr) {
            cout << "ЭТО СПАМ! 0_0" << "\n";
            return;
        }
    }
    cout << "это не спам (❁´◡`❁)" << "\n";
}

const char* Constan(const char* str, const char* pattern) {
    while (*str) {
        if (tolower(*str) == tolower(*pattern)) {
            const char* s1 = str;
            const char* s2 = pattern;
            while (*s1 && *s2 && tolower(*s1) == tolower(*s2)) {
                s1++;
                s2++;
            }
            if (!*s2) return str;
        }
        str++;
    }
    return nullptr;
}

int main() {
    const int MAX_LENGTH = 256;
    char str[MAX_LENGTH];

    cout << "Введите строчечку: ";
    cin.getline(str, MAX_LENGTH);

    char ch;
    cout << "Введите символ для поиска: ";
    cin >> ch;

    FindSlove(str, ch);

    Countik(str);
    SrediSlovecki(str);

    char word[MAX_LENGTH];
    cout << "Введите слово для подсчетика: ";
    cin >> word;
    CountikDerr(str, word);

    const char* badWords[] = { "viagra", "xxx" };
    CkeckSPam(str, badWords, sizeof(badWords) / sizeof(badWords[0]));

    return 0;
}