#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream in("in.txt");
    ofstream out("out.txt");

    string line;
    bool exist = false;
    string answer;
    while (getline(in, line)) {
        string letter;
        letter.push_back(line[0]);
        char blank[] = " ";
        char s[] = " ";
        for (int i = 0; i < line.length(); i++) {
            if ((s[0] == line[i]) && (letter[0] == line[i + 1])) {
                exist = true;
            }
        } 
        if (!exist) {
            out << line << '\n';
            int ans = 100000; int count = 0;
            for (int j = 0; j < line.length(); j++) {
                if (s[0] == line[j]) {
                    if (count < ans) {
                        string answ = "";
                        ans = count;
                        count = 0;
                        for (int k = (j-ans); k < j; k++) {
                            answ.push_back(line[k]);
                        }
                        if (answer.length() == 0) answer = answ;
                        if (answ.length() < answer.length()) answer = answ;
                    } else {
                        count = 0;
                    }
                } else {
                    count++;
                }
            }
        } else exist = false;
    }
    std::cout << "самое короткое слово: " << answer;
    in.close();
    out.close();
    return 0;
}