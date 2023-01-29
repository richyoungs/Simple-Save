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
#include <limits>
#include <filesystem>


//using namespace std;

class Game {
private:
    int favoriteNumber = -123456;
    void save() {

        std::filesystem::create_directories("./Data");
        std::ofstream file("Data/number.dat"); 
        if (file.is_open()) {
            file << favoriteNumber << std::endl;
            file.close();
            system("cls");
            std::cout << "Data saved successfully!" << std::endl;
            system("pause");
            displayMainMenu();
        }
        else {
            system("cls");
            std::cout << "Error: Unable to save data" << std::endl;
            system("pause");
            displayMainMenu();
        }
    }
    void load() {
        std::ifstream file("Data/number.dat");
        system("cls");
        std::cout << "Your number has been loaded from the save file" << std::endl;
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

std::cout << R"(
     _   _   _   _     _   _   _   _  
    / \ / \ / \ / \   / \ / \ / \ / \ 
   ( M | a | i | n ) ( M | e | n | u )
    \_/ \_/ \_/ \_/   \_/ \_/ \_/ \_/ 
_______________________________________
)" << std::endl << std::endl;

    std::cout << "1. Enter favorite number" << std::endl;
    std::cout << "2. Display favorite number" << std::endl;
    std::cout << "3. Options" << std::endl;
    std::cout << "4. Exit" << std::endl << std::endl;
    std::cout << "> ";

        int choice;
        std::cin >> choice;
        switch (choice) {

            case 1:
                system("cls");
                std::cout << "Enter your favorite number: ";
                std::cin >> favoriteNumber;

                while (!std::cin.good())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("cls");
                    std::cout << "Invalid entry. Please try again." << std::endl;
                    system("pause");
                    favoriteNumber = -123456;
                    displayMainMenu();
                }
                system("cls");
                std::cout << "Favorite number remembered." << std::endl;
                system("pause");
                displayMainMenu();
                

            case 2:
                if (favoriteNumber == -123456) {
                    system("cls");
                    std::cout << "No favorite number has been entered yet." << std::endl;
                    system("pause");  
                }
                else {
                    system("cls");
                    std::cout << "Your favorite number is " << favoriteNumber << std::endl;
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
                std::cout << "Invalid choice. Try again." << std::endl;
                std::cin.clear();
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

        std::cout << R"(
     _   _   _   _   _   _   _  
    / \ / \ / \ / \ / \ / \ / \ 
   ( O | p | t | i | o | n | s )
    \_/ \_/ \_/ \_/ \_/ \_/ \_/ 
________________________________

)" << std::endl << std::endl;

        std::cout << "1. Save favorite number" << std::endl;
        std::cout << "2. Load favorite number" << std::endl;
        std::cout << "3. Go back to main menu" << std::endl << std::endl;
        std::cout << "> ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (favoriteNumber == -123456){
                    system("cls");
                    std::cout << "No data to Save." << std::endl;
                    system("pause");
                    displayOptionsMenu();
                }
                else{
                    save();
                    std::cout << "Favorite number saved." << std::endl;
                    displayOptionsMenu();
                    break;
                }
            case 2:
                //This needs logically re-written. 
                //Fails to load on new boot since favoriteNumber is less than 0 by default an error is thrown
                //Issue will be logged in Github and resolved ASAP
                if (favoriteNumber <= 0 ){
                    system("cls");
                    std::cout << "No Data to Load." << std::endl;
                    system("pause");
                    displayOptionsMenu();
                }
                else{
                load();
                std::cout << "Loaded favorite number: " << favoriteNumber << std::endl;
                displayOptionsMenu();
                }
                break;
            case 3:
                displayMainMenu();
                break;
            default:
                system("cls");
                std::cout << "Invalid choice. Try again." << std::endl;
                std::cin.clear();
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

    std::cout <<  R"(
        
      ____                           ___               ____                              
     /\  _`\   __                   /\_ \             /\  _`\                            
     \ \,\L\_\/\_\    ___ ___   ____\//\ \      __    \ \,\L\_\     __    __  __    __   
      \/_\__ \\/\ \ /' __` __`\/\ '__`\ \ \   /'__`\   \/_\__ \   /'__`\ /\ \/\ \ /'__`\ 
        /\ \L\ \ \ \/\ \/\ \/\ \ \ \L\ \_\ \_/\  __/     /\ \L\ \/\ \L\.\\ \ \_/ /\  __/ 
        \ `\____\ \_\ \_\ \_\ \_\ \ ,__/\____\ \____\    \ `\____\ \__/.\_\ \___/\ \____\
         \/_____/\/_/\/_/\/_/\/_/\ \ \/\/____/\/____/     \/_____/\/__/\/_/\/__/  \/____/
                                  \ \_\                                                  
                                   \/_/   

Version 0.60
Build: 23.1.29                                               
 )" << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;

    system("pause");
    Game game;
    game.main();
    return 0;
}
