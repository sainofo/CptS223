include "Header.hpp"
#include "LinkedList.hpp"
#include "Game.hpp"

// Command Match
void Game::GameMenu() {
    int option = 0;

    string myText;

    ifstream MyComReadFile("commands.csv");

    do {
        cout << "-----WELCOME-----" << endl;
        cout << "Please select the option below!" << endl;
        cout << "1. Game Rules" << endl;
        cout << "2. Play Game" << endl;
        cout << "3. Load Previous Game" << endl;
        cout << "4. Add Command" << endl;
        cout << "5. Remove Command" << endl;
        cout << "6. Exit Game" << endl;
        cout << "Chosen Option: " << endl;
        std::cin >> option;
        cout << option;

        switch (option) {
        case 1:
            cout << "1. Game Rules" << endl;

            // Game Description/Rules
            cout << "Command Match Game Description" << endl;
            cout << "------------------------------" << endl;
            cout << "Command Match is a type of game where you match the commands and its description." << endl;
            cout << "There are 30 command terms and will be randomized." << endl;
            cout << "To win, you must match them all by guessing the command within the definiton." << endl;
            cout << "Here is the Commands Guide: " << endl;
            cout << "---------------------------" << endl;
            MyComReadFile.open("commands.csv");
            if (MyComReadFile.is_open()) {
                MyComReadFile >> myText;
                cout << myText;
            }
            else {
                cout << "The file is unable to open.\n" << endl;
            }
            MyComReadFile.close();
            system("pause");
            system("cls");
            break;

        case 2:
            cout << "2. Play Game" << endl;
            string def;
            string command;

            srand(32);
            def = (rand() % 32);
            cout << "which term matches the definition?\n enter the command: " << endl;
            cin >> command;
            cout << def << command << endl;
            break;
        case 3:
            cout << "3. Load Previous Game" << endl;
            srand(32);
            def = (rand() % 32);

            break;
        case 4:
            cout << "4. Add Command" << endl;
            cout << "type a command: " << endl;
            cin >> command;
            cout << "command is added!" << endl;
            break;
        case 5:
            cout << "5. Remove Command" << endl;
            int comm = 0;
            --comm;
            break;
        case 6:
            cout << "6. Exit Game" << endl;
            return;
            break;
        default: option;
        }
    } while (option <= 6);
}
