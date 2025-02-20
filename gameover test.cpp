#include <iostream>
#include <random>
#include <string>

//Vital functions pieces for HP tracking
void HPDISPLAY(int DMG);
int PLAYERHP = 20;
int remHP = 20;

//testings something
int UnoDos;
int playattempts;
void scorescreen(int playattempts);
int score;

int hplosstestvar;

bool have_magic_sword = false;
bool didrun = false;

char highscoreCURRENT;
int StoredScore;
char scoreholder;
bool InvalidNumInput = true;

int yesno;
int rngdice;

void ENEMYENC(std::string eniNM, std::string eniTXT, int eniHP, int eniDMG, int eniFLEE, int eniHIT, int eniSCR);

void TREASUREROLL(int treasurechance);
int occult_doll;
bool have_ancient_bowl = false;

int main() {
    srand(time(NULL));

    //vari resets
    PLAYERHP = 20;
    score = (rand() % 5000) + 3000;


    ENEMYENC("Goblin","swings a bat", 4, 1, 10, 5, 200);

    for (int i = 0; i < 5; i++)
    {
        HPDISPLAY((rand() % 6) + 1);
        std::cout << "You've been hit!";
        std::cout << " This is a test the HP is " << PLAYERHP << "/20";
    }
    return 0;
}

//treasure rolls are made my comparing the score to treasure chance, and if the score is greater then or equal to it the roll succeds.
//The treasure chance is a number I spescify that I then randomly generate in the spesifeid range (not including 0).
void TREASUREROLL(int treasurechance) {
    rngdice = ((rand() % treasurechance) + 1);
    if (score >= rngdice) {
        //successful treasure roll
        //You can choose not to open the chest as there is a small chance 5% of getting ambushed by a mimic and dying.
        std::cout << "Woah! You found a treasure chest!!!\nDo you want to open it?";
        InvalidNumInput = true;
        std::cout << "\n1) Open Chest\n2) Leave it alone";
        while (InvalidNumInput) {
            std::cout << "\nYour answer: ";
            std::cin >> yesno;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1024, '\n');
                std::cout << "\nYou have failed to input a valid number. Please input a 1 or a 2...";
            }
            else if (yesno == 2) {
                std::cout << "\n\nYou chose not to open the chest...\nPerhaps a correct choice...";
            }
            else if (yesno != 1) {
                //if num isnt a 1 or 2
                std::cin.clear();
                std::cin.ignore(1024, '\n');
                std::cout << "\nYou have failed to input a valid number. Please input a 1 or a 2...";
            }
            else {
                InvalidNumInput = false;
                std::cout << "\nYou approach the chest..." << std::endl;
                //what treasure will it be!!!
                //basically rolling a d20
                rngdice = ((rand() % 20) + 1);
                //GOLD CHANCE 50%
                if (rngdice <= 10) {
                    //this is the gold treasure chest branch the most common one
                    //this is determine which of the three tiers of gold sums you will get, and how much score you get
                    rngdice = ((rand() % 6) + 1);
                    if (rngdice <= 3) {
                        score = score + ((rand() % 100) + 1) + 200;
                        std::cout << "Inside it was a small amount of gold!" << std::endl;
                    }
                    else if (rngdice <= 5) {
                        score = score + ((rand() % 299) + 1) + 700;
                        std::cout << "Inside it was a decent amount of gold!!" << std::endl;
                    }
                    else if (rngdice == 6) {
                        score = score + ((rand() % 299) + 1) + 1700;
                        std::cout << "Inside it was a huge amount of gold!!!" << std::endl;
                    }

                }
                //MAGIC SWORD 15%
                else if (rngdice <= 13) {
                    //checks if it was already obtained.
                    if (!(have_magic_sword)) {
                        have_magic_sword = true;
                        score = score + ((rand() % 100) + 1) + 200;
                        std::cout << "Inside it was a Magic Sword!!!" << std::endl;
                        std::cout << "You will probablly be able to use this to vanquish monsters more easily..." << std::endl;
                    }
                    else {
                        //if you already have the sword you go here
                        score = score + ((rand() % 299) + 1) + 700;
                        std::cout << "Inside it was a decent amount of gold!!" << std::endl;
                    }
                }
                //OCCULT DOLL 15%
                else if (rngdice <= 16) {
                    occult_doll = occult_doll + 1;
                    std::cout << "Inside it was a strange doll..." << std::endl;
                    std::cout << "You wonder if it will be of any use..." << std::endl;
                }
                //MIMIC 5%
                else if (rngdice == 17) {
                    std::cout << "As you are searching inside the chest you suddenly feel something sharp begin to press into you..." << std::endl;
                    std::cout << "CHOMP!!!!" << std::endl;
                    std::cout << "The Chest must have been a Mimic..." << std::endl << "You have died..." << std::endl;
                    //DEATH
                    playattempts++;
                    //score punishment for death
                    score = (score / 3);
                    scorescreen(playattempts);

                }
                //health potion 10%
                //CHANGE TO A HIGHCHANCE BY MOVING AROUND VARS AND MAKE IT HEAL YOU INSTEAD FOR + 10 HP

                //finish this!!!

                else if (rngdice == 18 || rngdice == 19) {
                    std::cout << "Inside it was..." << std::endl;
                    std::cout << "nothing..." << std::endl;
                    std::cout << "Someone else must of have gotten to this treasure first." << std::endl;
                }
                //ANCIENT BOWL 5%
                else if (rngdice == 20) {
                    //checks if it was already obtained.
                    if (!(have_ancient_bowl)) {
                        have_ancient_bowl = true;
                        std::cout << "Inside it was a Ancient Bowl!!!" << std::endl;
                        std::cout << "You wonder what you can do with it..." << std::endl;
                    }
                    else {
                        //if you already have the bowl you go here and force encounter a mimic :)

                        //DEATH
                    }

                }
            }
        }
        //end of treasure command
    }
}

