#include <iostream>
#include <vector>
#include <queue>

#define NUM_GK 10
#define NUM_CB 16
#define NUM_LB 5
#define NUM_RB 6
#define NUM_DM 12
#define NUM_CM 19
#define NUM_LW 10
#define NUM_RW 10
#define NUM_ST 12

using namespace std;

// Player Class
class Player
{
public:
    string name;
    int hidden_rating;

    Player(string n, int r): name(n), hidden_rating(r){}
};

Player goalkeepers[NUM_GK]={
    Player("Lev Yashin", 10),
    Player("Manuel Neuer", 9),
    Player("Oliver Kahn", 9),
    Player("Peter Schmeichel", 9),
    Player("Petr Ceech", 8),
    Player("Edwin van der Sar", 8),
    Player("Dida", 7),
    Player("Thibaut Courtois", 8),
    Player("Gianluigi Buffon", 10),
    Player("Iker Casillas", 10)
};

Player center_backs[NUM_CB]={
    Player("Franz Beckenbauer", 10),
    Player("Paolo Maldini", 10),
    Player("Bobby Moore", 9),
    Player("Ronald Koeman", 8),
    Player("Alessandro Nesta", 8),
    Player("Virgil van Dijk", 8),
    Player("Sergio Ramos", 8),
    Player("Carles Puyol", 8),
    Player("John Terry", 8),
    Player("Nemanja Vidic", 7),
    Player("Thiago Silva", 7),
    Player("Gerard Piqué", 7),
    Player("Giorgio Chiellini", 7),
    Player("Rio Ferdinand", 7),
    Player("Franco Baresi", 9),
    Player("Fabio Cannavaro", 10)
};

Player left_backs[NUM_LB]={
    Player("Roberto Carlos", 10),
    Player("Ashley Cole", 9),
    Player("Dennis Irwin", 8),
    Player("Andrew Robertson", 8),
    Player("Marcelo Vieira", 9)
};

Player right_backs[NUM_RB]={
    Player("Cafu", 10),
    Player("Dani Alves", 9),
    Player("Lilian Thuram", 9),
    Player("Javier Zanetti", 9),
    Player("Trent Alexander-Arnold", 8),
    Player("Philipp Lahm", 9)
};

Player defensive_midfielders[NUM_DM]={
    Player("Lothar Matthaus", 10),
    Player("Claude Makelele", 9),
    Player("Patrick Vieira", 9),
    Player("Roy Keane", 8),
    Player("NGolo Kante", 8),
    Player("Casemiro", 8),
    Player("Sergio Busquets", 9),
    Player("Xabi Alonso", 8),
    Player("Rodri", 8),
    Player("Fernando Redondo", 8),
    Player("Dunga", 7),
    Player("Frank Rijkaard", 9)
};

Player central_midfielders[NUM_CM]={
    Player("Zinedine Zidane", 10),
    Player("Diego Maradona", 10),
    Player("Xavi Hernandez", 9),
    Player("Luka Modric", 9),
    Player("Steven Gerrard", 9),
    Player("Frank Lampard", 9),
    Player("Andres Iniesta", 9),
    Player("Toni Kroos", 9),
    Player("Paul Scholes", 9),
    Player("Zico", 8),
    Player("Kaka", 8),
    Player("Michael Laudrup", 8),
    Player("Mesut Ozil", 8),
    Player("Michael Platini", 8),
    Player("Rui Costa", 7),
    Player("Clarence Seedorf", 8),
    Player("Cesc Fabregas", 8),
    Player("Johan Cruyff", 10),
    Player("Andrea Pirlo", 9)
};

Player left_wingers[NUM_LW]={
    Player("Cristiano Ronaldo", 10),
    Player("Ryan Giggs", 9),
    Player("Pavel Nedved", 8),
    Player("Franck Ribery", 8),
    Player("Thierry Henry", 9),
    Player("Robert Pires", 8),
    Player("Neymar Jr.", 8),
    Player("Eden Hazard", 7),
    Player("Kylian Mbappe", 8),
    Player("Ronaldinho", 10)
};

