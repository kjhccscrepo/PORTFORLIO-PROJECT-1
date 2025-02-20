//start of program
//

#include <iostream>
#include <random>
#include <string>

//Vital functions pieces for HP tracking
void HPDISPLAY(int DMG);
int PLAYERHP = 20;
int remHP = 20;

//These are the vars for tracking the score screen and if the new score is higher or lower then the previous one.
int UnoDos;
int playattempts;
void scorescreen(int playattempts);
int score;
int StoredScore;

//Enemy encounter vars
void ENEMYENC(std::string eniNM, std::string eniTXT, int eniHP, int eniDMG, int eniFLEE, int eniHIT, int eniSCR);
bool didrun = false;

//These are the treasure variables
void TREASUREROLL(int treasurechance);
int occult_doll;
bool have_ancient_bowl = false;
bool have_magic_sword = false;

//enemy drop variables
int onions;

//Other Variables
bool gameloop = true;
bool InvalidNumInput = true;
int yesno;
int rngdice;

char EnemyGroup;




int main() {

    std::cout << R"(
                                                    &&
                                                    &&
 ______________________________________,___________&&&&              &
/__________________________________________________&@@@@@@@@@@@@@@@@&&}
\______________________________________ ___________&@@@@@@@@@@@@@@@@&&}
                                       `           &&&&              &
                                                    &&
                                                    &&
)" << '\n';
    std::cout << "\nThis game was made possible due to many numerous contributiors to the ASCII art archive." << std::endl;
    std::cout << "Welcome to Bountiful Dungeons!!!" << std::endl << "The goal of this game is too:\n 1. Explore a dungeon \n2. Collect monster parts and treasure\n 3. Cook up a sick meal with what you got \n4. Aim for the highest score!" << std::endl;
    while (gameloop) {
        std::cout << "\nWould you like to start the game?\n1) Start Game\n2) Close Game";
        while (InvalidNumInput) {
            std::cout << "\nYour answer: ";
            std::cin >> yesno;
            //this first branch of the if/else statement is for valididating user inputs, it checks for a non int input
            if (std::cin.fail()) {
                //the cin.clear clears the cin buffer, basically its what makes it so the program allows for cin >> gamestart to occour again.
                std::cin.clear(); 
                std::cin.ignore(1024, '\n');
                std::cout << "\nYou have failed to input a valid number. Please input a 1 or a 2...";
            }
            else if (yesno == 2) {
                std::cout << "\nUnderstood...";
                std::cout << "\n\nClosing the Game!\n";
                return 0;
            }
            else if (yesno != 2 && yesno != 1) {
                std::cin.clear();
                std::cin.ignore(1024, '\n');
                std::cout << "\nYou have failed to input a valid number. Please input a 1 or a 2...";
            }
            else {
                //for when a 1 is inputted
                InvalidNumInput = false;
            }
        }
        //these are the reset for variables that need to be reset upon replay
        srand(time(NULL));
        PLAYERHP = 20;
        score = 0;
        bool have_magic_sword = false;
        bool have_ancient_bowl = false;
        int occult_doll = 0;
        bool InvalidNumInput = true;
        bool didrun = false;
        EnemyGroup = 'null';

        onions = 0;

        //The following are randomized intro cutscenes, I kinda hate how they turned out but I'm not cutting them for whatever reason

        rngdice = (rand() % 4);
        if (rngdice == 0) {
            std::cout << std::endl;
            //this gives you an increased chance at getting a chance at th first treasure.
            //it does this by inscreasing your base score!!!
            std::cout << R"(
   ...    *    .   _  .   
*  .  *     .   * (_)   *
  .      |*  ..   *   ..
   .  * \|  *  ___  . . *
*   \/   |/ \/{o,o}     .
  _\_\   |  / /)  )* _/_ *
      \ \| /,--"-"---  ..
_-----`  |(,__,__/__/_ .
       \ ||      ..
        ||| .            *
        |||
ejm98   |||
  , -=-~' .-^- _
)" << '\n';
            std::cout << "\nAn beautiful owl sits on a tree outside a ominous dungeon...\nPerhaps this is a sign of good things to come!";
            score = score + (rand() % 36) + 470;
        }
        else if (rngdice == 1 || rngdice == 3) {
            std::cout << "\nYou feel a tug on your fishing line!\nThen reel in your line...\nBut then suddenly a fox comes out of nowhere!";
            std::cout << R"(
|\_/|,,_____,~~`
(.".)~~     )`~}}
 \o/\ /---~\\ ~}}
   _//    _// ~}
)" << '\n';
            std::cout << "\nDrats! The little fella stole your fish and ran off...";
            std::cout << "\nYou will have to go into the dungeon on an empty stomach, how sad...";
        }
        else if (rngdice == 2 || rngdice == 4) {
            std::cout << R"(
                           ≈            ×      ≠π-               
                           ≠            =   ≈≈=÷+                
                           =  ≠∞≠÷      ÷  ×≠≠-+≠                
                            =π≠≠÷       ×  -××--                 
                             √=≠×        +÷-××-+∞                
                             ∞=÷-≈        ≠×××--÷                
                             ≈∞≠≠≠       ∞-=≈÷×-÷                
                          ≠=×÷÷×=-××=÷≠×××+≠≠==××≠               
                         ∞≈≈÷=×≠×≠ ∞≠×=≠≠+×=÷×∞∞-×=              
                        ∞∞÷÷÷××+÷≈   +÷--≠×∞×+×≠∞+-÷≈            
                        ×××-+××-××   +×÷÷× ≠×-+=≈=×--×÷≠         
              ≠-++++++++++-××=π         ≠∞∞∞∞≠÷×++≠≠××-≠≈∞=≈     
              +-≠-×∞ππ≠=πππ≠×∞×≠÷∞∞-π≈×≠×≠-∞=≈÷-÷++≠=+÷×∞∞≈≠≠    
              ≈=÷-≠==≠×≠÷÷≠××-+×-+×××++++-××=++++++×=-++-++-×    
              ≈∞≠≠≠≈=≠≠≠≈=≈≠÷-+×-÷÷=-×-+---=∞×≠÷=--+×÷+-×÷×=÷∞   
            ≠ ∞√≠≠××≠=÷≠=∞-+×++-≠=√ =÷++++÷≠+×≈-++-++×+×+-+÷=∞√  
           π∞√≈≈=÷≠×∞×-×+√=×-++×÷÷×=××++++×+≠××=+×==++-÷××××÷≠÷× 
           ∞π≠×≠÷×÷≠-××××××-+++×÷-≠≠+×-++++÷++×÷×××××++×≠≠×÷×=≠≠ 
          ≠π≠=×≠=×-×××++××÷+++++-+-÷-+++++++××÷++-+++++×+×+×--=×÷
)" << '\n';
            std::cout << "\nWow! An ominous dungeon with an entrance through a hole in huge tree trunk!\nSounds perfect for exploring!" << std::endl;
        }
        std::cout << "\nAs you enter the dungeon you can feel a cold breeze coming from deep inside." << std::endl;
        std::cout << "You make your way through the dungeon...\nBut then you notice something move in the corner of your vision!" << std::endl;

        //Encounter 1 Skeleton|| Goblin|| Onion|
        EnemyGroup = 'A';
        rngdice = (rand() % 4);
        if (rngdice == 0 || rngdice == 1) {
            //combat!
            ENEMYENC("Skeleton", "swings a rusted sword", 3, ((rand() % 1) + 1), 3, 2, 300);
            //this is the succussfull enemy loot drop, i coulda worked it into the function but this seemed easier
            if (didrun = false) {
                //loot drop

            }
        }
        else if (rngdice == 3 || rngdice == 4) {
            ENEMYENC("Goblin", "swings a bat", 4, 1, 1, 4, 200);
            if (didrun = false) {

            }

        }
        else if (rngdice == 2) {
            ENEMYENC("Walking Onion", "tackles", 2, 1, 1, 6, 400);
            if (didrun = false) {
                std::cout << "You obtained 1 Onion!";
                onions++;
            }
        }
        else {
            //this branch should in theroy never fire off, but is there so that if it does happen, I know where to look.
            std::cerr << "A fatal error has occoured!" << std::endl;
            std::cerr << "Program ended up not having a allocated monster to the monster roll!!!" << std::endl;
            std::cerr << "Program is in Enemy Group" << EnemyGroup;
            return 0;
        }
    
        TREASUREROLL(777);
    }
    





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
        while (InvalidNumInput) {
            std::cout << "\n1) Open Chest\n2) Leave it alone";
            std::cout << "\nWhat do you do: ";
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
        std::cout << "\nWhat do you do: ";
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
            rngdice = ((rand() % eniFLEE) + 1);
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
                    std::cout << "Woah! A critical hit! Massive damage inflicted on the " << eniNM << "!" << std::endl;
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
            if (rngdice == ((rand() % eniHIT) + 1)) {
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