void ENEMYENC(std::string eniNM, std::string eniTXT, int eniHP, int eniDMG, int eniFLEE, int eniHIT, int eniSCR) {
    didrun = false;
    bool InvalidNumInput = true;
    while (InvalidNumInput || eniHP >= 0) {
        std::cout << "\n1) Attack\n2) Run";
        std::cout << "\nYour Answer: ";
        std::cin >> yesno;
        if (std::cin.fail()) {
            std::cin.clear(); std::cin.ignore(512, '\n');
            std::cout << "\nYou have failed to input a valid number. Please input a 1 or a 2..." << std::endl;
        }
        else if (yesno != 1 && yesno != 2) {
            std::cout << "\nYou have failed to input a valid number. Please input a 1 or a 2..." << std::endl;
        }
        else if (yesno == 2) {
            std::cout << "\nYou attempt to run away..." << std::endl;
            rngdice = (rand() % eniFLEE);
            if (rngdice == 1) {
                //fail to run and take damage
                std::cout << "But the " << eniNM << " catches up to you and " << eniTXT << "!" << std::endl;

                //taking damage
                HPDISPLAY(eniDMG);
            }
            else {
                //succussfull getaway. yields no score
                std::cout << "You get away from the " << eniNM << "! And continue to make your way through the dungeon." << std::endl;
                break;
                didrun = true;
            }
        }
        else {
            //attack
            InvalidNumInput = false;
            if (have_magic_sword) {
                rngdice = ((rand() % 4) + 5);
                std::cout << "You attack with your Magic Sword!";
                if (rngdice == 7) {
                    //crit                            
                    std::cout << "Woah! A critical hit! Massive damage inflicted on the " << eniNM << "!" << std::endl;
                    eniHP = eniHP - 9;
                }
                else {
                    eniHP = eniHP - 3;
                }

            }
            else {
                rngdice = ((rand() % 19) + 1);
                std::cout << "You attack with your Sword!";
                if (rngdice == 7) {
                    //crit                            
                    std::cout << "Woah! A critical hit! Massive damage inflicted on the enemy " << eniNM << "!" << std::endl;
                    eniHP = eniHP - 3;
                }
                else {
                    eniHP = eniHP - 1;
                }
            }

            //This is where enemy hit chance happens
            std::cout << "\nThe " << eniNM << " moves to attack you!" << std::endl;
            //hit chance
            rngdice = (rand() % eniHIT) + 1;
            if (rngdice != 4) {
                std::cout << "The " << eniNM << " attacks you and misses!" << std::endl;
            }
            else {
                std::cout << "The " << eniNM << " attacks you and " << eniTXT << "!" << std::endl;
                HPDISPLAY(eniDMG);
            }
        }

    }
    //this is for massive score increase after the encouter is cleared. it only happens if you didn't run
    if (didrun = false) {
        //foe deafeted!
        std::cout << "Success! The " << eniNM << " was vanquished!" << std::endl;
        score = score + ((rand() % (eniSCR / 15) + 1) + eniSCR);
    }
    else {
    //you do get points for surviving by running, but its a random number between 25 and 50
        score = score + ((rand() % 26) + 25);
    }


}