Player right_wingers[NUM_RW]={
    Player("Lionel Messi", 10),
    Player("George Best", 9),
    Player("Arjen Robben", 8),
    Player("Luis Figo", 8),
    Player("Gareth Bale", 8),
    Player("Ángel Di Maria", 8),
    Player("Jairzinho", 8),
    Player("David Beckham", 7),
    Player("Mohamed Salah", 7),
    Player("Garrincha", 10)
};

Player strikers[NUM_ST]={
    Player("Pele", 10),
    Player("Gerd Muller", 9),
    Player("Marco van Basten", 9),
    Player("Romario", 9),
    Player("Eusebio", 9),
    Player("Alfredo di Stefano", 9),
    Player("Ferenc Puskas", 9),
    Player("Luis Suarez", 8),
    Player("Karim Benzema", 8),
    Player("Robert Lewandowski", 8),
    Player("Sergio Aguero", 7),
    Player("Ronaldo Nazario", 10)
};


struct Node {
    Player player;
    Node* next;
    Node(Player p) : player(p), next(nullptr) {}
};


class Selectedplayer
{
private:
    Node* head;

public:
    Selectedplayer() : head(nullptr) {}
    void addPlayer(Player player){
        Node* newNode = new Node(player);
        if(head == nullptr)
            head = newNode;
        else{
            Node* temp = head;
            while(temp->next!= nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void displayTeam(){
        Node* temp = head;
        
        while(temp!= nullptr){
            cout << temp->player.name << " - " << temp->player.hidden_rating <<endl;
            temp = temp->next;
        }
    }
    
    int totalTeampoints(){
        int totalPoints = 0;
        Node* temp = head;
        while(temp!= nullptr){
            totalPoints += temp->player.hidden_rating;
            temp = temp->next;
        }
        return totalPoints;
    }
    
    
};



void displayPlayers(Player players[], int size){
    for(int i=0; i<size; i++){
        cout << i+1 << ". " << players[i].name /*<< " - " << players[i].hidden_rating */<< endl;
    }
}

int main(){

    Selectedplayer UserTeam;
    Selectedplayer CompilerTeam;
    

    cout << "\t\tWelcome to the Football Team Builder!\n" << endl;
    cout << "----------------------------------------------------------------\n" << endl;




    int gk = sizeof(goalkeepers) / sizeof(goalkeepers[0]);

    cout << "Goalkeeper List:\n";
    displayPlayers(goalkeepers, NUM_GK);
    cout << "Select your favourite Goalkeeper: ";
    int index ;
    cin >> index;
    UserTeam.addPlayer(goalkeepers[index -1]);
    goalkeepers[index-1] = goalkeepers[gk-1];
    gk--;
    CompilerTeam.addPlayer(goalkeepers[0]);
    

    int cb = sizeof(center_backs) / sizeof(center_backs[0]);
    cout << "Center Backs List:\n";
    displayPlayers(center_backs, NUM_CB);
    cout << "Select your favourite First Center Backs: ";
    cin >> index ;
    UserTeam.addPlayer(center_backs[index -1]);
    center_backs[index-1] = center_backs[cb-1];
    cb--;
    cout << "Select your favourite Second Center Backs: ";
    cin >> index ;
    UserTeam.addPlayer(center_backs[index -1]);
    center_backs[index-1] = center_backs[cb-1];
    cb--;
    CompilerTeam.addPlayer(center_backs[0]);
    CompilerTeam.addPlayer(center_backs[1]);


    int lb = sizeof(left_backs) / sizeof(left_backs[0]);
    cout << "Left Backs List:\n";
    displayPlayers(left_backs, NUM_LB);
    cout << "Select your favourite Left Back: ";
    cin >> index ;
    UserTeam.addPlayer(left_backs[index -1]);
    left_backs[index-1] = left_backs[lb-1];
    lb--;
    CompilerTeam.addPlayer(left_backs[0]);



    int rb = sizeof(right_backs) / sizeof(right_backs[0]);
    cout << "Right Backs List:\n";
    displayPlayers(right_backs, NUM_RB);
    cout << "Select your favourite Right Back: ";
    cin >> index ;
    UserTeam.addPlayer(right_backs[index -1]);
    right_backs[index-1] = right_backs[rb-1];
    rb--;
    CompilerTeam.addPlayer(right_backs[0]);



    int dm = sizeof(defensive_midfielders) / sizeof(defensive_midfielders[0]);
    cout << "Defensive Midfielders List:\n";
    displayPlayers(defensive_midfielders, NUM_DM);
    cout << "Select your favourite Defensive Midfielder: ";
    cin >> index ;
    UserTeam.addPlayer(defensive_midfielders[index -1]);
    defensive_midfielders[index-1] = defensive_midfielders[dm-1];
    dm-- ;
    CompilerTeam.addPlayer(defensive_midfielders[0]);



    int cm = sizeof(central_midfielders) / sizeof(central_midfielders[0]);
    cout << "Central Midfielders List:\n";
    displayPlayers(central_midfielders, NUM_CM);
    cout << "Select your favourite Central Midfielder: ";
    cin >> index ;
    UserTeam.addPlayer(central_midfielders[index -1]);
    central_midfielders[index-1] = central_midfielders[cm-1];
    cm--;
    cout << "Select your favourite Second Central Midfielder: ";
    cin >> index ;
    UserTeam.addPlayer(central_midfielders[index -1]);
    central_midfielders[index-1] = central_midfielders[cm-1];
    cm--;
    CompilerTeam.addPlayer(central_midfielders[0]);
    CompilerTeam.addPlayer(central_midfielders[1]);




    int lw = sizeof(left_wingers) / sizeof(left_wingers[0]);
    cout << "Left Wingers List:\n";
    displayPlayers(left_wingers, NUM_LW);
    cout << "Select your favourite Left Winger: ";
    cin >> index ;
    UserTeam.addPlayer(left_wingers[index -1]);
    left_wingers[index-1] = left_wingers[lw-1];
    lw--;
    CompilerTeam.addPlayer(left_wingers[0]);

    
    int rw = sizeof(right_wingers) / sizeof(right_wingers[0]);
    cout << "Right Wingers List:\n";
    displayPlayers(right_wingers, NUM_RW);
    cout << "Select your favourite Right Winger: ";
    cin >> index ;
    UserTeam.addPlayer(right_wingers[index -1]);
    right_wingers[index-1] = right_wingers[rw-1];
    rw--;
    CompilerTeam.addPlayer(right_wingers[0]);



    int st = sizeof(strikers) / sizeof(strikers[0]);
    cout << "Strikers List:\n";
    displayPlayers(strikers, NUM_ST);
    cout << "Select your favourite Striker: ";
    cin >> index ;
    UserTeam.addPlayer(strikers[index -1]);
    strikers[index-1] = strikers[st-1];
    st--;
    CompilerTeam.addPlayer(strikers[0]);



    cout << "\n-----------------------------------------------------------:\n";
    cout << "User Best XI Team:\n";
    UserTeam.displayTeam();
    int Team1 = UserTeam.totalTeampoints();
    cout << "User Team Points: " << Team1 << "\n";



    cout << "\n-----------------------------------------------------------:\n";
    cout << "Compiler Best XI Team:\n";
    CompilerTeam.displayTeam();
    int Team2 = CompilerTeam.totalTeampoints();
    cout << "Compiler Team Points: " << Team2 << "\n";

    if (Team1>Team2){
        cout << "\nUser Team Wins!\n";
        cout << "User Team: " << (Team1-Team2)%2+1 <<":" << 0 << " :Compiler Team\n";
    }
    else if (Team1<Team2){
        cout << "Compiler Team Wins!\n";
        cout << "User Team: " << 0 <<":" << (Team2-Team1)%2+1 << " :Compiler Team\n";
    }
    else{
        cout << "It's a Draw!\n";
        cout << "User Team: " << 2 <<":" << 2 << " :Compiler Team\n";
    }

    return 0;
}