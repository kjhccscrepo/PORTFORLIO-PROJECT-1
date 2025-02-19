// Online C++ compiler to run C++ program online
#include <iostream>
#include <random>


//Vital functions pieces
void HPDISPLAY(int DMG);
int PLAYERHP = 20;
int remHP = 20;

int hplosstestvar;

//the void function
void HPDISPLAY(int DMG) 
{
    std::cout << std::endl << "Damage taken!" << std::endl;
    PLAYERHP = PLAYERHP - DMG;
    std::cout << std::endl;
    remHP = PLAYERHP;
    if (remHP % 2 == 0) {
        for (remHP = PLAYERHP/2; remHP > 0; remHP--) {
            std::cout << "❤";
        }   
    }
    else {
        for (remHP = (PLAYERHP - 1) / 2; remHP > 0; remHP--) {
            std::cout << "❤";
        }
            std::cout << "♥";
    }
    std::cout << std::endl;
    
}
int main() {
    srand(time(NULL));
    for (int i; i < 5; i++) 
    {
    HPDISPLAY((rand() % 4) + 1);
    std::cout << "You've been hit!";
    std::cout << "This is a test the HP is " << PLAYERHP << "/20";
        
    }
   
    
    
    return 0;
}


