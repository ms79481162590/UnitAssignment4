#include <iostream>
#include <string> 
#include <unistd.h>
#include "Input_Validation_Extended.h"
using namespace std; 

class Team 
{
  private:
    string Name;
    string Coach_Name;
    string Home_City;
    bool Home_Status;
    int Score;
    int Timeout_Count;
  public:
    Team()
    {
      Name = "DefaultTeamName";
      Coach_Name = "DefaultCoachName";
      Home_City = "";
      Home_Status = false;
      Score = 0;
      Timeout_Count = 0;
    }
      void setName(string n) {Name = n;}
      void setCoachName(string cn) {Coach_Name = cn;}
      void setHome_City(string hm) {Home_City = hm;}
      void setHome_Status(bool s) {Home_Status = s;}
      void setScore(int s) {Score = s;}
      void setTimeout_Count(int tc) {Timeout_Count = tc;}
      string getName() const {return Name;}
      string getCoachName() const {return Coach_Name;}
      string getHome_City() const {return Home_City;}
      bool getHome_Status() const {return Home_Status;}
      int getScore() const {return Score;}
      int getTimeout_Count() const {return Timeout_Count;}
};

class Scoreboard
{
  private:
    int QTR;
    Team Home;
    Team Visitor;
  public:
    Scoreboard()
    {
      QTR = 0;
    }
    void setQTR(int qtr) { QTR = qtr; }
    void setHome(Team hSet) { Home = hSet; }
    void setVisitor(Team vSet) { Visitor = vSet; }
    int getQTR() const { return QTR; }
    Team getHome() const { return Home; }
    Team getVisitor() const { return Visitor; }
    void showScoreboard()
    {
       string color = ""; 
      string reset = "\x1b[35m";
      color = "\x1b[35;4m";  
      string score = "\x1b[35;1m"; 
      cout << color << "\t\tSoccer Scoreboard" << reset << endl; 
      cout << Home.getName() << "\t\t" << Visitor.getName() << endl; 
      cout << "\t" << score << Home.getScore() << reset << "\t\t\t\t\t\t" << Visitor.getScore() << endl; 
      cout << score << Home.getCoachName() << reset << "\t\t" << Visitor.getCoachName() << endl; 
      for(int i = 0; i < 47; i++) { cout << "*"; } cout << endl;
       
       //proces to show the home team status
       cout << "Home> \t"; 
       if(Home.getHome_Status() == true)
       {
         cout << "Team 1: " << Home.getName() << "*"; 
       }
       else if(Visitor.getHome_Status() == true)
       {
         cout << "Team 2: " << Visitor.getName() << "*"; 
       }
       else
       {
         cout << "Error: "; 
       }
       
       cout  << endl; 
    }
    
};

int main() {
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName = ""; 
  string userChoice = ""; 
  string newCoachName = ""; 
  int homeTeamQuestion = 0; 
  int newScore = 0;
  
  s.showScoreboard();

   //Set the home team 
  tOne.setHome_Status(true); //tOne is the Home Team now   

  //add some initial data to s
  s.setHome(tOne);
  
  s.setVisitor(tTwo); 

  //Loop this to make it an interactive menu
  do 
  {
      system("clear"); //clear the screen of previous content 
      s.showScoreboard(); //show the current scoreboard data
      //menu choices 
      cout << "A = Update Team Name" << endl; 
      cout << "B = Update Team Score" << endl; 
      cout << "C = Update Status" << endl; 
      cout << "D = Update Team Coach" << endl; 
      cout << "E = Exit" << endl;
      cout << ">"; 
      userChoice = getValidatedInput<string>(); 

      if(userChoice == "A" || userChoice == "a")
      {
        cout << "****Update Team Name module****" << endl;
        cout << "Which Team Name would you like to edit?" << endl;
        cout << "1 = Home 2 = Visitor";
        int nameChoice;
        nameChoice = getValidatedInput<int>();

        if (nameChoice == 1)
        {
          cout << "\nPlease enter a new Name for the home team: ";
          newName = getValidatedInput<string>();
          tOne.setName(newName); 
        }
        else if (nameChoice== 2)
        {
          cout << "\nPlease enter a new Name for the visiting team: ";
          newName = getValidatedInput<string>();
          tTwo.setName(newName); 
        }

      }
      else if(userChoice == "B" || userChoice == "b")
      {
        cout << "****Update Team Score module****" << endl;
        cout << "Which Team Score would you like to edit?" << endl;
        cout << "1 = Home 2 = Visitor";
        int scoreChoice;
        scoreChoice = getValidatedInput<int>();

        if(scoreChoice == 1)
        {
        cout << "\nPlease enter a new score for the home team: "; 
        newScore = getValidatedInput<int>();
        tOne.setScore(newScore);    
        }
        else if(scoreChoice == 2)
        {
          cout << "\nPlease enter a new Score for the visiting team: ";
          newScore = getValidatedInput<int>();
          tTwo.setScore(newScore);
        }

      }
      else if(userChoice == "C" || userChoice == "c")
      {
        cout << "\nUpdate Home Status Module****" << endl; 
        cout << "\nWho is the home team: 1 = T1, 2=T2: "; 
        homeTeamQuestion = validateInt(homeTeamQuestion); 
       
        if(homeTeamQuestion == 1)
        {
          tOne.setHome_Status(true); 
          tTwo.setHome_Status(false); 
          
        }
        else if(homeTeamQuestion == 2)
        {
          tOne.setHome_Status(false); 
          tTwo.setHome_Status(true);
          
        }
        else
        {
          cout << "\nInvalid Input!" << endl;
          sleep(2); 
        }
      }
      else if(userChoice == "D" || userChoice == "d")
      {
        cout << "****Update Team Coach module****" << endl;
        cout << "Which Team CoachName would you like to edit?" << endl;
        cout << "1 = Home 2 = Visitor";
        int coachNameChoice = getValidatedInput<int>();
        if (coachNameChoice == 1)
        {
          cout << "\nPlease enter a new CoachName for the home team: "; 
        newCoachName = getValidatedInput<string>();
        tOne.setCoachName(newCoachName);   
        }
        else if (coachNameChoice == 2)
        {
          cout << "\nPlease enter a new CoachName for the home team: "; 
        newCoachName = getValidatedInput<string>();
        tTwo.setCoachName(newCoachName);   
        }
      }
      else if(userChoice == "E" || userChoice == "e")
      {
        cout << "Exit chosen." << endl; 
      }
      else //invalid input: default clause
      {
        cout << "\nInvalid input." << endl; 
        sleep(2); //wait two seconds, go to the next process 
      }

      s.setHome(tOne); //refresh the data in s to the new updates...
      s.setVisitor(tTwo); //refresh the data
  
  }while(userChoice != "E" && userChoice != "e");


  return 0; 
} 