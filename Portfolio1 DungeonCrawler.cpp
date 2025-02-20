// Portfolio1 DungeonCrawler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>

//this is an attempt to make my own function
int HPDISPLAY(int x, int y);

int Gamestart;
int rngdice;
int score = 0;
int yesno;
int PLAYERHP = 20;
int EniAHP;
int remHP = 20;

int main()
{
    bool treasure = false;
    bool have_magic_sword = false;
    bool have_ancient_bowl = false;
    int occult_doll = 0;
    bool have_golden_arrow = false;
    bool LoopGame = true;
    bool InvalidNumInput = true;
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
    std::cout << "\nThis game was made possible due to people numerous contributions to the ASCII art archive, where most of the ASCII art in this game came from" << std::endl;
    //seeds the rng to the computers clock. I use null instead of num cause it gets rid of the warning message
    srand(time(NULL));
    do {

        std::cout << "Welcome to Bountiful Dungeons!!!" << std::endl << "The goal of this game is too explore a dungeon, collect monster parts and treasure, then cook up a sick meal with what you got" << std::endl;

        std::cout << "\nWould you like to start the game?\n1) Start Game\n2) Close Game";
        while (InvalidNumInput) {
            std::cout << "\nYour answer: ";
            std::cin >> Gamestart;
            //this first branch of the if/else statement is for valididating user inputs, it checks for a non int input
            if (std::cin.fail()) {
                //the cin.clear clears the cin buffer, basically its what makes it so the program allows for cin >> gamestart to occour again.
                std::cin.clear(); std::cin.ignore(512, '\n');
                std::cout << "\nYou have failed to input a valid number. Please input a 1 or a 2...";
            }
            else if (Gamestart == 2) {
                std::cout << "\nUnderstood...";
                std::cout << "\n\nClosing the Game!\n";
                return 0;
            }
            else if (Gamestart != 2 && Gamestart != 1) {
                std::cout << "\nYou have failed to input a valid number. Please input a 1 or a 2...";
            }
            else {
                //for when a 1 is inputted
                InvalidNumInput = false;
            }
        }
        //where the game actually starts
        score = 0;
        //randomized intro cutscene

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
        std::cout << "You make your way through the dungeon, but then you notice something move in the corner of your vision!" << std::endl;

        //Encounter 1 Skeleton|| Goblin|| Onion|
        rngdice = (rand() % 4);
        if (rngdice == 0 || rngdice == 1) {
            std::cout << "\nA Skeleton appears! It's bones rattle, and it looks like its going to attack!";
            std::cout << "\nWhat do you do?";

            //combat!

            //adds a variable between 275 and 350 to your score
            score = score + ((rand() % 74) + 1) + 275;
        }
        else if (rngdice == 4 || rngdice == 3) {
            std::cout << "\nA Goblin appears! It's snarls at you, and it looks like its going to attack!";
            std::cout << "\nWhat do you do?";
            InvalidNumInput = true;
            EniAHP = 3;
            while (InvalidNumInput || EniAHP > 0) {
                std::cout << "\n1) Attack\n2) Run";
                std::cout << "\nYour Answer: ";
                std::cin >> yesno;
                if (std::cin.fail()) {
                    //the cin.clear clears the cin buffer, basically its what makes it so the program allows for cin >> gamestart to occour again.
                    std::cin.clear(); std::cin.ignore(512, '\n');
                    std::cout << "\nYou have failed to input a valid number. Please input a 1 or a 2...";
                }
                else if (yesno == 2) {
                    std::cout << "\nYou attempt to run away..." << std::endl;
                    rngdice = (rand() % 10);
                    if (rngdice == 9) {
                    //fail to run and take damage
                        std::cout << "But the Goblin catches up to you and strikes!" << std::endl;
                        //taking damage
                        PLAYERHP = PLAYERHP - 1;
                        //make a common event (class?) for displaying remaining HP
                    }
                    else {
                    //succussfull getaway
                        std::cout << "You get away! And continue to make your way through the dungeon." << std::endl;
                    }
                }
                else if (yesno != 1) {
                    std::cout << "\nYou have failed to input a valid number. Please input a 1 or a 2..." << std::endl;
                }
                else {
                    //attack
                    InvalidNumInput = false;
                    if (have_magic_sword) {
                        rngdice = ((rand() % 4) + 5);
                        std::cout << "You attack with your Magic Sword!";
                        if (rngdice == 7) {
                            //crit                            
                            std::cout << "Woah! A critical hit! Massive damage inflicted on the enemy!" << std::endl;
                            EniAHP = EniAHP - 9;
                        }
                        else {
                            EniAHP = EniAHP - 3;
                        }
                        
                    }
                    else {
                        rngdice = ((rand() % 19) + 1);
                        std::cout << "You attack with your Sword!";
                        if (rngdice == 7) {
                            //crit                            
                            std::cout << "Woah! A critical hit! Massive damage inflicted on the enemy!" << std::endl;
                            EniAHP = EniAHP - 3;
                        }
                        else {
                            EniAHP = EniAHP - 1;
                        }
                    }
                //This is where enemy hit chance happens
                    std::cout << "\nThe Goblin moves to attack you!" << std::endl;
                    //goblin hit chance
                    rngdice = (rand() % 9) + 1;
                    if (rngdice != 4) {
                        std::cout << "The Goblin lunges at you and misses!" << std::endl;
                    }
                    else {
                        std::cout << "The Goblin lunges at you and smashes its mace into you!" << std::endl;
                        PLAYERHP = (PLAYERHP - 1);
                        
                       

                    }
                }
                
            }
            //combat!

            //adds a variable between 150 and 250 to your score
            score = score + ((rand() % 99) + 1) + 150;
        }
        else if (rngdice == 2) {
            std::cout << "\nWoah! It's a Walking Onion! A rare creature!\nThey are known to be a little bit skiddish!";
            std::cout << "\nWhat do you do?";

            //combat!

            //adds a variable between 300 and 377 to your score
            score = score + ((rand() % 76) + 1) + 300;
        }

        //treasure chance using score divided by 777

        rngdice = ((rand() % 776) + 1);
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
                    std::cin.clear(); std::cin.ignore(512, '\n');
                    std::cout << "\nYou have failed to input a valid number. Please input a 1 or a 2...";
                }
                else if (yesno == 2) {
                    std::cout << "\n\nYou chose not to open the chest...\nPerhaps a correct choice...";
                }
                else if (yesno != 1) {
                    //if num isnt a 1 or 2
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
                    else if (rngdice <= 16){
                        occult_doll = occult_doll + 1;
                        std::cout << "Inside it was a strange doll..." << std::endl;
                        std::cout << "You wonder if it will be of any use..." << std::endl;
                    }
                    //MIMIC 5%
                    else if (rngdice == 17) {
                        //DEATH 
                    }
                    //EMPTY 5%
                    //CHANGE TO A HIGHCHANCE BY MOVING AROUND VARS AND MAKE IT HEAL YOU INSTEAD FOR + 10 HP
                    else if (rngdice == 18) {
                        std::cout << "Inside it was..." << std::endl;
                        //add dramtic pause here
                        std::cout << "nothing..." << std::endl;
                        std::cout << "Someone else must of have gotten to this treasure first." << std::endl;
                    }
                    //GOLD ARROW
                    else if (rngdice == 19) {
                    
                        //MISSING CODE HERE, MAKE SURE TO CODE IT
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
            


        return 0;


    } while (LoopGame);


    std::cout << "\n\nClosing the Game!\n";
    return 0;
}

//trying to make my own function here.
int HPDISPLAY(int x, int y) {
    std::cout << "Damage taken!" << std::endl;
    std::cout << std::endl;
    for (remHP = PLAYERHP; remHP > 0; remHP--) {
        if (remHP % 2 == 0) {
            std::cout << "❤";
        } else {
            std::cout << "♥";
        }
    }
}
