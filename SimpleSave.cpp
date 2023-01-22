 /* A Simple C++ Program to load and save data
    Copyright (C) 2023  Rich Youngs

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    */
   
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Game {
private:
    int favoriteNumber = -123456;
    void save() {
        ofstream file("Data/number.dat");
        system("cls");
        cout << "Your number has been saved succesfully" << endl;
        system("pause");
        file << favoriteNumber << endl;
        // Data needs to be saved in a better format than just an int in a file
        // Testing has found that numbers are thrown into the file without organization
        // This causes issues when loading from the file
        file.close();
    }
    void load() {
        ifstream file("Data/number.dat");
        system("cls");
        cout << "Your number has been loaded from the save file" << endl;
        system("pause");
        file >> favoriteNumber;
        file.close();
        //Load function is operating normally as it should be
        
    }

public:
    void main() {
        displayMainMenu();
    }
    void displayMainMenu() {
        system("cls"); 

cout << R"(
     _   _   _   _     _   _   _   _  
    / \ / \ / \ / \   / \ / \ / \ / \ 
   ( M | a | i | n ) ( M | e | n | u )
    \_/ \_/ \_/ \_/   \_/ \_/ \_/ \_/ 
_______________________________________
)" << endl << endl;

        cout << "1. Enter favorite number" << endl;
        cout << "2. Display favorite number" << endl;
        cout << "3. Options" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "> ";

        int choice;
        cin >> choice;
        switch (choice) {

            case 1:
                system("cls");
                cout << "Enter your favorite number: ";
                cin >> favoriteNumber;  
                system("cls");
                cout << "Favorite number remembered." << endl;
                system("pause");
                displayMainMenu();  

            case 2:
                if (favoriteNumber == -123456) {
                    system("cls");
                    cout << "No favorite number has been entered yet." << endl;
                    system("pause");  
                }
                else {
                    system("cls");
                    cout << "Your favorite number is " << favoriteNumber << endl;
                    system("pause");
                }
                displayMainMenu();
                break;

            case 3:
                displayOptionsMenu();
                break;
            case 4:

                exit(0);
                break;
            default:

                system("cls");
                cout << "Invalid choice. Try again." << endl;
                cin.clear();
                //cin.ignore();
                //cin.clear();
                fflush(stdin);
                system("pause");
                displayMainMenu();
                break;
        }
    }
    void displayOptionsMenu() {
        system("cls");

        cout << R"(
     _   _   _   _   _   _   _  
    / \ / \ / \ / \ / \ / \ / \ 
   ( O | p | t | i | o | n | s )
    \_/ \_/ \_/ \_/ \_/ \_/ \_/ 
________________________________

)" << endl << endl;

        cout << "1. Save favorite number" << endl;
        cout << "2. Load favorite number" << endl;
        cout << "3. Go back to main menu" << endl << endl;
        cout << "> ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                if (favoriteNumber == -123456){
                    system("cls");
                    cout << "No data to Save." << endl;
                    system("pause");
                    displayOptionsMenu();
                }
                else{
                    save();
                    cout << "Favorite number saved." << endl;
                    displayOptionsMenu();
                    break;
                }
            case 2:
                if (favoriteNumber <= 0 ){
                    system("cls");
                    cout << "No Data to Load." << endl;
                    system("pause");
                    displayOptionsMenu();
                }
                else{
                load();
                cout << "Loaded favorite number: " << favoriteNumber << endl;
                displayOptionsMenu();
                }
                break;
            case 3:
                displayMainMenu();
                break;
            default:
                system("cls");
                cout << "Invalid choice. Try again." << endl;
                cin.clear();
                //cin.ignore();
                //cin.clear();
                system("pause");
                //cout << "Invalid choice. Try again." << endl;
                displayOptionsMenu();
                break;
        }
    }
};

int main() {

   cout <<  R"(
        
      ____                           ___               ____                              
     /\  _`\   __                   /\_ \             /\  _`\                            
     \ \,\L\_\/\_\    ___ ___   ____\//\ \      __    \ \,\L\_\     __    __  __    __   
      \/_\__ \\/\ \ /' __` __`\/\ '__`\ \ \   /'__`\   \/_\__ \   /'__`\ /\ \/\ \ /'__`\ 
        /\ \L\ \ \ \/\ \/\ \/\ \ \ \L\ \_\ \_/\  __/     /\ \L\ \/\ \L\.\\ \ \_/ /\  __/ 
        \ `\____\ \_\ \_\ \_\ \_\ \ ,__/\____\ \____\    \ `\____\ \__/.\_\ \___/\ \____\
         \/_____/\/_/\/_/\/_/\/_/\ \ \/\/____/\/____/     \/_____/\/__/\/_/\/__/  \/____/
                                  \ \_\                                                  
                                   \/_/                                                  
 )" << endl << endl <<endl << endl << endl << endl << endl << endl << endl;

    system("pause");
    Game game;
    game.main();
    return 0;
}