//this is a function I made that checks the users HP, and if they should game over.
void HPDISPLAY(int DMG)
{
    PLAYERHP = PLAYERHP - DMG;
    std::cout << std::endl << "Damage taken!" << std::endl;
    std::cout << std::endl;
    if (PLAYERHP <= 0) {
        //this is the game over procedure
        std::cout << std::endl << "Oh no! You are out of health!" << std::endl;
        playattempts++;
        scorescreen(playattempts);
        //punishment to score for getting a game over via death!
        score = (score / 3);
        std::cout << "GAME OVER!" << std::endl;
    }
    else {
        //regular damage taken procedure
        remHP = PLAYERHP;
        if (remHP % 2 == 0) {
            for (remHP = PLAYERHP / 2; remHP > 0; remHP--) {
                std::cout << "O";
            }
        }
        else {
            for (remHP = (PLAYERHP - 1) / 2; remHP > 0; remHP--) {
                std::cout << "O";
            }
            std::cout << "o";
        }
        std::cout << std::endl;
    }
}

void scorescreen(int playattempts) {
    std::cout << "Your final score was " << score << "!";
    if (score < 5000) {
        std::cout << std::endl << "Not super impressive..." << std::endl;
    }
    else if (score < 7000) {
        std::cout << std::endl << "A pretty average score..." << std::endl;
    }
    else { 
        std::cout << std::endl << "An impressive score!" << std::endl;
    }
    if (playattempts != 1) {
        if (score > StoredScore) {
            std::cout << "It was even higher then your previous High Score of ";
            std::cout << StoredScore << "!";
            StoredScore = score;
        }
        else if (StoredScore >= score) {
            std::cout << "A score of " << score << " isn't higher then your previous High Score of ";
            std::cout << StoredScore << "...";
        }
    }
    else {
        StoredScore = score;
    }

    std::cout << std::endl << "You have played the game " << playattempts << " time(s). Would you like to play again?" << std::endl;
    InvalidNumInput = true;
    std::cout << "\n1) Play Again\n2) Close Game";
    while (InvalidNumInput) {
        std::cout << "\nYour answer: ";
        std::cin >> UnoDos;
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(1024, '\n');
            std::cout << "\nYou have failed to input a valid number. Please input a 1 or a 2..." << std::endl;
        }
        else if (UnoDos == 1) {
            InvalidNumInput = false;
            main();
        }
        else if (UnoDos == 2) {
            InvalidNumInput = false;
            std::cout << "\n\nClosing the Game!\n";
            //ask about this
            exit(0);
        }
        else {
            std::cin.clear(); 
            std::cin.ignore(1024, '\n');
            std::cout << "\nYou have failed to input a valid number. Please input a 1 or a 2..." << std::endl;
   
        }
    }


}

/*
std::cout << "Please enter a 4 char name for the high score: ";
std::cin >> highscoreCURRENT;

std::cout << "HIGH SCORES:" << std::endl;
*/
//this is disastuerous implementation and I know its not correct, I look fowards to learning how to sort this better with better code.
/*if (playattempts == 1) {
    HighScore score1;
    score1.StoredScore = score;
    score1.scoreholder = highscoreCURRENT;

    std::cout << std::endl << "1. " << score1.scoreholder << "  " << score1.StoredScore;
    std::cout << std::endl << "2. ";
    std::cout << std::endl << "3. ";
    std::cout << std::endl << "4. ";
    std::cout << std::endl << "5. ";
}
else if (playattempts == 2) {
    HighScore score2;
    score2.StoredScore = score;
    score2.scoreholder = highscoreCURRENT;

    std::cout << std::endl << "1. " << score2.scoreholder << "  " << score2.StoredScore;
    std::cout << std::endl << "2. " << score1.scoreholder << "  " << score1.StoredScore;
    std::cout << std::endl << "3. ";
    std::cout << std::endl << "4. ";
    std::cout << std::endl << "5. ";
}
else if (playattempts == 3) {

}
else if (playattempts == 4) {

}
else if (playattempts == 5) {

}
else if (playattempts <= 6) {

}*/
