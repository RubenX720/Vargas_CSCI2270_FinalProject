#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <queue>
#include <limits.h>
#include <algorithm>
#include "Game.h"

using namespace std;

int main(int argc, char *argv[])
{
    Game game;
    cout<<"*************************************************************************"<<endl;
    cout << "Narrator: A long time ago, there was a Relic so powerful that could"  << endl;
    cout << "restore piece amongst the land of Rubicon. For ages, this Relic was" << endl;
    cout << "possessed by the royal family until the different tribes" << endl;
    cout << "waged war to possess it. Years have passed......Rubicon has split into" <<endl;
    cout << "five different kingdoms......and now it must be returned to the rightful"<< endl;
    cout << "heir to the throne.....Princess Lara........................." << endl;
    cout << "Only she can truly use it to defeat all evil lurking in the kingdom." <<endl;
    cout << "FIND HER AND RESTORE PEACE!" << endl;
    cout<<"*************************************************************************"<<endl;
    cout<<"                            g@@       "<< endl;
    cout<<"        A.                 d@V@"<< endl;
    cout<<"       i@b               iA` @                    .A"<< endl;
    cout<<"        i@V@s            dA`  @                   ,@@i"<< endl;
    cout<<"        i@ '*@Ws______mW@f    @@                  ]@@@"<< endl;
    cout<<"         @]  '^********f`     @@@                g@!l@"<< endl;
    cout<<"         @b           .  ,g   @@@W             ,W@[ l@"<< endl;
    cout<<"         ]@   Mmmmmf  ~**f^   @@^@@Wm_.      _g@@`  l@"<< endl;
    cout<<"          M[    ^^      ^^    @@  ^*@@@@@@@@@@@f`   l@"<< endl;
    cout<<"          ]@i  '[]`  . '[]`   @@      ~~~~~~~`      l@"<< endl;
    cout<<"          '@W       |[        @@               _.   l@"<< endl;
    cout<<"           Y@i      'Ns    .  @@   _m@@m,    g*~VWi l@"<< endl;
    cout<<"            M@. ,.       g@` ]@@  gP    V,  '  m- ` l@"<< endl;
    cout<<"           '@W  Vmmmmmm@f   @@@. ~  m-    g   '    l@"<< endl;
    cout<<"             '@b  'V***f    g@A@W    '     @        l@"<< endl;
    cout<<"              '*W_         g@A`M@b       g M_.      l@"<< endl;
    cout<<"                'VMms___gW@@f   @@.      '- ~`      W@"<< endl;
    cout<<"                   ~*****f~`     @@.     ,_m@Ws__   @@"<< endl;
    cout<<"                                 '@@.   gA~`   ~~* ]@P"<< endl;
    cout<<"                                  M@s.'`         g@A"<< endl;
    cout<<"                                   V@@Ws.    __m@@A"<< endl;
    cout<<"                                      ~*M@@@@@@@@*`"<< endl;
    cout<<"*************************************************************************"<<endl;
    cout<<"Greetings, our names are Geno and Gene......................."<<endl;
    cout<<"We have come a long way...we have the Relic you are looking"<<endl;
    cout<<"for. I need your help to deliver it to the rightful owner."<<endl;
    cout<<"We must hurry......everyone is after me. Let me tell you something..."<<endl;
    cout<<"you will find a menu of options. Each option will dictate your"<<endl;
    cout<<"adventure....In order to take the Relic....choose option 1 to store"<<endl;
    cout<<"the item in your bag of 'goodies'. Type in 'Relic' into the command line'"<<endl;
    cout<<"*************************************************************************"<<endl;
    string user_command;
    ifstream infile;
    while(true)
    {
        cout << "======Options======" << endl;
        cout << "1. Get Item" << endl;
        cout << "2. Use Item" << endl;
        cout << "3. View Map" << endl;
        cout << "4. Travel" << endl;
        cout << "5. Show Inventory" << endl;
        cout << "6. Gather Locations" <<endl;
        cout << "7. Reclaim Peace" << endl;
        cout << "8. Quit" << endl;
        cin >> user_command;
        cin.clear();
        cin.ignore(10000,'\n');
        int value;
        string city1;
        istringstream(user_command)>>value;
        switch (value)
        {
            case 1:
            {
                string title;
                cout<<"Take Item:"<<endl;
                getline(cin, title);
                if (title=="Relic"){
                    game.insertItem(title);
                    cout<<"*************************************************************************"<<endl;
                    cout<<"Gene: Great! Now, we have to find the Princess! We must travel to each"<<endl;
                    cout<<"of the kingdoms! First, press option '6' to gather our destination"<<endl;
                    cout<<"points. Press option '3' to view the map of the kingdoms we still have"<<endl;
                    cout<<"to visit. Notice that there is one destination that we cannot track."<<endl;
                    cout<<"Once we gather up clues as to the name of this destination....press option"<<endl;
                    cout<<"'4', enter the name of the 'secret' location, and travel there."<<endl;
                    cout<<"You can check your item inventory by pressing option '5'."<<endl;
                    cout<<"*************************************************************************"<<endl;
                }
                else if (title=="Sword"||"Shield"||"Fire-Amulet"||"Potion"||"Bomb"||"Bazooka"||"Master-Sword"||"Bow-and-Arrow"){
                        game.insertItem(title);
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Geno: You got an item!"<<endl;
                        cout<<"*************************************************************************"<<endl;
                }
                else {
                    cout<<"*************************************************************************"<<endl;
                    cout<<"Geno: No such item exists!"<<endl;
                    cout<<"*************************************************************************"<<endl;
                }
                break;
            }
            case 2:
            {
                string title;
                cout<<"Use Item:"<<endl;
                getline(cin, title);
                game.deleteItem(title);
                break;
            }
            case 3:
            {
                cout<<"TRAVEL TO REMAINING LOCATIONS"<<endl;
                game.printNetwork();
                break;
            }
            case 4:
            {
                string title;
                cout << "Enter a Kingdom: " << endl;
                getline(cin,city1);
                game.deleteCity(city1);
                cout<<"#############################################################"<<endl;
                cout<<"#                    _                                      #"<<endl;
                cout<<"#                  -=\\`\\                                    #"<<endl;
                cout<<"#              |\\ ____\\_\\__                                 #"<<endl;
                cout<<"#            -=\\c`\"\"\"\"\"\"\" \"`)                               #"<<endl;
                cout<<"#               `~~~~~/ /~~`\                                #"<<endl;
                cout<<"#                 -==/ /                                    #"<<endl;
                cout<<"#                   '-'                                     #"<<endl;
                cout<<"#                  _  _                                     #"<<endl;
                cout<<"#                 ( `   )_                                  #"<<endl;
                cout<<"#                (    )    `)                               #"<<endl;
                cout<<"#              (_   (_ .  _) _)                             #"<<endl;
                cout<<"#                                             _             #"<<endl;
                cout<<"#                                            (  )           #"<<endl;
                cout<<"#             _ .                         ( `  ) . )        #"<<endl;
                cout<<"#           (  _ )_                      (_, _(  ,_)_)      #"<<endl;
                cout<<"#         (_  _(_ ,)                                        #"<<endl;
                cout<<"#############################################################"<<endl;
                if(city1 == "Alberia"){
                        cout<<"*************************************************************************"<<endl;
                        cout<<"                     ###%###%####"<<endl;
                        cout<<"                    ######%##%#####"<<endl;
                        cout<<"                   ########%%#%####"<<endl;
                        cout<<"                   ##########%%%%%%"<<endl;
                        cout<<"                   ############%%#%"<<endl;
                        cout<<"                   ############%%##"<<endl;
                        cout<<"                   '####_'_'##%# "<<endl;
                        cout<<"                     #|L    L###%                %E%E%."<<endl;
                        cout<<"                     ##  < ' ,#%#                %E%E%EE%%"<<endl;
                        cout<<"                    ,##\  - ,##%%                %E%E%EE%EE%"<<endl;
                        cout<<"                       /\._.## %__               %E%E%E%EE%%EE"<<endl;
                        cout<<"                   _.-'  \  / ##  '-.            %E%E%E%E%%EE%%"<<endl;
                        cout<<"                  /    \  \/  ##    |             %E%E%E%EE%EEEE"<<endl;
                        cout<<"                  |\    \ /  /##  |/\             %E%EEEE%EEE%%%%"<<endl;
                        cout<<"                  | |    /  | ##  |  |           /%EEEE%EE%%EEEEEE"<<endl;
                        cout<<"                  | /   |  / %%   /  |          | / %%EEEEEEEEEEE'"<<endl;
                        cout<<"                  | |  /  /  ##% |   \          |  .Y"<<endl;
                        cout<<"                  |.|-/\-/-__## /\    \._.--.,-'  /"<<endl;
                        cout<<"                  |/%%%%%/%\%##%| \  _/       | /'"<<endl;
                        cout<<"                  %(%%%%(%%%|##%|  \          |/"<<endl;
                        cout<<"                 |%\%%%%|%%%\#%%|   \      _.-/"<<endl;
                        cout<<"                /|%%\%%%/%%%%|%/|    '_   ._-/"<<endl;
                        cout<<"               / |%%%|''|%%%%\  |      ---./ "<<endl;
                        cout<<"              |  |%%%%\ |%%%%%| \ "<<endl;
                        cout<<"             /   /%%%%| |%%%%%\  |"<<endl;
                        cout<<"             |  |%%%%%| |%%%'''' |" <<endl;
                        cout<<"             \ |%%%%%%| -''      |"<<endl;
                        cout<<"            / \|%%%%%%|   ||     |"<<endl;
                        cout<<"           /  /|%%%%%%|   ||      |"<<endl;
                        cout<<"      ____/  / |%%%%%%- | || ^    |"<<endl;
                        cout<<"    /      ./  |%%-'    | ||      |"<<endl;
                        cout<<"   --- > _/    |%| | |  | ||      |"<<endl;
                        cout<<"       -'       \\ | |  | ||  | | | "<<endl;
                        cout<<"                  /  |  | |   | | |"<<endl;
                        cout<<"                  |  |  | |   | | |"<<endl;
                        cout<<"                  |  |  | |   |/  |"<<endl;
                        cout<<"                  | /|  \ |   \   |"<<endl;
                        cout<<"                  |/=|    |       |"<<endl;
                        cout<<"                  ||=|    |       |"<<endl;
                        cout<<"                  ||=\    |       |"<<endl;
                        cout<<"                  ||====  |       |"<<endl;
                        cout<<"                  ||=====\        |"<<endl;
                        cout<<"                  |/|==   \       |"<<endl;
                        cout<<"                   \|     |\       |"<<endl;
                        cout<<"                    |     |===.__  |"<<endl;
                        cout<<"                    /    | =   .|''"<<endl;
                        cout<<"                   /=   %  =    |"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Vampire Princess: Welcome....I'm the only princess you'll find here!"<<endl;
                        cout<<"I see that you have brought me something....Come on...give me the"<<endl;
                        cout<<"Relic......give it now.........STOP RESISTING!"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Gene: Quick, use a weapon!"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Enter Item:"<<endl;
                        getline(cin, title);
                        game.deleteItem(title);
                        if(title=="Relic"){
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Geno: YA BOZO! YOU JUST GAVE HER THE RELIC! MISSION FAILED!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                                }
                                else if(title=="Sword"||"Master-Sword"||"Bazooka"||"Bow-and-Arrow"||"Bomb"||"Fire-Amulet"){
                                        cout<<"*************************************************************************"<<endl;
                                        cout<<"Vampire Princes: ARRGHHHHHHHH!"<<endl;
                                        cout<<"*************************************************************************"<<endl;
                                        cout<<"Gene: Good Job Kid! Hurry, take her 'Shield' and her 'Potion'!"<<endl;
                                        cout<<"*************************************************************************"<<endl;
                                        cout<<"Take Item:"<<endl;
                                        getline(cin, title);
                                        game.insertItem(title);
                                        cout<<"*************************************************************************"<<endl;
                                        cout<<"Take Item:"<<endl;
                                        getline(cin, title);
                                        game.insertItem(title);
                                        cout<<"*************************************************************************"<<endl;
                                        cout<<"Gene: Notice how her Shield had the letter 'O'"<<endl;
                                        cout<<"Hurry on to the next Kingdom!"<<endl;
                                        cout<<"*************************************************************************"<<endl;
                                        }
                }
                if(city1=="Hyrule"){
                        cout<<"*************************************************************************"<<endl;
                        cout<<"                             _______"<<endl;
                        cout<<"         ..-'`       ````---."<<endl;
                        cout<<"       .'          ___ .'````.'SS'."<<endl;
                        cout<<"      /        ..-SS####'.  /SSHH##'."<<endl;
                        cout<<"     |       .'SSSHHHH##|/#/#HH#H####'."<<endl;
                        cout<<"    /      .'SSHHHHH####/||#/: \SHH#####\ "<<endl;
                        cout<<"   /      /SSHHHHH#####/!||;`___|SSHH###\ "<<endl;
                        cout<<"-..__    /SSSHHH######.         \SSSHH###\ "<<endl;
                        cout<<"`.'-.''--._SHHH#####.'           '.SH####/"<<endl;
                        cout<<"  '. ``'-  '/SH####`/_             `|H##/"<<endl;
                        cout<<"  | '.     /SSHH###|`'==.       .=='/\H|"<<endl;
                        cout<<"  |   `'-.|SHHHH##/\__\/        /\//|~|/"<<endl;
                        cout<<"  |    |S#|/HHH##/             |``  |"<<endl;
                        cout<<"  |    \H' |H#.'`              \    |"<<endl;
                        cout<<"  |        ''`|               -     /"<<endl;
                        cout<<"  |          /H\          .----    /"<<endl;
                        cout<<"  |         |H#/'.           `    /"<<endl;
                        cout<<"  |          \| | '..            /"<<endl;
                        cout<<"  |            /|    ''..______.'"<<endl;
                        cout<<"   \          //\__    _..-. | "<<endl;
                        cout<<"    \         ||   ````     \ |_"<<endl;
                        cout<<"     \    _.-|               \| |_"<<endl;
                        cout<<"     _\_.-'   `'''''-.        |   `--."<<endl;
                        cout<<" ''``    \            `''-;    \ /"<<endl;
                        cout<<"          \      .-'|     ````.' -"<<endl;
                        cout<<"          |    .'  `--'''''-.. |/"<<endl;
                        cout<<"          |  .'               \|"<<endl;
                        cout<<"         |.'"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Link: So....you have come to Hyrule in search of a Princess?"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Geno: You should help us track her down!"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Link: I have my own Princess to look for...but...."<<endl;
                        cout<<"take these items for your troubles!"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Gene: Take the 'Bomb', the 'Bow-and-Arrow', and the 'Master-Sword'"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Take Item:"<<endl;
                        getline(cin, title);
                        game.insertItem(title);
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Take Item:"<<endl;
                        getline(cin, title);
                        game.insertItem(title);
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Take Item:"<<endl;
                        getline(cin, title);
                        game.insertItem(title);
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Link: By the way...this might help you"<<endl;
                        cout<<"in your journey towards the princess"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"#########################################################################"<<endl;
                        cout<<"#############NOTE:There is a secret location that starts#################"<<endl;
                        cout<<"########################with the letter 'XE'#############################"<<endl;
                        cout<<"#########################################################################"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Gene: Great!!!! Hurry on to the next Kingdom!"<<endl;
                        cout<<"*************************************************************************"<<endl;
                }
                if(city1 == "Coruscant"){
                        cout<<"*************************************************************************"<<endl;
                        cout<<"                   |'.             ,"<<endl;
                        cout<<"                   |  '-._        / )"<<endl;
                        cout<<"                 .'  .._  ',     /_'-,"<<endl;
                        cout<<"                '   /  _'.'_\   /._)')"<<endl;
                        cout<<"               :   /  '_' '_'  /  _.'"<<endl;
                        cout<<"               |E |   |Q| |Q| /   /"<<endl;
                        cout<<"              .'  _\  '-' '-'    /"<<endl;
                        cout<<"            .'--.(S     ,__` )  /"<<endl;
                        cout<<"                  '-.     _.'  /"<<endl;
                        cout<<"                __.--'----(   /"<<endl;
                        cout<<"            _.-'     :   __\ /"<<endl;
                        cout<<"           (      __.' :'  :Y"<<endl;
                        cout<<"            '.   '._,  :   :|"<<endl;
                        cout<<"              '.     ) :.__:|"<<endl;
                        cout<<"                \    \______/"<<endl;
                        cout<<"                 '._L/_H____]"<<endl;
                        cout<<"                  /_        /"<<endl;
                        cout<<"                 /  '-.__.-')"<<endl;
                        cout<<"               :      /   /"<<endl;
                        cout<<"                :     /   /"<<endl;
                        cout<<"              ,/_____/----;"<<endl;
                        cout<<"              '._____)----'"<<endl;
                        cout<<"              /     /   /"<<endl;
                        cout<<"             /     /   /"<<endl;
                        cout<<"           .'     /    \ "<<endl;
                        cout<<"          (______(-.____)"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Astro-Boy: Yeah...I think I've seen the princess a" <<endl;
                        cout<<"couple of times.......but hey...let me save you some"<<endl;
                        cout<<"time...I think I last saw her in the dark realm."<<endl;
                        cout<<"I think the place ends with letters 'BIA'."<<endl;
                        cout<<"I can't quite remember......hope that helps...."<<endl;
                        cout<<"BUT....if you give me an item.....I will give you something"<<endl;
                        cout<<"in return....depending on how the good the item is........"<<endl;
                        string title;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Give Item:"<<endl;
                        getline(cin, title);
                        game.deleteItem(title);
                        if(title=="Potion"||"Master-Sword"||"Bomb"||"Fire-Amulet"){
                                cout<<"Astro-Boy: Deal...Take this 'Bazooka'!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Take Item:"<<endl;
                                getline(cin, title);
                                game.insertItem(title);
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Gene: Hurry on to the next Kingdom!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                        }
                        else if(title=="Shield"||"Sword"||"Bow-and-Arrow"){
                                cout<<"Astro-Boy: Seriously....this sucks....BUT.."<<endl;
                                cout<<"I ain't giving it back....NOW SCRAM!!!!!!!!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Gene: Whatever....Hurry on to the next Kingdom!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                        }
                        else if(title=="Relic"){
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Geno: YA BOZO! YOU JUST GAVE HIM THE RELIC! MISSION FAILED!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                        }
                }
                if(city1=="El Infierno"){
                        cout<<"*************************************************************************"<<endl;
                        cout<<"         |\   \        /        /| "<<endl;
                        cout<<"        /  \  |\__  __/|       /  \ "<<endl;
                        cout<<"       / /\ \ \ _ \/ _ /      /    \ "<<endl;
                        cout<<"      / / /\ \ {*}\/{*}      /  / \ \ "<<endl;
                        cout<<"      | | | \ \( (00) )     /  // |\ \ "<<endl;
                        cout<<"      | | | |\ \(V""V)\    /  / | || \| "<<endl;
                        cout<<"      | | | | \ |^--^| \  /  / || || || "<<endl;
                        cout<<"     / / /  | |( WWWW__ \/  /| || || || "<<endl;
                        cout<<"    | | | | | |  \______\  / / || || || "<<endl;
                        cout<<"    | | | / | | )|______\ ) | / | || || "<<endl;
                        cout<<"    / / /  / /  /______/   /| \ \ || || "<<endl;
                        cout<<"   / / /  / /  /\_____/  |/ /__\ \ \ \ \ "<<endl;
                        cout<<"   | | | / /  /\______/    \   \__| \ \ \ "<<endl;
                        cout<<"   | | | | | |\______ __    \_    \__|_| \ "<<endl;
                        cout<<"   | | ,___ /\______ _  _     \_       \  | "<<endl;
                        cout<<"   | |/    /\_____  /    \      \__     \ |    /\ "<<endl;
                        cout<<"   |/ |   |\______ |      |        \___  \ |__/  \ "<<endl;
                        cout<<"   v  |   |\______ |      |            \___/     | "<<endl;
                        cout<<"      |   |\______ |      |                    __/ "<<endl;
                        cout<<"       \   \________\_    _\               ____/ "<<endl;
                        cout<<"     __/   /\_____ __/   /   )\_,      _____/ "<<endl;
                        cout<<"    /  ___/  \   /  ___/___)    \______/ "<<endl;
                        cout<<"    VVV  V        VVV  V "<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Dragon: An unwanted specimen...........LEAVE!!!"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Geno: Quick......exterminate the dragon!!!"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        string title;
                        cout<<"Use Item:"<<endl;
                        getline(cin, title);
                        game.deleteItem(title);
                        if(title=="Relic"){
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Geno: YA BOZO! YOU JUST GAVE HIM THE RELIC! MISSION FAILED!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                        }
                        else if(title=="Bazooka"||"Bomb"||"Master-Sword"){
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Dragon: ARGHHHHHHHHH!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Gene: Great Job Kid! Hurry, take his 'Fire Amulet'"<<endl;
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Take Item:"<<endl;
                                getline(cin, title);
                                game.insertItem(title);
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Geno: Do you see that? His amulet has the letter"<<endl;
                                cout<<"'R'..... Hurry on to the next Kingdom!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                        }
                        else if(title=="Sword"||"Bow-and-Arrow"){
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Dragon: SERIOUSLY....IS THAT ALL YOU GOT!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                        }
                        else if(title=="Shield"){
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Geno: It's Breathing fire....TAKE COVER!!!!!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                        }
                        else if(title=="Potion"){
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Gene: Congratulations.....you just made it more powerful!!!!!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                        }
                }
                if(city1=="Paraiso Verde"){
                        cout<<"*************************************************************************"<<endl;
                        cout<<"                 |###################|    "<<endl;
                        cout<<"                 |###################|          "<<endl;
                        cout<<"                 |###################|         " <<endl;
                        cout<<"                 |###################|          "<<endl;
                        cout<<"     ((-----------------------------------------"<<endl;
                        cout<<"     | \         /  /@@ \      /@@ \  \ "<<endl;
                        cout<<"      \ \,      /  (     )    (     )  \            _____"<<endl;
                        cout<<"       \ \      |   \___/      \___/   |           /  __ \ "<<endl;
                        cout<<"        \ --*-__/                      \           | |  | |"<<endl;
                        cout<<"         ""*-_                          -_         | |  ''' "<<endl;
                        cout<<"              \    -.  _________   .-   __--.__.-((  ))"<<endl;
                        cout<<"               \,    \^    U    ^/     /  -___--((  ))"<<endl;
                        cout<<"                 \,   \         /    /'            | |"<<endl;
                        cout<<"                  |    \       /   /'              | |"<<endl;
                        cout<<"                  |     '-----'    \               | |"<<endl;
                        cout<<"                /                  *-._          | | "<<endl;
                        cout<<"                /   /\          /*-._    \         | |"<<endl;
                        cout<<"               /   /  '\______/     /   /         | |"<<endl;
                        cout<<"              /   /                 /   /          | |"<<endl;
                        cout<<"             /. ./                  |. .|          ---"<<endl;
                        cout<<"            /  | |                  / | \ "<<endl;
                        cout<<"           /   |  \                /  |  \   "<<endl;
                        cout<<"          /.-./.-.|               /.-.|.-.\ "<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Mr.Toad: Alright.....I know why you're here..."<<endl;
                        cout<<"'N' is the letter....................because why not?"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Geno: 'N' is the letter and notice how this is the"<<endl;
                        cout<<"'third' kingdom we have visited!"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Gene: OK...thanks for the clue.......off to the next kingdom!"<<endl;
                        cout<<"*************************************************************************"<<endl;
                }
                if(city1=="XENORBIA"){
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Geno: We are fast approaching the Dark Kingdom....XENORBIA!"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Gene: Go into the Dark Castle............"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Fallen-Warrior: SO.....IT IS YOU WHO LOOKS FOR THE PRINCESS!!!!"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"                           ==(W{==========-      /===-"<<endl;
                        cout<<"                             ||  (.--.)         /===-_---~~~~~~~~~------____"<<endl;
                        cout<<"                             | \_,|**|,__      |===-~___                _,-'  "<<endl;
                        cout<<"                -==\\        `\ ' `--'   ),    `//~\\   ~~~~`---.___.-~~"<<endl;
                        cout<<"            ______-==|        /`\_. .__/\ \    | |  \\           _-~`"<<endl;
                        cout<<"      __--~~~  ,-/-==\\      (   | .  |~~~~|   | |   `\        ,'"<<endl;
                        cout<<"   _-~       /'    |  \\     )__/==0==-\<>/   / /      \      /"<<endl;
                        cout<<" .'        /       |   \\      /~\___/~~\/  /' /        \   /'"<<endl;
                        cout<<"/  ____  /         |    \`\.__/-~~   \  |_/'  /          \/'"<<endl;
                        cout<<"/-'~    ~~~~~---__  |     ~-/~         ( )   /'        _--~`"<<endl;
                        cout<<"                 \_|      /        _) | ;  ),   __--~~"<<endl;
                        cout<<"                   '~~--_/      _-~/- |/ \   '-~ \            "<<endl;
                        cout<<"                  {\__--_/}    / \\_>-|)<__\      \ "<<endl;
                        cout<<"                  /'   (_/  _-~  | |__>--<__|      | "<<endl;
                        cout<<"                 |   _/) )-~     | |__>--<__|      |   "<<endl;
                        cout<<"                 / /~ ,_/       / /__>---<__/      |  "<<endl;
                        cout<<"                o-o _//        /-~_>---<__-~      / "<<endl;
                        cout<<"                (^(~          /~_>---<__-      _-~          "<<endl;
                        cout<<"               ,/|           /__>--<__/     _-~                 "<<endl;
                        cout<<"            ,//('(          |__>--<__|     /                  .----_ "<<endl;
                        cout<<"           ( ( '))          |__>--<__|    |                 /' _---_~\ "<<endl;
                        cout<<"        `-)) )) (           |__>--<__|    |               /'  /     ~\`\ "<<endl;
                        cout<<"       ,/,'//( (             \__>--<__\    \            /'  //        ||"<<endl;
                        cout<<"     ,( ( ((, ))              ~-__>--<_~-_  ~--____---~' _/'/        /'"<<endl;
                        cout<<"   `~/  )` ) ,/|                 ~-_~>--<_/-__       __-~ _/ "<<endl;
                        cout<<" ._-~//( )/ )) `                    ~~-'_/_/ /~~~~~~~__--~ "<<endl;
                        cout<<"  ;'( ')/ ,)(                              ~~~~~~~~~~ "<<endl;
                        cout<<" ' ') '( (/"<<endl;
                        cout<<"   '   '  `"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        cout<<"Fallen-Warrior: NOW.....GIVE ME THE RELIC...OR MEET YOUR DEMISE!!!!"<<endl;
                        cout<<"*************************************************************************"<<endl;
                        string title;
                        cout<<"Use Item:"<<endl;
                        getline(cin, title);
                        game.deleteItem(title);
                        if(title=="Relic"){
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Geno: YA BOZO! YOU JUST GAVE HIM THE RELIC! MISSION FAILED!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                        }
                        else if(title=="Master-Sword"){
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Fallen-Warrior: ARGHHHHHHHHH! YOU KILLED MY DRAGON!!!! COME BACK HERE!!!!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Gene: RUN!!!!!!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                                cout<<"              __...gggg..__"<<endl;
                                cout<<"          .gd$$$$$SSSS$$$$$$$bg._"<<endl;
                                cout<<"        .dSSSS$$$$$$$SSS$$$$$$SSS$bg."<<endl;
                                cout<<"       d$$$$$$SSSS$$$$$SSSS$$$$$SS$$$bg."<<endl;
                                cout<<"      :SSS$$$$$$$$SSS$$$$$SSSS$$$SS$$SS$b."<<endl;
                                cout<<"      $$$$SS$$$$$$$$$SSS$$$$$SSS$$S$$$S$$$b"<<endl;
                                cout<<"     :$$$$$$SS$$$$$$$$$$SSSS$$$SS$S$$SS$$$S;"<<endl;
                                cout<<"     $$$$$$$$$SSP^**""**^T$SS$$$SS$$SS$$$S$$"<<endl;
                                cout<<"     SSSSS$$$$$;            `'*^S^*'   '*^TP "<<endl;
                                cout<<"    :$$$$$SS$$;                            ;"<<endl;
                                cout<<"    :$$$$$$$SS                             |"<<endl;
                                cout<<"    SSS$$$$$$;                             :"<<endl;
                                cout<<"    $$$SS$$$$                              ;"<<endl;
                                cout<<"    SS$$$SS^'"<<endl;
                                cout<<"    :$S$$$;      _                        :"<<endl;
                                cout<<"   :''*T$$     ,d$$s+._               _.g$P "<<endl;
                                cout<<"   |,'; T;    *'    `*Tbs+,  ,     .sP*'  ; "<<endl;
                                cout<<"   :  :          +g+=+._ `*^'    :'  _.++g"<<endl;
                                cout<<"    ;  \         `T. $$$\        ; .' $$$|"<<endl;
                                cout<<"    : `.           ` `'         |    `'| "<<endl;
                                cout<<"     \  ;                        :       ;"<<endl;
                                cout<<"     dbg$"<<endl;
                                cout<<"    :$$$$ \                             :"<<endl;
                                cout<<"    :S$$$  \                            ;"<<endl;
                                cout<<"     TS$$   `.                 ,  ;"<<endl;
                                cout<<"    .dSS$                   ;     :    :"<<endl;
                                cout<<"   d$$$SS`                  '--._.'    ;"<<endl;
                                cout<<"  :$$$$$; \ "<<endl;
                                cout<<"  :S$$$$;  \            .__.--._.-._  '"<<endl;
                                cout<<"   TS$$$    `.          \-._.-._.-.: ."<<endl;
                                cout<<"  .dSS$$   :  `.         `._      .'"<<endl;
                                cout<<" d$$$SS;    \   `.          `""""'  '"<<endl;
                                cout<<":$$$$$S;     \    `-.          '   / "<<endl;
                                cout<<":$$$$$$       `.     `-._         /"<<endl;
                                cout<<" TS$$$;        `-.      '**----*' "<<endl;
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Princess Lara: YOU MADE IT.....HURRY...GIVE ME THE RELIC!!!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Use Item:"<<endl;
                                    getline(cin, title);
                                    if(title=="Relic"){
                                            game.deleteItem(title);
                                    cout<<"*************************************************************************"<<endl;
                                    cout<<"Princess Lara: This is the one!"<<endl;
                                    cout<<"*************************************************************************"<<endl;
                                    cout<<"Gene: Unleash its power and kill him off!!"<<endl;
                                    cout<<"*************************************************************************"<<endl;
                                    cout<<"Fallen-Warrior: NOOOOOOOO! I HAVE BEEN DEFEATED!!!"<<endl;
                                    cout<<"*************************************************************************"<<endl;
                                    cout<<"Geno: Let's get out of here!!!"<<endl;
                                    cout<<"*************************************************************************"<<endl;
                                    cout<<"Princess Lara: There is one last task you must do......"<<endl;
                                    cout<<"Take my 'Azure-Amulet' as proof that you have reclaimed peace"<<endl;
                                    cout<<"*************************************************************************"<<endl;
                                    cout<<"Take Item:"<<endl;
                                        getline(cin, title);
                                        game.insertItem(title);
                                    cout<<"*************************************************************************"<<endl;
                                }
                        }
                        else if(title=="Sword"||"Bow-and-Arrow"||"Bomb"){
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Fallen-Warrior: SERIOUSLY....IS THAT ALL YOU GOT!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                        }
                        else if(title=="Shield"){
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Fallen-Warrior: VERY WELL!!!!!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                        }
                        else if(title=="Potion"){
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Gene: Congratulations.....you just made it more powerful!!!!!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                        }
                        else if(title=="Fire-Amulet"||"Bazooka"){
                                cout<<"*************************************************************************"<<endl;
                                cout<<"Fallen-Warrior: SUCH POWERFUL WEAPONS....DIDN't LEAVE A MARK!!!!!"<<endl;
                                cout<<"*************************************************************************"<<endl;
                        }
                }
                if(city1=="Final Boss"){
                    cout<<"You have made it to the final boss! It appears that he is the strongest character in the game"<<endl;
                    cout<<"You must use the Master Sword to defeat him and regain peace among our people!"<<endl;
                    cout<<"Use Item:"<<endl;
                    getline(cin, title);
                    if(title == "Master Sword" || "master sword" || "Master sword" || "master Sword")
                    {
                        game.deleteItem(title);
                        cout<<"You did it! But at the expense of your Master Sword.. The sword broke in half as you took the Final Boss' life. Now peace can be returned to the people."
                    }
                    else
                    {
                        cout<<"You must use the master sword!"<<endl;
                    }
                }
                break;
            }
            case 5:
            {
              cout<<"Your Bag Contains:"<<endl;
              game.printInventory();
              break;
            }
            case 6:
            {
                game.buildNetwork();
                cout<<"*************************************************************************"<<endl;
                cout<<"Geno: Good...Good! You need a weapon....add "<<endl;
                cout<<"this 'Sword' to your inventory!"<<endl;
                cout<<"*************************************************************************"<<endl;
                break;
            }
            case 7:
            {
                cout<<"*************************************************************************"<<endl;
                cout<<"In order to reclaim peace, you must have the Princess' token of approval."<<endl;
                cout<<"*************************************************************************"<<endl;
                cout<<"Use Item:"<<endl;
                string title;
                getline(cin, title);
                if(title=="Azure-Amulet"){
                game.deleteItem(title);
                cout<<"VICTORIOUS...YOU HAVE RESTORED PEACE AND RUBICON IS ONCE AGAIN UNITED!!!!"<<endl;
                return 0;
                }
                else{
                    cout<<"*************************************************************************"<<endl;
                    cout<<"Geno: No, that's not it!"<<endl;
                    cout<<"*************************************************************************"<<endl;
                }
                break;
            }
            case 8:
            {
              cout<<"*************************************************************************"<<endl;
              cout << "DISSAPOINTED GENO: I SEE.....THE COWARD'S WAY OUT!!!!" << endl;
              cout<<"*************************************************************************"<<endl;
              return 0;
            }
        }
    }
    return 0;
}
