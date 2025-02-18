// Portfolio1 DungeonCrawler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>

//varibles will be reset here

bool LoopGame = true;
bool InvalidNumInput = true;
int Gamestart;
int rngdice;
int score;

int main()
{

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

        rngdice = (rand()% 4);

        if (rngdice == 0) {
        std::cout << std::endl;
        //this gives you an garentued roll on the first treasure.
        //BUT i have to add the code that does that...
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
            score = score + (rand()% 36) + 470;

        }else if (rngdice == 1 || rngdice == 3) {
            std::cout << "\nYou feel a tug on your fishing line!\nThen reel in your line...\nBut then suddenly a fox comes out of nowhere!";
            std::cout << R"(
|\_/|,,_____,~~`
(.".)~~     )`~}}
 \o/\ /---~\\ ~}}
   _//    _// ~}
)" << '\n';
            std::cout << "\nDrats! The little fella stole your fish and ran off...";
            std::cout << "\nYou will have to go into the dungeon on an empty stomach, how sad...";

        }else if (rngdice == 2 || rngdice == 4) {
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

        rngdice = (rand() % 4);

        if (rngdice == 0 || rngdice == 1) {
            std::cout << "\nA Skeleton appears! It's bones rattle, and it looks like its going to attack!";
            std::cout << "\nWhat do you do?";
        }

        return 0;


    } while (LoopGame);


    std::cout << "\n\nClosing the Game!\n";
    return 0;
}
